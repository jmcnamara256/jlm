#ifndef JLMIO_H
#define JLMIO_H


#include <stdio.h>

#define INPUT  0x00
#define OUTPUT 0x01
#define HIGH   0x01
#define LOW    0x00

// the prescaler is set so that timer0 ticks every 64 clock cycles, and the
// the overflow handler is called every 256 ticks.
#define MICROSECONDS_PER_TIMER2_OVERFLOW 1024

// the whole number of milliseconds per timer0 overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER2_OVERFLOW / 1024)

// the fractional number of milliseconds per timer0 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
#define FRACT_INC ((MICROSECONDS_PER_TIMER2_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)

#define SELECT  639
#define LEFT    409
#define RIGHT   0
#define UP      99
#define DOWN    255
#define BTN_OFF     1015



//extern volatile unsigned long timer0_overflow_count;
//extern volatile unsigned long timer0_millis;

struct TIME {
    unsigned char HOUR = 0;
    unsigned char MIN = 0;
    unsigned char SEC = 0;
};

class jlm{
    public:
        
        

        static void timer2Init();

        static void TMR1INIT(unsigned int TMR1_BOT);
        
        static void TMR2INIT(unsigned char TMR2_BOT);

        static unsigned long GetMillis();

        static unsigned long GetMicros();

        // returns the current system time
        static TIME getTIME();

        // analog read from specified analog analog pin
        static unsigned int analog_read(unsigned char analog_pin);

        // setup adc to use Vcc +5v internal source
        static void adc_setup();

        // return the debounced analog read from a pin
        static unsigned int debounce(unsigned char analog_pin);

        //Set pinmode for digital pins
        static void PinMode(volatile uint8_t* pin, uint8_t position, uint8_t direction);

        //read digital pin values
        static int ReadPin(volatile uint8_t* pin, uint8_t position);

        //read write value to digital pin
        static void WritePin(volatile uint8_t* pin, uint8_t position,uint8_t value);

        //map values between a range
        static float Map(float x, float in_min, float in_max, float out_min, float out_max);

        // interger map overload
        static unsigned int Map(unsigned int x, unsigned int in_min, unsigned int in_max, unsigned int out_min, unsigned int out_max);

        // restrict values between a range of values
        static int Constrain(float x, int lowerbound, int upperbound);

        //check sign of value
        static int Sign(int x);

};

#endif