/*
  SwFlowSerial.cpp 
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

//#include "Arduino.h"
//#include "pins_arduino.h"
//#include "pinDefinitions.h"
#include "SwFlowSerial.h"

//namespace BreakoutUART {

struct _mbed_serial {
	mbed::UnbufferedSerial* obj;
};

void SW_FLOW_UART::begin(unsigned long baudrate) {
    if (_uart == NULL) {
        _uart = new arduino::UART(_sw_tx, _sw_rx, _sw_rts, _sw_cts);
    }

    _uart->begin(baudrate);

	  if (pinmap_find_peripheral(_sw_rts, PinMap_UART_RTS) == NC || 
		    pinmap_find_peripheral(_sw_cts, PinMap_UART_CTS) == NC) {
			  printf("Peripheral HW flow control not available %d %d\n",_sw_rts,_sw_cts);
		   _flowControl = new SoftwareFC(_sw_rts, _sw_cts);
		}

    if(_uart->_serial->obj != NULL) {    
        _uart->_serial->obj->attach(mbed::callback(this, &SW_FLOW_UART::on_rx), mbed::SerialBase::RxIrq);
    }
}

void SW_FLOW_UART::on_rx() {

  if(_uart->availableForStore() < 16) {
	  _flowControl->setRTS();
	}

  _uart->on_rx();
}

int SW_FLOW_UART::read() {

  if(_uart->availableForStore() > 16) {
		_flowControl->clearRTS();
	}
	
	return _uart->read();
}

size_t SW_FLOW_UART::write(uint8_t c) {

  while (_flowControl->CTS() == false) {}
	_uart->write(c);
}

size_t SW_FLOW_UART::write(const uint8_t* c, size_t len) {


}

//}

