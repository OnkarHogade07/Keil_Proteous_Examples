#include<reg51.h>

char arr[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

sbit D1=P1^0;
sbit D2=P1^1;

void delay(unsigned long int d)
{	while(d--);
}

void main ()
{	char n,count,c;
	int i;
		while(1)
		{	for(n=0; n<100; n++)
			{	for(i=0; i<100; i++)
				{	P2= arr[n/10];
					D1=0;	delay(50);	D1=1;
				
					P2= arr[n%10];
					D2=0;	delay(50);	D2=1;
				}
			}			
		}		
}