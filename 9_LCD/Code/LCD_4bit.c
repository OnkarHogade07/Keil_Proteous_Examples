#include<reg51.h>
sbit RS=P2^0;
sbit EN=P2^1;

void delay(unsigned int d)
{	while(d--);
}
void cmdwrt(unsigned char cmd)
{	P0=(P0 & 0xF0) | (cmd >> 4);
	RS=0;
	EN=1;	delay(100);
	EN=0; delay(100);

	P0=(P0 & 0xF0) | (cmd & 0x0F);
	RS=0;
	EN=1;	delay(100);
	EN=0; delay(100);
}
void datawrt(unsigned char dat)
{	P0=(P0 & 0xF0) | (dat >> 4);
	RS=1;
	EN=1;	delay(100);
	EN=0; delay(100);

	P0=(P0 & 0xF0) | (dat & 0x0F);
	RS=1;
	EN=1;	delay(100);
	EN=0; delay(100);
}
void strwrt(unsigned char *ptr)
{	for(	; *ptr!=0; ptr++)
		datawrt(*ptr);
}
void lcdinit()
{	cmdwrt(0x33);	//LCD Initialization in 8-bit mode.
	cmdwrt(0x32);	//LCD Initialization in 8-bit mode.
	cmdwrt(0x28);	//LCD Initialization in 8-bit mode.
	cmdwrt(0x0E);	//Display ON, Cursor ON
	cmdwrt(0x06);	//Cursor Autoincrement
	cmdwrt(0x01);	//Clear LCD
	delay(1000);
}
void main()
{	char str[]="EMBEDDED SYSTEM";
	lcdinit();
	cmdwrt(0x80	);
	strwrt(str);
	cmdwrt(0xC0);
	strwrt("CDAC");
	datawrt(49);
	datawrt(0x37);
	datawrt(70);
	datawrt(0x7A);
	while(1);
}