/* 
 * File:   Timer 2 como temporizador.c
 * Author: Christian QC
 *
 * Creado el 22 de enero de 2019, 02:42 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 * 
 */
void main() {
int contador=0;//variable auxiliar para lograr los 100ms con el timer2 PIC
    TRISBbits.TRISB7=0;//pinRB7 como salida digital, se colocará el led
    PORTBbits.RB7=0;//El led se inicia apagado y parpadea cada 100ms
    
    T2CON=0b01111110;// timer2 pic como temporizador prescaler de 16, si no se
                     //usa interrupciones el postcale no influye
    TMR2=0;//se limpia el timer2 PIC
    PR2=250;//para temporizar 4ms
    
    while(1){//ciclo de programa
        if(TMR2==PR2){//cada vez que pasen 4ms la variable auxiliar contador
            contador++;//aumenta en una uindad
        }
        if(contador==25){//cuando contador sea 25 habrán pasado 25*4ms=100ms
            PORTB^=(1<<7);//cada 100ms el pin RB7 cambia de estado
            contador=0;//se vuelve a poner a 0 para que se vuelvan a obtener
        }              //100ms luego de 25 conteos
    }
    
}

