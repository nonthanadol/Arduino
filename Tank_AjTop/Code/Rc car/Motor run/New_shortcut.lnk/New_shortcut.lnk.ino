int MotorPin2 = 13;
int MotorPin3 = 12;
int MotorPin4 = 14;
int MotorPin5 = 27;

int MotorPin6 = 23;
int MotorPin7 = 22;
int MotorPin8 = 21;
int MotorPin9 = 19;


void setup() {
  pinMode(MotorPin2, OUTPUT);//หลัง
  pinMode(MotorPin3, OUTPUT);//หลัง
  pinMode(MotorPin4, OUTPUT);//หลัง
  pinMode(MotorPin5, OUTPUT);//หลัง     
  pinMode(MotorPin6, OUTPUT);//หน้า
  pinMode(MotorPin7, OUTPUT);//หน้า  
  pinMode(MotorPin8, OUTPUT);//หลัง
  pinMode(MotorPin9, OUTPUT);//หลัง
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(MotorPin2, HIGH); 
  digitalWrite(MotorPin3, LOW);

  digitalWrite(MotorPin4, HIGH); 
  digitalWrite(MotorPin5, LOW); 
  
  digitalWrite(MotorPin6, HIGH); 
  digitalWrite(MotorPin7, LOW); 
  
  digitalWrite(MotorPin8, HIGH); 
  digitalWrite(MotorPin9, LOW); 
  Serial.println("Go ahead");
  
}
