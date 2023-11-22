#ifndef __PIN_H
#define __PIN_H
#include <stdint.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

class Pin{
public:
    typedef enum {
        PINPORT_A,
        PINPORT_B,
        PINPORT_D
    } PORT;
    Pin(PORT port, uint8_t pin)
    :port(port),pin(pin)
    {
    }

    void on(){
        if(port == PINPORT_B)
            BIT_SET(PORTB,this->pin);
        else if(port == PINPORT_A)
            BIT_SET(PORTC,this->pin);
        if(port == PINPORT_D)
            BIT_SET(PORTD,this->pin);
        
        //BIT_SET(this->port,this->pin);
    }
    void off(){
        if(port == PINPORT_B)
            BIT_CLEAR(PORTB,this->pin);
        else if(port == PINPORT_A)
            BIT_CLEAR(PORTC,this->pin);
        if(port == PINPORT_D)
            BIT_CLEAR(PORTD,this->pin);
    }
    void setOutput(){
        if(port == PINPORT_B)
            BIT_SET(DDRB,this->pin);
        else if(port == PINPORT_A)
            BIT_SET(DDRC,this->pin);
        if(port == PINPORT_D)
            BIT_SET(DDRD,this->pin);
    }
 private:    
    PORT port;
    uint8_t pin;
};

#endif //__PIN_H

