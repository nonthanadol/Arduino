unsigned long period = 1000; //ระยะเวลาที่ต้องการรอ
unsigned long last_time = 0; //ประกาศตัวแปรเป็น global เพื่อเก็บค่าไว้ไม่ให้ reset จากการวนloop
 
void setup() {
    Serial.begin(9600);
}
 
void loop() {
   
 if( millis() - last_time > period) {

     last_time = millis(); //เซฟเวลาปัจจุบันไว้เพื่อรอจนกว่า millis() จะมากกว่าตัวมันเท่า period 
     Serial.print(last_time);
     Serial.print("   ");
     Serial.println("Hello AI !");
 
 }
   
}
