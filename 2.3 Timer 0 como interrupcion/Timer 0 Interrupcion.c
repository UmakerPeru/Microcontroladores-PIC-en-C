/* 
 * File:   Timer 0 Interrupcion.c
 * Author: Christian QC
 *
 * Creado el 12 de enero de 2019, 01:57 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "configurador.h"
/*
 * Este ejemplo sencillo se basa en un led conectado a la pin RB0 que parpadea cada 1s usando laa interrupcion por 
 * desbordamiento del timer 0
 */
int cuenta = 0;   // Declaro una variable "cuenta"

// FUNCION DE INTERRUPCION
__interrupt() void MY_ISR(void) {
    cuenta++;                   // Incremento variable
    INTCONbits.TMR0IF = 0;      // Limpiamos bandera de desborde
    TMR0 = 60; // Para obtener un tiempo de 50ms necesitamos un TMR0 = 60
}

void main() {
   
    TRISB = 0;   // Puerto B como salidas
    PORTB = 0;   // inicializamos en 0 el puerto B
 
    // Configuración del timer & interrupcion
    TMR0 = 60; // Para obtener un tiempo de 50ms necesitamos un TMR0 = 60
    INTCON = 0b10100000; //GIE/PEIE/T0IE/INTE/RBIE/T0IF/INTF/RBIF  --> Registro de Interrupciones
    OPTION_REG=0b10000111; // RBPU/INTEDG/T0CS/T0SE/PSA/PS2/PS1/PS0 --> Regitro del timer 0
    // Bucle infinito
    while (1){
        if (cuenta == 20) // esto repetira el retardo de 50ms 20 veces obteniendo 1s
        {
            RB0 ^= 1; // cambia el valor del RB0 de 1 a 0 por cada repeticion  RB0 = ~ RB0
            cuenta = 0;
        }
    }
 // Todos los dias aprendo algo nuevo, el ultimo día de mi vida aprenderé a morir....Mi Abuelo.  
}
