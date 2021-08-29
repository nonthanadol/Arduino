const byte ledPin = 8;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  Serial.print("loop  ");
  Serial.println(state);
  digitalWrite(ledPin, state);
}

void blink() {
  Serial.println("Interrupt!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  state = !state;
//  LED();   
//  delay(500);
}
//void LED(){
//  Serial.print("LED  ");
//  while(1){
//  digitalWrite(ledPin, state);
//  }
//
//  }
