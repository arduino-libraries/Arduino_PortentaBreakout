# Portenta Breakout Carrier Library for Arduino

[![Check Arduino status](https://github.com/arduino-libraries/Arduino_PortentaBreakout/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_PortentaBreakout/actions/workflows/check-arduino.yml)
[![Compile Examples status](https://github.com/arduino-libraries/Arduino_PortentaBreakout/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_PortentaBreakout/actions/workflows/compile-examples.yml)
[![Spell Check status](https://github.com/arduino-libraries/Arduino_PortentaBreakout/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_PortentaBreakout/actions/workflows/spell-check.yml)

Arduino Library for the Arduino Portenta Breakout Carrier

For more information about this library please visit us at https://www.arduino.cc/en/Reference/Arduino_PortentaBreakout

For more information about this product please visit us at https://www.arduino.cc/pro/hardware/product/portenta-breakout

## License

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

## Peripherals table

|PERIPHERAL     |SILK           |BREAKOUT       |uC PIN         |API            |NOTES          |
|---------------|---------------|---------------|---------------|---------------|---------------|
|ETHERNET       |               |               |               |Breakout.Ethernet|               |
|               |D+             |ETHERNET_DP    |               |               |Not available as GPIO|
|               |D-             |ETHERNET_DN    |               |               |Not available as GPIO|
|               |GND            |               |               |               |               |
|               |GND            |               |               |               |               |
|               |L2             |ETHERNET_L2    |               |               |Not available as GPIO|
|               |L1             |ETHERNET_L1    |               |               |Not available as GPIO|
|               |C-             |ETHERNET_CN    |               |               |Not available as GPIO|
|               |C+             |ETHERNET_CP    |               |               |Not available as GPIO|
|               |B-             |ETHERNET_BN    |               |               |Not available as GPIO|
|               |B+             |ETHERNET_BP    |               |               |Not available as GPIO|
|               |A-             |ETHERNET_AN    |               |               |Not available as GPIO|
|               |A+             |ETHERNET_AP    |               |               |Not available as GPIO|
|UART0          |               |               |               |Breakout.UART0 |HW flow control not supported|
|               |3V3            |               |               |               |               |
|               |TX             |UART0_TX       |PA_0           |               |               |
|               |RX             |UART0_RX       |PI_9           |               |               |
|               |RTS            |UART0_RTS      |PI_10          |               |               |
|               |CTS            |UART0_CTS      |PI_13          |               |               |
|               |GND            |               |               |               |               |
|UART1          |               |               |               |Breakout.UART1 |HW flow control not supported|
|               |3V3            |               |               |               |               |
|               |TX             |UART1_TX       |PA_9           |               |               |
|               |RX             |UART1_RX       |PA_10          |               |               |
|               |RTS            |UART1_RTS      |PI_14          |               |               |
|               |CTS            |UART1_CTS      |PI_15          |               |               |
|               |GND            |               |               |               |               |
|DISPLAY        |               |               |               |               |               |
|               |D3P            |DISPLAY_D3P    |               |               |Not available as GPIO|
|               |D3N            |DISPLAY_D3N    |               |               |Not available as GPIO|
|               |D2P            |DISPLAY_D2P    |               |               |Not available as GPIO|
|               |D2N            |DISPLAY_D2N    |               |               |Not available as GPIO|
|               |D1P            |DISPLAY_D1P    |               |               |Not available as GPIO|
|               |D1N            |DISPLAY_D1N    |               |               |Not available as GPIO|
|               |D0P            |DISPLAY_D0P    |               |               |Not available as GPIO|
|               |D0N            |DISPLAY_D0N    |               |               |Not available as GPIO|
|               |CLKP           |DISPLAY_CLK_P  |               |               |Not available as GPIO|
|               |CLKN           |DISPLAY_CLK_N  |               |               |Not available as GPIO|
|               |GND            |               |               |               |               |
|               |GND            |               |               |               |               |
|CAN0           |               |               |               |               |Not connected  |
|               |5V             |               |               |               |               |
|               |TX             |CAN0_TX        |               |               |               |
|               |RX             |CAN0_RX        |               |               |               |
|               |GND            |               |               |               |               |
|CAN1           |               |               |               |TODO           |               |
|               |5V             |               |               |               |               |
|               |TX             |CAN1_TX        |PH_13          |               |               |
|               |RX             |CAN1_RX        |PB_8           |               |               |
|               |GND            |               |               |               |               |
|I2C            |               |               |               |               |               |
|               |3V3            |               |               |Breakout.I2C_1 |               |
|               |GND            |               |               |               |               |
|               |I2C1SDA        |I2C_SDA_1      |PB_7           |               |               |
|               |I2C1SCL        |I2C_SCL_1      |PB_6           |               |               |
|               |3V3            |               |               |Breakout.I2C_0 |               |
|               |GND            |               |               |               |               |
|               |I2C0SDA        |I2C_SDA_0      |PH_8           |               |               |
|               |I2C0SCL        |I2C_SCL_0      |PH_7           |               |               |
|               |3V3            |               |               |Breakout.I2C_2 |               |
|               |GND            |               |               |               |               |
|               |I2C2SDA        |I2C_SDA_2      |PH_12          |               |               |
|               |I2C2SCL        |I2C_SCL_2      |PH_11          |               |               |
|GPIO           |               |               |               |Breakout.digitalWrite|               |
|               |3V3            |               |               |               |               |
|               |0              |GPIO_0         |PC_13          |               |               |
|               |1              |GPIO_1         |PC_15          |               |               |
|               |2              |GPIO_2         |PD_4           |               |               |
|               |3              |GPIO_3         |PD_5           |               |               |
|               |4              |GPIO_4         |PE_3           |               |               |
|               |5              |GPIO_5         |PG_3           |               |               |
|               |6              |GPIO_6         |PG_10          |               |               |
|               |GND            |               |               |               |               |
|               |GND            |               |               |               |               |
|ANALOG         |               |               |               |Breakout.analogRead|               |
|               |GND            |               |               |               |               |
|               |REFN           |ANALOG_REFN    |               |               |               |
|               |REFP           |ANALOG_REFP    |               |               |               |
|               |A0             |ANALOG_A0      |PA_0_C         |               |               |
|               |A1             |ANALOG_A1      |PA_1_C         |               |Not available as GPIO if ETHERNET is used|
|               |A2             |ANALOG_A2      |PC_2_C         |               |               |
|               |A3             |ANALOG_A3      |PC_3_C         |               |               |
|               |A4             |ANALOG_A4      |PC_2           |               |As GPIO internally connected to A2|
|               |A5             |ANALOG_A5      |PC_3           |               |As GPIO internally connected to A3|
|               |A6             |ANALOG_A6      |PA_4           |               |               |
|               |A7             |ANALOG_A7      |PA_6           |               |               |
|PWM            |               |               |               |Breakout.analogWrite|Minimum frequency 770Hz|
|               |GND            |               |               |               |               |
|               |PWM0           |PWM0           |PA_8           |               |               |
|               |PWM1           |PWM1           |PC_6           |               |               |
|               |PWM2           |PWM2           |PC_7           |               |               |
|               |PWM3           |PWM3           |PG_7           |               |               |
|               |PWM4           |PWM4           |PJ_11          |               |Shares timer with PWM8|
|               |PWM5           |PWM5           |PK_1           |               |               |
|               |PWM6           |PWM6           |PH_15          |               |               |
|               |PWM7           |PWM7           |PJ_7           |               |               |
|               |PWM8           |PWM8           |PJ_10          |               |Shares timer with PWM4|
|               |PWM9           |PWM9           |PH_6           |               |               |
|SPI0           |               |               |               |               |Not connected  |
|               |3V3            |               |               |               |               |
|               |CS             |SPI0_CS        |               |               |               |
|               |CK             |SPI0_CK        |               |               |               |
|               |CIPO           |SPI0_CIPO      |               |               |               |
|               |COPI           |SPI0_COPI      |               |               |               |
|               |GND            |               |               |               |               |
|SPI1           |               |               |               |Breakout.SPI_1 |               |
|               |3V3            |               |               |               |               |
|               |CS             |SPI1_CS        |PI_0           |               |               |
|               |CK             |SPI1_CK        |PI_1           |               |               |
|               |CIPO           |SPI1_CIPO      |PC_2           |               |               |
|               |COPI           |SPI1_COPI      |PC_3           |               |               |
|               |GND            |               |               |               |               |
|UART2          |               |               |               |Breakout.UART2 |               |
|               |3V3            |               |               |               |               |
|               |TX             |UART2_TX       |PG_14          |               |               |
|               |RX             |UART2_RX       |PG_9           |               |               |
|               |RTS            |UART2_RTS      |               |               |Not connected  |
|               |CTS            |UART2_CTS      |               |               |Not connected  |
|               |GND            |               |               |               |               |
|UART3          |               |               |               |Breakout.UART3 |               |
|               |3V3            |               |               |               |               |
|               |TX             |UART3_TX       |PJ_8           |               |               |
|               |RX             |UART3_RX       |PJ_9           |               |               |
|               |RTS            |UART3_RTS      |               |               |Not connected  |
|               |CTS            |UART3_CTS      |               |               |Not connected  |
|               |GND            |               |               |               |               |
|PCIE           |               |               |               |               |Not connected  |
|               |TXN            |PCIE_TXN       |               |               |               |
|               |TXP            |PCIE_TXP       |               |               |               |
|               |RXN            |PCIE_RXN       |               |               |               |
|               |RXP            |PCIE_RXP       |               |               |               |
|               |CKN            |PCIE_CKN       |               |               |               |
|               |CKP            |PCIE_CKP       |               |               |               |
|               |GND            |               |               |               |               |
|               |RST            |               |               |               |               |
|SAI            |               |               |               |TODO           |               |
|               |GND            |               |               |               |               |
|               |D0             |SAI_D0         |PI_6           |               |               |
|               |D1             |SAI_D1         |               |               |Not connected  |
|               |FS             |SAI_FS         |PI_7           |               |               |
|               |SCK            |SAI_SCK        |PI_5           |               |               |
|               |3V3            |               |               |               |               |
|I2S            |               |               |               |TODO           |               |
|               |GND            |               |               |               |               |
|               |SDO            |I2S_SDO        |PI_3           |               |               |
|               |SDI            |I2S_SDI        |PI_2           |               |               |
|               |WS             |I2S_WS         |PB_9           |               |               |
|               |CK             |I2S_CK         |PD_3           |               |               |
|               |3V3            |               |               |               |               |
|CAMERA         |               |               |               |TODO           |               |
|               |D0P            |CAMERA_D0P     |PH_10          |               |               |
|               |D0N            |CAMERA_D0N     |PH_9           |               |               |
|               |D1P            |CAMERA_D1P     |PH_12          |               |               |
|               |D1N            |CAMERA_D1N     |PH_11          |               |               |
|               |D2P            |CAMERA_D2P     |PI_4           |               |               |
|               |D2N            |CAMERA_D2N     |PH_14          |               |               |
|               |D3P            |CAMERA_D3P     |PI_7           |               |               |
|               |D3N            |CAMERA_D3N     |PI_6           |               |               |
|               |CKP            |CAMERA_CKP     |PI_5           |               |               |
|               |CKN            |CAMERA_CKN     |PA_6           |               |               |
|               |HS             |CAMERA_HS      |PA_4           |               |               |
|               |GND            |               |               |               |               |
|PDM            |               |               |               |Breakout.PDM   |               |
|               |GND            |               |               |               |               |
|               |D0             |PDM_D0         |               |               |               |
|               |D1             |PDM_D1         |               |               |Not connected  |
|               |CK             |PDM_CK         |               |               |               |
|SPDIF          |               |               |               |               |Not connected  |
|               |GND            |               |               |               |               |
|               |GND            |               |               |               |               |
|               |RX             |SPDIF_RX       |               |               |               |
|               |TX             |SPDIF_TX       |               |               |               |
|USB0           |               |               |               |TODO           |               |
|               |GND            |               |               |               |               |
|               |ID             |USB0_ID        |               |               |Not connected  |
|               |D-             |USB0_DN        |PA_12          |               |               |
|               |D+             |USB0_DP        |PA_11          |               |               |
|               |VBUS           |               |               |               |               |
|USB1           |               |               |               |TODO           |               |
|               |GND            |               |               |               |               |
|               |ID             |USB1_ID        |PJ_6           |               |               |
|               |D-             |USB1_DN        |               |               |               |
|               |D+             |USB1_DP        |               |               |               |
|               |VBUS           |               |               |               |               |
|SD CARD        |               |               |               |TODO           |Available as CORE peripheral|
|               |RST            |               |               |               |Not connected  |
|               |GND            |               |               |               |               |
|               |WP             |SD_WP          |               |               |Not connected  |
|               |NC             |               |               |               |               |
|               |CD             |SD_CD          |               |               |Not connected  |
|               |D0             |SD_D0          |PB_14          |               |               |
|               |D3             |SD_D3          |PB_4           |               |               |
|               |CMD            |SD_CMD         |PD_7           |               |               |
|               |D2             |SD_D2          |PB_3           |               |               |
|               |CLK            |SD_CLK         |PD_6           |               |               |
|               |D1             |SD_D1          |PB_15          |               |               |
|               |VSD            |SD_VSD         |               |               |               |
|RTC            |               |               |               |Breakout.RTClock|               |

