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
	    SoftwareFC(int rts, int cts)  : _fc_rts((PinName)rts), _fc_cts((PinName)cts) {
			_enabled = true;
			mbed::DigitalOut rts_pin(_fc_rts);
			rts_pin = 0;
		}
		void setRTS() {
			if(_enabled) {
				mbed::DigitalOut rts_pin(_fc_rts);
				rts_pin = 1;
			} 
		};
		void clearRTS() {
			if(_enabled) {
				mbed::DigitalOut rts_pin(_fc_rts);
				rts_pin = 0;
			}
		};
		bool CTS() {
			if(_enabled) {
				mbed::DigitalIn cts_pin(_fc_cts);
				//printf("pin %d value %d\n", _fc_cts, cts_pin.read());
				return cts_pin.read() == 0 ? true : false; 
			} else {
				return true;
			} 
		};
    private:
	    PinName _fc_rts, _fc_cts;
	    bool _enabled = false;
};

class SW_FLOW_UART : public UART {
    public:
	    SW_FLOW_UART(int tx, int rx, int rts, int cts) {
			printf("ARDUINO_UART %d %d %d %d\n", tx, rx, rts, cts);
			_sw_tx  = (PinName)tx;
			_sw_rx  = (PinName)rx;
			_sw_rts = (PinName)rts;
			_sw_cts = (PinName)cts;
		}
        void begin(unsigned long);
        int read(void);
		size_t write(uint8_t c);
		size_t write(const uint8_t*, size_t);
    private:
	    PinName _sw_tx,_sw_rx,_sw_rts,_sw_cts;
        void on_rx();
        SoftwareFC* _flowControl = NULL;
		UART* _uart = NULL;
};

//}