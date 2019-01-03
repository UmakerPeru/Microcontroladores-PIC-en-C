/* 
 * File:   Display ascendente 0 a 9.c
 * Author: Christian QC
 *
 * Creado el 2 de enero de 2019, 10:36 PM
 *
 *  Este ejemplito se basa en hacer un contador ascendente del 0 al 9 y volver a 
 *  empezar, para ello trabajaremos con el display 7segmentos de catodo comun
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"


void main() {
    TRISB=0b00000000;
    int DISPLAY[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; //7seg hex 0-9
  while (1)
  {    
    for(int i = 0; i<=9 ; i++)
    { PORTB=DISPLAY[i];//muestra por el puerto B los digitos previamente cargados en DISPLAY
      __delay_ms(400);
    }
  } 
}

//"No se puede pactar con las dificultades, o las vencemos o nos vencen" ;)
