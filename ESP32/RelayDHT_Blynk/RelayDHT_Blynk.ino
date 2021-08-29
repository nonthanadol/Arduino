#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

char auth[] = "e-bSVzLzJWPWn1t7WPPU0qswoZoW-VJF";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo 1609";
char pass[] = "0938413308non";

#define ledpin1 33
#define relay 26
#define DHTPIN 25
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

boolean state1 = false;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();

  pinMode(ledpin1, OUTPUT);
  pinMode(relay, OUTPUT);

  
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) { //ถ้าไม่สามารถอ่านค่าอุณหภูมิและความชื้นเก็บใน t และ h ได้
    Serial.println("Failed to read from DHT sensor!");
    return; //กลับไปอ่านค่าใหม่ จนเมื่ออ่านค่าได้
  }
   Blynk.run();
   Blynk.virtualWrite(V1,t); // นำค่าอุณหภูมิจากตัวแปร t ไปเก็บไว้ใน V1 แล้วส่งไปยัง Blynk server
   Blynk.virtualWrite(V2,h);

}


BLYNK_WRITE(V3)
{

 //WidgetLED led1(V2);//ledในapp

 if (state1 == false) {
 
 state1 = true;
 String text1 = "On";
 Serial.println(text1);
 digitalWrite(ledpin1,HIGH);
 digitalWrite(relay,HIGH);
 //led1.on();
 delay(1000);
 }
 else {
 state1 = false;
  String text1 = "Off";
  Serial.println(text1) ;
  digitalWrite(ledpin1,LOW);
  digitalWrite(relay,LOW);
  //led1.off();
 }
}
