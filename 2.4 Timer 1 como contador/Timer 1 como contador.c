/* 
 * File:   Timer 1 como contador.c
 * Author: Christian QC
 *
 * Creado on 18 de enero de 2019, 01:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"

void main() {
    TRISDbits.TRISD1=0;//el pin RD1 generara la señal que entrara al pin TICKI
                       
    PORTDbits.RD1=0;// inicia apagado
    TRISB=0;//Puerto B como salida para ver indirectamente los incrementos de TMR1
    PORTB=0;//El puerto B se inicia a 0
    
    T1CON=0b00000111;// ----/----/T1CKPS1/T1CKPS0/T1OSCEN/~T1SYNC/TMR1CS/TMR1ON     timer1 pic como contador asíncrono
    TMR1=0;//se inicia a 0
    
    while(1){//ciclo de programa
        if(TMR1==0){//cuando el timer1 se ponga a 0, todos los leds del
        PORTB=0;//puerto B se apagan
        }
        
        switch(TMR1){//observa los valores que va tomando TMR1
            case 8000://cuando el registro tmr1 es 8000
                PORTB=0b00000001;
                break;
            case 16000://cuando el registro tmr1 es 16000
                PORTB=0b00000011;
                break;
            case 24000://cuando el registro tmr1 es 24000
                PORTB=0b00000111;
                break;
            case 32000://cuando el registro tmr1 es 32000
                PORTB=0b00001111;
                break;
            case 40000://cuando el registro tmr1 es 40000
                PORTB=0b00011111;
                break;
            case 48000://cuando el registro tmr1 es 48000
                PORTB=0b00111111;
                break;
            case 56000://cuando el registro tmr1 es 56000
                PORTB=0b01111111;
                break;
            case 60000://cuando el registro tmr1 es 60000
                PORTB=0b11111111;
                break;
        }
         
      
        PORTD^=(1<<1);//El pin RD1 se coloca sobre la entrada TICKI 
                      //de esta forma se logra enviar altos y bajos al pin T1CKI
    }                  
   
}

