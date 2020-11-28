#include<avr/io.h>
#include<util/delay.h>


void main()
{
	DDRB&=~(1<<0);
//	PORTB|=(1<<0);
	DDRB&=~(1<<1);
	PORTB|=(1<<1);
	DDRB&=~(1<<2);
		
	while(1)
	{
		if((PINB&1) && !(PINB&2))
		{
			PORTB|=(1<<2);
			_delay_ms(50);
		}
		else 
		{
			PORTB&=(1<<2);
			_delay_ms(50);
		}
	}
}
			

