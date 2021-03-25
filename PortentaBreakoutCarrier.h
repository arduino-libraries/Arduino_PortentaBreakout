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
#include "pins_arduino.h"
#include "mbed.h"

#define LAST_ARDUINO_PIN_NUMBER LEDB + 1
typedef enum {
    SPI0_CS = -1,
    SPI0_CK = -1,
    SPI0_MISO = -1,
    SPI0_MOSI = -1,
    SPI1_CS = LAST_ARDUINO_PIN_NUMBER + PI_0,
    SPI1_CK = LAST_ARDUINO_PIN_NUMBER + PI_1,
    SPI1_MISO = LAST_ARDUINO_PIN_NUMBER + PC_2,
    SPI1_MOSI = LAST_ARDUINO_PIN_NUMBER + PC_3,
    UART2_TX = LAST_ARDUINO_PIN_NUMBER + PG_14,
    UART2_RX = LAST_ARDUINO_PIN_NUMBER + PG_9,
    UART2_RTS = -1,
    UART2_CTS = -1,
    UART3_TX = LAST_ARDUINO_PIN_NUMBER + PJ_8,
    UART3_RX = LAST_ARDUINO_PIN_NUMBER + PJ_9,
    UART3_RTS = -1,
    UART3_CTS = -1,
    PCIE_TXN = -1,
    PCIE_TXP = -1,
    PCIE_RXN = -1,
    PCIE_RXP = -1,
    PCIE_CKN = -1,
    PCIE_CKP = -1,
    I2S_SDO = LAST_ARDUINO_PIN_NUMBER + PI_3,
    I2S_SDI = LAST_ARDUINO_PIN_NUMBER + PI_2,
    I2S_WS = LAST_ARDUINO_PIN_NUMBER + PB_9,
    I2S_CK = LAST_ARDUINO_PIN_NUMBER + PD_3,
    SAI_D1 = -1,
    SAI_D0 = LAST_ARDUINO_PIN_NUMBER + PI_6,
    SAI_FS = LAST_ARDUINO_PIN_NUMBER + PI_7,
    SAI_SCK = LAST_ARDUINO_PIN_NUMBER + PI_5,
    CAMERA_D0P = LAST_ARDUINO_PIN_NUMBER + PH_10,
    CAMERA_D0N = LAST_ARDUINO_PIN_NUMBER + PH_9,
    CAMERA_D1P = LAST_ARDUINO_PIN_NUMBER + PH_12,
    CAMERA_D1N = LAST_ARDUINO_PIN_NUMBER + PH_11,
    CAMERA_D2P = LAST_ARDUINO_PIN_NUMBER + PI_4,
    CAMERA_D2N = LAST_ARDUINO_PIN_NUMBER + PH_14,
    CAMERA_D3P = LAST_ARDUINO_PIN_NUMBER + PI_7,
    CAMERA_D3N = LAST_ARDUINO_PIN_NUMBER + PI_6,
    CAMERA_CKP = LAST_ARDUINO_PIN_NUMBER + PI_5,
    CAMERA_CKN = LAST_ARDUINO_PIN_NUMBER + PA_6,
    CAMERA_HS = LAST_ARDUINO_PIN_NUMBER + PA_4,
    PDM_D1 = -1,
    PDM_D0 = LAST_ARDUINO_PIN_NUMBER + PB_2,
    PDM_CK = LAST_ARDUINO_PIN_NUMBER + PE_2,
    SPDIF_RX = -1,
    SPDIF_TX= -1,
    USBHS_ID = LAST_ARDUINO_PIN_NUMBER + PJ_6,
    USBHS_DN = -1,
    USBHS_DP = -1,
    USBFS_ID = -1,
    USBFS_DN = LAST_ARDUINO_PIN_NUMBER + PA_12,
    USBFS_DP = LAST_ARDUINO_PIN_NUMBER + PA_11,
    SD_WP = -1,
    SD_CD = -1,
    SD_D0 = LAST_ARDUINO_PIN_NUMBER + PB_14,
    SD_D3  = LAST_ARDUINO_PIN_NUMBER + PB_4,
    SD_CMD = LAST_ARDUINO_PIN_NUMBER + PD_7,
    SD_D2 = LAST_ARDUINO_PIN_NUMBER + PB_3,
    SD_CLK = LAST_ARDUINO_PIN_NUMBER + PD_6,
    SD_D1 = LAST_ARDUINO_PIN_NUMBER + PB_15,
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
    UART0_TX = LAST_ARDUINO_PIN_NUMBER + PA_0,
    UART0_RX = LAST_ARDUINO_PIN_NUMBER + PI_9,
    UART0_RTS = LAST_ARDUINO_PIN_NUMBER + PI_10,
    UART0_CTS = LAST_ARDUINO_PIN_NUMBER + PI_13,
    UART1_TX = LAST_ARDUINO_PIN_NUMBER + PA_9,
    UART1_RX = LAST_ARDUINO_PIN_NUMBER + PA_10,
    UART1_RTS = LAST_ARDUINO_PIN_NUMBER + PI_14,
    UART1_CTS = LAST_ARDUINO_PIN_NUMBER + PI_15,
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
    CAN1_TX = LAST_ARDUINO_PIN_NUMBER + PH_13,
    CAN1_RX = LAST_ARDUINO_PIN_NUMBER + PB_8,
    I2C_SDA_1 = LAST_ARDUINO_PIN_NUMBER + PB_7,
    I2C_SCL_1 = LAST_ARDUINO_PIN_NUMBER + PB_6,
    I2C_SDA_0 = LAST_ARDUINO_PIN_NUMBER + PH_8,
    I2C_SCL_0 = LAST_ARDUINO_PIN_NUMBER + PH_7,
    I2C_SDA_2 = LAST_ARDUINO_PIN_NUMBER + PH_12,
    I2C_SCL_2 = LAST_ARDUINO_PIN_NUMBER + PH_11,
    GPIO_0 = LAST_ARDUINO_PIN_NUMBER + PC_13,
    GPIO_1 = LAST_ARDUINO_PIN_NUMBER + PC_15,
    GPIO_2 = LAST_ARDUINO_PIN_NUMBER + PD_4,
    GPIO_3 = LAST_ARDUINO_PIN_NUMBER + PD_5,
    GPIO_4 = LAST_ARDUINO_PIN_NUMBER + PE_3,
    GPIO_5 = LAST_ARDUINO_PIN_NUMBER + PG_3,
    GPIO_6 = LAST_ARDUINO_PIN_NUMBER + PG_10,
    ANALOG_REFN = -1,
    ANALOG_REFP = -1,
    ANALOG_A7 = LAST_ARDUINO_PIN_NUMBER + PA_6,
    ANALOG_A6 = LAST_ARDUINO_PIN_NUMBER + PA_4,
    ANALOG_A5 = LAST_ARDUINO_PIN_NUMBER + PC_3,
    ANALOG_A4 = LAST_ARDUINO_PIN_NUMBER + PC_2,
    ANALOG_A3 = LAST_ARDUINO_PIN_NUMBER + PC_3,
    ANALOG_A2 = LAST_ARDUINO_PIN_NUMBER + PC_2,
    ANALOG_A1 = LAST_ARDUINO_PIN_NUMBER + PA_1,
    ANALOG_A0 = LAST_ARDUINO_PIN_NUMBER + PA_0,
    PWM9 = LAST_ARDUINO_PIN_NUMBER + PH_6,
    PWM8 = LAST_ARDUINO_PIN_NUMBER + PJ_10,
    PWM7 = LAST_ARDUINO_PIN_NUMBER + PJ_7,
    PWM6 = LAST_ARDUINO_PIN_NUMBER + PH_15,
    PWM5 = LAST_ARDUINO_PIN_NUMBER + PK_1,
    PWM4 = LAST_ARDUINO_PIN_NUMBER + PJ_11,
    PWM3 = LAST_ARDUINO_PIN_NUMBER + PG_7,
    PWM2 = LAST_ARDUINO_PIN_NUMBER + PC_7,
    PWM1 = LAST_ARDUINO_PIN_NUMBER + PC_6,
    PWM0 = LAST_ARDUINO_PIN_NUMBER + PA_8,
    TRST = -1,
    TRACEDATA_0 = LAST_ARDUINO_PIN_NUMBER + PE_3,
    TRACEDATA_1 = LAST_ARDUINO_PIN_NUMBER + PG_14,
    TRACEDATA_CLK = LAST_ARDUINO_PIN_NUMBER + PE_2,
    USB_FLAG = -1,
    USB_EN = -1
} breakoutPin;

class BreakoutCarrierClass {
public:
    int pinMode(breakoutPin pin, PinMode mode) {
        if (pin > -1) {
            ::pinMode((int)pin, mode);
            return 1;
        }
        return -1;
    }
    int digitalWrite(breakoutPin pin, PinStatus status) {
          if (pin > -1) {
            ::digitalWrite((int)pin, status);
            return 1;
        }
        return -1;
    }
    bool digitalRead(breakoutPin pin){
        if (pin > -1) {
            return ::digitalRead((int)pin);
        }
        return -1;
    }
};

BreakoutCarrierClass Breakout;

#endif // _BREAKOUT_CARRIER_H