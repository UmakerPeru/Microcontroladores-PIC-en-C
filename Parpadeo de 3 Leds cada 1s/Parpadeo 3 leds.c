/* 
 * File:   Parpadeo 3 leds.c
 * Author: Christian QC
 *
 * Creado el 1 de enero de 2019, 09:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"
/*
 * Aqui otro ejemplito mas de led"s, esta vez como encender tres 
 * leds por el puerto b de tres formas distintas...asi podran elegir
 *  la que les guste más jeje:
 */
void main() {
    TRISB=0b00000000; // puerto B como entrada
    PORTB=0b00000000; // Limpia el puerto B (inician apagados)
    while(1)
    { 
        PORTBbits.RB0=1;
        __delay_ms(1000);
        PORTBbits.RB0^=1;
        __delay_ms(1000);
        
        RB1=1; 
        __delay_ms(1000);
        RB1=0;
        __delay_ms(1000);
        
        RB2=!RB1; // RB2 es igual a la negación logica de RB1
        __delay_ms(1000);
        RB2=RB1;
        __delay_ms(1000);
                    
    }   
}
// Ya vamos manejando esto de los led"s jeje..... :)
