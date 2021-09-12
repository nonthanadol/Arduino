#define LED       13    // Declare LED pin
#define MASTER_EN   8   // connected to RS485 Enable pin

void setup() {
  pinMode(LED , OUTPUT);            // Declare LED pin as output
  pinMode(MASTER_EN , OUTPUT);      // Declare Enable pin as output
  Serial.begin(9600);               // set serial communication baudrate 
  digitalWrite(MASTER_EN , LOW);    // Make Enable pin low
                                    // Receiving mode ON 
}

////###Blink LED###
//void loop() {
//  digitalWrite(MASTER_EN , HIGH);     // Make Enable pin high to send Data
//  delay(5);                           // required minimum delay of 5ms
//  Serial.println('A');                // Send character A serially
//  Serial.flush();                     // wait for transmission of data
//  delay(1000);
//  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON
//}

////###Read from potentiometer###
//void loop() {
//  int sensorValue = analogRead(A0);
//  digitalWrite(MASTER_EN , HIGH);     // Make Enable pin high to send Data
//  delay(5);                           // required minimum delay of 5ms
//  Serial.println(sensorValue);  
//  //Serial.flush();                     // wait for transmission of data
//  delay(1000);
//  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON
//}

////###control 1 servo###
//void loop() {
//  int sensorValue = analogRead(A0);
//  int map_servo_master = map(sensorValue, 0, 1023, 0, 180);
//  digitalWrite(MASTER_EN , HIGH);     // Make Enable pin high to send Data
//  delay(5);                           // required minimum delay of 5ms
//  Serial.println(map_servo_master);  
//  Serial.flush();                     // wait for transmission of data
//  delay(1000);
//  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON
//}

//######
void loop() {
  int sensorValue = analogRead(A0);
  int map_servo_master = map(sensorValue, 0, 1023, 0, 180);
  digitalWrite(MASTER_EN , HIGH);     // Make Enable pin high to send Data
  delay(5);                           // required minimum delay of 5ms
  Serial.println(map_servo_master);  
  Serial.flush();                     // wait for transmission of data
  delay(1000);
  digitalWrite(MASTER_EN , LOW);      // Receiving mode ON

   if(Serial.available())                     // If serial data is available then enter into while loop
  {
    if(Serial.read()=='A')                   
    {
       Serial.println("Get feedback");
    }
  }


  
}
