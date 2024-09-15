#include<reg51.h>

sbit R1=P3^0;
sbit R2=P3^1;
sbit R3=P3^2;
sbit R4=P3^3;
sbit C1=P3^4;
sbit C2=P3^5;
sbit C3=P3^6;
sbit C4=P3^7;

char arr[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40, 0x00};
char pass[]={1,2,3,4};

void delay(unsigned long int d)
{	
	while(d--);
}

void unlock(void)
{
	  char i=0;
		do
		{
				P2=arr[i];
				i++;
			  delay(7000);
		}while(i<9);
}

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
void main ()
{
		
		char key;
	
		do
		{
			while(1)
			{
				key=key_scan();
			}while(key=='X');
      			
		}
		
		if(key==pass[0])
		{
				do
			{
				while(1)
				{
						key=key_scan();
				}while(key=='X');			
			}
			
			if(key==pass[1])
			{
					do
				{
					while(1)
					{
							key=key_scan();
					}while(key=='X');			
				}
			if(key==pass[2])
			{
					
			}
			}
			
		}
		
		