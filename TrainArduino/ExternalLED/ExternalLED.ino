#define ledpin 32
void setup() {
 pinMode(ledpin,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  digitalWrite(ledpin,HIGH);
  Serial.println("on");
  delay(500);
  digitalWrite(ledpin,LOW);
  Serial.println("off");
  delay(500);

}
