/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>


Servo myservo_21;  // create servo object to control a servo
Servo myservo_22;  // create servo object to control a servo
Servo myservo_23;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos_21 = 180;    // variable to store the servo position
int pos_22 = 90;    // variable to store the servo position
int pos_23 = 90;    // variable to store the servo position

void setup() {

  myservo_21.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo_22.attach(7);  // attaches the servo on pin 9 to the servo object
  myservo_23.attach(8);  // attaches the servo on pin 9 to the servo object

}

void loop() {

  
  myservo_21.write(pos_21);              // te/ll servo to go to position in variable 'pos'
  myservo_22.write(pos_22);              // tell servo to go to position in variable 'pos'
  myservo_23.write(pos_23);              // tell servo to go to position in variable 'pos'

}
