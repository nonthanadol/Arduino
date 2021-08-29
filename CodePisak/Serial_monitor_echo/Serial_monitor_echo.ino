void setup() //run only once
{
  Serial.begin(9600); //baud rate 8 bit = 1 byte, 9600 bit per second
}

void loop() // run continuously
{
  if (Serial.available() > 0) {
//     int input = Serial.read(); //อ่านค่าที่พิมใน Serial port ถ้า ตัวแปรที่มารอรับเป็น int จะเก็บ acii code , ถ้าตัวแปรที่มารอรับเป็น char จะเก็บตัวอักษร    
//     int output = input+10;
//     Serial.println(output);

     char input = Serial.read();
     Serial.println(input);
  
  
  }
}


//void loop() // run continuously
//{
//  if (Serial.available() > 0) {
//    Serial.write(Serial.read()); //อ่านค่าที่พิมใน Serial port และเขียนลง serial monitor
//    Serial.write(97); // return the number of bytes written 
//    Serial.write("97");
//  }
//}


// โจทย์ ถ้า Serial.read() == 'a' ให้ arduino ใช้คำสั่ง Serial.println ออกมาว่า "a is received"





//void loop() // run continuously
//{
//  if (Serial.available() > 0) {
//    if (Serial.read() == 'a'){
//      Serial.println("a is received");
//    }
//  }
//}
