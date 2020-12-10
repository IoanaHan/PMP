
#include <Servo.h>


// Pinii motor 1
#define mpin00 5
#define mpin01 6
// Pinii motor 2
#define mpin10 3
#define mpin11 11

// Pinii motor 3
#define mpin00 5
#define mpin01 6
// Pinii motor 4
#define mpin10 3
#define mpin11 11

int in1 = 10;
int in2 = 11;
int in3 = 12;
int in4 = 13;


Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);
  servo.write(0);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(360);
  delay(500);
  servo.write(0);
  delay(500);
  
}
