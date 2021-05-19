/*
  portentaBreakoutAnalog.cpp 
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2018-2019 Arduino SA

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#include "Arduino.h"
#include "pins_arduino.h"
#include "pinDefinitions.h"
#include "Analog.h"

namespace BreakoutPWM {

static int write_resolution = 8;
HRTIMPWMClass *hrtimpwm = NULL;

void analogWrite(pin_size_t pin, int val)
{
    if (pin >= PINS_COUNT) {
        return;
    }

    float percent = (float)val/(float)((1 << write_resolution)-1);

    if (digitalPinToPinName(pin) == PG_7) {
        if(hrtimpwm == NULL) {
            hrtimpwm = new HRTIMPWMClass();
            hrtimpwm->period_us(1300); //Max period for HRTIM
        }
        if (percent < 0) {
            delete hrtimpwm;
            hrtimpwm = NULL;
        } else {
            hrtimpwm->write(percent);
        }
    } else { 
        mbed::PwmOut* pwm = digitalPinToPwm(pin);
        if (pwm == NULL) {
            pwm = new mbed::PwmOut(digitalPinToPinName(pin));
            digitalPinToPwm(pin) = pwm;
            pwm->period_us(1300); //700Hz
        }
        if (percent < 0) {
            delete pwm;
            digitalPinToPwm(pin) = NULL;
        } else {
            pwm->write(percent);
        }
    }
}

void analogWriteResolution(int bits)
{
    write_resolution = bits;
}

}
