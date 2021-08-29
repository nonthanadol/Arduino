//#define ENCA 2 // Yellow
//#define ENCB 3 // White
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(ENCA,INPUT);
//  pinMode(ENCB,INPUT);
//}
//
//void loop() {
//  int a = digitalRead(ENCA);
//  int b = digitalRead(ENCB);
//  Serial.print(a*5); 
//  Serial.print(" ");
//  Serial.print(b*5);
//  Serial.println();
//}

//##############################################

//#define ENCA 2 // YELLOW
//#define ENCB 3 // WHITE
//
//int pos = 0;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(ENCA,INPUT);
//  pinMode(ENCB,INPUT);
//  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
//}
//
//void loop() {
//  Serial.println(pos);
//}
//
//void readEncoder(){
//  int b = digitalRead(ENCB);
//  if(b > 0){
//    pos++;
//  }
//  else{
//    pos--;
//  }
//}

//##############################################


//#define ENCA 2 // YELLOW
//#define ENCB 3 // WHITE
//#define PWM 9
//#define IN2 6
//#define IN1 7
//
//int pos = 0; 
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(ENCA,INPUT);
//  pinMode(ENCB,INPUT);
//  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
//  
//  pinMode(PWM,OUTPUT);
//  pinMode(IN1,OUTPUT);
//  pinMode(IN2,OUTPUT);
//}
//
//void loop() {
//  
//  setMotor(1, 255, PWM, IN1, IN2);
//  delay(200);
//  Serial.println(pos);
//  setMotor(-1, 255, PWM, IN1, IN2);
//  delay(200);
//  Serial.println(pos);
//  setMotor(0, 255, PWM, IN1, IN2);
//  delay(20);
//  Serial.println(pos);
//}
//
//void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
//  analogWrite(pwm,pwmVal);
//  if(dir == 1){
//    digitalWrite(in1,HIGH);
//    digitalWrite(in2,LOW);
//  }
//  else if(dir == -1){
//    digitalWrite(in1,LOW);
//    digitalWrite(in2,HIGH);
//  }
//  else{
//    digitalWrite(in1,LOW);
//    digitalWrite(in2,LOW);
//  }
//}
//
//void readEncoder(){
//  int b = digitalRead(ENCB);
//  if(b > 0){
//    pos++;
//  }
//  else{
//    pos--;
//  }
//}
//###############################################################

#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE
#define PWM 9
#define IN2 6
#define IN1 7

int pos = 0;
int posprev = 0;

long prevT = 0;

float eprev = 0;
float eintegral = 0;

//vel param
float currentVel = 0;
float prevVel = 0;
float eprevVel = 0;
float eintegralVel = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  Serial.println("target pos");
}

void loop() {

  // set target position
  int target = 3410;
  int targetVel = 1000;
  //int target = 250*sin(prevT/1e6);
  float deltaPos = 0;

  // PID constants
  float kp = 1;
  float kd = 0.01;
  float ki = 0.15; //0.0;

  // time difference
  long currT = micros();
  float deltaTm = currT - prevT;
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT; //store previous time
//  Serial.println(deltaTm);
  
//  currentVel = (float)((pos-posprev));
  deltaPos = pos-posprev;
  posprev = pos;
  currentVel = deltaPos/deltaT;
//  Serial.print("pos ");
//  Serial.println(pos);
//  Serial.print("posprev ");
//  Serial.println(posprev);
//  Serial.print("deltaT ");
//  Serial.println(deltaT);
//  Serial.print("deltaPos ");
//  Serial.println(deltaPos);
 // Serial.print("vel ");
  //Serial.println(currentVel);

  
//  // error
//  int e = pos - target; //e(t) = target position - measured position
//
//  // derivative
//  float dedt = (e-eprev)/(deltaT);
//
//  // integral
//  eintegral = eintegral + e*deltaT;
//
//  // control signal
//  float u = kp*e + kd*dedt + ki*eintegral;


  //// vel control loop ////
  // error
  int eVel = currentVel - targetVel; //e(t) = target position - measured position

  // derivative
  float dedtVel = (eVel-eprevVel)/(deltaT);

  // integral
  eintegralVel = eintegralVel + eVel*deltaT;

  // control signal
  float u = kp*eVel + kd*dedtVel + ki*eintegralVel;
  // Serial.println(u);
  //// vel control loop  ////


  // motor power
  float pwr = fabs(u);
  if( pwr > 255 ){
    pwr = 255;
  }

  // motor direction
  int dir = 1;
  if(u<0){
    dir = -1;
  }

  // signal the motor
  setMotor(dir,pwr,PWM,IN1,IN2);


  // store previous error
//  eprev = e;
  eprevVel = eVel;
  

//  Serial.print(target);
//  Serial.print(" ");
//  Serial.print(pos);
//  Serial.println();
}

void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }  
}

void readEncoder(){
  int b = digitalRead(ENCB);
  if(b > 0){
    pos++;
  }
  else{
    pos--;
  }
  
}
