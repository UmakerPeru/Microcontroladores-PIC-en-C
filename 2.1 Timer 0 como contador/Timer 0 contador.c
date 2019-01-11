/* 
 * File:   Timer 0 contador.c
 * Author: Christian QC
 *
 * Creado el 10 de enero de 2019, 04:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 * 
 */
void main() {
    TRISB=0;//Puerto B como salida para ver los valores del registro TMR0 en binario
    PORTB=0;//El puerto B se inicia a 0
    
    OPTION_REG=0b10101000;//timer0 pic como contador, por flanco de subida
    TMR0=0;//El timer0 PIC se inicia a 0 para comenzar a contar
    
    while(1){//ciclo de programa
        PORTB=TMR0;//al puerto B se le asigna el valor del registro TMR0
        __delay_ms(200);//Pausa para ver mejor los valores
    }
}
