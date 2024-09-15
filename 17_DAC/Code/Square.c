#include<reg51.h>

void delay(unsigned int d)
{	while(d--);
}

void main()
{	unsigned char val=0;
	while(1)
	{	P2=val=~val;
		delay(1000);
	}
}