#include<reg51.h>

sbit LED = P2^0;

void delay(unsigned int d)
{	while(d--);
}

void INT0_ISR() interrupt 0
{	LED=1;
	delay(50000);
	LED=0;
}

void main()
{	EA=1;
	EX0=1;
	while(1);
}