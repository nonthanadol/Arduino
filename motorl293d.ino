#include <AFMotor.h>

const int MOTOR_1 = 1; 
const int MOTOR_2 = 2; 
const int MOTOR_3 = 3; 
const int MOTOR_4 = 4; 

AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); // create motor object, 64KHz pwm
//===============================================================================
//  Initialization
//=============================================================================== 
void setup() {
  Serial.begin(9600);           // Initialize serial port
  Serial.println("Motor test");
  
  motor1.setSpeed(150);          // set the motor speed to 0-255
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
}
//===============================================================================
//  Main
//=============================================================================== 
void loop() {
  // Simply run the selected motor in both directions and stop.  Then repeat
  Serial.println("Forward");
 
  motor1.run(FORWARD);         // turn it on going forward
  motor2.run(FORWARD);
  motor3.run(FORWARD); 
  motor4.run(FORWARD);
  delay(3000);
 
  Serial.println("Reverse");
  motor1.run(BACKWARD);        // the other way
  motor2.run(BACKWARD); 
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD); 
  delay(3000);
  
  Serial.println("Stop");
  motor1.run(RELEASE);         // stopped
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(3000);
}
