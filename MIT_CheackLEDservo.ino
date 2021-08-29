#include <Servo.h>
#include <SoftwareSerial.h>
Servo myservo1;
SoftwareSerial bluetooth(2, 3); // TX, RX
//String Value;
void setup() {
  myservo1.attach(8);
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(7,OUTPUT);
}

void loop() {
 if (bluetooth.available()>0){ //ถ้าอ่านค่าจากBluetoothได้
    int servopos = bluetooth.read();
    String Value=bluetooth.readString(); //อ่านค่าที่ได้จากbluetooth เก็บในValue
    
   // int servopos = bluetooth.read();
    
    
    Serial.println(Value);
    Serial.println(servopos);

     if(servopos>=0){
    myservo1.write(servopos);
    Serial.println("servo 1 ON");  
      }

     
     if(Value == "1"){
       Serial.println("ON");
       digitalWrite(7,HIGH);
     }
     else{
      Serial.println("OFF");
      digitalWrite(7,LOW);
     }    
   }
 
  

}
