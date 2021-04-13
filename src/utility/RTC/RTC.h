/*
  RTC.h
  Copyright (c) 2021 Arduino LLC. All right reserved.
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

#ifndef ARDUINO_HW_RTC_H
#define ARDUINO_HW_RTC_H

#include "RealTimeClock.h"

class HWClock : public RealTimeClock {
public:
    HWClock();

    // Get the current time as unix-timestamp.
    // Return 0 if time has not been set.
    virtual Timestamp getTime();

    // Set the current time as unix-timestamp
    virtual bool setTime(Timestamp t);

private:
    uint64_t lastTimestamp;
};

#endif
