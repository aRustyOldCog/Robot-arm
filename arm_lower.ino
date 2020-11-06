#include <Stepper.h>

#define stepsPerRevolution 4096 // the number of steps in one revolution of motor (28BYJ-48)

// initialize the stepper library for both steppers: 
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11); //a1,a2,a3,a4
Stepper stepper1(stepsPerRevolution, 2, 4, 3, 5);

int potState = 0; 
int pot1State = 0;

void setup() {
  Serial.begin(9600); //begin debug monitor
 }
 void loop() {
  potState = analogRead(A0); //reads the values from the potentiometers
  pot1State = analogRead(A1); 
  
  Serial.println(pot1State); 
  stepper.setSpeed(5);
  stepper1.setSpeed(5);

  if (potState > 600){  //code below controls movement
    stepper.step(10);
  }
  
  if (potState < 400){
    stepper.step(-10);
  }

  if (pot1State < 400){
    stepper1.step(-10);
    delay(5);
  }
  if (pot1State > 600){
    stepper1.step(10);
  }
  
 }
