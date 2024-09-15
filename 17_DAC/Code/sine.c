#include<reg51.h>
#include<math.h>
/*
void delay(unsigned int d)
{	while(d--);
}
*/
void main()
{	int ang;
	unsigned char amp;
	while(1)
	{	for(ang=180; ang<360; ang+=1)
		{	amp=128+127*sin(ang*3.142/180);
			P2=amp;
		}
	}
}
	