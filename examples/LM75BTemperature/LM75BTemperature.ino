/*
  Portenta Breakout - LM75BTemperature
  
  The sketch shows how to read temperature from LM75B using I2C bus of the Portenta Breakout.
  
  The circuit:
   - Portenta H7
   - Portenta Breakout
  
  This example code is in the public domain.
*/

#include <Arduino_PortentaBreakout.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  // Join I2C_1 bus
  Breakout.I2C_1.begin();

}

void loop() {
  
  // Transmit to device 0x48 LM75B default address and select register 0x00
  Breakout.I2C_1.beginTransmission(0x48);
  Breakout.I2C_1.write(0x00);  
  Breakout.I2C_1.endTransmission();

  // Read 2 bytes from temperature register 0x00
  Breakout.I2C_1.requestFrom(0x48, 2);

  // Convert data into human readable format
  word regdata = (Breakout.I2C_1.read() << 8) | Breakout.I2C_1.read();
  float temp = (float(regdata) / 256);

  // Print temperature
  Serial.println(temp);
  
  delay(1000);
}
