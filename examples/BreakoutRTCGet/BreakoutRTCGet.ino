/*
  Breakout Carrier - BreakoutRTCGet

  The sketch shows how to read the RTC of the PortentaH7 using the Breakout Carrier.

  The circuit:
   - Portenta H7
   - BreakOut Carrier
   - CR2032 Battery

  This example code is in the public domain.
*/
#include <Arduino_PortentaBreakoutCarrier.h>

Timestamp utcTime;

void setup() {
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  // Read the current timestamp from the RTC
  utcTime = Breakout.RTClock.getTime();

  // Print the data
  Serial.println(utcTime.getUnixTimestamp());
  Serial.print("year: ");
  Serial.println(utcTime.year() + 1900);
  Serial.print("month: ");
  Serial.println(utcTime.month() + 1);
  Serial.print("day: ");
  Serial.println(utcTime.day());
  Serial.print("hours: ");
  Serial.println(utcTime.hour());
  Serial.print("minutes: ");
  Serial.println(utcTime.minute());
  Serial.print("seconds: ");
  Serial.println(utcTime.second());
  
  delay(1000);
}
