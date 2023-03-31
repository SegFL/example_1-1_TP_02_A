#include "mbed.h"
#include "arm_book_lib.h"






int main()
{
   //DigitalIn gasDetector(D2);

    //Declaro una variable del tipo gpio_t de nombre gasDetector y la inicializo con gpio_ini_in_ex con el pin 
    // al que estara conectada y el modo en el cual la inicializo
   gpio_t gasDetector;
   gpio_init_in_ex(&gasDetector, D2,PullDown);



    //DigitalOut alarmLed(LED1);
    
    //Declaro e inicializo una variable del tipo gpio_init_out en el pin LED1(definido en PinNames.h como PB0
    //para este micro en particular)
    gpio_t alarmLed;
    gpio_init_out(&alarmLed, LED1);

    //gasDetector.mode(PullDown);

    
    //alarmLed = OFF;
    gpio_write(&alarmLed, OFF);

    while (true) {
        if ( gasDetector == ON ) {
            gpio_write(&alarmLed, ON);  //para cambiar el valor de alarmLed tengo que usar
                                        // la funcion gpio_write
        }
        
        if ( gasDetector == OFF ) {
            gpio_write(&alarmLed, ON);
        }
    }
}