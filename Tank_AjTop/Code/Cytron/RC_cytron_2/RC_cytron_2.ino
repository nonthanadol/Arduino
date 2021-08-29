#include <Servo.h> // include the servo library to control the servos
#include "CytronMotorDriver.h"

// Configure the motor driver.
CytronMD motor1(PWM_DIR, 5, 8);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 11, 13); // PWM 2 = Pin 9, DIR 2 = Pin 10.

Servo servo1;   // name each servo output for use with the servo library    
Servo servo2;  

unsigned long now;                        // timing variables to update data at a regular interval                  
unsigned long rc_update;
const int channels = 4;                   // specify the number of receiver channels
float RC_in[channels];                    // an array to store the calibrated input from receiver 

const int servo1_pin = 9;  // identify the pins that each servo signal wire is connected to
const int servo2_pin = 10;

int servo1_uS;      // variables to store the pulse widths to be sent to the servo
int servo2_uS; 
int servo3_uS;      
int servo4_uS; 
int motor1_out;
int motor2_out;

void setup() {
    servo1.attach(servo1_pin, 500, 2500); // attach the servo library to each servo pin, and define min and max uS values
    servo2.attach(servo2_pin, 500, 2500);
    setup_pwmRead();                      
    Serial.begin(9600);
}

void loop() {  
    
    now = millis();
    
    if(RC_avail() || now - rc_update > 25){   // if RC data is available or 25ms has passed since last update (adjust to be equal or greater than the frame rate of receiver)
      
      rc_update = now;                           
      
//      print_RCpwm();                        // uncommment to print raw data from receiver to serial
      
      for (int i = 0; i<channels; i++){       // run through each RC channel
        int CH = i+1;
        
        RC_in[i] = RC_decode(CH);             // decode receiver channel and apply failsafe
        
        //print_decimal2percentage(RC_in[i]);   // uncomment to print calibrated receiver input (+-100%) to serial       
      }
      //Serial.println();                       // uncomment when printing calibrated receiver input to serial.
    }
    servo1_uS = RC_in[0]*1000;
    servo2_uS = RC_in[1]*1000;
    servo3_uS = RC_in[2]*1000;
    servo4_uS = RC_in[3]*1000;
//    Serial.print("S1 ");
//    Serial.println(servo1_uS);
//    Serial.print("S2 ");
//    Serial.println(servo2_uS);
//    Serial.print("S3 ");
//    Serial.println(servo3_uS);
//    Serial.print("S4 ");
//    Serial.println(servo4_uS);
    servo1_uS = map(servo1_uS,  -1000, 1000, -255, 255);
    servo2_uS = map(servo2_uS,  -1000, 1000, -255, 255);
    servo3_uS = map(servo3_uS,  -1000, 1000, 0, 90);
    servo4_uS = map(servo4_uS,  -1000, 1000, 0, 90);
//    Serial.print("S1 ");
//    Serial.println(servo1_uS);
    Serial.print("S2 ");
    Serial.println(servo2_uS);
//    Serial.print("S3 ");
//    Serial.println(servo3_uS);
//    Serial.print("S4 ");
//    Serial.println(servo4_uS);
    servo1.write(servo3_uS);
    delay(15);
    servo2.write(servo4_uS);
    delay(15);
    motor1_out = servo2_uS + servo1_uS;
    motor2_out = servo2_uS - servo1_uS;
    motor1.setSpeed(motor1_out);   // Motor 1 runs forward at 50% speed.
    motor2.setSpeed(motor2_out); //ok  // Motor 2 runs backward at 50% speed.
    delay(50);
}
