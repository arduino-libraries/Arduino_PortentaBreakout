/*
  SwFlowSerial.h 
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

//namespace BreakoutUART {


#include "mbed.h"


class SoftwareFC {
	public:
	    SoftwareFC(int rts, int cts)  : _rts((PinName)rts), _cts((PinName)cts) {
			_enabled = true;
		}
		void setRTS() {
			if(_enabled) {
				mbed::DigitalOut rts_pin(_rts);
				rts_pin = 1;
			} 
		};
		void clearRTS() {
			if(_enabled) {
				mbed::DigitalOut rts_pin(_rts);
				rts_pin = 0;
			}
		};
		bool CTS() {
			if(_enabled) {
				mbed::DigitalIn cts_pin(_cts);
				return cts_pin.read() == 0 ? true : false; 
			} else {
				return true;
			} 
		};
    private:
	    PinName _rts, _cts;
	    bool _enabled = false;
};

class SW_FLOW_UART : public UART {
    public:
        void begin(unsigned long);
        int read(void);
		size_t write(uint8_t c);
		size_t write(const uint8_t*, size_t);
    private:
        void on_rx();
        SoftwareFC* _flowControl = NULL;
};

//}