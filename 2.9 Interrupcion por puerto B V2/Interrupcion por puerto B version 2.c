/* 
 * File:   Interrupcion por puerto B version 2.c
 * Author: Christian QC
 *
 * Creado el 23 de enero de 2019, 03:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "configurador.h"
/*
 * 
 */
void main() {
    TRISB|=(15<<4);//RB4 a RB7  entrada
    TRISB&=~(1<<0);//RB0 salida TRISBbits.TRISB0
    PORTB&=~(1<<0);//PORTBbits.RB0=0
    TRISC&=~(15<<4);//RC4 a RC7  salida de led
    PORTC&=~(15<<4);// RC4 a RC7 apagado
    OPTION_REG= 0b00000000;// OPTION_REGbits.nRBPU=0  ~RBPU/INTEDG/T0CS/T0SE/PSA/PS2/PS1/PS0
    INTCON=0;//limpia el registro INTCON
    INTCON = 0b10001000;//GIE/PEIE/TMR0IE/INTE/RBIE/TMR0IF/INTF/RBIF
    
    while (1) {
        //nada en el ciclo principal del programa
    }
}

__interrupt() void portb(void){
    if(RBIF==1){//si la bandera se pone a 1
        uint8_t a;//variable donde se almacena
        a=PORTB;//el valor leido del puerto B
                //necesario para las interrupciones
        
        if(RB4==0)
            PORTC^=(1<<4);//cambia de estado el RC4
        if(RB5==0)
            PORTC^=(1<<5);//cambia de estado el RC5
        if(RB6==0)
            PORTC^=(1<<6);//cambia de estado el RC6
        if(RB7==0)
            PORTC^=(1<<7);//cambia de estado el RC7
     //las siguientes lineas son para evitar los rebotes
        while((RB4==0)||(RB5==0)||(RB6==0)||(RB7==0))
        __delay_ms(30); 
        while((RB4==0)||(RB5==0)||(RB6==0)||(RB7==0))
         __delay_ms(30); 
        
        RBIF=0;
            
    }
}
