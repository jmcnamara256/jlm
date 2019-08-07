#include "jlmio.h"
#include <avr/io.h>
 
// analog read from specified analog analog pin
unsigned int analog_read(unsigned char analog_pin) {
    ADMUX &= 0b11110000;        // clear ADC mux bits
    ADMUX |= analog_pin;        // select mux channel
    ADCSRA |= (1<<ADSC);        // start conversion

    while((ADCSRA & 0b00010000) == 0){
        // wait untill conversion finishes
    }

    
    return (ADCH << 2) | (ADCL);
}

// initialise the adc module
void adc_setup() {
    ADMUX = 0b01000000;         // set the voltage reference to Vcc +5v
    ADCSRA = 0b10000111;        // turn on ADC, disable auto trigger, disable interrupts, set prescale
}