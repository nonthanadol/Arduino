int ledPin2 = 2;
int ledPin3 = 3;

int val = 0;
void setup() {
  pinMode(ledPin2, OUTPUT);  
  pinMode(ledPin3, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A5);  //อ่านค่าสัญญาณ analog ขา5 ที่ต่อกับ LDR Photoresistor Sensor Module
  Serial.print("val = "); 
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  if (val < 500) { //มืด
    digitalWrite(ledPin2, LOW); 
    digitalWrite(ledPin3, HIGH); 
  }
  else {
    digitalWrite(ledPin2, HIGH); 
    digitalWrite(ledPin3, LOW); 
  }
  delay(100);
}
