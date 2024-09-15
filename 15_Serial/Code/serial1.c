#include<reg51.h>
void main()
{	char str[]="Onkar",c=0;
	TMOD=0x20;
	SCON=0x50;
	TH1=-3;
	TR1=1;
	
	for(c=0; str[c]!=0; c++)
	{	
			SBUF=str[c];
			while(TI==0);
			TI=0;
	}
	while(1);
	
}