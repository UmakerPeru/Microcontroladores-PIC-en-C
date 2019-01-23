/* 
 * File:   Interrupcion por puerto B.c
 * Author: Christian QC
 *
 * Creado el 22 de enero de 2019, 11:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
#include <stdint.h> // para el uint8_t
/*
 * 
 */
void main() {
  
    TRISB=0b00010000;
    /*TRISB|=(1<<4) RB4 entrada TRISBbits.TRISB4=1
     *TRISB&=~(1<<0) RB0 salida  TRISBbits.TRISB4=0
     */
    PORTB=0b00000000;
    /*Limpia todos excepto el que el RB4
     *PORTB&=~(1<<0) PORTBbits.RB0=0
     */
     TRISC=0b0001000; //RC4 salida de led
     //TRISC&=~(1<<4) RC4 salida de led
     PORTC=0b00010000;
     //PORTC&=~(1<<4);
     OPTION_REG= 0b00000000;// OPTION_REGbits.nRBPU=0  ~RBPU/INTEDG/T0CS/T0SE/PSA/PS2/PS1/PS0
     INTCON=0;//Limpia el registro INTCON
     INTCON = 0b10001000;//GIE/PEIE/TMR0IE/INTE/RBIE/TMR0IF/INTF/RBIF

             while(1)
             {
                 //nada en el ciclo principal del programa
              }
}

__interrupt() void pinb(void){
    if(RBIF==1){//si la bandera se pone a 1
        uint8_t a;//variable donde se almacena
        a=PORTB;//el valor leido del puerto B
                //necesario para las interrupciones
        PORTC^=(1<<4);//cambia el estado del PIN RC4
        while(RB4==0);//mientras este llegando
        __delay_ms(30);//un 0 al pin RB4 , estas ultimas 4
        while(RB4==0);//lineas de codigo son para
        __delay_ms(30);//que los rebotes no afecten
        
        RBIF=0;// se pone la bandera a 0 para que 
               //siga detectando interrupciones
    }
}
