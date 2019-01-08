/* 
 * File:   Contador 0 a 9 reversisble 7seg.c
 * Author: Christian QC
 *
 * Creado el 3 de enero de 2019, 02:23 AM
 * 
 * Ya que sabemos contar del 0 al 9 y del 9 al 0 
 * mediante el display 7 segmentos.....
 * esta vez el ejemplito propuesto es incorporarle 
 * un switch por el RD0 y si dicho switch esta 
 * abierto el contador sera ascendente(del 0 al 9) y si esta 
 * cerrado el switch el contador sera descendente(del 9 al 0)....
 * aqui el codigo:
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"
/*
 * 
 */
void main() {
   
   TRISB=0b00000000;
   TRISD=0b00000001; //el RD0 es entrada de pulsador
   int DISPLAY[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; //7seg hex 0-9
   int i=0; 
  while (1)
  { 
      if(RD0==1 & i <= 9)
      { PORTB=DISPLAY[i];
        __delay_ms(500);
        i++;
        if(i==10) 
        {i=0;}
      }
      else if( RD0 == 0 & i >=0)
      { PORTB=DISPLAY[i];
        __delay_ms(500);
        i--;       
        if(i==-1)
        {i=9;}
      }
      
      
  } 
   // El que no sabe lo que busca no entiende lo que encuentra ;)
}
