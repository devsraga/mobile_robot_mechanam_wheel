//remote.....................................
#include <IRremote.h>
int IRpin=53;
IRrecv IR(IRpin);
decode_results cmd;
String myCom;


//Pin_variables...............................
int In1[] = {30,32,46,48};
int In2[]= {31,33,47,49};
int pwm[]= {7,8,11,12};
int enb[] ={24,25,40,41};
int curr[] = {26,27,42,43};
int A[] ={2,4,6,10};
int B[] ={3,5,9,13};

//others......................................
int wise;
int velocity  = 60;  //min = 122  and max = 255
int pos[] = {0,0,0,0};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i<=3; i++){
    pinMode(In1[i],OUTPUT);
    pinMode(In2[i],OUTPUT);
    pinMode(pwm[i],OUTPUT);
    pinMode(enb[i],OUTPUT);
    pinMode(curr[i],OUTPUT);
    pinMode(enb[i],OUTPUT);
    pinMode(curr[i],OUTPUT);
    attachInterrupt(digitalPinToInterrupt(A[i]),readEncoder, RISING);
    
  }
Serial.begin(9600);
IR.enableIRIn();
}

void loop() {
  

    mot_enb();
  curr_enb();
  remote();
     vel_cont();
  remote_control();
//test(0);
//  fwd();
}
