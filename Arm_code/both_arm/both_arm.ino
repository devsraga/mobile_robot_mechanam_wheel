/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo_11;  // create servo object to control a servo
Servo myservo_12;  // create servo object to control a servo
Servo myservo_13;  // create servo object to control a servo

Servo myservo_21;  // create servo object to control a servo
Servo myservo_22;  // create servo object to control a servo
Servo myservo_23;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos_11 = 45;    // variable to store the servo position
int pos_12 = 90;    // variable to store the servo position
int pos_13 = 0;    // variable to store the servo position

int pos_21 = 45;    // variable to store the servo position
int pos_22 = 90;    // variable to store the servo position
int pos_23 = 0;    // variable to store the servo position

void setup() {
  myservo_11.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo_12.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo_13.attach(11);  // attaches the servo on pin 9 to the servo object

  myservo_21.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo_22.attach(7);  // attaches the servo on pin 9 to the servo object
  myservo_23.attach(8);  // attaches the servo on pin 9 to the servo object

}

void loop() {

  myservo_11.write(pos_11);              // tell servo to go to position in variable 'pos'
  myservo_12.write(pos_12);              // tell servo to go to position in variable 'pos'
  myservo_13.write(pos_13);              // tell servo to go to position in variable 'pos'
  
  myservo_21.write(pos_21);              // tell servo to go to position in variable 'pos'
  myservo_22.write(pos_22);              // tell servo to go to position in variable 'pos'
  myservo_23.write(pos_23);              // tell servo to go to position in variable 'pos'

}
