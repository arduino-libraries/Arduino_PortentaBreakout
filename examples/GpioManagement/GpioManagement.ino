/*
  Breakout Carrier - Gpio Management

  The sketch shows how to use the Breakout Carrier
  and how to turns a PIN on for one second, then off for one
  second, repeatedly.

  The circuit:
   - Portenta H7
   - BreakOut Carrier

  This example code is in the public domain.
*/
#include "PortentaBreakoutCarrier.h"

// the macros to access each gpio are made using the peripheral silk name 
// and the pin Name(e.g. the GPIO 0 pin can be accessed using 
// GPIO_0), all the pin respect this naming except the followings:
// I2C: I2C_SDA_1, I2C_SCL_1, I2C_SDA_0, I2C_SCL_0, I2C_SDA_2, I2C_SCL_2
// PWM: PWM9, PWM8, PWM7, PWM6, PWM5, PWM4, PWM3, PWM2, PWM1, PWM0
// not all the PINS are writatble, for pins availablity refers to:
// https://content.arduino.cc/assets/Pinout_PortentaBreakout_latest.pdf

int pin = SD_CMD;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  int res = Breakout.setPinMode(pin, OUTPUT);
  if (res == -1){
    Serila.println("Error: the pin is not connected to the Breakout pins");
  }
  Breakout.GPIOWrite(pin, LOW);
}

void loop() {
  Breakout.GPIOWrite(pin, HIGH);
  Serial.println("Read: ");
  Serial.println(Breakout.GPIORead(pin));
  delay(1000);
  Breakout.GPIOWrite(pin, LOW);
   Serial.println("Read: ");
  Serial.println(Breakout.GPIORead(pin));
  delay(1000);
}