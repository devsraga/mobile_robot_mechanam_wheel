/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <sensor_msgs/Joy.h>









// robot arm...................................
float   joint_big_right;
float   joint_11;
float   joint_12;
float   joint_13;


float   joint_big_left;
float   joint_21;
float   joint_22;
float   joint_23;

float   fwd_bwd_val;
float   right_left_val;
float   cw_ccw_val;

float   f_r_val;
float   f_l_val;
float   b_r_val;
float   b_l_val;

float   opt_vel_val;



ros::NodeHandle  nh;



Servo myservo_big_right; // create servo object to control a servo
Servo myservo_11; // create servo object to control a servo
Servo myservo_12;  // create servo object to control a servo
Servo myservo_13;  // create servo object to control a servo

Servo myservo_big_left;  // create servo object to control a servo
Servo myservo_21; // create servo object to control a servo
Servo myservo_22;  // create servo object to control a servo
Servo myservo_23;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void servo_cb( const sensor_msgs::Joy& cmd_msg) {


if (cmd_msg.axes[4] == -1){
  
  float   joint_big_right = cmd_msg.axes[0];
  float   joint_11 = cmd_msg.axes[1];
  float   joint_12 = cmd_msg.axes[2];
  
}
  


if (cmd_msg.axes[4] == 1){
  
  float joint_big_left = cmd_msg.axes[0];
  float joint_21 = cmd_msg.axes[1];
  float joint_22 = cmd_msg.axes[2];

}

    float   joint_13 = cmd_msg.axes[3];
      float joint_23 = cmd_msg.axes[3];

  //  float  pos_11 = 90 * (joint_11 + 1);
  //  float  pos_12 = 90 * (joint_12 + 1);
  //  float  pos_13 = 90 * (1 - joint_13);
  //  float  pos_21 = 90 * (joint_21 + 1);
  //  float  pos_22 = 90 * (joint_22 + 1);
  //  float  pos_23 = 90 * (1 - joint_23);
  float  pos_big_right = 90 * (joint_big_right + 1);
  float  pos_11 = 22.5 * (joint_11 - 1) + 180.0;
  float  pos_12 = 90 * (joint_12 + 1);
  float  pos_13 = 90 * (1 - joint_13);

  float  pos_big_left = 90 * (joint_big_left + 1);
  float  pos_21 = 22.5 * (joint_21 - 1) + 180.0;
  float  pos_22 = 90 * (joint_22 + 1);
  float  pos_23 = 90 * (1 - joint_23);

  myservo_big_right.write(pos_big_right);              // tell servo to go to position in variable 'pos'
  myservo_11.write(pos_11);              // tell servo to go to position in variable 'pos'
  myservo_12.write(pos_12);              // tell servo to go to position in variable 'pos'
  myservo_13.write(pos_13);              // tell servo to go to position in variable 'pos'
  
  myservo_big_left.write(pos_big_left);              // tell servo to go to position in variable 'pos'
  myservo_21.write(pos_21);              // tell servo to go to position in variable 'pos'
  myservo_22.write(pos_22);              // tell servo to go to position in variable 'pos'
  myservo_23.write(pos_23);              // tell servo to go to position in variable 'pos'




}

ros::Subscriber<sensor_msgs::Joy> sub("/joy", servo_cb);


void setup() {

  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);

  myservo_big_right.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo_11.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo_12.attach(4);  // attaches the servo on pin 9 to the servo object
  myservo_13.attach(5);  // attaches the servo on pin 9 to the servo object

  myservo_big_left.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo_21.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo_22.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo_23.attach(13);  // attaches the servo on pin 9 to the servo object



}

void loop() {

  nh.spinOnce();
  delay(1);


}
