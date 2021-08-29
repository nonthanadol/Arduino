#include <LiquidCrystal_I2C.h>
#include "DHT.h"
DHT dht;
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
  Serial.begin(9600);
  dht.setup(26);
  lcd.init();// initialize the lcd 
  lcd.backlight(); // เปิด backlight 
  lcd.setCursor(0, 0);
  lcd.print("Start!!!");
  pinMode(18,OUTPUT);

}

void loop() {
  
  float temperature = dht.getTemperature();
  float humidity = dht.getHumidity(); 
   Serial.print(temperature);
   Serial.print(" ");
    Serial.println(humidity);
   lcd.clear();
   lcd.home();
   lcd.setCursor(0, 0);
   lcd.print(temperature);
   lcd.setCursor(0, 1);
   lcd.print(humidity);
  
}







//void loop() {
//  
//  float Temp=scantemp();
//  float Hum=scanhum();
//  LCD(Temp,Hum);
//
//}
//
//void LCD(float T,float H){
//  
//   lcd.clear();
//   lcd.home();
//   lcd.setCursor(0, 0);
//   lcd.print(T);
//   lcd.setCursor(0, 1);
//   lcd.print(H);
//  
//}
//
//float scantemp(){
//  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
//  Serial.print(temperature);
//  Serial.print(" ");
//  return temperature;
//}
//float scanhum(){
//  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
//  Serial.println(humidity);
//  return humidity;
//}
