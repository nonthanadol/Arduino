 //Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
//Arduino Bluetooth App Control Mecanum Wheel Robot

#include <AFMotor.h>   //Download and Install AFMotor.h Library
#include <SoftwareSerial.h>

AF_DCMotor motor1(1); //Front Left Wheel
AF_DCMotor motor2(2); //Back Left Wheel
AF_DCMotor motor3(3); //Front Right Wheel
AF_DCMotor motor4(4); //Back Right Wheel
SoftwareSerial bluetooth(5, 3); // TX, RX

String readString;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(250);   //Set Motor Speed
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  bluetooth.begin(9600);
}

void loop() {
  while( bluetooth.available()> 0 ){
    delay(50);
    char c = bluetooth.read();
    readString+=c;
  }
  
  if(readString.length()>0){
  
    Serial.println(readString);
    if (readString =="FORWARD"){      // MOVE FORWARD
        ADVANCE();
//      motor1.run (FORWARD);
//      motor2.run (FORWARD);
//      motor3.run (FORWARD);
//      motor4.run (FORWARD);
    }
    if (readString =="BACKWARD"){     // MOVE BACKWARD
        BACK();
//      motor1.run (BACKWARD);
//      motor2.run (BACKWARD);
//      motor3.run (BACKWARD);
//      motor4.run (BACKWARD);
    }
    if (readString =="LEFT"){     // MOVE LEFT SIDE
        LEFT_2();
//      motor1.run (BACKWARD);
//      motor2.run (FORWARD);
//      motor3.run (FORWARD);
//      motor4.run (BACKWARD);
    }
    if (readString =="RIGHT"){     // MOVE RIGHT SIDE
        RIGHT_2();
//      motor1.run (FORWARD);
//      motor2.run (BACKWARD);
//      motor3.run (BACKWARD);
//      motor4.run (FORWARD);
    }
    if (readString =="FORWARDLEFT"){     // MOVE FORWARD LEFT
        LEFT_1();
//      motor1.run (RELEASE);
//      motor2.run (FORWARD);
//      motor3.run (FORWARD);
//      motor4.run (RELEASE);
    }
    if (readString =="FORWARDRIGHT"){     // MOVE FORWARD RIGHT
        RIGHT_1();
//      motor1.run (FORWARD);
//      motor2.run (RELEASE);
//      motor3.run (RELEASE);
//      motor4.run (FORWARD);
    }
    if (readString =="BACKWARDLEFT"){     // MOVE BACKWARD LEFT
        LEFT_3();
//      motor1.run (BACKWARD);
//      motor2.run (RELEASE);
//      motor3.run (RELEASE);
//      motor4.run (BACKWARD);
    }
    if (readString =="BACKWARDRIGHT"){     // MOVE BACKWARD RIGHT
        RIGHT_3();
//      motor1.run (RELEASE);
//      motor2.run (BACKWARD);
//      motor3.run (BACKWARD);
//      motor4.run (RELEASE);
    }
    if (readString =="ROTATELEFT"){     // ROTATE LEFT SIDE
        TURN_LEFT();
//      motor1.run (BACKWARD);
//      motor2.run (BACKWARD);
//      motor3.run (FORWARD);
//      motor4.run (FORWARD);
    }
    if (readString =="ROTATERIGHT"){     // ROTATE RIGHT SIDE
        TURN_RIGHT();
//      motor1.run (FORWARD);
//      motor2.run (FORWARD);
//      motor3.run (BACKWARD);
//      motor4.run (BACKWARD);
    }
    if (readString =="STOP"){     // STOP
        STOP();
//      motor1.run (RELEASE);
//      motor2.run (RELEASE);
//      motor3.run (RELEASE);
//      motor4.run (RELEASE);
    }

    readString="";
  }
}


//    ↑A-----B↑   
//     |  ↑  |
//     |  |  |
//    ↑C-----D↑
void ADVANCE()
{
  motor1.run(FORWARD);   motor4.run(FORWARD);      
  motor2.run(FORWARD);   motor3.run(FORWARD); 
}

//    ↓A-----B↓   
//     |  |  |
//     |  ↓  |
//    ↓C-----D↓
void BACK()
{
  motor1.run(BACKWARD);   motor4.run(BACKWARD);      
  motor2.run(BACKWARD);   motor3.run(BACKWARD);
}
//    =A-----B↑   
//     |   ↖ |
//     | ↖   |
//    ↑C-----D=
void LEFT_1()
{
  motor1.run(RELEASE);   motor4.run(FORWARD);      
  motor2.run(FORWARD);   motor3.run(RELEASE);
}

//    ↓A-----B↑   
//     |  ←  |
//     |  ←  |
//    ↑C-----D↓
void LEFT_2()
{
  motor1.run(BACKWARD);   motor4.run(FORWARD);      
  motor2.run(FORWARD);    motor3.run(BACKWARD);
}
//    ↓A-----B=   
//     | ↙   |
//     |   ↙ |
//    =C-----D↓
void LEFT_3()
{
  motor1.run(BACKWARD);   motor4.run(RELEASE);      
  motor2.run(RELEASE);   motor3.run(BACKWARD);
}
//    ↑A-----B=   
//     | ↗   |
//     |   ↗ |
//    =C-----D↑
void RIGHT_1()
{
  motor1.run(FORWARD);   motor4.run(RELEASE);      
  motor2.run(RELEASE);   motor3.run(FORWARD);
}
//    ↑A-----B↓   
//     |  →  |
//     |  →  |
//    ↓C-----D↑
void RIGHT_2()
{
  motor1.run(FORWARD);   motor4.run(BACKWARD);      
  motor2.run(BACKWARD);   motor3.run(FORWARD);
}
//    =A-----B↓   
//     |   ↘ |
//     | ↘   |
//    ↓C-----D=
void RIGHT_3()
{
  motor1.run(RELEASE);   motor4.run(BACKWARD);      
  motor2.run(BACKWARD);   motor3.run(RELEASE);
}
//    ↓A-----B↑
//     |     |
//     |     |
//    ↓C-----D↑
void TURN_LEFT()
{
  motor1.run(BACKWARD);   motor4.run(FORWARD);      
  motor2.run(BACKWARD);   motor3.run(FORWARD);
}
//    ↑A-----B↓
//     |     |
//     |     |
//    ↑C-----D↓
void TURN_RIGHT()
{
  motor1.run(FORWARD);   motor4.run(BACKWARD);      
  motor2.run(FORWARD);   motor3.run(BACKWARD);  
}
//    =A-----B=  
//     |  =  |
//     |  =  |
//    =C-----D=
void STOP()
{ Serial.println("Stop");
  motor1.run(RELEASE);   motor4.run(RELEASE);      
  motor2.run(RELEASE);   motor3.run(RELEASE);
}
