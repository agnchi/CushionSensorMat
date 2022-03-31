
#include "uart.h"
#include "gpio.h"
#include "adc.h"
#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

char string_buffer[32];
char new_line[]="\n\r";
uint16_t analogRead;
extern uint8_t adc_finished;


int main(void)
{
	TX_init(9600);
	ADC_init();
	sei();
	adc_finished=1;
	
   _delay_ms(500);
    while (1) 
    {
		
		/*for(uint8_t i=0;i<32;i++)
		{
			analogRead=read_MUX(i);
			itoa(analogRead,string_buffer,10);
			send_string(string_buffer);
			send_character(',');
		}*/
		while(adc_finished==0);
		analogRead=read_MUX(0);
		itoa(analogRead,string_buffer,10);
		send_string(string_buffer);
		send_character(',');
		
		while(adc_finished==0);
		analogRead=read_MUX(15);
		itoa(analogRead,string_buffer,10);
		send_string(string_buffer);
		send_character(',');
	
		
			
	
		
		send_string(new_line);
		_delay_ms(500);
    }
}