#include <LiquidCrystal_I2C.h>

#define trig 13
#define echo 12
LiquidCrystal_I2C lcd(0x27,16,2); 
long currentMillis = 0;
long previousMillis = 0;
long previousMillis1 = 0;
boolean LED_state = 0;

void setup() {
  pinMode(10, OUTPUT);//Buzzer
  pinMode(11, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(9, 1);// 1 = HIGH , 0 = LOW

  lcd.init();// initialize the lcd 
  //lcd.noBacklight();   // ปิด backlight
  lcd.backlight();       // เปิด backlight 


 
  Serial.begin(9600);
}
void loop()
{
  int distance = scan(); 
  currentMillis = millis(); //Returns the number of milliseconds passed since the Arduino board began running the current program
  
  if (currentMillis - previousMillis1 >= 500)  {
        LCDdisplay(distance); //เรียกใช้Function LCDdisplay ส่งค่าระยะที่วัดได้เข้าไป
        previousMillis1 = currentMillis; // เพิ่มค่าตัวลบ(อัพเดตเวลา)
      }
  
  
  if (distance <= 100) {
     if (distance >= 1 && distance <= 30) { 
        digitalWrite(9, 0);
      
        //distance น้อย ไฟกระพริบเร็ว
        if ((currentMillis - previousMillis >= 10 * distance) && LED_state == 0) { 
          digitalWrite(11, 1);
          analogWrite(10, 255);
          LED_state = 1;
          previousMillis = currentMillis; // เพิ่มค่าตัวลบ(อัพเดตเวลา)
        }
        else if ((currentMillis - previousMillis >= 10 * distance) && LED_state == 1) {
          digitalWrite(11, 0);
          analogWrite(10, 0);
          LED_state = 0;
          previousMillis = currentMillis;// เพิ่มค่าตัวลบ(อัพเดตเวลา)
        }
     }
     else {
        digitalWrite(11, 0);
        digitalWrite(9, 1);
     }

  }
  else {
     digitalWrite(11, 0);
     digitalWrite(9, 1);
  }
 
}


int scan() {
  int duration, cm; // duration-->สำหรับเก็บค่าเวลาที่เสียงเดินทาง , cm --> สำหรับเก็บค่าระยะทางที่คำนวณได้
  // เคลียร์ค่าขา trig ป้องกันกรณีสถานะค้างเก่าค้างอยู่
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // ให้ขา trig ส่งคลื่นออกไป 10 ไมโครวินาทีแล้วปิด
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

 // จับเวลาจนกว่าจะมีคลื่นเสียงมากระทบ echo โดยคำสั่ง pulseIn
  duration = pulseIn(echo, HIGH);
 // cm = microsecondsToCentimeters(duration);
  cm = (duration*0.034)/2;

  Serial.print(cm);
  Serial.println(" cm");
  delay(10);

  return cm;
}

//int microsecondsToCentimeters(int microseconds)
//{
//  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
//  // The ping travels out and back, so to find the distance of the
//  // object we take half of the distance travelled.
//  return microseconds / 29 / 2;
//}

void LCDdisplay(int x){
    //long y=x/100;
   lcd.clear();
   lcd.home();
   lcd.setCursor(4, 0);
   lcd.print(x);
   lcd.setCursor(8, 0);
   lcd.print("cm."); 
  }


  
