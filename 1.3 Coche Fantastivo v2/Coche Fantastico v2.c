/* 
 * File:   Coche Fantastico v2.c
 * Author: Christian QC
 *
 * Creado el 2 de enero de 2019, 01:42 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 *  Barrido de leds simulando la iluminación del coche fantastico
 *  por el puerto B por el metodo de desplazamiento de bits
 *          RB0 -> 1 LED
 *          RB1 -> 2 LED
 *          RB2 -> 3 LED
 *          RB3 -> 4LED
 */
void main() {
    TRISB=0b00000000;
    PORTB=0b00000001; //Led RB0 a iluminar
    while(1) 
  {
    
        while(PORTB<=7)
      { __delay_ms(300);
        PORTB=PORTB<<1; //desplaza un bit a la izquierda
      }    
       
         while(PORTB >=2)
      { __delay_ms(300);
        PORTB=PORTB>>1; //desplaza un bit a la derecha
      }    
  }     
}
