#include "pitches.h"

//int melody[] = {
//  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5
//};
//
//// The note duration, 8 = 8th note, 4 = quarter note, etc.
//int durations[] = {
//  8, 8, 8, 4, 4, 4 
//};
//// determine the length of the arrays to use in the loop iteration
//int songLength = sizeof(melody)/sizeof(melody[0]);

void setup() {
// declare pin 9 to be an output:
pinMode(9, OUTPUT);
beep(50);
beep(50);
beep(50);
delay(1000);
}

void loop() {
  
    int duration = 1000/8; //1000ms/8 = 125ms
    tone(9, NOTE_C4, duration);
    // pause between notes
    int pause = duration * 1.3;
    delay(pause);
    // stop the tone
    noTone(9);

}

void beep(unsigned char delayms){
analogWrite(9, 100); // Almost any value can be used except 0 and 255
// experiment to get the best tone
delay(delayms); // wait for a delayms ms
analogWrite(9, 0); // 0 turns it off
delay(delayms); // wait for a delayms ms
}
