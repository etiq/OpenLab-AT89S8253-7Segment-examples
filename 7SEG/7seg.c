#include <REG8253.H>
#include "delay.h"

extern unsigned char seg_code[10]={0xC0,0xf9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x90};
/*SSD code for the digits from 0-9*/

void display_all(unsigned char num)/*function to display a data on all SSD*/
{

    P2=0x0f;
    P0=seg_code[num];
}

void display(unsigned char num,unsigned char seg_num)/*function to display a data on specified SSD*/
{
    if(seg_num==1)
    {
        P2=0x08;
        P0=seg_code[num];
    }
    else if(seg_num==2)
    {
       P2=0x04;
       P0=seg_code[num];
    }
    else if(seg_num==3)
    {
        P2=0x02;
        P0=seg_code[num];
    }
    else if(seg_num==4)
    {
        P2=0x01;
        P0=seg_code[num];
    }
}

void display_4digitnum(unsigned int num) /*function to display a 4digit data on SSD*/
{
    unsigned char i=0,j,a;
    a=0x01;
    while(i<4)
    {
      j=num%10;
      num=num/10;
      P2=a;
      P0=seg_code[j];
			P3=0;
      Delay_us(3000);
			P3=1;
      a=a<<1;
      i++;  
    }
    }