#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "02xnXW733dpG94Zb02KvWdwNhjtJArav";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo 1609";
char pass[] = "0938413308non";
 
#define WATER_PUMP 27
boolean state = false;
 
void setup()
{
 // Debug console
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 pinMode(WATER_PUMP, OUTPUT);
}
 
void loop()
{
 Blynk.run();
}
 
BLYNK_WRITE(V1)
{
 if (state == false) {
 state = true;
 Blynk.notify("You just watered your plant."); //แจ้งเตือนในแอป
 digitalWrite(WATER_PUMP,HIGH);
 delay(1000);
 }
 else {
 state = false;
 digitalWrite(WATER_PUMP,LOW);
 }
}
