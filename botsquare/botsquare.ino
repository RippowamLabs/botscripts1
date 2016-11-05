#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *RightMotor2 = AFMS.getMotor(2);
// You can also make another motor on port M2
Adafruit_DCMotor *LeftMotor1 = AFMS.getMotor(1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz 
}

void loop() {
  uint8_t i;
 
  LeftMotor1->setSpeed(110);
  RightMotor2->setSpeed(110);
  
  RightMotor2->run(BACKWARD);
  LeftMotor1->run(BACKWARD);

  delay(1800);
  
  LeftMotor1->setSpeed(5);
  RightMotor2->setSpeed(125);
 
  delay(525);
}
