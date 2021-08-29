//การใช้งาน switch button หรือสวิตช์กดติดปล่อยดับ
void setup() {
  pinMode(2,INPUT_PULLUP); //use pin2 for switch
  pinMode(13,OUTPUT); //internal LED
  Serial.begin(9600); //9600 baud rate for serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == LOW){
    Serial.println("On");
    digitalWrite(13,HIGH);
  }
  else{
    Serial.println("Off");
    digitalWrite(13,LOW);
  }
  delay(100); //delay 100ms between each loop
}
