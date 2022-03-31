
#include "gpio.h"
#include "adc.h"
/*
uint8_t mux_array[32][6]={
	{0,0,0,0,0,1}, //channel 0
	{0,0,0,1,0,1}, //channel 1
	{0,0,1,0,0,1}, //channel 2
	{0,0,1,1,0,1}, //channel 3
	{0,1,0,0,0,1}, //channel 4
	{0,1,0,1,0,1}, //channel 5
	{0,1,1,0,0,1}, //channel 6
	{0,1,1,1,0,1}, //channel 7
	{1,0,0,0,0,1}, //channel 8
	{1,0,0,1,0,1}, //channel 9
	{1,0,1,0,0,1}, //channel 10
	{1,0,1,1,0,1}, //channel 11
	{1,1,0,0,0,1}, //channel 12
	{1,1,0,1,0,1}, //channel 13
	{1,1,1,0,0,1}, //channel 14
	{1,1,1,1,0,1}, //channel 15
	{0,0,0,0,1,0}, //channel 16
	{0,0,0,1,1,0}, //channel 17
	{0,0,1,0,1,0}, //channel 18
	{0,0,1,1,1,0}, //channel 19
	{0,1,0,0,1,0}, //channel 20
	{0,1,0,1,1,0}, //channel 21
	{0,1,1,0,1,0}, //channel 22
	{0,1,1,1,1,0}, //channel 23
	{1,0,0,0,1,0}, //channel 24
	{1,0,0,1,1,0}, //channel 25
	{1,0,1,0,1,0}, //channel 26
	{1,0,1,1,1,0}, //channel 27
	{1,1,0,0,1,0}, //channel 28
	{1,1,0,1,1,0}, //channel 29
	{1,1,1,0,1,0}, //channel 30
	{1,1,1,1,1,0}  //channel 31
};
*/

	//4	  5	 6	7	2  3
	//S0 S1 S2 S3 EN0 EN1
uint8_t mux_array[32][6]={
	{0,1,0,0,0,0}, //channel 0
	{0,1,0,0,0,1}, //channel 1
	{0,1,0,0,1,0}, //channel 2
	{0,1,0,0,1,1}, //channel 3
	{0,1,0,1,0,0}, //channel 4
	{0,1,0,1,0,1}, //channel 5
	{0,1,0,1,1,0}, //channel 6
	{0,1,0,1,1,1}, //channel 7
	{0,1,1,0,0,0}, //channel 8
	{0,1,1,0,0,1}, //channel 9
	{0,1,1,0,1,0}, //channel 10
	{0,1,1,0,1,1}, //channel 11
	{0,1,1,1,0,0}, //channel 12
	{0,1,1,1,0,1}, //channel 13
	{0,1,1,1,1,0}, //channel 14
	{0,1,1,1,1,1}, //channel 15
	{1,0,0,0,0,0}, //channel 16
	{1,0,0,0,0,1}, //channel 17
	{1,0,0,0,1,0}, //channel 18
	{1,0,0,0,1,1}, //channel 19
	{1,0,0,1,0,0}, //channel 20
	{1,0,0,1,0,1}, //channel 21
	{1,0,0,1,1,0}, //channel 22
	{1,0,0,1,1,1}, //channel 23
	{1,0,1,0,0,0}, //channel 24
	{1,0,1,0,0,1}, //channel 25
	{1,0,1,0,1,0}, //channel 26
	{1,0,1,0,1,1}, //channel 27
	{1,0,1,1,0,0}, //channel 28
	{1,0,1,1,0,1}, //channel 29
	{1,0,1,1,1,0}, //channel 30
	{1,0,1,1,1,1}  //channel 31
};
void GPIO_init(void)
{
	DDRD=(1<<DDD2)|(1<<DDD3)|(1<<DDD4)|(1<<DDD5)|(1<<DDD6)|(1<<DDD7);	
}

uint16_t read_MUX(uint8_t channel_num)
{
	uint8_t bit_value;
	for(uint8_t i=0;i<6;i++)
	{
		bit_value=(mux_array[channel_num][i]);
		PORTD|=(bit_value<<(i+2));
	}
	
	uint16_t analogVAL;
	analogVAL=ADC_convert();
	return analogVAL;
}
