/*
  RTC.cpp
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

#include "Arduino.h"
#include "RealTimeClock.h"
#include "RTC.h"
#include "mbed.h"

HWClock::HWClock() : lastTimestamp(0)
{
  // Empty
}


// getTime returns the current time as unix-timestamp.
// Return 0 if time has not been set.
Timestamp HWClock :: getTime() {
    Timestamp res;
    //if (lastTimestamp == 0) {
    //    return res;
    //}
    time_t seconds = time(NULL);
    res.setFromUnixTimestamp(seconds);
    return res;
}

// setTime sets the current time given a unix-timestamp.
bool HWClock :: setTime(Timestamp t) {
    lastTimestamp = t.getUnixTimestamp();
    ::set_time(lastTimestamp);
}

// setTimeWith will sync the current clock with the
// time given by the specified provider.
//void HWClock :: setTimeWith(TimeSyncProvider &ts) {
//    setTime(ts.getTime());
//}

