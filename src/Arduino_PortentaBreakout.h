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
#include <CAN.h>
#include "utility/RTC/RTC.h"

#if defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4)
#include <Portenta_Ethernet.h>
#include <Ethernet.h>

typedef enum {
    SPI0_CS = -1,
    SPI0_CK = -1,
    SPI0_CIPO = -1,
    SPI0_COPI = -1,
    SPI1_CS = PI_0,
    SPI1_CK = PI_1,
    SPI1_CIPO = PC_2,
    SPI1_COPI = PC_3,
    UART2_TX = PG_14,
    UART2_RX = PG_9,
    UART2_RTS = -1,
    UART2_CTS = -1,
    UART3_TX = PJ_8,
    UART3_RX = PJ_9,
    UART3_RTS = -1,
    UART3_CTS = -1,
    PCIE_TXN = -1,
    PCIE_TXP = -1,
    PCIE_RXN = -1,
    PCIE_RXP = -1,
    PCIE_CKN = -1,
    PCIE_CKP = -1,
    I2S_SDO = PI_3,
    I2S_SDI = PI_2,
    I2S_WS = PB_9,
    I2S_CK = PD_3,
    SAI_D1 = -1,
    SAI_D0 = PI_6,
    SAI_FS = PI_7,
    SAI_SCK = PI_5,
    CAMERA_D0P = PH_10,
    CAMERA_D0N = PH_9,
    CAMERA_D1P = PH_12,
    CAMERA_D1N = PH_11,
    CAMERA_D2P = PI_4,
    CAMERA_D2N = PH_14,
    CAMERA_D3P = PI_7,
    CAMERA_D3N = PI_6,
    CAMERA_CKP = PI_5,
    CAMERA_CKN = PA_6,
    CAMERA_HS = PA_4,
    PDM_D1 = -1,
    PDM_D0 = PB_2,
    PDM_CK = PE_2,
    SPDIF_RX = -1,
    SPDIF_TX= -1,
    USB1_ID = PJ_6,
    USB1_DN = -1,
    USB1_DP = -1,
    USB0_ID = -1,
    USB0_DN = PA_12,
    USB0_DP = PA_11,
    SD_WP = -1,
    SD_CD = -1,
    SD_D0 = PB_14,
    SD_D3  = PB_4,
    SD_CMD = PD_7,
    SD_D2 = PB_3,
    SD_CLK = PD_6,
    SD_D1 = PB_15,
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
    UART0_TX = PA_0,
    UART0_RX = PI_9,
    UART0_RTS = PI_10,
    UART0_CTS = PI_13,
    UART1_TX = PA_9,
    UART1_RX = PA_10,
    UART1_RTS = PI_14,
    UART1_CTS = PI_15,
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
    CAN1_TX = PH_13,
    CAN1_RX = PB_8,
    I2C1_SDA = PB_7,
    I2C1_SCL = PB_6,
    I2C0_SDA = PH_8,
    I2C0_SCL = PH_7,
    I2C2_SDA = PH_12,
    I2C2_SCL = PH_11,
    GPIO_0 = PC_13,
    GPIO_1 = PC_15,
    GPIO_2 = PD_4,
    GPIO_3 = PD_5,
    GPIO_4 = PE_3,
    GPIO_5 = PG_3,
    GPIO_6 = PG_10,
    ANALOG_REFN = -1,
    ANALOG_REFP = -1,
    ANALOG_A7 = PA_6,
    ANALOG_A6 = PA_4,
    ANALOG_A5 = PC_3_ALT0,
    ANALOG_A4 = PC_2_ALT0,
    ANALOG_A3 = PC_3,
    ANALOG_A2 = PC_2,
    ANALOG_A1 = PA_1,
    ANALOG_A0 = PA_0,
    PWM9 = PH_6,
    PWM8 = PJ_10,
    PWM7 = PJ_7,
    PWM6 = PH_15,
    PWM5 = PK_1,
    PWM4 = PJ_11,
    PWM3 = PG_7,
    PWM2 = PC_7,
    PWM1 = PC_6,
    PWM0 = PA_8,
    TRST = -1,
    TRACEDATA_0 = PE_3,
    TRACEDATA_1 = PG_14,
    TRACEDATA_CLK = PE_2,
    USB_FLAG = -1,
    USB_EN = -1
} breakoutPin;

#endif

#if defined(ARDUINO_PORTENTA_X8)

typedef enum {
    SPI0_CS = -1,
    SPI0_CK = -1,
    SPI0_CIPO = -1,
    SPI0_COPI = -1,
    SPI1_CS = -1,
    SPI1_CK = -1,
    SPI1_CIPO = -1,
    SPI1_COPI = -1,
    UART2_TX = -1,
    UART2_RX = -1,
    UART2_RTS = -1,
    UART2_CTS = -1,
    UART3_TX = -1,
    UART3_RX = -1,
    UART3_RTS = -1,
    UART3_CTS = -1,
    PCIE_TXN = -1,
    PCIE_TXP = -1,
    PCIE_RXN = -1,
    PCIE_RXP = -1,
    PCIE_CKN = -1,
    PCIE_CKP = -1,
    I2S_SDO = -1,
    I2S_SDI = -1,
    I2S_WS = -1,
    I2S_CK = -1,
    SAI_D1 = -1,
    SAI_D0 = -1,
    SAI_FS = -1,
    SAI_SCK = -1,
    CAMERA_D0P = -1,
    CAMERA_D0N = -1,
    CAMERA_D1P = -1,
    CAMERA_D1N = -1,
    CAMERA_D2P = -1,
    CAMERA_D2N = -1,
    CAMERA_D3P = -1,
    CAMERA_D3N = -1,
    CAMERA_CKP = -1,
    CAMERA_CKN = -1,
    CAMERA_HS = -1,
    PDM_D1 = PC_0,
    PDM_D0 = PE_7,
    PDM_CK = PD_10,
    SPDIF_RX = -1,
    SPDIF_TX= -1,
    USB1_ID = -1,
    USB1_DN = -1,
    USB1_DP = -1,
    USB0_ID = -1,
    USB0_DN = -1,
    USB0_DP = -1,
    SD_WP = -1,
    SD_CD = -1,
    SD_D0 = -1,
    SD_D3  = -1,
    SD_CMD = -1,
    SD_D2 = -1,
    SD_CLK = -1,
    SD_D1 = -1,
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
    UART0_TX = PD_5,
    UART0_RX = PD_6,
    UART0_RTS = PD_4,
    UART0_CTS = PD_3,
    UART1_TX = -1,
    UART1_RX = -1,
    UART1_RTS = -1,
    UART1_CTS = -1,
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
    CAN0_TX = PD_1,
    CAN0_RX = PD_0,
    CAN1_TX = PB_6,
    CAN1_RX = PB_5,
    I2C1_SDA = -1,
    I2C1_SCL = -1,
    I2C0_SDA = -1,
    I2C0_SCL = -1,
    I2C2_SDA = -1,
    I2C2_SCL = -1,
    GPIO_0 = PF_8,
    GPIO_1 = PF_6,
    GPIO_2 = PF_3,
    GPIO_3 = PF_4,
    GPIO_4 = PF_12,
    GPIO_5 = PE_10,
    GPIO_6 = PE_11,
    ANALOG_REFN = -1,
    ANALOG_REFP = -1,
    ANALOG_A7 = PF_5,
    ANALOG_A6 = PF_9,
    ANALOG_A5 = PF_7,
    ANALOG_A4 = PC_4,
    ANALOG_A3 = PB_1,
    ANALOG_A2 = PF_13,
    ANALOG_A1 = PA_6,
    ANALOG_A0 = PF_11,
    PWM9 = PC_8,
    PWM8 = PA_12,
    PWM7 = PC_6,
    PWM6 = PA_8,
    PWM5 = PD_15,
    PWM4 = PA_11,
    PWM3 = PB_10,
    PWM2 = PA_10,
    PWM1 = PA_9,
    PWM0 = PC_7,
    TRST = -1,
    TRACEDATA_0 = -1,
    TRACEDATA_1 = -1,
    TRACEDATA_CLK = -1,
    USB_FLAG = -1,
    USB_EN = -1
} breakoutPin;

#endif

#define MACRO_ERROR_NOT_CONNECTED_STR "\n\n****\nPeripheral not accessible on this target\n****\n\n"
#define MACRO_ERROR_NOT_CONNECTED __attribute__ ((error(MACRO_ERROR_NOT_CONNECTED_STR)))

class BreakoutCarrierClass {
public:
    int pinMode(breakoutPin pin, PinMode mode) {
        if (pin > -1) {
            ::pinMode((PinName)pin, mode);
            return 1;
        }
        return -1;
    }
    int digitalWrite(breakoutPin pin, PinStatus status) {
          if (pin > -1) {
            ::digitalWrite((PinName)pin, status);
            return 1;
        }
        return -1;
    }
    bool digitalRead(breakoutPin pin) {
        if (pin > -1) {
            return ::digitalRead((PinName)pin);
        }
        return -1;
    }
    void analogWrite(breakoutPin pin, int val) {
        if (pin > -1) {
            ::analogWrite((PinName)pin, val);
        }
        return;
    }
    void analogWriteResolution(int bits) {
        ::analogWriteResolution(bits);
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

#if defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4)
    MbedI2C I2C_0;
    MbedI2C I2C_1;
    MbedI2C I2C_2;
    UART UART0;
    UART UART1;
    UART UART2;
    UART UART3;
    MbedSPI SPI_0;
    PDMClass PDM;
    mbed::CAN CAN1;
    arduino::EthernetClass Ethernet;
    HWClock RTClock;
    BreakoutCarrierClass() : I2C_0((PinName)I2C0_SDA, (PinName)I2C0_SCL),
                             I2C_1((PinName)I2C1_SDA, (PinName)I2C1_SCL),
                             I2C_2((PinName)I2C2_SDA, (PinName)I2C2_SCL),
                             UART0((PinName)UART0_TX, (PinName)UART0_RX, NC/*UART0_RTS*/, NC/*UART0_CTS*/),
                             UART1((PinName)UART1_TX, (PinName)UART1_RX, NC/*UART1_RTS*/, NC/*UART1_CTS*/),
                             UART2((PinName)UART2_TX, (PinName)UART2_RX, NC, NC),
                             UART3((PinName)UART3_TX, (PinName)UART3_RX, NC, NC),
                             SPI_0((PinName)SPI0_CIPO, (PinName)SPI0_COPI, (PinName)SPI0_CK),
                             PDM((PinName)PDM_D0, (PinName)PDM_CK, NC),
                             CAN1((PinName)CAN1_TX, (PinName)CAN1_RX),
                             Ethernet(),
                             RTClock()
    {
    }
#endif

#if defined(ARDUINO_PORTENTA_X8)

#warning "Most peripherals are only available from Linux side, please follow http://url_to_x8_guide to take full advantage of your Portenta X8"

    UART UART0;
    // TODO: patch the core to expose PDMClass for X8 too
    //PDMClass PDM;
    mbed::CAN CAN0;
    mbed::CAN CAN1;
    HWClock RTClock;
    BreakoutCarrierClass() : UART0((PinName)UART0_TX, (PinName)UART0_RX, (PinName)UART0_RTS, (PinName)UART0_CTS),
                             //PDM((PinName)PDM_D0, (PinName)PDM_CK, NC),
                             CAN0((PinName)CAN0_TX, (PinName)CAN0_RX),
                             CAN1((PinName)CAN1_TX, (PinName)CAN1_RX),
                             RTClock()
    {
    }
#endif

};

BreakoutCarrierClass Breakout;

#endif // ARDUINO_PORTENTA_BREAKOUT_H
