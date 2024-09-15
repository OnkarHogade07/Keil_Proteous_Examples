#include<reg51.h>

sbit RS=P2^0;
sbit EN=P2^1;

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

void main()
{	
		
		
	  lcdinit();
		cmdwrt(0x81);
		datawrt(0x30);
		datawrt(0x31);
		datawrt(0x32);
		datawrt(0x33);
		datawrt(0x34);
		datawrt(0x35);
		datawrt(0x36);
		datawrt(0x37);;
		datawrt(0x38);
		datawrt(0x39);
		
		
		while(1);
		
		
	
		
		
		while(1);
}