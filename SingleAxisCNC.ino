#include <Stepper.h>

// the number of the pushbutton pin  and  corresponding LEDs//
int Button_For = 8;
int LED_For = 12;
int Button_Rev = 10;
int LED_Rev = 11;


// variable for reading the pushbutton status //
int Forward_State = 0;
int Reverse_State = 0;
int MoveSize = 30;

// Create Stepper Motor Class //
Stepper Motor(2038, 4, 6, 5, 7);


void setup() {
  // Initialize Button Input  and LED output//
  pinMode(Button_Rev, INPUT);
  pinMode(Button_For, INPUT);
  pinMode(LED_For, OUTPUT);
  pinMode(LED_Rev, OUTPUT);
  
  // Initialize Stepper Motors //
  Motor.setSpeed(10);
}

void loop() {
  // read the state of the pushbutton value: //
  Forward_State = digitalRead(Button_For);
  Reverse_State = digitalRead(Button_Rev);
  // check if the pushbutton is pressed. //
  // if it is, the buttonState is HIGH: //

//IF FORWARD BUTTON IS PRESSED MOVE "x" STEPS//
//AND TURN ON PROPER LED//
  if (Forward_State == HIGH) {
    Motor.step(509.5);
    digitalWrite(LED_For, HIGH);
  }
  else {
  //SHUT OFF LED//
    digitalWrite(LED_For, LOW);
  }

//IF REVERSE BUTTON IS PRESSED MOVE "x" STEPS//
//AND TURN ON PROPER LED//
  if (Reverse_State == HIGH) {
    Motor.step(-509.5);
    digitalWrite(LED_Rev, HIGH);
  }
  else {
  //SHUT OFF LED//
    digitalWrite(LED_Rev, LOW);
  }
}
