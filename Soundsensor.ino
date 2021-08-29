int Sen = A5; // ประกาศตัวแปรให้เซ็นเซอร์อยู่ที่ ขา A5
int val = 0;
int LED = 2; // ประกาศตัวแปรให้ LED อยู่ที่ ขา D0
int I = 0;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = analogRead(Sen);
  Serial.println(val);
  //Serial.println(I);
  if (val > 876 || val < 1  ) {
    I = I + 1;
    
  }
  if (I == 1) {
    digitalWrite(LED, HIGH); // ถ้าค่า val เท่ากับ 1 สั่งให้ LED ติด
    Serial.println("LED_ON");
  }
  if (I == 2) {
    digitalWrite(LED, LOW); // ถ้าค่า val ไม่ใช่ 1 สั่งให้ LED ดับ
    Serial.println("LED_OFF");
    I = 0;
  }
  delay(200);
} 
