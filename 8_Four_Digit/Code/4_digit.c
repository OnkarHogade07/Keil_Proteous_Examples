#include<reg51.h>

char arr[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

sbit D1=P3^0;
sbit D2=P3^1;
sbit D3=P3^2;
sbit D4=P3^3;

void delay(unsigned int d)
{	while(d--);
}

void main ()
{
	int n,n1,count; 
	char c, dig[5];

	while(1)
	{	for(n=1; n<1000; n++)
		{	n1=n;
			for(c=0; n1>0; c++)
			{	dig[c]=n1%10;
				n1/=10;
			}
			for(count=0; count<100; count++)
			{	P2=arr[dig[3]];
				D1=0; delay(10);	D1=1;
				
				P2=arr[dig[2]];
				D2=0; delay(10);	D2=1;
				
				P2=arr[dig[1]];
				D3=0; delay(10);	D3=1;
				
				P2=arr[dig[0]];
				D4=0; delay(10);	D4=1;
			}
		}
	}
}
