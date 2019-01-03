/* 
 * File:   Display descendente 9 a 0.c
 * Author: Christian QC
 *
 * Creado el 2 de enero de 2019, 11:42 PM
 * 
 * Bien el ejemplito de hoy es igual que el anterior, es 
 * decir un contador descendente 9-0 y vuelta a empezar.....digo que 
 * es igual en tema de codigo, solamente cambia algun que otro comando.......aqui esta:
 */

#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"
/*
 * 
 */
void main() {
    TRISB=0b00000000;
    int DISPLAY[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; //7seg hex 0-9
  while (1)
  {    
    for(int i = 9; i>=0 ; i--)
    { PORTB=DISPLAY[i];//muestra por el puerto B los digitos previamente cargados en DISPLAY
      __delay_ms(400);
    }
  } 
}

//Bueno...ya sabemos contar de 0 al 9 y del 9 al 0 por separado....... ;)
