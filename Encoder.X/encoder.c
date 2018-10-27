/*
 * File:   encoder.c
 * Author: georg
 *
 * Created on October 27, 2018, 12:00 PM
 */


#include <xc.h>
#include "bit_settings.h"
#include "encoder.h"

#define R1A LATBbits.LATB5 	// encoder 
#define R1B LATBbits.LATB4

extern unsigned quantity;

void enc_change()
{
    	unsigned char state_1;
	static unsigned char oldstate_1;  // this variable need to be static as it has to retain the value between calls
	__delay_ms(1); 				//	delay for 1ms here for debounce
	state_1= R1B<<1 | R1A;			//  combine the pin status and assign to state variable
	if(oldstate_1==0x0){
	if( state_1 ==0x1)
	{   
        quantity++;
	}
    else if( state_1 == 0x2)
	{  
        quantity--;
	}

	}
	oldstate_1 = state_1;				// store the current state value to oldstate value this value will be used in next call

	PORTB = PORTB;					// read or Any read or write of PORTB,This will end the mismatch condition
   
	INTCONbits.RBIF = 0; 			// clear the porb change intrrupt flag
    
}


void enc_setup()
{
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    INTCONbits.RBIE=1;//INT
    INTCON2bits.RBIP=1;
    IOCB=0xf0;//ENC INT
    PORTB=0x00;
    PORTD=0x00;
    TRISD=0X00;
    TRISBbits.RB4=1;
    TRISBbits.RB5=1;//ENC
}