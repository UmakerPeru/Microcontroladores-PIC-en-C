/* 
 * File:   Timer 0 como temporizador.c
 * Author: Christian QC
 *
 * Creado el 11 de enero de 2019, 08:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 * En este ejemplo se ve el uso del timer0
 * como temporizador , se cambia el estado del 
 * pin RD0 cada 50ms, se utilizarán los resultados obtenidos para el 
 * el prescaler del timer0, se obtuvo que para 
 * temporizar 50ms se utiliza el prescaler de 256 y el registro TMR0
 * se tiene que cargar en un inicio con 60, esto es TMR0=60.
 */
void main() {
 
    TRISD=0b00000000;//Pin RD0 como salida digital, aquí se colocará el led
    PORTD=0b00000000;//El led del RD0 se inicia apagado (los demas tambien ;) )
    
    OPTION_REG=0b10000111; //timer0 pic como temporizador, prescaler 256
    TMR0=60; //El led se inicia apagado
    
    while (1)
    { if(TMR0 == 255) //cuando transcurran 50ms
        {PORTD^=(1<<0); //cambia el estado del pin RD0
         TMR0=60; //carga con 60 el timer0 pic para que cada vez que llegue a 255 transcurran 50ms
        }
    }
    
    //Nadie nació sabiendo...Que genio ese Nadie!!!
}

