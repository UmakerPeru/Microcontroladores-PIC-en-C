/* 
 * File:   Pulsador con led.c
 * Author: Christian QC
 *
 * Creado el 2 de enero de 2019, 02:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"
/*
 * Utilizando una estructura condicional "if" podemos leer un pulsador 
 * conectado en RB1 para encender o apagar un LED en el pin RB0.
 */
void main() {

    TRISB=0b00000010; // RB1 es la unica entrada
    PORTB=0b00000000; // limpia el puerto B excepto las salidas
            while(1)
            { if(RB1==0) // el pulsador conectado en RB1 esta presionado?
               {RB0=1;   // enciende el led conectado en RB0
               __delay_ms(20); //tiempo de espera hasta q asiente el valor (antirebote)
               }
              else
               {RB0=0; //apaga el led
               __delay_ms(20);
               }
            }

}
//"No se puede pactar con las dificultades, o las vencemos o nos vencen" ;)
