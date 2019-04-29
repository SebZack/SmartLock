// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 11;
const int pin = 10; //1234

char input;
// Create a servo object 
Servo Servo1;

void setup() { 

  
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin);
   pinMode(9, OUTPUT);//buzzer
   pinMode(13, OUTPUT);//led indicator when singing a note
   Serial.begin(9600);
   Serial.println("SmartLock is starting up");
   Servo1.write(0); //Set servo to 0 degrees
   delay(500);
   Serial.println("Welcome");
}
void loop(){ 

  if(Serial.available()){
    input = Serial.read();

    
    if(input == '1'){
      Serial.println("1");
      lock();
    }
   if(input == '0'){
      Serial.println("0");
      unlock();
    }
   if(input == '6'){
      Serial.println("6");
      mario();
    }
  }
}

void unlock() {
    Servo1.write(180); //Set servo to 180 degrees
    Serial.println("Unlocked");
    delay(100);
   }

void lock() {
    Servo1.write(0); //Set servo to 0 degrees
    Serial.println("Locked");
    delay(1);
    }

void mario() {
  sing(1);
  sing(1);
  sing(2);
}
int song = 0;
