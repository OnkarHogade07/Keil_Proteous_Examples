#include<reg51.h>

char arr[5]="ABCDE",c;

void serial_ISR() interrupt 4
{	if(TI)
	{	TI=0;
		c++;
		if(c<5)
			SBUF=arr[c];
		else
		{	P2=0xAA;
			IE=0;
		}
	}
}

void main()
{	TMOD=0x20;
	SCON=0x50;
	TH1=-3;
	TR1=1;
	IE=0x90;
	SBUF=arr[0];
	while(1);
}