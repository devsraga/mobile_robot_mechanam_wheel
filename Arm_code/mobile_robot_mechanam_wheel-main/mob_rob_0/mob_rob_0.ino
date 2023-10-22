
#include <avr/io.h>

#include <avr/interrupt.h>

#include <math.h>

//Pin_variables...............................
int In1[] = {8,26};
int In2[]= {7,27};
int pwm[]= {9,5};
int enb[] ={24,25};
int curr[] = {26,27};
int EncoderPinA[] ={2,3};
int EncoderPinB[] ={3,31};


//int In1[] = {22,26};
//int In2[]= {23,27};
//int pwm[]= {4,5};
//int enb[] ={24,25};
//int curr[] = {26,27};
//int EncoderPinA[] ={2,3};
//int EncoderPinB[] ={30,31};

long counts = 0;
long counts_2 = 0;

//others......................................
int wise;
int velocity  = 60;  //min = 122  and max = 255
//in/t pos[] = {0,0};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i<=1; i++){
    pinMode(In1[i],OUTPUT);
    pinMode(In2[i],OUTPUT);
    pinMode(pwm[i],OUTPUT);
    pinMode(enb[i],OUTPUT);
    pinMode(curr[i],OUTPUT);
    pinMode(enb[i],OUTPUT);
    pinMode(curr[i],OUTPUT);
    
    pinMode(EncoderPinA[i], INPUT); //initialize Encoder Pins
    pinMode(EncoderPinB[i], INPUT);  
    digitalWrite(EncoderPinA[i], LOW); //initialize Pin States
    digitalWrite(EncoderPinB[i], LOW);
//    attachInterrupt(i, readEncoder, CHANGE); ///attach interrupt to PIN 2 

    
    attachInterrupt(digitalPinToInterrupt(EncoderPinA[i]),readEncoder, RISING);
    
  }
Serial.begin(115200);

}

void loop() {
  

    mot_enb();
  curr_enb();
  setMotor(1,45, pwm[0], In1[0],In2[0]);
  Serial.print(counts);
  
  Serial.print("  ");
  
  Serial.println(counts_2);
delay(3000);

}


void readEncoder() //this function is triggered by the encoder CHANGE, and increments the encoder counter

{ 

  if(digitalRead(EncoderPinB[0]) == digitalRead(EncoderPinA[0]) )
  if(digitalRead(EncoderPinB[1]) == digitalRead(EncoderPinB[1]) )

  {

    counts = counts-1; //you may need to redefine positive and negative directions
    counts_2 = counts_2-1;
  }

  else

  {

    counts = counts+1;
    counts_2 = counts_2+1;
  }

}
