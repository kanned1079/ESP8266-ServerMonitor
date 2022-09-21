#include <ioCC2530.h>
#include <string.h>

#define	uint unsigned int
#define	uchar unsigned char

#define LED1 P1_0
#define LED2 P1_1

void Delay_ms(uint); 
void initUART(void);
void UartSend_String(char *Data,int len);

char Txdata[14];	

void Delay_ms(uint n)
{
  uint i,j; 
  for(i=0;i<n;i++)
    { 
      for(j=0;j<1774;j++);
    }
}

void IO_Init()
{
  P1DIR = 0x01;	
  LED1 = 1;	
}

void InitUART(void)
{
  PERCFG = 0x00;	

  P0SEL = 0x0c;	
  P2DIR &= ~0XC0;	

  U0CSR |= 0x80;	
  U0GCR |= 11;
  U0BAUD |= 216;	
  UTX0IF = 0;	
}
void UartSend_String(char *Data,int len)
{
  int j; for(j=0;j<len;j++)
  {
    U0DBUF = *Data++; while(UTX0IF == 0);
    UTX0IF = 0;
  }
}

void main(void)
{
  CLKCONCMD &= ~0x40;	
  while(CLKCONSTA & 0x40);	
  CLKCONCMD &= ~0x47;	
 
  IO_Init(); 
  InitUART();
  strcpy(Txdata,"HelloWorld");
  while(1)
  {

    UartSend_String(Txdata,sizeof("HelloWorld"));	
    Delay_ms(80);
    LED1=!LED1;	
  }
}
