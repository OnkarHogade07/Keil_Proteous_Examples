#include<reg51.h>

sbit R1=P3^0;
sbit R2=P3^1;
sbit R3=P3^2;
sbit R4=P3^3;
sbit C1=P3^4;
sbit C2=P3^5;
sbit C3=P3^6;
sbit C4=P3^7;

sbit L1=P0^0;
sbit L2=P0^1;
sbit L3=P0^2;
sbit L4=P0^3;
sbit L5=P0^4;
sbit L6=P0^5;
sbit L7=P0^6;
sbit L8=P0^7;


char scan_keys()
{
	  P3=0xFF;
	
		R1=0;
		if(C1==0)				return 1;
		else if(C2==0)	return 2;
		else if(C3==0)	return 3;
		else if(C4==0)	return 4;
		R1=1;
	
		R2=0;
		if(C1==0)				return 5;
		else if(C2==0)	return 6;
		else if(C3==0)	return 7;
		else if(C4==0)	return 8;
		R2=1;
	
		R3=0;
		if(C1==0)				return 9;
		else if(C2==0)	return 10;
		else if(C3==0)	return 11;
		else if(C4==0)	return 12;
		R3=1;
		
		R4=0;
		if(C1==0)				return 13;
		else if(C2==0)	return 14;
		else if(C3==0)	return 15;
		else if(C4==0)	return 16;
		R4=1;
		
		return 'X';
}


void main ()
{
	char key;
	
	while(1)
	{
			do
			{
					key=scan_keys();
			}while(key=='X');
			
		  P2=key;	
	}
	P0=0x00;
	
	if(key==1)			L1=1;
	else if(key==2) L2=2;
		
}