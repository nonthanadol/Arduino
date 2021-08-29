void setup() {
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);

}

void loop() {
   beep();
   

}
void beep(){
  int sensorValue = analogRead(A0);
  int Volume = sensorValue/4;
  //int Sleep = map
  analogWrite(9, Volume);
  
  digitalWrite(10,HIGH);
  delay(100000/(sensorValue+100));
  digitalWrite(10,LOW);
  delay(100000/(sensorValue+100));
}
