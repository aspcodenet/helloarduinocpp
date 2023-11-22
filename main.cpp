#include <avr/io.h>
#include <util/delay.h>
#include "Pin.h"

// ARDUINO NR 10
// PORTB + pinne 2


// ARDUINO UNO 0
// PORTD + pinne 0

// https://wokwi.com/projects/365047092561218561
// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)




int main(){
    //init
 
    Pin thePin(Pin::PORT::PINPORT_B, 2); 
    thePin.setOutput();
//    Pin thePin2(PORTB, 3);

    while(1){
       // SÄTTA pinnen
       thePin.on();
       _delay_ms(1000);
        // CLEARA pinnen
       thePin.off();
       _delay_ms(1000);
    }
    return 0; 
}

