void setup() //run only once
{
  Serial.begin(9600); //baud rate 8 bit = 1 byte, 9600 bit per second
}
     
void loop() // run continuously
{
//syntax

/* คอมเม้นท์แบบบล็อก */

/*
; semicolon ใช้จบบรรทัด
// คอมเม้นท์
{} curly brace วงเล็บปีกกา
[] square bracket วงเล็บเหลี่ยม
() Round Brackets หรือ Parentheses วงเล็บ
indentation การย่อหน้าด้วย spacebar(ทีละ1) และ tab(ทีละ2) --> ดูคีย์ลัดที่ edit
*/  

////ชนิดตัวแปรพื้นฐาน: int (integer=จำนวนเต็ม), float(จำนวนทศนิยม), char(ตัวอักษร), String(ข้อความ), bool(จริงหรือเท็จ)
//  int a = 1;
//  int b = 2;
//  int c;
//  c = a + b;
//  Serial.print("c = ");
//  Serial.println(c);
//  delay(1000);


//  float a_float = 1.2;
//  int b = 2;
//  float c_float;
//  c_float = a_float+b;
//  Serial.print("c_float = ");
//  Serial.println(c_float);
//  delay(1000);

//  char char_a = 'a'; //character
//  Serial.println(char_a);
//  delay(1000);


//  String my_string1 = "Arduino1";
//  String my_string2 = "Arduino2";
//  Serial.println(my_string1);
//  Serial.println(my_string2[0]); // index การเข้าถึงสมาชิกแต่ละตัวของ string เริ่มจาก 0
//  Serial.println(my_string2[1]);
//  Serial.println(my_string2[2]);
//  Serial.println(my_string2[3]);
//  Serial.println(my_string2[4]);
//  Serial.println(my_string2[5]);
//  Serial.println(my_string2[6]);
//  Serial.println(my_string2[7]); // ถ้า string มีสมาชิก n ตัว, index ตัวสุดท้ายคือ n-1
//  delay(100000);

//  bool bool1 = true; //boolean = 1
//  bool bool2 = false; // = 0
//  Serial.println(bool1);
//  Serial.println(bool2);
//  delay(1000);
//
  char myword1[] = { 'H' , 'e' , 'l' , 'l' , 'o' , '\0' }; //null character
  char myword2[] = { 'a' , 'b' , 'c' , 'd' , 'e' , '\0' }; 
  Serial.println(myword1);
  Serial.println(myword2);
  delay(1000);
  
}
