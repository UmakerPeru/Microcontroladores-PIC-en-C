/* 
 * Archivo: led.c
 * Autor: Christian QC
 *
 * Creado el 1 de enero de 2019, 05:42 PM
 * El primer ejemplo como no!!! la iluminacion de un led!!!jeje alguien alguna vez a visto programa similar???jeje 
 * bueno fuera de bromas por alguno hay que empezar y este es el nivel inferior jeje. El programa consiste en el encendido
 * y apagado de un led cada 1s por el pin RB0 del pueto B:
 */

# include  < stdio.h >
# include  < stdlib.h >
# incluye  " configuracion.h "

/*
 *  El registro TRISB (de 8bits) determina la funcion de sus pines , 0 - salida / 1 - entrada
 *  La instrucción RB0 carga al bit RB0 del registro PORTB con el valor que se le añada , 0 - HIGH / 1 - LOW,
 *  También se puede usar alternativamente a RB0 la instrucción PORTBbits.RB0 que hace basicamente lo mismo 
 *  Otra instrucción que haria lo mismo seria PORTB=0b00000001 (para cargar 1 al RB0) Y PORTB=0b00000000(para cargar 0 al RB0)
 *  La diferencia entre RB0/PORTBbits contra PORTB es que los primeros leen todo el registro, 
 *  se modifica el bit y luego se vuelve a escribir todo el registro (RMW para abreviar) lo que puede tardar un tiempo. . 
 */


void  main () {

    TRISB=0b00000000; //RB0 a RB7  como salidas 
    mientras ( 1 )
    { RB0=1; //enciende el RB0
      __delay_ms(1000); //retardo de 1s
      RB0=0; //apaga el RB0
      __delay_ms(1000); //retardo de 1s
    }
    
}
