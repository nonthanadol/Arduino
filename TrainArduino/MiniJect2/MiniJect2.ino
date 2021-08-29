#include <Servo.h> //include servo library
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 26
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3f,16,2); 
Servo myservo1; // create servo object
int sensorValue1,x=0;
unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long preiod1 = 10;

void setup() {
  dht.begin();
  myservo1.attach(7); 
  Serial.begin(9600);
  lcd.init();// initialize the lcd 
  lcd.backlight(); // เปิด backlight 

}

void loop() {
   int location;
   float T;
   float H;
   location = servo();
   if (millis() - previousMillis >= 500)  {
            T = ScanTemp();
            H = ScanHum();
            LCD(T,H,location);
            previousMillis = millis(); //อัพเดตเวลา
    }

}

int servo(){
  if(millis() - previousMillis1 >= preiod1){
    previousMillis1 = millis(); //อัพเดตเวลา
    sensorValue1 = analogRead(A0);
    Serial.println(sensorValue1);
    x = map(sensorValue1,0,1023,180,0);
    myservo1.write(x); 
   }
  return x;
} 

float ScanTemp(){
  float temperature = dht.readTemperature(); // ดึงค่าอุณหภูมิ
  return temperature; 
}

float ScanHum(){
  float humidity = dht.readHumidity(); // ดึงค่าความชื้น
  return humidity;  
}


void LCD(float T,float H,int loc){
 
   lcd.clear();
   lcd.home();
   
   lcd.setCursor(0, 0);
   lcd.print("Hu:");
   lcd.setCursor(3, 0);
   lcd.print(H);

   lcd.setCursor(9, 0);
   lcd.print("T:");
   lcd.setCursor(11, 0);
   lcd.print(T);

   lcd.setCursor(0, 1);
   lcd.print("Location:");
   lcd.setCursor(9, 1);
   lcd.print(loc); 
}
