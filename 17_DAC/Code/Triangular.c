#include<reg51.h>
void delay(unsigned int d)
{	while(d--);
}
void main()
{	unsigned char amp;
	while(1)
 	{	for(amp=0	; amp<255; amp++)
		{	P2=amp;
			delay(80);
		}
		for(	;amp>0; amp--)
		{	P2=amp;
			delay(100);
		}
	}
}