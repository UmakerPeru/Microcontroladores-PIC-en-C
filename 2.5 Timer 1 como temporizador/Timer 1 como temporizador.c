/* 
 * File:   Timer 1 como temporizador.c
 * Author: Christian QC
 *
 * Creado el 19 de enero de 2019, 01:06 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 * 
 */
void main() {

    TRISBbits.TRISB7=0;//pinRB7 como salida digital, se colocará el led
    PORTBbits.RB7=0;//El led se inicia apagado y parpadea cada 500ms
    
    T1CON=0b00110001;// timer1 pic como temporizador prescaler de 8
    TMR1=3035;//se inicia a este valor para obtener 500ms
    
    while(1){//ciclo de programa
        if(TMR1==65535){//cuando el timer1 llegue a este valor habrán pasado 500ms
        PORTB^=(1<<7);//el led en el pin RB7 cambiará de estado cada 500ms
        TMR1=3035;//se carga nuevamente el timer1 pic con este valor
        }         //para seguir obteniendo 500ms
        
    }
}
