#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); // TX, RX
void setup()
{
  Serial.begin(9600);
  while (!Serial);
  bluetooth.begin(9600);
}
void loop()
{
  if (bluetooth.available())
    Serial.write(bluetooth.read());
  if (Serial.available())
    bluetooth.write(Serial.read());
}
