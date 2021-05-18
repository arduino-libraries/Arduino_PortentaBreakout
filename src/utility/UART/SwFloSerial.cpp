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

	UART::begin(baudrate);
	if(pinmap_find_peripheral(_rts, PinMap_UART_RTS) == NC && 
		 pinmap_find_peripheral(_cts, PinMap_UART_CTS) == NC) {
			printf("Peripheral HW flow control not available\n");
		   _flowControl = new SoftwareFC(_rts, _cts);
		}

    //Change rx interrupt attached function
    if (_serial->obj != NULL) {
		_serial->obj->attach(mbed::callback(this, &UART::on_rx), mbed::SerialBase::RxIrq);
	}
}

void SW_FLOW_UART::on_rx() {

  if(UART::availableForStore() < 16) {
	  _flowControl->setRTS();
	}
	
	UART::on_rx();
}

int SW_FLOW_UART::read() {

  if(UART::availableForStore() > 16) {
		_flowControl->clearRTS();
	}
	
	return UART::read();
}

size_t SW_FLOW_UART::write(uint8_t c) {

  while (_flowControl->CTS() == false) {}
	UART::write(c);
}

size_t SW_FLOW_UART::write(const uint8_t* c, size_t len) {


}

//}

