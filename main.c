#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>

#define TRACE

#ifdef TRACE
#include "trace.h"
#include <avr/sleep.h>
#endif

int main(void)
{
    DDRB |= (1 << 4);

    for(uint8_t i = 10; i != 0; --i) {
        PORTB |= (1 << 4);
        _delay_ms(1000);
        PORTB &= ~(1 << 4);
        _delay_ms(1000);
    }

    #ifdef TRACE
    sleep_cpu();
    #endif

    return 0;
}

