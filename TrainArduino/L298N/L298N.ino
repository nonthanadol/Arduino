int MotorPin2 = 7;
int MotorPin3 = 6;
int PWMPin9 = 9;
void setup() {
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(PWMPin9, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, LOW);
  for (int x = 0; x < 255; x++) {
    analogWrite(PWMPin9, x);
    delay(10);
    Serial.println(x);
  }
  delay(2000);
}
