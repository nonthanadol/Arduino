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


void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  

}

void loop() {
  // set target position
  int target = 3410;
  
   // PID constants
  float kp = 1;
  float kd = 0.01;
  float ki = 0.15; //0.0;

  // time difference
  long currT = micros();
  //float deltaTm = currT - prevT;
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT; //store previous time

   // error
  int e = pos - target; //e(t) = target position - measured position

  // derivative
  float dedt = (e-eprev)/(deltaT);

  // integral
  eintegral = eintegral + e*deltaT;

  // control signal
  float u = kp*e + kd*dedt + ki*eintegral;
 // Serial.println(u);
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
  eprev = e;

  Serial.print(target);
  Serial.print(" ");
  Serial.print(pos);
  Serial.println();
  
}

void setMotor(int dir, int pwmpos, int pwm, int in1, int in2){
  analogWrite(pwm,pwmpos);
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
