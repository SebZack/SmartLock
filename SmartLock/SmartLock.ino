// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 

char input;
// Create a servo object 
Servo Servo1; 
void setup() { 

  
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   Serial.begin(9600);
   Serial.println("SmartLock is starting up");
   delay(500);
   Servo1.write(0); //Set servo to 0 degrees
   delay(500);
   Serial.println("Welcome");
}
void loop(){ 

  if(Serial.available()){
    input = Serial.read();
    
  }

  


  
  unlock();
  delay(100);
  lock();
  delay(100);
}

void unlock() {
    Servo1.write(180); //Set servo to 180 degrees
    
    delay(100);
   
}

void lock() {
    Servo1.write(0); //Set servo to 0 degrees
    delay(100);
    
}
