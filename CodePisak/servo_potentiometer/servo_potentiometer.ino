#include <Servo.h> //include servo library
Servo myservo; // create servo object

void setup() {
	myservo.attach(7); //use pin 7 for servo signal
	pinMode(3,OUTPUT);
	Serial.begin(9600); // baud rate = 9600 bit per second
}

void loop() {
	int sensorValue = analogRead(A0); // potentiometer = A0
	//  int map_servo = map(sensorValue, 0, 1023, 0, 180);
	int motor_pw = sensorValue/4;
	//  int map_servo = sensorValue*180/1023; //ไม่ถูกต้อง
	int map_servo = float(sensorValue)*180/1023; //ถูกต้อง เพื่อการคำนวณ

	Serial.println(map_servo);
	myservo.write(map_servo);  
	analogWrite(3,motor_pw);
	delay(20);
}
