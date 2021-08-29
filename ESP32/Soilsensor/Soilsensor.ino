int ledPin = 25;
int ledPin3 = 26;
int analogPin = 33; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่0
int val = 0;
void setup() {
  pinMode(ledPin, OUTPUT);  // sets the pin as output
  pinMode(ledPin3, OUTPUT);  // sets the pin as output
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);  //อ่านค่าสัญญาณ analog ขา5 ที่ต่อกับ Soil Moisture Sensor Module v1
  Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  if (val > 1000) { 
    digitalWrite(ledPin, LOW); // สั่งให้ LED ที่ Pin2 ดับ
    digitalWrite(ledPin3, HIGH); // สั่งให้ LED ที่ Pin3 ติดสว่าง
  }
  else {
    digitalWrite(ledPin, HIGH); // สั่งให้ LED ที่ Pin2 ติดสว่าง
    digitalWrite(ledPin3, LOW); // สั่งให้ LED ที่ Pin3 ดับ
  }
  delay(100);
}
