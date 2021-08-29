#define D1 9
#define D2 10
//#define D3 5
//#define D4 6

void setup() {
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
//pinMode(D3,OUTPUT);
//pinMode(D4,OUTPUT);
pinMode(8,INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int val = map(sensorValue,0,1023,0,255);
  analogWrite(D1,0);
  analogWrite(D2,val);
//  analogWrite(D3,0);
//  analogWrite(D4,val);
  if(digitalRead(8)==HIGH){
    analogWrite(D1,val);
    analogWrite(D2,0);
//    analogWrite(D3,val);
//    analogWrite(D4,0);
    }

}
