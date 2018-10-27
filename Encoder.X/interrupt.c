/*
 * File:   interrupt.c
 * Author: georg
 *
 * Created on January 1, 2017, 1:56 PM
 */


#include <xc.h> 
#include "encoder.h"

int a=0;

void interrupt enc()
{

    if(INTCONbits.RBIF==1)

    {

         enc_change();
        
    }

    
}