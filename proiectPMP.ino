#include <Servo.h>          
#include <NewPing.h>        


 int LeftMotorForward = 10;
 int LeftMotorBackward = 11;
 int RightMotorForward = 12;
 int RightMotorBackward = 13;


#define trig_pin 4 
#define echo_pin 5 

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); 
Servo servo_motor; 


void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(9); //our servo pin
  servo_motor.write(90);
  delay(50);
  distance = sonar.ping_cm();
  delay(100);
 distance = sonar.ping_cm();
  delay(100);
 distance = sonar.ping_cm();
  delay(100);
 distance = sonar.ping_cm();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  distance = sonar.ping_cm();
  if (distance <= 35){
    moveStop();
    delay(250);
    moveBackward();
    delay(400);
    moveStop();
    delay(250);
    distanceRight = lookRight();
    delay(250);
    distanceLeft = lookLeft();
    delay(250);

    if (distance >= distanceLeft){
      turnRight();
      delay(400);
      moveStop();
    }
    else{
      turnLeft();
      delay(400);
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    
    distance = sonar.ping_cm();
    
}

int lookRight(){  
   servo_motor.write(180);
  delay(200);
  int d = sonar.ping_cm();
  delay(100);
  servo_motor.write(90);
  return d;
}

int lookLeft(){
  servo_motor.write(0);
  delay(200);
  int d =  sonar.ping_cm();
  delay(100);
  servo_motor.write(90);
  return d;
}

//int readPing(){
//  delay(70);
//  int cm = sonar.ping_cm();
//  if (cm==0){
//    cm=250;
//  }
//  return cm;
//}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(250);

  // merge in fata
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH); 
  digitalWrite(RightMotorForward, HIGH); 
  
  digitalWrite(LeftMotorForward, LOW); 
  digitalWrite(RightMotorBackward, LOW); 

  delay(250);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
