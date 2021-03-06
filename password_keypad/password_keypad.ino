#include <Servo.h>
#include <Keypad.h>
#include <Password.h>

int servoPin = 11;
int buzzer = 10;
int greenLed = 13;
int redLed = 12;
int state = 1;


String newPasswordString; //hold the new password
char newPassword[6]; //charater string of newPasswordString
 
Password password = Password( "1337" );
Servo Servo1;

 
byte maxPasswordLength = 6; 
byte currentPasswordLength = 0;

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'S','0','E'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 3, 8, 7, 5 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 4, 2, 6 }; 
 
// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup(){
   Serial.begin(9600);
   Servo1.attach(servoPin);
   pinMode(10, OUTPUT);//buzzer
   pinMode(greenLed, OUTPUT);
   pinMode(redLed, OUTPUT);
   Servo1.write(0); //Set servo to 0 degrees
   delay(500);
   Serial.println("Lock is ready!");
}
 
void loop(){
   char key = keypad.getKey();
   if (key != NO_KEY){
      delay(60); 
      switch (key){
      case 'A': break; 
      case 'B': break; 
      case 'C': break; 
      case 'D': break; 
      case 'E': checkPassword(); break;
      case 'S': resetPassword(); break;
      default: processNumberKey(key);
      }
   }
   
}
 
void processNumberKey(char key) {
   Serial.print(key);
   currentPasswordLength++;
   password.append(key);
   digitalWrite(buzzer, HIGH);
   delay(50);
   digitalWrite(buzzer, LOW);
   if (currentPasswordLength == maxPasswordLength) {
      checkPassword();
   } 
}

void checkPassword() {
   if (password.evaluate()){
    if (state == 0){
      Servo1.write(0); //Set servo to 0 degrees
      Serial.println("Unlocked");
      state = 1;
      lockAndUnlockBeep();
      blinkGreenLed();
    }
    else if (state == 1) {
      Servo1.write(90); //Set servo to 180 degrees
      state = 0;
      Serial.println("Locked");
      lockAndUnlockBeep();
      blinkRedLed();
      
    }
      
   } else {
      Serial.println(" Fel pin!");
      wrongBlink();
   } 
   resetPassword();
}

void resetPassword() {
   password.reset(); 
   currentPasswordLength = 0;
}

void mario() {
  sing(1);
}

int song = 0;

void lockAndUnlockBeep() {
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
}

void blinkGreenLed() {
  
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      delay(50);
      digitalWrite(greenLed, LOW);
      delay(50);
      digitalWrite(greenLed, HIGH);
      delay(50);
      digitalWrite(greenLed, LOW);
      delay(100);
      digitalWrite(greenLed, HIGH);
}

void blinkRedLed() {

      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      delay(50);
      digitalWrite(redLed, LOW);
      delay(50);
      digitalWrite(redLed, HIGH);
      delay(50);
      digitalWrite(redLed, LOW);
      delay(100);
      digitalWrite(redLed, HIGH);
}

void wrongBlink(){

digitalWrite(redLed, LOW);
digitalWrite(greenLed, LOW);


digitalWrite(redLed, HIGH);
digitalWrite(greenLed, HIGH);
digitalWrite(buzzer, HIGH);
delay(50);
digitalWrite(redLed, LOW);
digitalWrite(greenLed, LOW);
digitalWrite(buzzer, LOW);
delay(20);
digitalWrite(redLed, HIGH);
digitalWrite(greenLed, HIGH);
digitalWrite(buzzer, HIGH);
delay(50);
digitalWrite(redLed, LOW);
digitalWrite(greenLed, LOW);
digitalWrite(buzzer, LOW);
}
