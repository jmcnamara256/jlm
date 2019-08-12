#ifndef JLMIO_H
#define JLMIO_H


#include <stdio.h>

#define INPUT  0x00
#define OUTPUT 0x01
#define HIGH   0x01
#define LOW    0x00

// analog read from specified analog analog pin
extern unsigned int analog_read(unsigned char analog_pin);

// setup adc to use Vcc +5v internal source
extern void adc_setup();

//Set pinmode for digital pins
void PinMode(volatile uint8_t* pin, uint8_t position, uint8_t direction);

//read digital pin values
int ReadPin(volatile uint8_t* pin, uint8_t position);

//read write value to digital pin
void WritePin(volatile uint8_t* pin, uint8_t position,uint8_t value);

//map values between a range
float Map(float x, float in_min, float in_max, float out_min, float out_max);

// restrict values between a range of values
int Constrain(float x, int lowerbound, int upperbound);

//check sign of value
int Sign(int x);

#endif