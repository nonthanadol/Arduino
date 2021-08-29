#include <Servo.h> //include servo library
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int sensorValue1,sensorValue2,sensorValue3,sensorValue4;
int x,y,z,w;
//unsigned long currentMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long preiod1 = 10;
unsigned long preiod2 = 12;
unsigned long preiod3 = 15;
unsigned long preiod4 = 20;
 
void setup() {
 myservo1.attach(6); //use pin 7 for servo signal
 myservo2.attach(9);
 myservo3.attach(10);
 myservo4.attach(11);
 Serial.begin(9600);
}
void loop(){
  servo1();
  servo2();
  servo3();
  servo4();
  
}

void servo1(){
  
  if(millis() - previousMillis1 >= preiod1){
    previousMillis1 = millis(); //อัพเดตเวลา
    sensorValue1 = analogRead(A4);
    Serial.println(sensorValue1);
    x = map(sensorValue1,0,1023,0,180);
    myservo1.write(x); 
   }
}
void servo2(){
  
  if(millis() - previousMillis2 >= preiod2){
    previousMillis2 = millis();//อัพเดตเวลา
    sensorValue2 = analogRead(A1);
    Serial.println(sensorValue2);
    y = map(sensorValue2,0,1023,0,180);
    myservo2.write(y); 
   }
}
void servo3(){
  
  if(millis() - previousMillis3 >= preiod3){
    previousMillis3 = millis();//อัพเดตเวลา
    sensorValue3 = analogRead(A2);
    Serial.println(sensorValue3);
    z = map(sensorValue3,0,1023,0,180);
    myservo3.write(z); 
   }
}
void servo4(){
  
  if(millis() - previousMillis4 >= preiod4){
    previousMillis4 = millis();//อัพเดตเวลา
    sensorValue4 = analogRead(A3);
    Serial.println(sensorValue4);
    w = map(sensorValue4,0,1023,0,180);
    myservo4.write(w); 
   }
}
