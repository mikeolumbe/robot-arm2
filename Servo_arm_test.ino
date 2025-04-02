#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 30;    // variable to store the servo position

void setup() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // Initialize serial communication for debugging (optional)
}

void loop() {
  // Grip
  Serial.println("Move arm up..."); //optional serial print.
  for (pos = 30; pos <= 180; pos += 1) { // goes from 30 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000); // Hold grip for 1 second

  // Ungrip
  Serial.println("Move arm down.."); //optional serial print.
  for (pos = 180; pos >= 30; pos -= 1) { // goes from 180 degrees to 30 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000); // Hold ungrip for 1 second

  //Alternative grip/ungrip using direct writes.
  /*
  Serial.println("Gripping...");
  myservo.write(90); //grip
  delay(1000);

  Serial.println("Ungripping...");
  myservo.write(0); //ungrip
  delay(1000);
  */
}