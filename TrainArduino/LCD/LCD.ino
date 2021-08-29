#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  //  
  lcd.backlight();
  lcd.setCursor(0,0);//แถว1
  lcd.print("Hello world!");
  lcd.setCursor(0,1);//แถว2
  lcd.print("Uschool!");
  
}


void loop()
{
}
