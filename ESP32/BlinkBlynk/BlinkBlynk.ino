#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "4-oTvuEZsr9cSiFeEc3b6vbBEpCJEj1V";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo 1609";
char pass[] = "0938413308non";

#define ledpin1 25
#define ledpin2 33
boolean state1 = false;
boolean state2 = false;

void setup()
{
 // Debug console
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 pinMode(ledpin1, OUTPUT);
 pinMode(ledpin2, OUTPUT);
}

void loop()
{
 Blynk.run();
}

BLYNK_WRITE(V2)
{
 WidgetLED led1(V2);//ledในapp
 if (state1 == false) {
 state1 = true;
 String text1 = "On";
 Serial.println(text1);
 Blynk.virtualWrite(V2,text1); //แจ้งเตือนในแอป
 digitalWrite(ledpin1,HIGH);
 led1.on();
 delay(1000);
 }
 else {
 state1 = false;
  String text1 = "Off";
  Serial.println(text1) ;
  Blynk.virtualWrite(V2,text1); //app display
  digitalWrite(ledpin1,LOW);
  led1.off();
 }
}

BLYNK_WRITE(V3)
{
 WidgetLED led2(V3);//ledในapp
 if (state2 == false) {
 state2 = true;
 String text2 = "On";
 Serial.println(text2);
 Blynk.virtualWrite(V3,text2); //app display
 digitalWrite(ledpin2,HIGH);
 led2.setValue(50);//ปรับค่าความสว่างของแสงในapp
 delay(1000);
 }
 else {
  state2 = false;
  String text2 = "Off";
  Serial.println(text2) ;
  Blynk.virtualWrite(V2,text2); //แจ้งเตือนในแอป
  digitalWrite(ledpin2,LOW);
  led2.off();
 }
}
