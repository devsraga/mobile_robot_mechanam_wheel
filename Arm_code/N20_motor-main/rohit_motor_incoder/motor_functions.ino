
void motion(){
//  setMotor(1,150,pwm,in1,in2);
//  delay(1000);
//  Serial.println(pos);
//    
//  setMotor(-1,150,pwm,in1,in2);
//  delay(1000);
//  Serial.println(pos);
//  
//  setMotor(0,150,pwm,in1,in2);
//  delay(20);
//  Serial.println(pos);
 
}


void setMotor(int dir, int pwm, int pwmVal, int in1, int in2){
  analogWrite(pwm, pwmVal);
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
