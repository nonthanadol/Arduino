#include "DHT.h"
#include <LiquidCrystal_I2C.h>

DHT dht;
LiquidCrystal_I2C lcd(0x3f,16,2);  // set the LCD address to 0x3f for a 16 chars and 2 line display

void setup() {
   
   dht.setup(2); // data pin 2
   lcd.init(); // initialize the lcd 
   lcd.backlight();
   
}

void loop() {
 
  float humidity = dht.getHumidity(); //ดึงค่าความชื้น
  float temperature = dht.getTemperature();//ดึงค่าอุณหภูมิ 
    
    lcd.setCursor(0,0);
    lcd.print("Hum");
    lcd.setCursor(4,0);
    lcd.print(humidity);
    lcd.setCursor(10,0); 
    lcd.print("%");
    
    lcd.setCursor(0,1);
    lcd.print("Temp");
    lcd.setCursor(5,1);
    lcd.print(temperature);
    lcd.setCursor(11,1);
    lcd.print("C");
  
}
