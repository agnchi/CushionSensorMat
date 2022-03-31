/*

PORTD:	pin2 EN0
		pin3 EN1
		pin4 S0
		pin5 S1
		pin6 S2
		pin7 S3
*/

#include <avr/io.h>
#include <stdio.h>



void GPIO_init(void);
uint16_t read_MUX(uint8_t channel_num);

