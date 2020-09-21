#include <Servo.h> 
Servo servoHorizontal;

int servoH = 90;
int servoHLimitHigh = 180;
int servoHLimitLow = 0;
int tolerance = 10;

void setup()
{
Serial.begin(9600);
servoHorizontal.attach(7);
servoHorizontal.write(180);
delay(3000);
}

void loop() 
{
  int ldrLeft = analogRead(A4);
  int ldrRight = analogRead(A0);
  int diffHorizontal = ldrLeft - ldrRight;// check the diffirence of left and right
  
  if ( diffHorizontal <-1*tolerance || diffHorizontal > tolerance){ //check if the difference is tolerable else rotate the motor
    if (ldrLeft > ldrRight){
      servoH = servoH + 2;
      if (servoH > servoHLimitHigh){servoH = servoHLimitHigh;}
    } else if (ldrLeft < ldrRight){
      servoH = servoH-2;
      if (servoH_value < servohLimitLow){servoH_value = servoHLimitLow;}
    } else if (ldrLeft = ldrRight){
    // nothing
    }
  } 
  servoHorizontal.write(servoH_value);
  delay(10);
}
