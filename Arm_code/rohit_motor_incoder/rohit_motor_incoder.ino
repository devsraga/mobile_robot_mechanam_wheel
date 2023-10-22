//variables...............................
int in1 = 26;
int in2 = 27;
int pwm_pin_1 = 4;
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
pinMode(pwm_pin_1, OUTPUT);

}


//loop........................................
void loop() {

digitalWrite(in1, HIGH);

digitalWrite(in1, LOW);

analogWrite(pwm_pin_1, 255);


}
