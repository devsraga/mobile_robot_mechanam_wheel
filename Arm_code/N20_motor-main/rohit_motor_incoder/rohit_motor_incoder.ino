//variables...............................
int in1 = 22;
int in2 = 23;
int pwm_pin_1 = 5;
int enb = 8;
int A = 2;
int B = 31;

int pos = 0;
//volatile int posi = 0; // specify posi as volatile: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
long prevT = 0;
float eprev = 0;
float eintegral = 0;

//int pwmVal  = 200;  //min = 122  and max = 255


// Setup...................................
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(A,INPUT);
pinMode(B,INPUT);
attachInterrupt(digitalPinToInterrupt(A),readEncoder, RISING);

}


//loop........................................
void loop() {

  setMotor(1,150,pwm_pin_1,in1,in2);
  readEncoder();
  delay(100);
  Serial.println(pos);

}

//Functions ##############################################
