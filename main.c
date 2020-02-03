#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>

void main(void)
{
    DDRB |= (1 << 4);

    for(;;) {
        PORTB |= (1 << 4);
        _delay_ms(1000);
        PORTB &= ~(1 << 4);
        _delay_ms(1000);
    }
}

