/*
  Portenta Breakout - analogRead

  The sketch shows how to use analog inputs of the Portenta Breakout.

  The circuit:
   - Portenta H7
   - Portenta Breakout

  This example code is in the public domain.
*/
#include <Arduino_PortentaBreakout.h>

const byte ANALOG_PIN_NUMBER = 8;
const int ANALOG_RESOLUTION = 16;

// The access to each analog input is made using the peripheral silk name.
breakoutPin analogPin[] = {ANALOG_A0, ANALOG_A1, ANALOG_A2, ANALOG_A3, 
                           ANALOG_A4, ANALOG_A5, ANALOG_A6, ANALOG_A7};

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Max analog resolution is 16bits
  Breakout.analogReadResolution(ANALOG_RESOLUTION);
}

void loop() {
  // Loop through all the available inputs and print input value
  for(int i = 0; i < ANALOG_PIN_NUMBER; i++) {
    int w = Breakout.analogRead(analogPin[i]);
    Serial.print("A");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(w);
    
    delay(1000);
  }
}
