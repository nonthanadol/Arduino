#include "AFMotor.h"

const int MOTOR_1 = 1; 
const int MOTOR_2 = 2; 
const int MOTOR_3 = 3; 
const int MOTOR_4 = 4; 

AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); // create motor object, 64KHz pwm
unsigned long interval[] = {200,400,600,1000,1200,1400,1600,62000,62000};     // the time we need to wait

long currentMillis = 0;
long previousMillis = 0;
long previousMillis1 = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
long previousMillis4 = 0;
long previousMillis5 = 0;
long previousMillis6 = 0;
long previousMillis7 = 0;
long previousMillis8 = 0;
long previousMillis9 = 0;
void setup() {
 
  Serial.begin(9600);           // Initialize serial port
  Serial.println("Start");

  motor1.setSpeed(100);          // set the motor speed to 0-255
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
}

void loop() {
        
       currentMillis = millis();
    Serial.print(currentMillis);
    Serial.print("   ");
    Serial.print(previousMillis);
    Serial.print("   ");
    Serial.print(previousMillis1);
    Serial.print("   ");
     Serial.print(previousMillis2);
    Serial.print("   ");
    Serial.println(previousMillis3);
    
    if ((currentMillis - previousMillis >= 5000) and (currentMillis - previousMillis <= 9000 ))  {
        
        Serial.println("ADVANCE ");
        
        ADVANCE();
       //previousMillis = currentMillis;
      }
    
    if ((currentMillis - previousMillis1 >= 10000)  and(currentMillis - previousMillis1 <= 12000)) {
        STOP();
       // previousMillis1 = currentMillis;
      }
       if ((currentMillis - previousMillis2 >= 12000)  and(currentMillis - previousMillis2 <= 16000)) {
        BACK();
       // previousMillis1 = currentMillis;
      }
       if ((currentMillis - previousMillis3 >= 16000)  and(currentMillis - previousMillis3 <= 18000)) {
        STOP();
       // previousMillis1 = currentMillis;
      }
       if ((currentMillis - previousMillis4 >= 18000)  and(currentMillis - previousMillis4 <= 22000)) {
        LEFT_1();
       // previousMillis1 = currentMillis;
      }
       if ((currentMillis - previousMillis5 >= 22000)  and(currentMillis - previousMillis5 <= 26000)) {
       RIGHT_3();
       // previousMillis1 = currentMillis;
      }
      if ((currentMillis - previousMillis6 >= 26000)  and(currentMillis - previousMillis6 <= 30000)) {
       LEFT_2();
       // previousMillis1 = currentMillis;
      }
      if ((currentMillis - previousMillis7 >= 30000)  and(currentMillis - previousMillis7 <= 34000)) {
       RIGHT_2();
       // previousMillis1 = currentMillis;
      }
       if ((currentMillis - previousMillis8 >= 34000)  and(currentMillis - previousMillis8 <= 38000)) {
       RIGHT_1();
       // previousMillis1 = currentMillis;
      }
      if ((currentMillis - previousMillis9 >= 38000)  and(currentMillis - previousMillis9 <= 42000)) {
       LEFT_3();
       // previousMillis1 = currentMillis;
      }
             
}


//    ↑A-----B↑   
//     |  ↑  |
//     |  |  |
//    ↑C-----D↑
void ADVANCE()
{
  motor1.run(FORWARD);   motor4.run(FORWARD);      
  motor2.run(FORWARD);   motor3.run(FORWARD); 
}

//    ↓A-----B↓   
//     |  |  |
//     |  ↓  |
//    ↓C-----D↓
void BACK()
{
  motor1.run(BACKWARD);   motor4.run(BACKWARD);      
  motor2.run(BACKWARD);   motor3.run(BACKWARD);
}
//    =A-----B↑   
//     |   ↖ |
//     | ↖   |
//    ↑C-----D=
void LEFT_1()
{
  motor1.run(RELEASE);   motor4.run(FORWARD);      
  motor2.run(FORWARD);   motor3.run(RELEASE);
}

//    ↓A-----B↑   
//     |  ←  |
//     |  ←  |
//    ↑C-----D↓
void LEFT_2()
{
  motor1.run(BACKWARD);   motor4.run(FORWARD);      
  motor2.run(FORWARD);    motor3.run(BACKWARD);
}
//    ↓A-----B=   
//     | ↙   |
//     |   ↙ |
//    =C-----D↓
void LEFT_3()
{
  motor1.run(BACKWARD);   motor4.run(RELEASE);      
  motor2.run(RELEASE);   motor3.run(BACKWARD);
}
//    ↑A-----B=   
//     | ↗   |
//     |   ↗ |
//    =C-----D↑
void RIGHT_1()
{
  motor1.run(FORWARD);   motor4.run(RELEASE);      
  motor2.run(RELEASE);   motor3.run(FORWARD);
}
//    ↑A-----B↓   
//     |  →  |
//     |  →  |
//    ↓C-----D↑
void RIGHT_2()
{
  motor1.run(FORWARD);   motor4.run(BACKWARD);      
  motor2.run(BACKWARD);   motor3.run(FORWARD);
}
//    =A-----B↓   
//     |   ↘ |
//     | ↘   |
//    ↓C-----D=
void RIGHT_3()
{
  motor1.run(RELEASE);   motor4.run(BACKWARD);      
  motor2.run(BACKWARD);   motor3.run(RELEASE);
}
//    ↓A-----B↑
//     |     |
//     |     |
//    ↓C-----D↑
void TURN_LEFT()
{
  motor1.run(BACKWARD);   motor4.run(FORWARD);      
  motor2.run(BACKWARD);   motor3.run(FORWARD);
}
//    ↑A-----B↓
//     |     |
//     |     |
//    ↑C-----D↓
void TURN_RIGHT()
{
  motor1.run(FORWARD);   motor4.run(BACKWARD);      
  motor2.run(FORWARD);   motor3.run(BACKWARD);  
}
//    =A-----B=  
//     |  =  |
//     |  =  |
//    =C-----D=
void STOP()
{ Serial.println("Stop");
  motor1.run(RELEASE);   motor4.run(RELEASE);      
  motor2.run(RELEASE);   motor3.run(RELEASE);
}
