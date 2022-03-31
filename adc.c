
#include "adc.h"

uint8_t adc_finished=0;
ISR(ADC_vect)
{
	adc_finished=1;
	
}

void ADC_init(void)
{
	ADMUX|=(1<<REFS0)|(1<<MUX0)|(1<<MUX1);
	ADCSRA|=(1<<ADEN)|(1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	DIDR0|=(1<<ADC3D);
}

uint16_t ADC_convert(void)
{
	uint8_t adcl=0;
	uint8_t adch=0;
	adc_finished=0;
	ADCSRA|=1<<ADSC;
	while(adc_finished==0);
	adcl=ADCL;
	adch=ADCH;
	return (adch<<8 |adcl);
}
