#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>

void main(void)
{
    DDRB |= 0x01;

    for(;;) {
        PORTB |= 0x01;
        _delay_ms(1000);
        PORTB &= ~(0x01);
        _delay_ms(1000);
    }
}

