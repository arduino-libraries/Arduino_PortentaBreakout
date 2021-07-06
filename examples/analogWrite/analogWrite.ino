/*
  Portenta Breakout - analogWrite

  The sketch shows how to use analogWrite API of the Portenta Breakout.

  The circuit:
   - Portenta H7
   - Portenta Breakout

  This example code is in the public domain.
*/
#include "Arduino_PortentaBreakout.h"

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  //Default write resolution is 8bits
  Breakout.analogWriteResolution(8);

  //PWM0 and PWM3 are using HRTIM peripheral and minimum frequency is 760Hz
  Breakout.analogWrite(PWM0, 25);
  Breakout.analogWrite(PWM1, 50);
  Breakout.analogWrite(PWM2, 75);
  Breakout.analogWrite(PWM3, 100);
  // PWM4 and PWM8 are sharing the same timer channel therefore is not possible 
  // to use both outputs at the same time
  Breakout.analogWrite(PWM4, 125);
  Breakout.analogWrite(PWM5, 150);
  Breakout.analogWrite(PWM6, 175);
  Breakout.analogWrite(PWM7, 200);
  //Breakout.analogWrite(PWM8, 225);
  Breakout.analogWrite(PWM9, 250);
}

void loop() {
    delay(100);
}
