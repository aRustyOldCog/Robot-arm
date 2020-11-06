#include <Servo.h>
#include <Stepper.h>

Servo myServo;

#define stepsPerRevolution 4096 // the number of steps in one revolution of motor (28BYJ-48)

Stepper stepper(stepsPerRevolution, 8, 10, 9, 11); //a1,a2,a3,a4
 int potState = 0; 
 int sensorvalue;
void setup() {
 pinMode(A1,INPUT);
  pinMode(3,OUTPUT);
  myServo.attach(3);

}

void loop() {
 
  sensorvalue = analogRead(A1); //reads the values from the potentiometers
  sensorvalue = map(sensorvalue, 0, 1023, 0, 180);
  myServo.write(sensorvalue); //writes to servo

 potState = analogRead(A0); //reads the values from the potentiometers


 if (potState > 600){  //code below controls movement
    stepper.step(10);
  
  
  if (potState < 400){
    stepper.step(-10);
  }
 } }
