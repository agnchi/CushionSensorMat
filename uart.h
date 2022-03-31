
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>


void TX_init( uint32_t baud );
void send_character(uint8_t c);
void send_string(char* c);