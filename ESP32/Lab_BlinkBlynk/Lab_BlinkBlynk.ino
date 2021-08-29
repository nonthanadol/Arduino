#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = " e-bSVzLzJWPWn1t7WPPU0qswoZoW-VJF";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo 1609";
char pass[] = "0938413308non";

void setup(){  
Serial.begin(11520);
Blynk.begin(auth, ssid, pass); //เชื่อมต่อกับ wifi Network และ Blynk Server
}

void loop(){
  
  Blynk.run();
  
 }

// button -->select pin digital
