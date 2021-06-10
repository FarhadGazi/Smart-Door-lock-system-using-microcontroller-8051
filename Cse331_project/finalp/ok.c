#include<reg51.h>
#include<string.h>
sbit RS = P3^0;
sbit EN = P3^1;
sbit IN1 =P3^2;
sbit IN2 = P3^3;
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<255;j++);
}
void cmd(char cm)
{
	P2 = cm;
	RS = 0;
	EN = 1;
	delay(1);
	EN = 0;
}
void dat(char dt)
{
	P2 = dt;
	RS = 1;
	EN = 1;
	delay(1);
	EN = 0;
}

void display(char *lcd)
{
	while(*lcd != '\0')
	{
		dat(*lcd);
		lcd++;
	}
}
void lcdint()
{
	cmd(0x01);
	cmd(0x38);
	cmd(0x0E);
	cmd(0x80);
	
}

void main()
{
	char pass[5] = "1234";
	char pass2[5];
	int i=0;
	char *ptr;
	ptr = pass2;
	lcdint();
	display("Password-");
	pass2[4]='\0';
		
		while(1)
		{
		while(i<4)
	{
		P1=0xFE;
		if(P1==0xEE)
		{
			*(ptr+i)='7';
			dat('7');
			delay(200);
			cmd(0x06);
			
			i++;
			
		}
		else if(P1==0xDE)
		{
			*(ptr+i)='8';
			dat('8');
			delay(200);
			cmd(0x06);
			
			i++;
			
		}
		else if(P1==0xBE)
		{
			*(ptr+i)='9';
			dat('9');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0x7E)
		{
			*(ptr+i)='/';
			dat('/');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		
	
		P1=0xFD;
		if(P1==0xED)
		{
			*(ptr+i)='4';
			dat('4');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0xDD)
		{
			*(ptr+i)='5';
			dat('5');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0xBD)
		{
			*(ptr+i)='6';
			dat('6');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if (P1==0x7D)
		{
			*(ptr+i)='*';
			dat('*');
			delay(200);
			cmd(0x06);
			
			i++;
		}
	
	
		P1=0xFB;
		if(P1==0xEB)
		{
			*(ptr+i)='1';
			dat('1');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0xDB)
		{
			*(ptr+i)='2';
			dat('2');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0xBB)
		{
			*(ptr+i)='3';
			dat('3');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0x7B)
		{
			*(ptr+i)='-';
			dat('-');
			delay(200);
			cmd(0x06);
			
			i++;
		}
	
	
	
		P1=0xF7;
		if(P1==0xE7)
		{
			*(ptr+i)='C';
			dat('C');
			delay(200);
			cmd(0x06);
			
			i++;
			
		}
		else if(P1==0xD7)
		{
			*(ptr+i)='0';
			dat('0');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0xB7)
		{
			*(ptr+i)='=';
			dat('=');
			delay(200);
			cmd(0x06);
			
			i++;
		}
		else if(P1==0x77)
		{
			*(ptr+i)='+';
			dat('+');
			delay(200);
			cmd(0x06);
			
			i++;
		}
	}

while(i==4)
{

if ((strcmp(pass, pass2)) == 0)
{
	cmd(0xC0);
	display("Correct");
	IN1 = 1;
	IN2 = 0;
	delay(100);	
}
else
{
	cmd(0xC0);
	display("Incorrect");
	IN1 = 0;
	IN2 = 0;
	delay(100);
}
}
}
	}