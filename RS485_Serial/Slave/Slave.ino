#include <Servo.h> //include servo library
Servo myservo; // create servo object

#define LED       13
#define SLAVE_EN  8

void setup() {
  pinMode(LED , OUTPUT);                        // Declare LED pin as output
  pinMode(SLAVE_EN , OUTPUT);                   // Declare Enable pin as output
  Serial.begin(9600);                           // set serial communication baudrate 
  myservo.attach(7);
  digitalWrite(SLAVE_EN , LOW);                 // Make Enable pin low
                                                // Receiving mode ON 
}

// //###Blink LED###
//void loop() {
//  while(Serial.available())                     // If serial data is available then enter into while loop
//  {
//    if(Serial.read() == 'A')                    // if available data is A
//    {
//      digitalWrite(LED , !digitalRead(LED));    // LED Blink
//    }
//  }
//}

////###Read from potentiometer###
//void loop() {
//  if(Serial.available())                     // If serial data is available then enter into while loop
//  {
//    if(Serial.read())                    
//    {
//      int sensorValue = Serial.parseInt ();
//      Serial.println("In Slave");
//      Serial.println(sensorValue);
//    }
//  }
//}

////###control 1 servo###
//void loop() {
//  if(Serial.available())                     // If serial data is available then enter into while loop
//  {
//    if(Serial.read())                   
//    {
//      int map_servo_Slave = Serial.parseInt ();
//      Serial.println("In Slave");
//      Serial.println(map_servo_Slave);
//      myservo.write(map_servo_Slave);
//    }
//  }
//}

//######
void loop() {
  if(Serial.available())                     // If serial data is available then enter into while loop
  {
    if(Serial.read())                   
    {
      int map_servo_Slave = Serial.parseInt ();
      Serial.println("In Slave");
      Serial.println(map_servo_Slave);
      myservo.write(map_servo_Slave);
      if(map_servo_Slave > 90){
        digitalWrite(SLAVE_EN , HIGH);
        delay(5); 
        Serial.println("A");
        Serial.flush();  
        digitalWrite(SLAVE_EN , LOW);
      }        
    }
  }
}
