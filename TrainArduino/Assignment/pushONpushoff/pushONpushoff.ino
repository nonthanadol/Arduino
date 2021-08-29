int i =0;
void setup() {
   pinMode(6,INPUT);
   pinMode(12,OUTPUT);
   Serial.begin(9600);

}

void loop() {
//run ทุกครั้งที่กดปุ่ม
 
 while(digitalRead(6)==HIGH){
    if(i==0){
      digitalWrite(12,HIGH);
      Serial.println(i);
      i+=1;
      }
    else{
      digitalWrite(12,LOW);
      Serial.println(i);
      i=i-1;
      }
  
  }
  
  delay(100);//เผื่อเวลาให้ยกนิ้วออกจากปุ่ม

}
