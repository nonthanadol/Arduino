int i =0;
void setup() {
   pinMode(2,INPUT);
   pinMode(5,OUTPUT);
   Serial.begin(9600);

}

void loop() {
//run ทุกครั้งที่กดปุ่ม
 
 while(digitalRead(2)==HIGH){
    if(i==0){
      digitalWrite(5,HIGH);
      Serial.println(i);
      i+=1;
      }
    else{
      digitalWrite(5,LOW);
      Serial.println(i);
      i=i-1;
      }
  
  }
  
  delay(10);//เผื่อเวลาให้ยกนิ้วออกจากปุ่ม

}
