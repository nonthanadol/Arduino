#include <Servo.h> //include servo library

Servo myservo; // create servo object

void setup() {
  myservo.attach(7); //use pin 7 for servo signal
}

void loop() {
  myservo.write(0); //move servo to 0 degree            
  delay(1000); //delay 1000 ms                      

  myservo.write(180); //move servo to 180 degree  
  delay(1000); //delay 1000 ms                       
}
