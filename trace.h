#ifndef _TRACE_H_
#define _TRACE_H_

#include "/usr/local/include/simavr/avr/avr_mcu_section.h"

// simavr trace output filename
AVR_MCU_VCD_FILE("simulation.vcd", 1);

const struct avr_mmcu_vcd_trace_t _mytrace[]  _MMCU_ = {
    // AVR status
	{ AVR_MCU_VCD_SYMBOL("SREG"), .what = (void*)&SREG, },

    // microcontroller status and control
	{ AVR_MCU_VCD_SYMBOL("MCUSR"), .what = (void*)&MCUSR, },
	{ AVR_MCU_VCD_SYMBOL("MCUCR"), .what = (void*)&MCUCR, },

    // 

    // sleep mode control
	{ AVR_MCU_VCD_SYMBOL("SMCR"), .what = (void*)&SMCR, },

    // GPIO
	{ AVR_MCU_VCD_SYMBOL("DDRB"), .what = (void*)&DDRB, },
	{ AVR_MCU_VCD_SYMBOL("DDRC"), .what = (void*)&DDRC, },
	{ AVR_MCU_VCD_SYMBOL("DDRD"), .what = (void*)&DDRD, },

	{ AVR_MCU_VCD_SYMBOL("PORTB"), .what = (void*)&PORTB, },
	{ AVR_MCU_VCD_SYMBOL("PORTC"), .what = (void*)&PORTC, },
	{ AVR_MCU_VCD_SYMBOL("PORTD"), .what = (void*)&PORTD, },

	{ AVR_MCU_VCD_SYMBOL("PINB"), .what = (void*)&PINB, },
	{ AVR_MCU_VCD_SYMBOL("PINC"), .what = (void*)&PINC, },
	{ AVR_MCU_VCD_SYMBOL("PIND"), .what = (void*)&PIND, },

	{ AVR_MCU_VCD_SYMBOL("DIDR0"), .what = (void*)&DIDR0, },
	{ AVR_MCU_VCD_SYMBOL("DIDR1"), .what = (void*)&DIDR1, },

	{ AVR_MCU_VCD_SYMBOL("GPIOR0"), .what = (void*)&GPIOR0, },
	{ AVR_MCU_VCD_SYMBOL("GPIOR1"), .what = (void*)&GPIOR1, },
	{ AVR_MCU_VCD_SYMBOL("GPIOR2"), .what = (void*)&GPIOR2, },

    // EEPROM
	{ AVR_MCU_VCD_SYMBOL("EEARH"), .what = (void*)&EEARH, },
	{ AVR_MCU_VCD_SYMBOL("EEARL"), .what = (void*)&EEARL, },
	{ AVR_MCU_VCD_SYMBOL("EEDR"), .what = (void*)&EEDR, },
	{ AVR_MCU_VCD_SYMBOL("EECR"), .what = (void*)&EECR, },

    // ADC
	{ AVR_MCU_VCD_SYMBOL("ADMUX"), .what = (void*)&ADMUX, },
	{ AVR_MCU_VCD_SYMBOL("ADCSRA"), .what = (void*)&ADCSRA, },
	{ AVR_MCU_VCD_SYMBOL("ADCSRB"), .what = (void*)&ADCSRB, },
	{ AVR_MCU_VCD_SYMBOL("ADCH"), .what = (void*)&ADCH, },
	{ AVR_MCU_VCD_SYMBOL("ADCL"), .what = (void*)&ADCL, },

    // timers
	{ AVR_MCU_VCD_SYMBOL("GTCCR"), .what = (void*)&GTCCR, },
	{ AVR_MCU_VCD_SYMBOL("ASSR"), .what = (void*)&ASSR, },
        // absolute timer/counter values
	{ AVR_MCU_VCD_SYMBOL("TCNT0"), .what = (void*)&TCNT0, },
	{ AVR_MCU_VCD_SYMBOL("TCNT1H"), .what = (void*)&TCNT1H, },
	{ AVR_MCU_VCD_SYMBOL("TCNT1L"), .what = (void*)&TCNT1L, },
	{ AVR_MCU_VCD_SYMBOL("TCNT2"), .what = (void*)&TCNT2, },
        // timer/counter control
	{ AVR_MCU_VCD_SYMBOL("TCCR0A"), .what = (void*)&TCCR0A, },
	{ AVR_MCU_VCD_SYMBOL("TCCR0B"), .what = (void*)&TCCR0B, },
	{ AVR_MCU_VCD_SYMBOL("TCCR1A"), .what = (void*)&TCCR1A, },
	{ AVR_MCU_VCD_SYMBOL("TCCR1B"), .what = (void*)&TCCR1B, },
	{ AVR_MCU_VCD_SYMBOL("TCCR1C"), .what = (void*)&TCCR1C, },
	{ AVR_MCU_VCD_SYMBOL("TCCR2A"), .what = (void*)&TCCR2A, },
	{ AVR_MCU_VCD_SYMBOL("TCCR2B"), .what = (void*)&TCCR2B, },
        // timer/counter output compare
	{ AVR_MCU_VCD_SYMBOL("OCR0A"), .what = (void*)&OCR0A, },
	{ AVR_MCU_VCD_SYMBOL("OCR0B"), .what = (void*)&OCR0B, },
	{ AVR_MCU_VCD_SYMBOL("OCR1AH"), .what = (void*)&OCR1AH, },
	{ AVR_MCU_VCD_SYMBOL("OCR1AL"), .what = (void*)&OCR1AL, },
	{ AVR_MCU_VCD_SYMBOL("OCR1BH"), .what = (void*)&OCR1BH, },
	{ AVR_MCU_VCD_SYMBOL("OCR1BL"), .what = (void*)&OCR1BL, },
	{ AVR_MCU_VCD_SYMBOL("OCR2A"), .what = (void*)&OCR2A, },
	{ AVR_MCU_VCD_SYMBOL("OCR2B"), .what = (void*)&OCR2B, },
        // timer/counter input capture
    { AVR_MCU_VCD_SYMBOL("ICR1H"), .what = (void*)&ICR1H, },
	{ AVR_MCU_VCD_SYMBOL("ICR1L"), .what = (void*)&ICR1L, },
        // timer/counter interrupt masks
	{ AVR_MCU_VCD_SYMBOL("TIMSK0"), .what = (void*)&TIMSK0, },
	{ AVR_MCU_VCD_SYMBOL("TIMSK1"), .what = (void*)&TIMSK1, },
	{ AVR_MCU_VCD_SYMBOL("TIMSK2"), .what = (void*)&TIMSK2, },
        // timer/counter interrupt flags
	{ AVR_MCU_VCD_SYMBOL("TIFR0"), .what = (void*)&TIFR0, },
	{ AVR_MCU_VCD_SYMBOL("TIFR1"), .what = (void*)&TIFR1, },
	{ AVR_MCU_VCD_SYMBOL("TIFR2"), .what = (void*)&TIFR2, },
};

#endif

