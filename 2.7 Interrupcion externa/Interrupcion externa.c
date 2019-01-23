/* 
 * File:   Interrupcion externa.c
 * Author: Christian Quispe
 *
 * Creado el 22 de enero de 2019, 01:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 * 
 */
void main() {
  TRISBbits.TRISB3=0;//como salida para el led que parpadea cada 200ms
    TRISBbits.TRISB4=0;//par el leda que parpadea mientras
                       //ocurre la interrupción
    PORTBbits.RB3=0;//led inicia apagado
    PORTBbits.RB4=0;//led inicia apagado
    
    INTCONbits.GIE=1;//habilita las interrupciones
    INTCONbits.INTE=1;//habilita el uso de la interrupción externa
    INTCONbits.INTF=0;//bandera a 0 para detectar las
                      //interrupciones externas
 
    OPTION_REGbits.INTEDG=1;//la interrupción externa en el pin ocurrirá 
                            //por flanco de subida
    
    while(1){//ciclo del programa
        PORTB^=(1<<3);//el led en el pin RB3 cambia de estado
        __delay_ms(200);//cada 200ms
    }
    return;
}
 
void delay_ms(unsigned int t){//función para el control de pausas
    for(int i=0;i<t;i++){
        __delay_ms(1);
    }
}
 
__interrupt() void int_ext(){//rutina de atención a las interrupciones
    if(INTCONbits.INTF){//si la bandera de detección de la 
                        //interrrrupción externa se pone a 1
        for(int i=0;i<20;i++){
            PORTB^=(1<<4);//cambia el estado del pin RB4
            __delay_ms(200);
        }
        INTCONbits.INTF=0;//bandera nuevamente a 0 para seguir detectando
                          //interrupciones externas
    }
}


