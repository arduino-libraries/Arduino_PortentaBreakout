/*Portenta Breakout Carrier Library for Arduino =

Arduino Library for the Arduino Portenta Breakout Carrier

For more information about this library please visit us at https://www.arduino.cc/en/Reference/Arduino_PortentaBreakout

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

#ifndef ARDUINO_PORTENTA_BREAKOUT_H
#define ARDUINO_PORTENTA_BREAKOUT_H

#include <Arduino.h>
#include <pins_arduino.h>
#include <mbed.h>
#include <Wire.h>
#include <SPI.h>
#include <PDM.h>
#include <Portenta_Ethernet.h>
#include <Ethernet.h>
#include "utility/Analog/Analog.h"
#include "utility/RTC/RTC.h"

#define LAST_ARDUINO_PIN_NUMBER LEDB + 1
typedef enum {
    SPI0_CS = -1,
    SPI0_CK = -1,
    SPI0_CIPO = -1,
    SPI0_COPI = -1,
    SPI1_CS = LAST_ARDUINO_PIN_NUMBER + PI_0,
    SPI1_CK = LAST_ARDUINO_PIN_NUMBER + PI_1,
    SPI1_CIPO = LAST_ARDUINO_PIN_NUMBER + PC_2,
    SPI1_COPI = LAST_ARDUINO_PIN_NUMBER + PC_3,
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
    USB1_ID = LAST_ARDUINO_PIN_NUMBER + PJ_6,
    USB1_DN = -1,
    USB1_DP = -1,
    USB0_ID = -1,
    USB0_DN = LAST_ARDUINO_PIN_NUMBER + PA_12,
    USB0_DP = LAST_ARDUINO_PIN_NUMBER + PA_11,
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
    DISPLAY_CLKP = -1,
    DISPLAY_CLKN = -1,
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
    ANALOG_A5 = LAST_ARDUINO_PIN_NUMBER + PC_3_ALT0,
    ANALOG_A4 = LAST_ARDUINO_PIN_NUMBER + PC_2_ALT0,
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
    bool digitalRead(breakoutPin pin) {
        if (pin > -1) {
            return ::digitalRead((int)pin);
        }
        return -1;
    }
    void analogWrite(breakoutPin pin, int val) {
        if (pin > -1) {
            BreakoutPWM::analogWrite((int)pin, val);
        }
        return;
    }
    void analogWriteResolution(int bits) {
        BreakoutPWM::analogWriteResolution(bits);
    }
    int analogRead(breakoutPin pin) {
        if (pin > -1) {
            int val;
            switch(pin) {
            case ANALOG_A7:
                val = A7;
                break;
            case ANALOG_A6:
                val = A6;
                break;
            case ANALOG_A5:
                val = A5;
                break;
            case ANALOG_A4:
                val = A4;
                break;
            case ANALOG_A3:
                val = A3;
                break;
            case ANALOG_A2:
                val = A2;
                break;
            case ANALOG_A1:
                val = A1;
                break;
            case ANALOG_A0:
                val = A0;
                break;
            default:
                return -1;
            }
            return ::analogRead(val);
        }
        return -1;
    }
    void analogReadResolution(int bits) {
        ::analogReadResolution(bits);
    }
    MbedI2C I2C_0;
    MbedI2C I2C_1;
    MbedI2C I2C_2;
    UART UART0;
    UART UART1;
    UART UART2;
    UART UART3;
    MbedSPI SPI_0;
    PDMClass PDM;
    arduino::EthernetClass Ethernet;
    HWClock RTClock;
    BreakoutCarrierClass() : I2C_0(PH_8,PH_7),
                             I2C_1(PB_7,PB_6),
                             I2C_2(PH_12,PH_11),
                             UART0(PA_0, PI_9, NC/*PI_10*/, NC/*PI_13*/),
                             UART1(PA_9, PA_10, NC/*PI_14*/, NC/*PI_15*/),
                             UART2(PG_14, PG_9, NC, NC),
                             UART3(PJ_8, PJ_9, NC, NC),
                             SPI_0(PC_2, PC_3, PI_1),
                             PDM(PB_2, PE_2, NC),
                             Ethernet(),
                             RTClock()
    {
    }
};

BreakoutCarrierClass Breakout;

#endif // ARDUINO_PORTENTA_BREAKOUT_H
