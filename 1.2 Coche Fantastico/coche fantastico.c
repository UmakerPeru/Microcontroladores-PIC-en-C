/* 
 * File:   coche fantastico.c
 * Author: Christian QC
 *
 * creado el 1 de enero de 2019, 10:44 PM
 * 
 * Una mas de led"s jeje!!!¿quien no vio la serie de tv del coche fantastico??
 * ¿quien no soño algun dia con tener uno?¿quien no hablo alguna que otra vez al 
 * volante del coche haber si le respondia Kit?? pues el siguiente ejemplito va 
 * dedicado a las luces del coche fantastico, ese movimiento de un lateral a 
 * otro y viceversa:
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"

/*
 *  Barrido de leds simulando la iluminación del coche fantastico
 *  por el puerto B
 *          RB0 -> 1 LED
 *          RB1 -> 2 LED
 *          RB2 -> 3 LED
 *          RB3 -> 4LED
 */
void derecha(); //declaración de la función derecha
void izquierda();

void main() {
    TRISB=0b00000000;
    PORTB=0b00000000;// Limpiamos el puerto B
    while (1)
    { derecha();
      izquierda();
    }
   }

void derecha()
{ RB0=1;
  __delay_ms(300);
  RB0=0;
  RB1=1;
  __delay_ms(300);
  RB1=0;
  RB2=1;
  __delay_ms(300);
  RB2=0;
  RB3=1;
  __delay_ms(300);
}

void izquierda()
{RB3=0;
 RB2=1;
 __delay_ms(300);
 RB2=0;
 RB1=1;
 __delay_ms(300);
 RB1=0;
}
