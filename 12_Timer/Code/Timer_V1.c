#include<reg51.h>

sbit LED=P2^0;

void delay_50ms( char d)
{	TMOD=0x01;		
	for(	; d>0; d--)
	{	TH0=0x4C;
		TL0=0x00;
		TR0=1;		//STart the Timer 0.
		while(TF0==0);
		TR0=0;	//STop the timer 0.
		TF0=0;	//Clear the Timer flag.
	}
}

void main()
{	bit b;
	while(1)
	{	LED=b=~b;
		delay_50ms(20);
	}
}