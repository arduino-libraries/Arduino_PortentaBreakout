/*Portenta Breakout Carrier Library for Arduino =

Arduino Library for the Arduino Portenta Breakout Carrier

For more information about this library please visit us at https://www.arduino.cc/en/Reference/PortentaBreakoutCarrier

== License ==

Copyright (c) 2021 Arduino SA. All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef _BREAKOUT_CARRIER_H
#define _BREAKOUT_CARRIER_H
#include "Arduino.h"
#include "mbed.h"
#define PK_7_pox LEDB
typedef enum {
    SPI0_CS = -1,
    SPI0_CK = -1,
    SPI0_MISO = -1,
    SPI0_MOSI = -1,
    SPI1_CS = PK_7_pox + 129,
    SPI1_CK = PK_7_pox + 130,
    SPI1_MISO = PK_7_pox + 35,
    SPI1_MOSI = PK_7_pox + 36,
    UART2_TX = PK_7_pox + 111,
    UART2_RX = PK_7_pox+ 106,
    UART2_RTS = -1,
    UART2_CTS = -1,
    UART3_TX = PK_7_pox + 153,
    UART3_RX = PK_7_pox + 154,
    UART3_RTS = -1,
    UART3_CTS = -1,
    PCIE_TXN = -1,
    PCIE_TXP = -1,
    PCIE_RXN = -1,
    PCIE_RXP = -1,
    PCIE_CKN = -1,
    PCIE_CKP = -1,
    I2S_SDO = PK_7_pox + 132,
    I2S_SDI = PK_7_pox + 131,
    I2S_WS = PK_7_pox + 26,
    I2S_CK = PK_7_pox + 52,
    SAI_D1 = -1,
    SAI_D0 = PK_7_pox + 135,
    SAI_FS = PK_7_pox + 136,
    SAI_SCK = PK_7_pox + 134,
    CAMERA_D0P = PK_7_pox + 123,
    CAMERA_D0N = PK_7_pox + 122,
    CAMERA_D1P = PK_7_pox + 125,
    CAMERA_D1N = PK_7_pox + 124,
    CAMERA_D2P = PK_7_pox + 133,
    CAMERA_D2N = PK_7_pox + 127,
    CAMERA_D3P = PK_7_pox + 136,
    CAMERA_D3N = PK_7_pox + 135,
    CAMERA_CKP = PK_7_pox + 134,
    CAMERA_CKN = PK_7_pox + 7,
    CAMERA_HS = PK_7_pox + 5,
    PDM_D1 = -1,
    PDM_D0 = PK_7_pox + 19,
    PDM_CK = PK_7_pox + 67,
    SPDIF_RX = -1,
    SPDIF_TX= -1,
    USBHS_ID = PK_7_pox + 151,
    USBHS_DN = -1,
    USBHS_DP = -1,
    USBFS_ID = -1,
    USBFS_DN = PK_7_pox + 13,
    USBFS_DP = PK_7_pox + 12,
    SD_WP = -1,
    SD_CD = -1,
    SD_D0 = PK_7_pox + 31,
    SD_D3  = PK_7_pox + 21,
    SD_CMD = PK_7_pox + 56,
    SD_D2 = PK_7_pox + 20,
    SD_CLK = PK_7_pox + 55,
    SD_D1 = PK_7_pox + 32,
    SD_VSD = -1,
    ETHERNET_DP = -1,
    ETHERNET_DN = -1,
    ETHERNET_CN = -1,
    ETHERNET_CP = -1,
    ETHERNET_BN = -1,
    ETHERNET_BP = -1,
    ETHERNET_AN = -1,
    ETHERNET_AP = -1,
    ETHERNET_L2 = -1,
    ETHERNET_L1 = -1,
    UART0_TX = PK_7_pox + 1,
    UART0_RX = PK_7_pox + 138,
    UART0_RTS = PK_7_pox + 139,
    UART0_CTS = PK_7_pox + 142,
    UART1_TX = PK_7_pox + 10,
    UART1_RX = PK_7_pox + 11,
    UART1_RTS = PK_7_pox + 143,
    UART1_CTS = PK_7_pox + 144,
    DISPLAY_D3P = -1,
    DISPLAY_D3N = -1,
    DISPLAY_D2P = -1,
    DISPLAY_D2N = -1,
    DISPLAY_D1P = -1,
    DISPLAY_D1N = -1,
    DISPLAY_D0P = -1,
    DISPLAY_D0N = -1,
    DISPLAY_CLK_P = -1,
    DISPLAY_CLK_N = -1,
    CAN0_TX = -1,
    CAN0_RX = -1,
    CAN1_TX = PK_7_pox + 126,
    CAN1_RX = PK_7_pox + 25,
    I2C_SDA_1 = PK_7_pox + 24,
    I2C_SCL_1 = PK_7_pox + 23,
    I2C_SDA_0 = PK_7_pox + 121,
    I2C_SCL_0 = PK_7_pox + 120,
    I2C_SDA_2 = PK_7_pox + 125,
    I2C_SCL_2 = PK_7_pox + 124,
    GPIO_0 = PK_7_pox + 46,
    GPIO_1 = PK_7_pox + 48,
    GPIO_2 = PK_7_pox + 53,
    GPIO_3 = PK_7_pox + 54,
    GPIO_4 = PK_7_pox + 68,
    GPIO_5 = PK_7_pox + 100,
    GPIO_6 = PK_7_pox + 107,
    ANALOG_REFN = -1,
    ANALOG_REFP = -1,
    ANALOG_A7 = PK_7_pox + 7,
    ANALOG_A6 = PK_7_pox + 5,
    ANALOG_A5 = PK_7_pox + 36,
    ANALOG_A4 = PK_7_pox + 35,
    ANALOG_A3 = PK_7_pox + 36,
    ANALOG_A2 = PK_7_pox + 35,
    ANALOG_A1 = PK_7_pox + 2,
    ANALOG_A0 = PK_7_pox + 1,
    PWM9 = PK_7_pox + 119,
    PWM8 = PK_7_pox + 155,
    PWM7 = PK_7_pox + 152,
    PWM6 = PK_7_pox + 128,
    PWM5 = PK_7_pox + 162,
    PWM4 = PK_7_pox + 156,
    PWM3 = PK_7_pox + 104,
    PWM2 = PK_7_pox + 39,
    PWM1 = PK_7_pox + 38,
    PWM0 = PK_7_pox + 9,
    TRST = -1,
    TRACEDATA_0 = PK_7_pox + 68,
    TRACEDATA_1 = PK_7_pox + 111,
    TRACEDATA_CLK = PK_7_pox + 67,
    USB_FLAG = -1,
    USB_EN = -1
};

class BreakoutCarrierClass {
public:
    pin_size_t getPin(int pin) {
        if (pin > -1) {
            return digitalPinToPinName(pin);
        }
        return 0;
    }

    int setPinMode(int pin, PinMode mode) {
        if (pin > -1) {
            pinMode(digitalPinToPinName(pin), mode);
            return 1;
        }
        return -1;
    }
    int GPIOWrite(int pin, PinStatus status) {
          if (pin > -1) {
            digitalWrite(digitalPinToPinName(pin), status);
            return 1;
        }
        return -1;
    }
    bool GPIORead(int pin){
           if (pin > -1) {
            return digitalRead(digitalPinToPinName(pin));
        }
        return -1;
    }
};

BreakoutCarrierClass Breakout;

#endif // _BREAKOUT_CARRIER_H