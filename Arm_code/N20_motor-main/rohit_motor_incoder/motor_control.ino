
void m_control(){
// set target position
// int target = 12000;
int target = 250*sin(prevT/1e6);

// PID constant

float kp = 1;
float kd = 0.025;
float ki = 0.0;

// time diffrence
long currT = micros();
float deltaT = ((float)(currT-prevT))/1.0e6;
prevT = currT; 

//// Read the position in an atomic block to avoid a potential
//  // misread if the interrupt coincides with this code running
//  // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
//  int pos = 0; 
//  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
//    pos = posi;
//  }

// error
int e = pos-target;

// derivative
float dedt = (e-eprev)/(deltaT);

// integral

float eintegral = eintegral + e *deltaT;

// control signal
float u = kp*e + kd*dedt + ki*eintegral;

// motor power

float pwr = fabs(u);
if(pwr>255){
  pwr = 255;
}

// motor direction

int dir = 1;
if (u<0){
  dir = -1;
}
// signal the motor
//setMotor(dir,pwr,pwm,in1,in2);

// store previous error 
eprev = e;
Serial.print(target);
Serial.print(" ");
Serial.print(pos);
Serial.println();
}
