
void readEncoder(){
  int pulseB = digitalRead(B);
  if(pulseB>0){
    pos++;
  }
  else{
    pos--;
  }
}
