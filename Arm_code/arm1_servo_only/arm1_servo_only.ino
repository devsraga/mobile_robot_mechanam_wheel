/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>


float home_pos_r[] = {0, 180, 90, 90}; 
float home_pos_l[] = {180, 180, 90, 90};

float middle_pos_r[] = {90, 180, 90, 90}; 
float middle_pos_l[] = {90, 180, 90, 90};


float up_pos_r[] = {180, 180, 90, 90}; 
float up_pos_l[] = {0, 180, 90, 90};

float joy_pos_r[] = {90, 135, 90, 90}; 
float joy_pos_l[] = {90, 135, 90, 90};
int dt = 6000;
int dt2 = 2000;



// right arm define
Servo r_shoulder_1;
Servo r_shoulder_2; 
Servo r_elbow; 
Servo r_wrist; 


// leftt arm define
Servo l_shoulder_1;
Servo l_shoulder_2; 
Servo l_elbow; 
Servo l_wrist; 

// right arm positions
float pos_r_shoulder_1;    // variable to store the servo position
float pos_r_shoulder_2;   // variable to store the servo position
float pos_r_elbow;    // variable to store the servo position
float pos_r_wrist;;

// left arm positions
float pos_l_shoulder_1;    // variable to store the servo position
float pos_l_shoulder_2;    // variable to store the servo position
float pos_l_elbow;    // variable to store the servo position
float pos_l_wrist;

void setup() {
  r_shoulder_1.attach(2);  // attaches the servo on pin 9 to the servo object
    r_shoulder_2.attach(3);  // attaches the servo on pin 9 to the servo object
      r_elbow.attach(4);  // attaches the servo on pin 9 to the servo object
      r_wrist.attach(5);  // attaches the servo on pin 9 to the servo obj

        l_shoulder_1.attach(6);  // attaches the servo on pin 9 to the servo object
    l_shoulder_2.attach(9);  // attaches the servo on pin 9 to the servo object
      l_elbow.attach(10);  // attaches the servo on pin 9 to the servo object
      l_wrist.attach(13);  // attaches the servo on pin 9 to the servo obj
      
}

void loop() {

motion(home_pos_r, home_pos_l);
delay(dt);

motion(middle_pos_r, middle_pos_l);
delay(dt);




robot_is_happy();



motion(middle_pos_r, middle_pos_l);
delay(dt);

motion(home_pos_r, home_pos_l);
delay(dt);

}




 void motion(float* right_pos, float* left_pos){

    pos_r_shoulder_1 = right_pos[0];
    pos_r_shoulder_2 = right_pos[1];
    pos_r_elbow = right_pos[2];
    pos_r_wrist = right_pos[3];

   pos_l_shoulder_1 = left_pos[0];
   pos_l_shoulder_2 = left_pos[1];
    pos_l_elbow = left_pos[2];
    pos_l_wrist = left_pos[3];
    
    r_shoulder_1.write(pos_r_shoulder_1);              // tell servo to go to position in variable 'pos'
        r_shoulder_2.write(pos_r_shoulder_2);              // tell servo to go to position in variable 'pos'
            r_elbow.write(pos_r_elbow);              // tell servo to go to position in variable 'pos'
                        r_wrist.write(pos_r_wrist);              // tell servo to go to position in variable 'pos'

    l_shoulder_1.write(pos_l_shoulder_1);              // tell servo to go to position in variable 'pos'
        l_shoulder_2.write(pos_l_shoulder_2);              // tell servo to go to position in variable 'pos'
            l_elbow.write(pos_l_elbow);              // tell servo to go to position in variable 'pos'
                        l_wrist.write(pos_l_wrist);              // tell servo to go to position in variable 'pos'
}


void robot_is_happy(){
  
motion(joy_pos_r, joy_pos_l);
delay(dt2);

motion(middle_pos_r, middle_pos_l);
delay(dt2);

motion(joy_pos_r, joy_pos_l);
delay(dt2);

motion(middle_pos_r, middle_pos_l);
delay(dt2); 
}
