/*
  Portenta Breakout - BreakoutRTCSet

  The sketch shows how to configure the RTC of the PortentaH7 using the Portenta Breakout.

  The circuit:
   - Portenta H7
   - Portenta Breakout
   - CR2032 Battery

  This example code is in the public domain.
*/
#include <Arduino_PortentaBreakout.h>

Timestamp utcTime;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  // Configure UTC timestamp
  utcTime.setFromUnixTimestamp(1618234648);
  // Store the timestamp into the RTC
  Breakout.RTClock.setTime(utcTime);
}

void loop() {
    delay(1000);
}
