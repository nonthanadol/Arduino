void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
 Serial.begin(9600);
}

void loop() {
   for(int i=0;i<5;i++){
    digitalWrite(8,HIGH);
    Serial.println("LED 1 HIGH : LED 2 LOW : LED 3 LOW");
    delay(1000); 
    digitalWrite(8,LOW);
    Serial.println("LED 1 LOW  : LED 2 LOW : LED 3 LOW");
    delay(1000);
   }
   for(int i=0;i<5;i++){
    digitalWrite(9,HIGH);
    Serial.println("LED 1 LOW  : LED 2 HIGH : LED 3 LOW");
    delay(500);
    digitalWrite(9,LOW);
    Serial.println("LED 1 LOW  : LED 2 LOW  : LED 3 LOW");
    delay(500);
   }
   for(int i=0;i<5;i++){
    digitalWrite(10,HIGH);
    Serial.println("LED 1 LOW  : LED 2 LOW : LED 3 HIGH");
    delay(100);
    digitalWrite(10,LOW);
    Serial.println("LED 1 LOW  : LED 2 LOW : LED 3 LOW");
    delay(100);
   }

}
