#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    /*
    gasDetector(D2) es un constructor por parametro que devuelve un objeto del tipo DigitalIn
    esde embeb
    la clase DigitalIn crea un gpio() y luego lo inicializa con el pin D2
    esto llama a un metodo de gpip que inicializa el pin con los abjetos PinName y PinMode
    y lo configura como entrada
    esto intermamente si el pin no estaa en unso busca el puerto asociado al pin y 
    te lo configura como entrada
    stm se encarga de poner los valores del pin y de encontrar a que puerto esta asociado(en este caso esta en el puerto F)
*/
    DigitalIn gasDetector(D2); 

/*
    alarmLed(LED1) es un constructor por parametro que devuelve un objeto del tipo DigitalOut
    la clase DigitalOut hereda de gpio, una clase de pin generico abstracta supongo
    hace lo mismo que la clase digitalIn pero cambian las mascaras y otros parametros de cofiguracion
*/
    DigitalOut alarmLed(LED1);

/*
    mode(PullDown) es un metodo de la clase DigitalIn recibe un objeto de la clase PinMode y no devuelve nada
    core_util_... primero chequea que se pueda ejecutar la operacion de pullDown
    se encarga de que no ocurra una itrerrupcion cuando va a habilitar el pulldown
    cueando es seguro llama a la funcion gpio_mode le pasa el pin y le pasa pull
    gpio_mode busca al pin y le cambia el modo
    luego llama a la funcion deabajo para volver a actibar interrrupciones y 
    dejarlo en el estado antes de llamar a este metodo

*/

    gasDetector.mode(PullDown);

    alarmLed = OFF;

    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
            printf("Se prendio la alarma\n");
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
            printf("Se apago la alarma");
        }
    }
}