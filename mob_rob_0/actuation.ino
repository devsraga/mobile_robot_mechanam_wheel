// printing velocity..........................................
void print_vel(int vel_pwm){
//  float vel_val = (vel_pwm-122)*0.75;
  int vel_val = vel_pwm;
Serial.print("Velocity is: ");
Serial.print( vel_val);
Serial.println( " RPM");
}



// vel_control.................................................
void vel_cont(){
if (myCom=="v+"){
  velocity=velocity+10;
  
  if (velocity>255){
    velocity = 255;
  }

}
if (myCom=="v-"){
  velocity=velocity-10;
    if (velocity<0){
    velocity = 0;
  }
}
}



// actuations.................................................
void mot_actuation(){
if (myCom=="two"){
fwd();
Serial.print("Moving forward: ");
}
if (myCom=="eight"){
bwd();
Serial.print("Moving backward: ");

}

if (myCom=="six"){
right();
Serial.print("Moving right: ");

}

if (myCom=="four"){
left();
Serial.print("Moving left: ");

}

if (myCom=="three"){
f_r();
Serial.print("Moving forward_right: ");

}

if (myCom=="one"){
f_l();
Serial.print("Moving forward_left: ");

}

if (myCom=="nine"){
b_r();
Serial.print("Moving backward_right: ");

}

if (myCom=="seven"){
b_l();
Serial.print("Moving backward_left: ");

}


if (myCom=="five"){
stop_robo();
Serial.print("Robot Stoped: ");

}

if (myCom=="cw_rot"){
cw_rot();
Serial.print("Rotating clockwise: ");

}

if (myCom=="ccw_rot"){
ccw_rot();
Serial.print("Rotating counter_clockwise: ");

}

  }
