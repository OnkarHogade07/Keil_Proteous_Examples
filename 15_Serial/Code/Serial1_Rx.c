#include<reg51.h>
sbit LED=P2^0;

void main()
{	char str[]="Onkar",c=0,byte;
	TMOD=0x20;
	SCON=0x50;
	TH1=-3;
	TR1=1;
	while(1)	
	{	while(RI==0);
		RI=0;
		byte=SBUF;
		if(byte=='A')	LED=1;
		else					LED=0;
	}
	
}