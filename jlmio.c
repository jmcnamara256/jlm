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

//Set pinmode for digital pins
void PinMode(volatile uint8_t* pin, uint8_t position, uint8_t direction){
    if (direction == INPUT){
        *pin &= ~(1<<position);

    } else if(direction == OUTPUT){
        *pin |= (1<<position);

    }
}

//read digital pin values
int ReadPin(volatile uint8_t* pin, uint8_t position){
    uint8_t output;

    output = (~(*pin) & 1<<position);
    return output;
}

//read write value to digital pin
void WritePin(volatile uint8_t* pin, uint8_t position,uint8_t value){
    if(value == HIGH){
        *pin |= (1<<position);
        
    }else if(value==LOW){
        *pin &= ~(1<<position);
        
    }
}

//map values between a range
float Map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// restrict values between a range of values
int Constrain(float x, int lowerbound, int upperbound){
    if (x > upperbound){
        x = upperbound;
    } else if(x < lowerbound){
        x = lowerbound;
    }
    return x;
}

//check sign of value
int Sign(int x){
    if (x < 0){
        return 0;
    } else{
        return 1;
    }
}

