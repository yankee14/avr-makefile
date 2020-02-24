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

};

#endif

