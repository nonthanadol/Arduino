//Ans 123123123

unsigned long time_1 = 0;
unsigned long time_2 = 0;
unsigned long time_3 = 0;



void setup() {
 Serial.begin(9600);

}

void loop() {
  Serial.print(millis());
  Serial.print("   ");
  Serial.print(time_1);
  Serial.print("   ");
  Serial.print(time_2);
  Serial.print("   ");
  Serial.println(time_3);
  
  if(millis() - time_1 >3000){ 
        time_1 = millis();
        Serial.print("1");
    }
   
   if(millis() - time_2 >4000 ){ 
        time_2 = millis();
        Serial.print("2");
        
         
    }
   
   if(millis() - time_3 >5000 ){
        time_3 = millis();
        Serial.print("3");
       
    }

}
