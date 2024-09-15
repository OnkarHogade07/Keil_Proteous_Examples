//Receive all the bytes serially on interrupt and take the necessary action.
#include<reg51.h>
sbit RS=P2^0;
sbit EN=P2^1;

bit flag=0;
char arr[20]={0},c;

void delay(unsigned int d)
{	while(d--);
}
void cmdwrt(unsigned char cmd)
{	P0=cmd;
	RS=0;
	EN=1;	delay(100);
	EN=0; delay(100);
}
void datawrt(unsigned char dat)
{	P0=dat;
	RS=1;
	EN=1;	delay(100);
	EN=0; delay(100);
}
void strwrt(unsigned char *ptr)
{	for(	; *ptr!=0; ptr++)
		datawrt(*ptr);
}
void lcdinit()
{	cmdwrt(0x38);	//LCD Initialization in 8-bit mode.
	cmdwrt(0x0E);	//Display ON, Cursor ON
	cmdwrt(0x06);	//Cursor Autoincrement
	cmdwrt(0x01);	//Clear LCD
	delay(1000);
}

void serial_ISR() interrupt 4
{	if(RI)
	{	RI=0;
		arr[c]=SBUF;
		if(arr[c]=='#')
		{	flag=1;
			c=0;
		}
		else
			c++;
	}
}

void main()
{	char str[]="WELCOME";
	lcdinit();
	cmdwrt(0x84	);
	strwrt(str);
	cmdwrt(0xC0);
	
	TMOD=0x20;
	SCON=0x50;
	TH1=-3;
	TR1=1;
	IE=0x90;
	SBUF=arr[0];
	while(1)
	{	if(flag)
		{	cmdwrt(0xC0);
			strwrt(arr);
			flag=0;
		}
	}
}