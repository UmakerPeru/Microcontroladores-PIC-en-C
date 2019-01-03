/* 
 * File:   configuracion.h
 * Autor: Christian QC
 *
 * Creado el 1 de enero de 2019, 05:42 PM
 */

#ifndef CONFIGURACION_H
# define 	CONFIGURACION_H

# Ifdef 	__cplusplus
extern  " C " {
#endif

# Definir  _XTAL_FREQ  4000000
    
// PIC16F877A Ajustes de bit de configuración

// declaraciones de configuración de línea de origen 'C'

// CONFIG
# pragma config FOSC = XT         // Bits de selección del oscilador (oscilador XT)
# pragma config WDTE = OFF        // Bit de habilitación del temporizador de vigilancia (WDT desactivado)
# pragma config PWRTE = APAGADO       // Bit de habilitación del temporizador de encendido (PWRT desactivado)
# pragma config BOREN = ON // Bit de habilitación de restablecimiento de salida de red        (BOR habilitado)
# pragma config LVP = APAGADO         // Bit de Habilitación de Programación en Serie de Bajo Voltaje (Suministro Único) (RB3 es E / S digital, HV en MCLR debe usarse para la programación)
# pragma config CPD = OFF         // Bit de protección de código de memoria de datos EEPROM (protección de código de datos EEPROM desactivada)
# pragma config WRT = OFF         // Bits de habilitación de escritura de memoria de programa flash (protección de escritura desactivada; el control EECON puede escribir en toda la memoria de programa)
# pragma config CP = OFF          // Bit de protección de código de memoria de programa flash (Protección de código desactivada)

// Las declaraciones de configuración de #pragma deben preceder a los archivos de proyecto incluidos.
// Use enums de proyecto en lugar de #define para ON y OFF.

# incluye  < xc.h >





# Ifdef 	__cplusplus
}
# endif

#endif	/* CONFIGURACION_H */
