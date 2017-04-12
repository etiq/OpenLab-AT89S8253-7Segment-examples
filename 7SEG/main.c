/*
PROJECT Name: LED
Author      : Etiq Technologies
Created on  :16 April 2016
Description:  The Project is a demo project for interfacing 7segment displays 
              with AT89S8253 microcontroller .4 seven segment displays are 
							interfaced with port0 as the data port and port2 as the control 
							port.delay library and seven segment library file is included to 
							generate an up counter counting from 0-9999.with a delay of 1 sec.
							

*/


#include <REG8253.H>
#include "7seg.h"
#include "delay.h"

unsigned char j=0;         //count to count the timer overflows to generate 1 sec delay

/* Interrupt is enabled for timer1 and for every overflow of the timer1 count is incremented */
	 
void timer1(void) interrupt 3 //interrupt subroutine  
{
j++;
}


void main (void)
{
unsigned int i;
/*Enable the timer1 interrupt */
	
ET1=1;               //timer1 interrupt enable
EA=1;                //global interrupt enable
	

/*infinite loop*/
	
while(1)
 {
	/*counter loop for displaying from 0-9999*/	
		for(i=0;i<9999;i++)
		{
TMOD=0x11;              //setting timer 1 in mode1

/*timer1 register is loaded with calculated values to generate delay of 25ms such that 
40 multiples of overflows can create 1 sec delay*/	
			
TL1=0XCB;          //LSB of the value in lower byte register     
TH1=0x7D;          //MSB of the value in higher byte register
			
TR1=1;             //start timer1  
j=0;           //pre load the counter with 0
			
			
while(j<40)       //loop for 1 sec delay
{	
display_4digitnum(i);	 //display the counter variable 
}
	}
}
	}

/*=============================================================================
=============================================================================*/

