#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include <NewPing.h>
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *RightMotor2 = AFMS.getMotor(2);
// You can also make another motor on port M2
Adafruit_DCMotor *LeftMotor1 = AFMS.getMotor(1);

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PINrt  8  // 8 Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PINrt     10  // 10 Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 140 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LED 13
#define inPin 2

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

NewPing sonar2(TRIGGER_PINrt, ECHO_PINrt, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

boolean boolRight = false;

void setup() {
AFMS.begin(); // create with the default frequency 1.6KHz
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
 
}

void loop() {
uint8_t i;

delay(75); 
//delay(200); 
                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
     unsigned int uSright = sonar2.ping(); // Send ping, get ping time in microseconds (uS).
//  Serial.print("PingRight: ");
 //   Serial.println(uSright ); // C  
//  
//delay(75); 

  //right sensor
                                                            //convert ping time to distance in cm and print result (0 = outside set distance range)
 unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
   Serial.print(uS ); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
 //delay(75);  

int tglOn = digitalRead(inPin);

if ( uS < 850 && uS > 200) {
//  
//
    rotateLeft();
    digitalWrite(LED,HIGH);
    delay(700);
    digitalWrite(LED,LOW);
    
//    boolRight = false;
//  }
 } else if ( uSright < 850 && uSright > 200 )  {
  //if ( uSright < 850 && uSright > 200 )  { 
   rotateRight();
    digitalWrite(LED,HIGH);
    delay(700);
    digitalWrite(LED,LOW);
   
//} else if ( (uSright < 850 && uSright > 200) && (uS < 850 && uS > 200))  {
 } else if ( tglOn == HIGH )  {
 
   goBackward();
   digitalWrite(LED,HIGH);
    delay(700);
    digitalWrite(LED,LOW);
 
 } else {
   
  goForward();
   
 }
  
  
  
  
}

void goForward ()
{
LeftMotor1->setSpeed(120);
RightMotor2->setSpeed(120);
RightMotor2->run(BACKWARD);
LeftMotor1->run(BACKWARD);
}
 
void rotateLeft ()
{
LeftMotor1->setSpeed(50);
RightMotor2->setSpeed(120);
RightMotor2->run(FORWARD);
LeftMotor1->run(FORWARD);
//RightMotor2->run(RELEASE);
//LeftMotor1->run(RELEASE);
}

void rotateRight ()
{
LeftMotor1->setSpeed(120);
RightMotor2->setSpeed(50);
RightMotor2->run(FORWARD);
LeftMotor1->run(FORWARD);
//RightMotor2->run(RELEASE);
//LeftMotor1->run(RELEASE);
}

void goBackward ()
{
LeftMotor1->setSpeed(130);
RightMotor2->setSpeed(130);
RightMotor2->run(FORWARD);
LeftMotor1->run(BACKWARD);
}
