void readEncoder(){
  for(int i = 0; i<=3; i++){
  int pulseB[]={};
   pulseB[i] = digitalRead(B[i]);
  if(pulseB[i]>0){
    pos[i]++;
  }
  else{
    pos[i]--;
  }
}
}
