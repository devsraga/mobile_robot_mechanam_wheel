
// motor_setting.............................................
void setMotor(int dir, int pwmVal, int PWM, int in1,int in2){
  analogWrite(PWM, pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}




// Enabeling the motors....................................
void mot_enb(){
  
    for (int k; k<=3;k++){
  digitalWrite(enb[k],HIGH);
  }
}


// Enabeling the current protection....................................
void curr_enb(){
  
    for (int m; m<=3;m++){
  digitalWrite(curr[m],HIGH);
  }
}
  

// moving forward............................................
void fwd(){
  for (int j; j<=3;j++){
  setMotor(1,velocity, pwm[j], In1[j],In2[j]);
  }
}



// moving backward............................................
void bwd(){
  for (int j; j<=3;j++){
  setMotor(-1,velocity, pwm[j], In1[j],In2[j]);
  }
}



// moving right............................................
void right(){
  for (int j; j<=3;j++){
    if (j==0 || j==3){
    wise = 1;
    }
    else{
    wise = -1;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// moving left............................................
void left(){
  for (int j; j<=3;j++){
    if (j==1 || j==2){
    wise = 1;
    }
    else{
    wise = -1;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}




// moving forward_right............................................
void f_r(){
  for (int j; j<=3;j++){
    if (j==0 || j==3){
    wise = 1;
    }
    else{
    wise = 0;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// moving forward_left............................................
void f_l(){
  for (int j; j<=3;j++){
    if (j==1 || j==2){
    wise = 1;
    }
    else{
    wise = 0;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// moving backward_right............................................
void b_r(){
  for (int j; j<=3;j++){
    if (j==0 || j==3){
    wise = -1;
    }
    else{
    wise = 0;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// moving backward_left............................................
void b_l(){
  for (int j; j<=3;j++){
    if (j==1 || j==2){
    wise = -1;
    }
    else{
    wise = 0;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// stop robot............................................
void stop_robo(){
  for (int j; j<=3;j++){
    if (j==0 || j==3){
    wise = 0;
    }
    else{
    wise = 0;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// rotating mobile robot clockwise............................................
void cw_rot(){
  for (int j; j<=3;j++){
    if (j==0 || j==2){
    wise = 1;
    }
    else{
    wise = -1;
    }
  setMotor(wise,velocity, pwm[j], In1[j],In2[j]);
  }
}



// rotating mobile robot counter_clockwise............................................
void ccw_rot(){
  for (int j; j<=3; j++){
    if (j==0 || j==2){
    wise = -1;
    }
    else{
    wise = 1;
    }
  setMotor(wise, velocity, pwm[j], In1[j], In2[j]);
  }
}

void test(int b){
  int j = b;
 setMotor(wise, velocity, pwm[j], In1[j], In2[j]); 
}

// remote controlling the procces............................................
void remote_control(){
remote();
vel_cont();
mot_actuation();
print_vel(velocity);
}
