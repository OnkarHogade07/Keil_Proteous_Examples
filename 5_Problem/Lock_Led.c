#include<reg51.h>

sbit Switch=P1^0;
sbit LED=P3^0;

void main ()
{
	while(1)
	{
			if(Switch==0)
			{
					LED=1;
			}
			else
			{
					LED=0;
			}
	}
}