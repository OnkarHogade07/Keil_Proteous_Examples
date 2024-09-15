#include<reg51.h>
#define eeprom_addr 0xA0
#define rtc_addr 0xD0

sbit SCL=P2^0;
sbit SDA=P2^1;


void delay(unsigned int d)
{	while(d--);
}

void i2c_start()
{	SDA=1;
	SCL=1;
	while(SCL==0);
	SDA=0;
	SCL=0;
}
void i2c_stop()
{	SDA=0;
	SCL=1;
	while(SCL==0);
	SDA=1;
	SCL=0;
}
void i2c_write(char dat)
{	char c;
	for(c=0; c<8; c++)
	{	if(dat & 0x80 == 0x80)
			SDA=1;
		else	
			SDA=0;
		SCL=1;
		while(SCL==0);
		SCL=0;		
		dat=dat<<1;
	}
	delay(5000);
}
void i2c_ack()
{	SDA=1;
	SCL=1;
	while(SCL==0);
	SCL=0;
	SDA=0;
}
	
void rtc_write(char addr, char dat)
{	i2c_start();
	i2c_write(rtc_addr);
	i2c_ack();
	i2c_write(addr);
	i2c_ack();
	i2c_write(dat);
	i2c_ack();
	i2c_stop();	
}
/*
void eeprom64_write(int addr, char dat)
{	i2c_start();
	i2c_write(eeprom_addr);
	i2c_ack();
	i2c_write(addr/256);
	i2c_ack();
	i2c_write(addr%256);
	i2c_ack();
	i2c_write(dat);
	i2c_ack();
	i2c_stop();	
}
*/
void main()
{	delay(500000);
	delay(500000);
//	eeprom64_write(0x0000,'A');
	while(1)
		rtc_write(0x39,'A');
}