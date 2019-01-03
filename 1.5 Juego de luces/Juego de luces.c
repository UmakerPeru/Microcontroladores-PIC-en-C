/* 
 * File:   Juego de luces.c
 * Author: Christian QC
 *
 * Creado el 2 de enero de 2019, 12:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
 

void main() {
    TRISB=0b00000000;
    PORTB=0b00000000; 
    while(1)
    {   int led[]={0b10000001,0b01000010,0b00100100,0b00011000}; 
       
        for(int i=0; i<=2 ;i++)
        { PORTB=led[i];
          __delay_ms(300);
        }
     
        for(int i=3; i>=1;i--)
        { PORTB=led[i];
         __delay_ms(300);
        }  
}
    
}
//Despacito pero sin pausa! ;)
