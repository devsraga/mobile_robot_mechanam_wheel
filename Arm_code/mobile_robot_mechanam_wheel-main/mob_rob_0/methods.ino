//Functions ##############################################






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
  
    for (int k; k<=1;k++){
  digitalWrite(enb[k],HIGH);
  }
}


// Enabeling the current protection....................................
void curr_enb(){
  
    for (int m; m<=1;m++){
  digitalWrite(curr[m],HIGH);
  }
}
  
