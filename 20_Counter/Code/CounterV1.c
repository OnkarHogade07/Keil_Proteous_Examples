#include<reg51.h>

sbit SW=P3^2;

void main()
{	TMOD=0x0D;	
	TH0=0;
	TL0=0;
	TR0=1;
	
	while(1)
	{
		P1=TL0;
		P2=TH0;
	}
}