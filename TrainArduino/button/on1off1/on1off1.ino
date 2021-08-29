void setup() {
   pinMode(2,INPUT);
   pinMode(5,OUTPUT);
   pinMode(7,OUTPUT);

}

void loop() {
  if(digitalRead(2) == HIGH){
    Serial.println("On");
    digitalWrite(5,HIGH);
    digitalWrite(7,LOW);
  }
   else{
    digitalWrite(5,LOW);
    Serial.println("Off");
    digitalWrite(7,HIGH);
    }
   

}
