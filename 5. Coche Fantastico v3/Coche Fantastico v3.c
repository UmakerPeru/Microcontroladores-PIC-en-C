/* 
 * File:   Coche Fantastico v3.c
 * Author: Christian QC
 *
 * Creado el 2 de enero de 2019, 11:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"
/* 
 *  Notas: Barrido de led"s simulando la iluminacion del coche fantastico por el
 *  puerto B.
 * 
 *  RB0 -> 1º Led       RB4 -> 5º Led
 *  RB1 -> 2º Led       RB5 -> 6º Led
 *  RB2 -> 3º Led       RB6 -> 7º Led
 *  RB3 -> 4º Led       RB7 -> 8º Led
 * 
 *  En la variable cont se va almacenando los valores 1-2-4-8-16-32-64-128
 *  que en binario corresponden a la secuencia 00000001-00000010-00000100...
 *  que son los led"s a iluminar, coincidiendo con la secuencia de iluminación
 *  del coche fantastico(version peruana: auto fantastico)
 */
void main() {
    TRISB=0b00000000;
    PORTB=0b00000000;
    while(1)
    {    for(int i=1; i<=128 ; i=i*2)
        { PORTB=i;
          __delay_ms(300);
        }
         
        for(int i=64 ; i>=2;i=i/2)
        { PORTB=i;
          __delay_ms(300);
        }
    }
   
}
