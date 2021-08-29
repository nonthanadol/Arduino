#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 26
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3f,16,2);  // set the LCD address to 0x3f for a 16 chars and 2 line display


void setup() {
   
   dht.begin();
   lcd.init(); // initialize the lcd 
   lcd.backlight();
   
}

void loop() {
 
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
    
    lcd.setCursor(0,0);
    lcd.print("Hum");
    lcd.setCursor(4,0);
    lcd.print(h);
    lcd.setCursor(10,0); 
    lcd.print("%");
    
    lcd.setCursor(0,1);
    lcd.print("Temp");
    lcd.setCursor(5,1);
    lcd.print(t);
    lcd.setCursor(11,1);
    lcd.print("C");
  
}
