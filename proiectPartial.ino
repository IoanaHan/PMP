#include <Servo.h>
Servo myServo;

//L298N
int motorBackR = 13;
int motorFrontR = 12; 
int motorBackL = 11;
int motorFrontL = 10;

int forward = 0;
int back = 0;
int left = 0;
int right = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
 

 //motoare
  pinMode(motorFrontR, OUTPUT);
  pinMode(motorFrontL, OUTPUT);
  pinMode(motorBackL, OUTPUT);
  pinMode(motorBackR, OUTPUT);

  digitalWrite(motorBackR, LOW);
  digitalWrite(motorFrontR, LOW);
  digitalWrite(motorBackL, LOW);
  digitalWrite(motorFrontL, LOW);
  
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<180; i++){
      myServo.write(i);
      delay(5);
  }
    for(int i = 180; i>0; i--){
      myServo.write(i);
      delay(5);
  }
 wheelsForward();
 delay(1000);
 stopWheels();
 delay(1000);
 wheelsBackward();
  delay(3000);
 turnLeft();
 delay(3000);
}

void stopWheels(){

  digitalWrite(motorBackR, LOW);
  digitalWrite(motorFrontR, LOW);
  digitalWrite(motorBackL, LOW);
  digitalWrite(motorFrontL, LOW);
  
}

void wheelsForward(){
  
 if (forward == 0) {
    forward = 1;
    digitalWrite(motorBackR, LOW);
    digitalWrite(motorFrontR, HIGH);
    digitalWrite(motorBackL, LOW);
    digitalWrite(motorFrontL, HIGH);
 }
}

void wheelsBackward(){

    forward = 0;
    digitalWrite(motorBackR, HIGH);
    digitalWrite(motorFrontR, LOW);
    digitalWrite(motorBackL, HIGH);
    digitalWrite(motorFrontL, LOW);
  }


void turnLeft(){
  
  digitalWrite(motorBackR, HIGH);
  digitalWrite(motorFrontR, HIGH);
  digitalWrite(motorBackL, LOW);
  digitalWrite(motorFrontL, LOW);
}

void turnRight(){
  
  digitalWrite(motorBackR, LOW);
  digitalWrite(motorFrontR, LOW);
  digitalWrite(motorBackL, LOW);
  digitalWrite(motorFrontL, HIGH);
}
