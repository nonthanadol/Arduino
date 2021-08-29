#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

char auth[] = "e-bSVzLzJWPWn1t7WPPU0qswoZoW-VJF";
char ssid[] = "vivo 1609";
char pass[] = "0938413308non";
#define DHTPIN 25
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(11520);
  Blynk.begin(auth, ssid, pass); //เชื่อมต่อกับ wifi Network และ Blynk Server
  dht.begin();//เริ่มต้นใช้งานsensor DHT
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) { //ถ้าไม่สามารถอ่านค่าอุณหภูมิและความชื้นเก็บใน t และ h ได้
    Serial.println("Failed to read from DHT sensor!");
    return; //กลับไปอ่านค่าใหม่ จนเมื่ออ่านค่าได้
  }
  Blynk.run(); //Blynk ทำงาน
  Blynk.virtualWrite(V1,t); // นำค่าอุณหภูมิจากตัวแปร t ไปเก็บไว้ใน V1 แล้วส่งไปยัง Blynk server
  Blynk.virtualWrite(V2,h);

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("C |");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%");
  delay(1000);

}

//Gauge (Temp),(Hum) -->Input pin-->virtual V1,V2 --> กำหนดค่า min-max = 0-50 , 0-100 --> Label /pin/C --> Refresh interval เลือก Push 
//Super chart -->ชื่อกราฟ DHT11 --> เลือก seeting --> input V1 --> Min/max -->
