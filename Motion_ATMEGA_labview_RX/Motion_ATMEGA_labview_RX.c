#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"
#include"string.h"
#include<stdlib.h>

void main()
{
	USARTInit(51);
	InitLCD(0);
	char data;
	uint8_t FSR1;
	char arr[10];
	LCDWriteStringXY(0,0,"LABVIEW GUI");
	LCDWriteStringXY(0,1,"With PROTEUS");
	_delay_ms(1000);
	LCDClear();
	LCDWriteStringXY(0,0,"MotionDet.SYSTEM--------");
	while(1)
	{
	data= USARTReadChar();
	if(data=='a')
	   {
	    LCDClear();
	  	FSR1=10;
	    write("FSR1:");
		itoa(FSR1,arr,10);
		write(arr);
		USARTWriteChar('\n');
		LCDWriteString("Motion DETECTED");
	 	_delay_ms(50);
    	}

	else if(data=='b') 
	   {
	    LCDClear();
	 	FSR1=20;
	    write("FSR1:");
		itoa(FSR1,arr,10);
		write(arr);
		USARTWriteChar('\n');
		LCDWriteString("NO Motion DETECTED");
	 	_delay_ms(50);
    	}
	}
	}
