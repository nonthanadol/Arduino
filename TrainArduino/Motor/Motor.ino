#define D1 9
#define D2 10
#define D3 5
#define D4 6

void setup() {
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
}

void loop() {
analogWrite(D1,0);
analogWrite(D2,50);
analogWrite(D3,0);
analogWrite(D4,50);
delay(2000);
analogWrite(D1,50);
analogWrite(D2,0);
analogWrite(D3,50);
analogWrite(D4,0);
delay(2000);
}
