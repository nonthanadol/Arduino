//int sum = 0; // global variable

void setup() //run only once
{
  Serial.begin(9600); //baud rate 8 bit = 1 byte, 9600 bit per second
}

void loop() // run continuously
{
////// นับเลข 0 ถึง 10 เพิ่มทีละ 1 ด้วย i++
//  for (int i = 0; i <= 10; i++) { // i วิ่งจาก 0 ถึง 10
//    Serial.println(i);
//    delay(200);
//  }
//
//// นับเลข 10 ถึง 0 ลดลงทีละ 1 ด้วย i--
//  for (int i = 10; i >= 0; i--) { // i วิ่งจาก 10 ถึง 0
//    Serial.println(i);
//    delay(200);
//  }
//}

//// นับเลข 0 ถึง 10 เพิ่มทีละ 1 ด้วย i+=1
//  for (int i = 0; i <= 10; i+=1) { // i วิ่งจาก 0 ถึง 10
//    Serial.println(i);
//    delay(200);
//  }


//// นับเลข 0 ถึง 10 เพิ่มทีละ 2 ด้วย i+=2
//  for (int i = 0; i <= 10; i+=2) { // i วิ่งจาก 0 ถึง 10
//    Serial.println(i);
//    delay(200);
//  }

//// นับเลข 0 ถึง 50 เพิ่มทีละ 5 ด้วย i+=5
//  for (int i = 0; i <= 50; i+=5) { // i วิ่งจาก 0 ถึง 10
//    Serial.println(i);
//    delay(200);
//  }
//}


//// นับเลข 10 ถึง 0 ลดลงทีละ 1 ด้วย i--
//  for (int i = 10; i >= 0; i--) { // i วิ่งจาก 10 ถึง 0
//    Serial.println(i);
//    delay(200);
//  }


//// นำค่า i จาก for loop ไปใช้ในการคำนวณ
//  for (int i = 0; i <= 10; i++) { // i วิ่งจาก 0 ถึง 10
//    int b = 2*i; // b เท่ากับ i คูณ 2
//    Serial.println(b);
//    delay(200);
//  }


//// นับผลรวมเลขด้วยโอเปอเรอเตอร์ +=
  int sum = 0;
  for (int i = 0; i <= 10; i++) { // i วิ่งจาก 0 ถึง 10
    sum += i; // sum ค่าใหม่ = sum ค่าเก่า + ค่า i
    Serial.println(sum);
    delay(100);
  }
  Serial.print("Summation 1 to 10 = ");
  Serial.println(sum);
  delay(100000);
//}


//// ใช้ if กับค่า i ที่วิ่งใน for loop
//  for (int i = 0; i <= 10; i++) { // i วิ่งจาก 0 ถึง 10
//    if (i%2 == 1){ //หารด้วย 2 แล้วเหลือเศษ 1
//      Serial.println(i);
//      delay(200);
//    }
//  }


//// print แต่ละตัวอักษรใน string
//  String my_string1 = "Arduino1";
//  for (int i = 0; i <= 7; i++) { // i วิ่งจาก 0 ถึง 7
//    Serial.println(my_string1[i]);
//    delay(100);
//  }
//  delay(100000);


//// เรียงตัวอักษร
//  String alphabet = "abcdefghijklmnopqrstuvwxyz";
//  for (int i = 0; i <= 26; i++) { // i วิ่งจาก 0 ถึง 26
//    Serial.println(alphabet[i]);
//    delay(100);
//  }
//  delay(100000);
  
//} // end of void loop()

/*
ใช้ for loop
1. print ค่าตัวเลขจำนวนเต็ม 0 - 20
2. print เลขคู่ 2 ถึง 40
3. print เลขคี่ 1 ถึง 41
4. บวก 0 - 20 
5. บวกเลขคู่ 2 ถึง 20 (2,4,6,8,...,18,20)
6. บวกเลขคี่ 1 ถึง 21 (1,3,5,7,...,19,21)
7. Serial.println ตัวอักษรลำดับเลขคี่จาก String alphabet 
8. Serial.println ตัวอักษรลำดับ 5 10 15 20 25 จาก String alphabet 
9. ใช้ arduino หาว่าเลข 1024 มีตัวประกอบอะไรบ้าง (ยาก)
10. ใช้ arduino คำนวณและแสดงผลการหาจำนวนเฉพาะทุกตัวตั้งแต่ 0 - 50 (ยาก)
*/
