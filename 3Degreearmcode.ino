#include <Servo.h>
#include <AccelStepper.h>

Servo servo1;
Servo servo2;
AccelStepper myStepper(AccelStepper::FULL4WIRE, 8, 10, 9, 11);

int buttonState = 1;
int lastButtonRead = HIGH;
int lastPot2Val = 0;
const int noiseThreshold = 10;

const int buttonPin = 3;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int pot1 = A0; 
const int pot2 = A1; 
const int servo1Pin = 7;
const int servo2Pin = 2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  myStepper.setMaxSpeed(1000.0);
  myStepper.setAcceleration(400.0);
}

void loop() {
  int currentButtonRead = digitalRead(buttonPin);
  
  if (lastButtonRead == HIGH && currentButtonRead == LOW) {
    buttonState++;
  }
  lastButtonRead = currentButtonRead;

  if (buttonState == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    int pot2Val = analogRead(pot2);

    if (abs(pot2Val - lastPot2Val) > noiseThreshold) {
      int stepperTarget = map(pot2Val, 0, 1023, 0, 2048);
      
      myStepper.enableOutputs();
      myStepper.moveTo(stepperTarget);
      
      lastPot2Val = pot2Val;
    }
  }
  
  else if (buttonState == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);

    int pot1Val = analogRead(pot1);
    int angle1 = map(pot1Val, 0, 1023, 0, 180);
    servo1.write(angle1);
  }
  
  else if (buttonState == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    int pot1Val = analogRead(pot1);
    int angle2 = map(pot1Val, 0, 1023, 0, 180);
    servo2.write(angle2);
  }
  
  else {
    buttonState = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  if (myStepper.distanceToGo() == 0) {
    myStepper.disableOutputs();
  }

  myStepper.run();
}