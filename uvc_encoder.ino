#include "CytronMotorDriver.h"
#define ENC1A 2 // YELLOW
#define ENC1B 3 // WHITE
float PWM1 =0;
int dir1 = 1;
CytronMD motor1(PWM_DIR, 44, 45);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 46, 47); // PWM 2 = Pin 9, DIR 2 = Pin 10.
double channel[10];

int pos1 = 0;
int posprev1 = 0;

long prevT = 0;

//vel param
float currentVel1 = 0;
float prevVel1 = 0;
float eprevVel1 = 0;
float eintegralVel1 = 0;


void setup() {
  Serial.begin(9600);
  //Remote
  pinMode(4, INPUT);//ch4
  pinMode(6, INPUT);//ch5
  //
  //encoder1
  pinMode(ENC1A,INPUT);
  pinMode(ENC1B,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC1A),readEncoder1,RISING);
}

void loop() {
  channel[3] = pulseIn(4, HIGH);//waits for the pin to go from LOW to HIGH, starts timing, then waits for the pin to go LOW and stops timing.
  channel[4] = pulseIn(6, HIGH);
  Serial.print(channel[3]);
  Serial.print(" - ");
  Serial.println(channel[4]); 

  //set speed
  if(channel[4] < 1100){   
    float u1  = vel_control1(255);  // set argument pulse per sec. not pwm
    PWM1 =fabs(u1);
    dir1 = 1;
    if(u1<0){
       dir1 = -1;
     }
  }
  else if(channel[4] > 1700){
    float u1  = vel_control1(255);  
    PWM1 =fabs(u1);
    dir1 = 1;
    if(u1<0){
       dir1 = -1;
     }
  }
  else{  
    float u1  = vel_control1(255);  
    PWM1 =fabs(u1);
    dir1 = 1;
    if(u1<0){
       dir1 = -1;
    } 
  }
  

  if(channel[3] > 1700){ forward(PWM1,dir1); } 
  if(channel[3] < 1200){ backward(PWM1,dir1); }
  else{ stop1(); }

}
void forward(int pwm1,int dir1)
{
  Serial.println("forward");
  motor1.setSpeed(dir1*pwm1);   // Motor 1 runs forward 
  motor2.setSpeed(dir1*pwm1);   // Motor 2 runs forward 
  delay(100);
  }

void backward(int pwm1,int dir1)
{
  Serial.println("backward");
  motor1.setSpeed(dir1*pwm1);   // Motor 1 runs backward 
  motor2.setSpeed(dir1*pwm1);   // Motor 2 runs backward 
  delay(100);
  }
void stop1()
{
  motor1.setSpeed(0);     // Motor 1 stops.
  motor2.setSpeed(0);     // Motor 2 stops.
  delay(100);
}
float vel_control1(int target1){
  
  // set target
 int targetVel1 = target1;
 float deltaPos1 = 0;

 // PID constants
  float kp = 1;
  float kd = 0.01;
  float ki = 0.15; //0.0;

// time difference
  long currT = micros();
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT; //store previous time

// position difference
  deltaPos1 = pos1-posprev1;
  posprev1 = pos1;
  currentVel1 = deltaPos1/deltaT; // pulse per sec

 //// vel control loop ////
  // error
  int eVel1 = currentVel1 - targetVel1; //e(t) = target position - measured position

  // derivative(dv/dt)
  float dedtVel1 = (eVel1-eprevVel1)/(deltaT);

  // integral
  eintegralVel1 = eintegralVel1 + eVel1*deltaT;

  // control signal
  float u = kp*eVel1 + kd*dedtVel1 + ki*eintegralVel1;
 
  //float u1 = fabs(u);
  Serial.print("vel1 = ");
  Serial.println(currentVel1);
 
  return u;
  }
  
void readEncoder1(){
  int b = digitalRead(ENC1B);
  if(b > 0){
    pos1++;
  }
  else{
    pos1--;
  }
  
}
