#include<reg51.h>

sbit R1=P3^0;
sbit R2=P3^1;
sbit R3=P3^2;
sbit R4=P3^3;
sbit C1=P3^4;
sbit C2=P3^5;
sbit C3=P3^6;
sbit C4=P3^7;


sbit RS=P2^0;
sbit EN=P2^1;

char key_scan()
{
		P3=0xFF;
		
		R1=0;
	
		if(C1==0)					return 7;
		else if(C2==0)		return 8;
		else if(C3==0)		return 9;
		else if(C4==0)		return '-';
		R1=1;
	
	  R2=0;
	
		if(C1==0)					return 4;
		else if(C2==0)		return 5;
		else if(C3==0)		return 6;
		else if(C4==0)		return '*';
		R2=1;
	
	  R3=0;
	
		if(C1==0)					return 1;
		else if(C2==0)		return 2;
		else if(C3==0)		return 3;
		else if(C4==0)		return '-';
		R3=1;
		
		R4=0;
	
		if(C1==0)					return 'O';
		else if(C2==0)		return 0;
		else if(C3==0)		return '=';
		else if(C4==0)		return '+';
		R4=1;
		
		return 'X';
}

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

void main ()
{
    char key;
		bit s=0;
		lcdinit();
		cmdwrt(0x80);
   
    
	
		do
		{	
			
			if(b=1)
			{
				
				key=key_scan();
			
				if(key!='X')
				{
						datawrt(48+key);
						
				}
				else
				{
						datawrt(' ');

				}
				
			
				
				
			
		}while(key!='X');
		
	

    
}


