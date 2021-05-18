#include "SwFlowSerial.h"

void SW_FLOW_UART::begin(unsigned long baudrate) {

	if (_serial == NULL) {
		_serial = new mbed_serial;
		_serial->obj = NULL;
	}
	if (_serial->obj == NULL) {
		printf("New uart device\n");
		_serial->obj = new mbed::UnbufferedSerial(_tx, _rx, baudrate);
	} else {
		_serial->obj->baud(baudrate);
	}
	if (_rts != NC) {
		printf("Set flow control\n");
		if(pinmap_find_peripheral(_rts, PinMap_UART_RTS) != NC) {
            //_serial->obj->set_flow_control(mbed::SerialBase::Flow::RTSCTS, _rts, _cts);
		} else {
			printf("Peripheral HW flow control not available\n");
		    if(rts_gpio == NULL) {
			    rts_gpio = new mbed::DigitalOut(_rts);
			    cts_gpio = new mbed::DigitalIn(_cts);
		    }
		}
	}
	if (_serial->obj != NULL) {
		_serial->obj->attach(mbed::callback(this, &UART::on_rx), mbed::SerialBase::RxIrq);
	}
}

void UART::on_rx() {

	while(_serial->obj->readable()) {
		char c;
		_serial->obj->read(&c, 1);
		rx_buffer.store_char(c);
		if(rx_buffer.available() < 16) {
			*rts_gpio = 1;//RTS HIGH
		}
	}
}

void UART::end() {

	if (_serial->obj != NULL) {
		delete _serial->obj;
		_serial->obj = NULL;
	}
}

int UART::read() {

    if(rx_buffer.available()> 16) {
		*rts_gpio = 0;//RTS LOW
	}
	return rx_buffer.read_char();
}

size_t UART::write(uint8_t c) {

	while (!_serial->obj->writeable()) {}
	while (*cts_gpio == 1) {/*printf("waiting cts\n");*/}
	int ret = _serial->obj->write(&c, 1);
	return ret == -1 ? 0 : 1;
}

size_t UART::write(const uint8_t* c, size_t len) {

	while (!_serial->obj->writeable()) {}
	// we need to check cts each byte
	while (*cts_gpio == 1) {/*printf("waiting cts\n");*/}
	_serial->obj->set_blocking(true);
	int ret = _serial->obj->write(c, len);
	return ret == -1 ? 0 : len;
}
