
#include "uart.h"

volatile static uint8_t tx_busy = 0;

ISR(USART_TX_vect)
{
	tx_busy = 0;
}

void TX_init( uint32_t baud )
{
	unsigned int ubrr=((F_CPU/(16*baud))-1);
	UBRR0H = (ubrr&0x0F00)>>8;
	UBRR0L = ubrr&0x00FF;
	UCSR0B |= (1<<TXEN0)|(1<<TXCIE0);
}
void send_character(uint8_t c)
{
	while (tx_busy==1);
	tx_busy = 1;
	UDR0=c;
}
void send_string(char* c)
{
	uint16_t i=0;
	while(c[i]!='\0')
	{
		send_character(c[i]);
		i++;
	}
} 
