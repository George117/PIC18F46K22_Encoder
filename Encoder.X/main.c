/*
 * File:   main.c
 * Author: georg
 *
 * Created on October 27, 2018, 11:53 AM
 */

#define _XTAL_FREQ 64000000
#include <xc.h>
#include "bit_settings.h"
#include "config.h"
#include "interrupt.h"
#include "encoder.h"

unsigned quantity = 0;


void main(void) {
    
    config();
    while(1)
    {
        if((quantity%2)==1)
        {
        
            LATDbits.LATD0=1;
            __delay_ms(10);
            LATDbits.LATD0=0;
            __delay_ms(10);
        
        }
        
        if((quantity%2)==0)
        {
            LATDbits.LATD0=1;
            __delay_ms(1);
            LATDbits.LATD0=0;
            __delay_ms(1);
        
        }
    }
    return;
}
