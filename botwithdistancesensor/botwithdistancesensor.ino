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

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN  8
// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 140 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LED 13


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
AFMS.begin(); // create with the default frequency 1.6KHz
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
 
}

void loop() {
uint8_t i;

 delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  //Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
   Serial.print(uS ); // Convert ping time to distance in cm and print result (0 = outside set distance range)

  Serial.println("cm");
if ( uS > 100 && uS < 935 ) {
    rotateLeft();
    digitalWrite(LED,HIGH);
    delay(1000);
  } else {
  goForward();
 digitalWrite(LED,LOW);  
  }
}

void goForward ()
{
LeftMotor1->setSpeed(120);
  RightMotor2->setSpeed(120);
RightMotor2->run(FORWARD);
LeftMotor1->run(BACKWARD);
}
 
void rotateLeft ()
{
LeftMotor1->setSpeed(120);
RightMotor2->setSpeed(60);
RightMotor2->run(FORWARD);
LeftMotor1->run(BACKWARD);
//RightMotor2->run(RELEASE);
//LeftMotor1->run(RELEASE);
}
