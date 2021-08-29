//การใช้งาน switch button หรือสวิตช์กดติดปล่อยดับ
void setup() {
  pinMode(2,INPUT); //use pin2 for switch
  pinMode(8,OUTPUT); //internal LED
  pinMode(7,OUTPUT); //external LED
  Serial.begin(9600); //9600 baud rate for serial monitor
}

void loop() {
  if (digitalRead(2) == HIGH){
    Serial.println("On");
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
  }
  else{
    Serial.println("Off");
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
  }
  delay(100); //delay 100ms between each loop
}
