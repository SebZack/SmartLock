// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
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
  unlock();
  delay(1000);
  lock();
  delay(1000);
}

void unlock() {
    Servo1.write(180); //Set servo to 180 degrees
    delay(1000);
   
}

void lock() {
    Servo1.write(0); //Set servo to 0 degrees
    delay(1000);
    
}
