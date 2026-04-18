#include <Servo.h>
Servo esc;
#define s0 A1
#define s1 A2
#define s2 A3
#define s3 A4
#define AI A0
#define ir 9

int sensore[16];
int filter = 400;
const int selectPins[4] = {s0, s1, s2, s3};

long position = 7500;    
long lastPosition = 7500;

// PID
float Kp = 0.8;       // 0.33    |0.25 |0.18 |0.5    |0.6 
float Ki = 0;      // 0.001       |0     |0.001      |0   base 150
float Kd = 8;       //  3.25    |1    |4   |6      |6.2

int error = 0;
int lastError = 0;
long integral = 0;

// Motor pins
#define PWMA 3
#define AIN1 5
#define AIN2 4
#define BIN1 7
#define BIN2 6
#define PWMB 11

int baseSpeed = 160; //70 |145   |150   |160

void setup()

{
  //Serial.begin(115200);

  for (int i = 0; i < 4; i++)
  pinMode(selectPins[i], OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  esc.attach(10);               // Συνδέουμε το σήμα του ESC στο pin 3
  armESC(); 
  int pwm = map(70, 0, 100, 1000, 2000); // Μετατροπή ποσοστού σε μικροδευτερόλεπτα
  esc.writeMicroseconds(pwm);
  delay(2000);


}

void loop(){
while (digitalRead(ir) == 1)
{

  position = readLine();

  error = position - 7500;

  integral += error;
  

  int derivative = error - lastError;

  float correction = Kp*error + Ki*integral + Kd*derivative;

  correction = constrain(correction,-95,90); //-70,110 |-90,110

  lastError = error;

  int leftSpeed = constrain(baseSpeed + correction, 0, 255); //new
  int rightSpeed = constrain(baseSpeed - correction, 0, 255); //new

  setMotor(leftSpeed,rightSpeed);
}
  setMotor(0,0);
}
long readLine()
{

  long avg = 0;
  int sum = 0;

  for (int channel = 0; channel < 16; channel++)
  {

    for (int bit = 0; bit < 4; bit++)
    digitalWrite(selectPins[bit], (channel >> bit) & 1);

    delayMicroseconds(20);

    sensore[channel] = analogRead(AI);
    // Serial.print(sensore[channel]);
     //Serial.print(" ");
    // delay(100);
    sensore[channel] = (sensore[channel] > filter) ? 1 : 0;



    if(sensore[channel] == 1)
    {
      avg += (long)channel * 1000;
      sum++;
    }

  }

  Serial.println();

  if(sum == 0)
  return lastPosition;

  lastPosition = avg / sum;

  return lastPosition;
}

void setMotor(int leftSpeed,int rightSpeed)
{

  digitalWrite(AIN1,0x1);
  digitalWrite(AIN2,0x0);

  digitalWrite(BIN1,0x1);
  digitalWrite(BIN2,0x0);

  analogWrite(PWMA,leftSpeed);
  analogWrite(PWMB,rightSpeed);
}
void armESC() {
  esc.writeMicroseconds(1000); // Συνήθως 1000us για μηδέν γκάζι
  delay(3000);                 // Περιμένουμε 3 δευτ. για arming
}