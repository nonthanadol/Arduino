#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
  lcd.init();// initialize the lcd 
  lcd.backlight();       // เปิด backlight 
  Serial.begin(9600);
  }
void loop() {
  String text = "Hello AAI";
  Serial.println(text);
  LCD(text);
  
  delay(1000);
  
  }

void LCD(String x){
  
   lcd.clear();
   lcd.home();
   lcd.setCursor(0, 0);
   lcd.print(x);
  
  }


  
