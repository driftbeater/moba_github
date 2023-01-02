/*
 * main.c
 *
 *  Created on: Mar 29, 2011
 *      Author: gerd
 */

#ifndef F_CPU
#error "F_CPU not defined "
#endif

// fuses should be low FF high C9

#include <avr/io.h>
#include <util/delay.h>
#include "i2cmaster.h"
#include "PCA9555.h"
#include "debounce.h"
#include "basic.h"

const uint8_t ms_per_cycle = 5; // Heart beat. One main loop
const uint8_t cycles_weiche = 100; // 500ms
const uint8_t cycles_taster = 10; // 50ms debouncing
const uint8_t cycles_rueckmelder = 20; // 100ms debouncing for point motor
const uint8_t cycles_ac = 200; // 1s

uint8_t inputDataSlaveA_A;
uint8_t inputDataSlaveA_B;
uint8_t outputDataSlaveA_A = 0;
uint8_t outputDataSlaveA_B = 0;
uint8_t inputDataSlaveB_A;
uint8_t inputDataSlaveB_B;
uint8_t outputDataSlaveB_A;
uint8_t outputDataSlaveB_B;
uint8_t inputDataSlaveC_A;
uint8_t inputDataSlaveC_B;
uint8_t outputDataSlaveC_A = 0;
uint8_t outputDataSlaveC_B = 0;
uint8_t inputDataSlaveD_A;
uint8_t inputDataSlaveD_B;
uint8_t outputDataSlaveD_A = 0;
uint8_t outputDataSlaveD_B = 0;
uint8_t outputDataSlaveE_A;
uint8_t outputDataSlaveE_B;
uint8_t inputDataSlaveE_A;
uint8_t inputDataSlaveE_B;

//void setOnboardLed(uint8_t flag)
//{
//	uint8_t dataPortB = 0;
//	if ( flag )
//	{
//		dataPortB &= ~( 1 << PB1 );
//	}
//	else
//	{
//		dataPortB |= ( 1 << PB1 );
//	}
//	PORTB = dataPortB;
//}
void setOnboardLed(uint8_t flag)
{
	uint8_t dataPortB = 0;
	setBit8u(&dataPortB, PB1, flag);
	PORTB = dataPortB;
}

void setLed1(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_B, PCA9555_B6, flag);
}
void setLed2(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_A, PCA9555_A7, flag);
}
void setLed3(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_B, PCA9555_B0, flag);
}
void setLed4(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A1, flag);
}
void setLed5(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_B, PCA9555_B7, flag);
}
void setLed6(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A0, flag);
}
void setLed7(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_B, PCA9555_B4, flag);
}
void setLed8(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_A, PCA9555_A5, flag);
}
void setLed9(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_B, PCA9555_B4, flag);
}
void setLed10(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A5, flag);
}
void setLed11(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_B, PCA9555_B5, flag);
}
void setLed12(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A6, flag);
}
void setLed13(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_B, PCA9555_B1, flag);
}
void setLed14(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A2, flag);
}
void setLed15(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_B, PCA9555_B2, flag);
}
void setLed16(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A3, flag);
}
void setLed17(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_B, PCA9555_B3, flag);
}
void setLed18(uint8_t flag)
{
	setBit8u(&outputDataSlaveC_A, PCA9555_A4, flag);
}
void setLed19(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_B, PCA9555_B5, flag);
}
void setLed20(uint8_t flag)
{
	setBit8u(&outputDataSlaveD_A, PCA9555_A6, flag);
}

uint8_t getTaster1()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_B, PCA9555_B2);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getTaster2()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_A, PCA9555_A3);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTaster3()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_A, PCA9555_A2);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTaster4()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_B, PCA9555_B1);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getTaster5()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_A, PCA9555_A1);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getTaster6()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveC_B, PCA9555_B7);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getTaster7()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveC_A, PCA9555_A7);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getTaster8()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveC_B, PCA9555_B6);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTaster9()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_A, PCA9555_A4);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getTaster10()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveD_B, PCA9555_B3);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}

uint8_t getWeiche1()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveB_A, PCA9555_A0);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	///return rueckmelder > 0;
	return state > 0;
}

uint8_t getWeiche2()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveB_A, PCA9555_A4);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche3()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveE_A, PCA9555_A0);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche4()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveE_A, PCA9555_A4);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche5()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveE_B, PCA9555_B3);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche6()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveB_A, PCA9555_A3);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche7()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveB_B, PCA9555_B3);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche8()
{
	static int8_t state = 0;
	uint8_t rueckmelder = getBit8u(inputDataSlaveA_B, PCA9555_B3);
	setStateDebounced(cycles_rueckmelder, rueckmelder, &(state));
	return state > 0;
}

uint8_t getWeiche9()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_A, PCA9555_A0);
	setStateDebounced(cycles_rueckmelder, pressed, &(state));
	return state > 0;
}

uint8_t getWeiche10()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_A, PCA9555_A4);
	setStateDebounced(cycles_rueckmelder, pressed, &(state));
	return state > 0;
}

void toggleWeiche1(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveB_B, PCA9555_B7, state);
}
void toggleWeiche2(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveB_A, PCA9555_A7, state);
}
void toggleWeiche3(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveE_B, PCA9555_B7, state);
}
void toggleWeiche4(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveE_A, PCA9555_A7, state);
}
void toggleWeiche5(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveE_B, PCA9555_B6, state);
}


void toggleWeiche6(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveB_A, PCA9555_A6, state);
}
void toggleWeiche7(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveB_B, PCA9555_B6, state);
}
void toggleWeiche8(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveA_B, PCA9555_B6, state);
}
void toggleWeiche9(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &state);
	setBit8(&outputDataSlaveA_B, PCA9555_B7, state);
}

void toggleWeiche10(uint8_t toggle_)
{
	static int8_t state = 0;
	toggleStateDebounced(cycles_weiche, toggle_, &(state));
	setBit8(&outputDataSlaveA_A, PCA9555_A7, state);
}
void setRelaisForAc(uint8_t newState_)
{
	static int8_t state = 0;
	setStateDebounced(cycles_ac, newState_, &state);
	setBit8u(&outputDataSlaveB_B, PCA9555_B5, state);
}

void setEntkuppler1(uint8_t flag)
{
	static int8_t state = 0;
	setStateDebounced(cycles_weiche, flag, &state);
	setBit8u(&outputDataSlaveB_B, PCA9555_B2, state);
}
void setEntkuppler2(uint8_t flag)
{
	static int8_t state = 0;
	setStateDebounced(cycles_weiche, flag, &state);
	setBit8u(&outputDataSlaveB_A, PCA9555_A2, state);
}
void setEntkuppler3(uint8_t flag)
{
	static int8_t state = 0;
	setStateDebounced(cycles_weiche, flag, &state);
	setBit8u(&outputDataSlaveB_B, PCA9555_B1, state);
}
void setEntkuppler4(uint8_t flag)
{
	static int8_t state = 0;
	setStateDebounced(cycles_weiche, flag, &state);
	setBit8u(&outputDataSlaveB_A, PCA9555_A1, state);
}
void setEntkuppler5(uint8_t flag)
{
	static int8_t state = 0;
	setStateDebounced(cycles_weiche, flag, &state);
	setBit8u(&outputDataSlaveB_B, PCA9555_B0, state);
}
uint8_t getTsEnt1()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_A, PCA9555_A3);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTsEnt2()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_B, PCA9555_B2);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTsEnt3()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_A, PCA9555_A2);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTsEnt4()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_B, PCA9555_B1);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}
uint8_t getTsEnt5()
{
	static int8_t state = 0;
	uint8_t pressed = getBit8u(inputDataSlaveA_A, PCA9555_A1);
	// 10 x 5 = 50ms
	setStateDebounced(cycles_taster, pressed, &(state));
	return state > 0;
}



int main()
{
	// init AVR

	// AVR Port B
	// Onboard Led
	// Port B.1 (Pin 15) is Output (Led), all others input
	DDRB = 1 << PB1;

	// fixed part for PCA9555:    0b0100
	// variable part         :          AAA
	// R/W                   :             x
	const uint8_t addressSlaveA = 0b01000000;
	const uint8_t addressSlaveB = 0b01000010;
	const uint8_t addressSlaveC = 0b01000100;
	const uint8_t addressSlaveD = 0b01000110;
	//@todo address 100, not 101
	const uint8_t addressSlaveE = 0b01001000;
	// const uint8_t addressSlaveF = 0b01001010;
	//const uint8_t addressSlaveG = 0b01001100;
	//const uint8_t addressSlaveH = 0b01001110;

	// init I2C library
	i2c_init();

	// Slave A. Input A0, A1, A2, A3, A4,  B0, B1, B2, B3. Others output
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			      addressSlaveA,
			      (1 << PCA9555_A0) |
			      (1 << PCA9555_A1) |
			      (1 << PCA9555_A2) |
			      (1 << PCA9555_A3) |
			      (1 << PCA9555_A4),
			      (1 << PCA9555_B0) |
			      (1 << PCA9555_B1) |
			      (1 << PCA9555_B2) |
			      (1 << PCA9555_B3) );


	// Slave B. Input A0, A3, A4, B3
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			      addressSlaveB,
			      (1 << PCA9555_A0) |
			      (1 << PCA9555_A3) |
			      (1 << PCA9555_A4),
			      (1 << PCA9555_B3) );
	// Slave B. Reverse all inputs
	PCA9555_write(PCA9555_CommandPolarityInversionPortA,
			      addressSlaveB,
			      (1 << PCA9555_A0) |
			      (1 << PCA9555_A3) |
			      (1 << PCA9555_A4),
			      (1 << PCA9555_B3) );


	// Slave C. Input B7, B6, A7. All others output
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			      addressSlaveC,
			      1 << PCA9555_A7 ,
			      (1 << PCA9555_B7) | (1 << PCA9555_B6) );

	// Slave C. Reverse all inputs
	PCA9555_write(PCA9555_CommandPolarityInversionPortA,
	        	  addressSlaveC,
			      1 << PCA9555_A7,
			      (1 << PCA9555_B7) | (1 << PCA9555_B6) );

	// Slave D. Input A0, A1, A2, A3, A4, B0, B1, B2. All others output
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			addressSlaveD,
			(1 << PCA9555_A0) |
			(1 << PCA9555_A1) |
			(1 << PCA9555_A2) |
			(1 << PCA9555_A3) |
			(1 << PCA9555_A4),
			(1 << PCA9555_B0) |
			(1 << PCA9555_B1) |
			(1 << PCA9555_B2) |
			(1 << PCA9555_B3));
	// Slave D. Reverse all inputs
	PCA9555_write(PCA9555_CommandPolarityInversionPortA,
			      addressSlaveD,
			      (1 << PCA9555_A0) |
			      (1 << PCA9555_A1) |
			      (1 << PCA9555_A2) |
			      (1 << PCA9555_A3) |
			      (1 << PCA9555_A4),
			      (1 << PCA9555_B0) |
			      (1 << PCA9555_B1) |
			      (1 << PCA9555_B2) |
			      (1 << PCA9555_B3));


	// Slave E. Input A0, A1, A2, A3, A4, B0, B1, B2, B3. All others output
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			addressSlaveE,
			(1 << PCA9555_A0) |
			(1 << PCA9555_A1) |
			(1 << PCA9555_A2) |
			(1 << PCA9555_A3) |
			(1 << PCA9555_A4),
			(1 << PCA9555_B0) |
			(1 << PCA9555_B1) |
			(1 << PCA9555_B2) |
			(1 << PCA9555_B3));
	// Slave E. Reverse all inputs from Weichenrueckmelder
	PCA9555_write(PCA9555_CommandPolarityInversionPortA,
			      addressSlaveE,
			      (1 << PCA9555_A0) |
			      (1 << PCA9555_A4),
			      (1 << PCA9555_B3));


	// static int first = 1;
	uint16_t count = 0;
	uint16_t init = 0;
	for (;; ++count)
	{
		if (count  >20)
		{
			count = 0;
		}
		if ( count  > 10)
		{
			setOnboardLed(1);
		}
		else
		{
			setOnboardLed(0);
		}

	    // Read inputs of Slave A
		PCA9555_read(addressSlaveA, &inputDataSlaveA_A, &inputDataSlaveA_B);
	    // Read inputs of Slave B
		PCA9555_read(addressSlaveB, &inputDataSlaveB_A, &inputDataSlaveB_B);
		// Read inputs of Slave C
		PCA9555_read(addressSlaveC, &inputDataSlaveC_A, &inputDataSlaveC_B);
		// Read inputs of Slave D
		PCA9555_read(addressSlaveD, &inputDataSlaveD_A, &inputDataSlaveD_B);
		// Read inputs of Slave E
		PCA9555_read(addressSlaveE, &inputDataSlaveE_A, &inputDataSlaveE_B);

		setLed2(getWeiche1());
		setLed1(!getWeiche1());
		setLed3(getWeiche2());
		setLed4(!getWeiche2());

		setLed6(getWeiche3());
		setLed5(!getWeiche3());
		setLed8(getWeiche4());
		setLed7(!getWeiche4());
		setLed20(getWeiche5());
		setLed19(!getWeiche5());

		setLed12(getWeiche6());
		setLed11(!getWeiche6());
		setLed10(getWeiche7());
		setLed9(!getWeiche7());
		setLed13(getWeiche8());
		setLed14(!getWeiche8());
		setLed16(getWeiche9());
		setLed15(!getWeiche9());
		setLed18(getWeiche10());
		setLed17(!getWeiche10());

		toggleWeiche1(getTaster1());
		toggleWeiche2(getTaster2());
		toggleWeiche3(getTaster3());
		toggleWeiche4(getTaster4());
		toggleWeiche5(getTaster5());
		toggleWeiche6(getTaster6());
		toggleWeiche7(getTaster7());
		toggleWeiche8(getTaster8());
		toggleWeiche9(getTaster9());
		toggleWeiche10(getTaster10());

		setEntkuppler1(getTsEnt1());
		setEntkuppler2(getTsEnt2());
		setEntkuppler3(getTsEnt3());
		setEntkuppler4(getTsEnt4());
		setEntkuppler5(getTsEnt5());

		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveA, outputDataSlaveA_A, outputDataSlaveA_B);
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveB, outputDataSlaveB_A, outputDataSlaveB_B);
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveC, outputDataSlaveC_A, outputDataSlaveC_B);
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveD, outputDataSlaveD_A, outputDataSlaveD_B);
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveE, outputDataSlaveE_A, outputDataSlaveE_B);

		if ( ++init < 1000 ) // 5s
		{
			setRelaisForAc(0);
		}
		else
		{
			setRelaisForAc(1);
		}

		_delay_ms(ms_per_cycle);

	};

	return 0;
}


