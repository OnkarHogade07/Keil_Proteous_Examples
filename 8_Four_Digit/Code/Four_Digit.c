#include<reg51.h>

char arr[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

sbit D1=P3^0;
sbit D2=P3^1;
sbit D3=P3^2;
sbit D4=P3^3;

void delay(unsigned long int d)
{	while(d--);
}

void main ()
{
	int n; 
	
	char temp;

	while(1)
	{
		 for(n=1; n<1000; n++)
	{
					temp=n%10;
					P2=arr[temp];
					D1=0; delay(5000);	D1=1;
					n=n/10;
		
				  temp=n%10;
					P2=arr[temp];
					D2=0; delay(5000);	D2=1;
					n=n/10;
				
					temp=n%10;
					P2=arr[temp];
					D3=0; delay(5000);	D=1;
					n=n/10;
				
					
			
	}
	}

	
	
}
