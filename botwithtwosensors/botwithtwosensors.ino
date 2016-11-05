#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <NewPing.h> // http://playground.arduino.cc/Code/NewPing

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *RightMotor2 = AFMS.getMotor(2);
// You can also make another motor on port M2
Adafruit_DCMotor *LeftMotor1 = AFMS.getMotor(1);

#define TRIGGER_PIN   12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN      11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PINrt 8   // 8 Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PINrt    10  // 10 Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE  140 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LED 13
#define inPin 2

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);      // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PINrt, ECHO_PINrt, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean boolRight = false;

void setup() {
  AFMS.begin();       // create with the default frequency 1.6KHz
  Serial.begin(9600); // Open serial monitor to see ping results.
}

void loop() {
  delay(75); // Wait X ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uSRight = sonar2.ping(); // Send ping, get ping time in microseconds (uS)
  unsigned int uSLeft = sonar.ping(); // Send ping, get ping time in microseconds (uS)
  // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.print(F("PingRight: ")); Serial.println(uSRight ); Serial.print("cm");
  Serial.print(F("PingLeft: ")); Serial.print(uSLeft ); Serial.println("cm");

  int tglOn = digitalRead(inPin);

  if ( uSLeft < 850 && uSLeft > 200) {
    rotateLeft();
    digitalWrite(LED,HIGH);
    delay(700);
    digitalWrite(LED,LOW);
  } else if ( uSRight < 850 && uSRight > 200 )  {
    rotateRight();
    digitalWrite(LED,HIGH);
    delay(700);
    digitalWrite(LED,LOW);
  } else if ( tglOn == HIGH )  {
    goBackward();
    digitalWrite(LED,HIGH);
    delay(700);
    digitalWrite(LED,LOW);
  } else {
    goForward();
  }
}

void goForward (){
  LeftMotor1->setSpeed(120);
  RightMotor2->setSpeed(120);
  RightMotor2->run(BACKWARD);
  LeftMotor1->run(BACKWARD);
}
 
void rotateLeft(){
  LeftMotor1->setSpeed(50);
  RightMotor2->setSpeed(120);
  RightMotor2->run(FORWARD);
  LeftMotor1->run(FORWARD);
}

void rotateRight(){
  LeftMotor1->setSpeed(120);
  RightMotor2->setSpeed(50);
  RightMotor2->run(FORWARD);
  LeftMotor1->run(FORWARD);
}

void goBackward(){
  LeftMotor1->setSpeed(130);
  RightMotor2->setSpeed(130);
  RightMotor2->run(FORWARD);
  LeftMotor1->run(BACKWARD);
}

void stopMotors(){
  RightMotor2->run(RELEASE);
  LeftMotor1->run(RELEASE);
}

