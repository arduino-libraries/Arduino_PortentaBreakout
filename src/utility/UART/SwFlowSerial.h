
#include "mbed.h"

class SW_FLOW_UART : public UART {
    public:
    SW_FLOW_UART(int tx, int rx, int rts, int cts) : _tx((PinName)tx), _rx((PinName)rx), _rts((PinName)rts), _cts((PinName)cts) {}
        void begin(unsigned long);
		//void begin(unsigned long baudrate, uint16_t config);
        void end();
        int read(void);
		size_t write(uint8_t c);
		size_t write(const uint8_t*, size_t);
    private:
        PinName _tx, _rx, _rts, _cts;
        void on_rx();
        bool enabled = true;
		mbed::DigitalOut *rts_gpio = NULL;
		mbed::DigitalIn *cts_gpio = NULL;
};