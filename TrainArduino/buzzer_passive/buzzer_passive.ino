void setup() {
// declare pin 9 to be an output:
pinMode(9, OUTPUT);
beep(50);
beep(50);
beep(50);
delay(1000);
}

void loop() {
  beep(1000); //change frequency by changing delay
}
void beep(unsigned char delayms){
analogWrite(9, 255); // Almost any value can be used except 0 and 255
delay(delayms); // wait for a delayms ms
analogWrite(9, 0); // 0 turns it off
delay(delayms); // wait for a delayms ms
}
