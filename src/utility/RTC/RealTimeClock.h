/*
  RealTimeClock.h
  
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

#pragma once

#include "TimeSyncProvider.h"

// RealTimeClock interface
// RTC should implement this interface.
// A RealTimeClock may be used as a TimeSyncProvider.
class RealTimeClock : public TimeSyncProvider
{
  public:
    // getTime returns the current time as unix-timestamp.
    // Return 0 if time has not been set.
    virtual Timestamp getTime() = 0;

    // setTime sets the current time given a unix-timestamp.
    virtual bool setTime(Timestamp t) = 0;

    // setTimeWith will sync the current clock with the
    // time given by the specified provider.
    //void setTimeWith(TimeSyncProvider &ts) {
    //  setTime(ts.getTime());
    //}
};
