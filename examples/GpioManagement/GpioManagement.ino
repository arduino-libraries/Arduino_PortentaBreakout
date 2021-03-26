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
#include "Arduino_PortentaBreakoutCarrier.h"

// The macros to access each gpio are made using the peripheral silk name
// and the pin Name (e.g. the GPIO 0 pin can be accessed using
// GPIO_0), all the pin respect this naming except the followings:
// I2C: I2C_SDA_1, I2C_SCL_1, I2C_SDA_0, I2C_SCL_0, I2C_SDA_2, I2C_SCL_2
// PWM: PWM9, PWM8, PWM7, PWM6, PWM5, PWM4, PWM3, PWM2, PWM1, PWM0
// not all the PINS are writatble and not all PINS are connected to the header,
// for pins availablity refers to:
// https://content.arduino.cc/assets/Pinout_PortentaBreakout_latest.pdf

breakoutPin pin = ANALOG_A7;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  int res = Breakout.pinMode(pin, OUTPUT);
  if (res == -1) {
    Serial.println("Error: pin not connected");
    while(1);
  }
  Breakout.digitalWrite(pin, LOW);
}

void loop() {
  Breakout.digitalWrite(pin, HIGH);
  Serial.print("Read: ");
  Serial.println(Breakout.digitalRead(pin));
  delay(1000);
  Breakout.digitalWrite(pin, LOW);
  Serial.print("Read: ");
  Serial.println(Breakout.digitalRead(pin));
  delay(1000);
}