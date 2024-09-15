#include<reg51.h>

void delay(unsigned long int d)
{	while(d--);
}

void main()
{
	char arr[4]={0x0A, 0x09, 0x05, 0x06},c;
	while(1)
	{	
		for(c=0; c<4; c++)
		{	P2=arr[c];
			delay(13000);
		}
		
		for(c=2; c>0; c--)
		{	
			P2=arr[c];
			delay(13000);
		}
		
	}
}