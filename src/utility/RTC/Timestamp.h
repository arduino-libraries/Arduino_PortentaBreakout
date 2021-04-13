/*
  Timestamp.h
  
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

// Timestamp represents a fixed time
typedef struct {
  public:
    int second() { return ts32 % 60; }
    int minute();
    int hour();

    int day();
    int month();
    int year();

    // Internal data
  private:
    // use uint64 to handle the 2038 rollover
    uint64_t ts;

    // *** to avoid 64bit math on small systems an alternative may be:

  public:
    void setFromUnixTimestamp(uint64_t t) {
      after_2038 = (t >= 0x100000000);
      ts32 = t;
    }
    uint64_t getUnixTimestamp() {
      uint64_t t = ts32;
      if (after_2038) t += 0x100000000;
      return t;
    }

    // Internal data
  private:
    uint32_t ts32;
    bool after_2038;

    // More accessor methods, for example:
    //void setTimeVal(struct tm t); // accept posix timeval
    //struct tm getTimeVal();       // return posix timeval
} Timestamp;
