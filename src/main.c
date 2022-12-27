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


const uint8_t NR_OF_POINTS = 10;

uint8_t dataSlaveA_A;
uint8_t dataSlaveA_B;
uint8_t dataSlaveB_A;
uint8_t dataSlaveB_B;
uint8_t inputDataSlaveC_A;
uint8_t inputDataSlaveC_B;
uint8_t outputDataSlaveC_A = 0;
uint8_t outputDataSlaveC_B = 0;
uint8_t inputDataSlaveD_A;
uint8_t inputDataSlaveD_B;
uint8_t outputDataSlaveD_A = 0;
uint8_t outputDataSlaveD_B = 0;
uint8_t dataSlaveE_A;
uint8_t dataSlaveE_B;
uint8_t dataSlaveF_A;
uint8_t dataSlaveF_B;

uint8_t targetW1;
uint8_t targetW2;
uint8_t targetW3;
uint8_t targetW4;
uint8_t targetW5;
uint8_t targetW6;
uint8_t targetW7;
uint8_t targetW8;
uint8_t targetW9;
uint8_t targetW10;



void setOnBoardLed(uint8_t flag)
{
	uint8_t dataPortB = 0;
	if ( flag )
	{
		dataPortB &= ~( 1 << PB1 );
	}
	else
	{
		dataPortB |= ( 1 << PB1 );
	}
	PORTB = dataPortB;
}

void setLed1(uint8_t flag)
{
	setBit(&outputDataSlaveD_B, PCA9555_B6, flag);
}
void setLed2(uint8_t flag)
{
	setBit(&outputDataSlaveD_A, PCA9555_A7, flag);
}
void setLed3(uint8_t flag)
{
	setBit(&outputDataSlaveC_B, PCA9555_B0, flag);
}
void setLed4(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A1, flag);
}
void setLed5(uint8_t flag)
{
	setBit(&outputDataSlaveD_B, PCA9555_B7, flag);
}
void setLed6(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A0, flag);
}
void setLed7(uint8_t flag)
{
	setBit(&outputDataSlaveD_B, PCA9555_B4, flag);
}
void setLed8(uint8_t flag)
{
	setBit(&outputDataSlaveD_A, PCA9555_A5, flag);
}
void setLed9(uint8_t flag)
{
	setBit(&outputDataSlaveC_B, PCA9555_B4, flag);
}
void setLed10(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A5, flag);
}
void setLed11(uint8_t flag)
{
	setBit(&outputDataSlaveC_B, PCA9555_B5, flag);
}
void setLed12(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A6, flag);
}
void setLed13(uint8_t flag)
{
	setBit(&outputDataSlaveC_B, PCA9555_B1, flag);
}
void setLed14(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A2, flag);
}
void setLed15(uint8_t flag)
{
	setBit(&outputDataSlaveC_B, PCA9555_B2, flag);
}
void setLed16(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A3, flag);
}
void setLed17(uint8_t flag)
{
	setBit(&outputDataSlaveC_B, PCA9555_B3, flag);
}
void setLed18(uint8_t flag)
{
	setBit(&outputDataSlaveC_A, PCA9555_A4, flag);
}
void setLed19(uint8_t flag)
{
	setBit(&outputDataSlaveD_B, PCA9555_B5, flag);
}
void setLed20(uint8_t flag)
{
	setBit(&outputDataSlaveD_A, PCA9555_A6, flag);
}

uint8_t getTs1()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_B, PCA9555_B2);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}

uint8_t getTs2()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_A, PCA9555_A3);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs3()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_A, PCA9555_A2);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs4()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_B, PCA9555_B1);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs5()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_A, PCA9555_A1);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs6()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveC_B, PCA9555_B7);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs7()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveC_A, PCA9555_A7);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs8()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveC_B, PCA9555_B6);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs9()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_B, PCA9555_B0);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}
uint8_t getTs10()
{
	static int8_t state = 0;
	uint8_t pressed = getBit(inputDataSlaveD_A, PCA9555_A0);
	// 10 x 5 = 50ms
	setStateDebounced(10, pressed, &(state));
	return state > 0;
}

int main()
{
	// init AVR

	// AVR Port B
	// Port B.1 (Pin 15) is Output (Led), all others input
	DDRB = 1 << PB1;
    for (uint8_t x = 0; x < 0; ++x)
	{
		setOnBoardLed(0);
		_delay_ms(2000);
		setOnBoardLed(1);
		_delay_ms(2000);
	}

	// initialize. Output pin = 0, all others (Input) = 1, i.e. internal pull ups active

	// init Slave A
	// fixed part for PCA9555:    0b0100
	// variable part         :          AAA
	// R/W                   :             x
	const uint8_t addressSlaveA = 0b01000000;
	// const uint8_t addressSlaveB = 0b01000010; not used, yet
	const uint8_t addressSlaveC = 0b01000100;
	const uint8_t addressSlaveD = 0b01000110;
	// const uint8_t addressSlaveE = 0b01001000; not used, yet
	// const uint8_t addressSlaveF = 0b01001010; not used, yet
	// const uint8_t addressSlaveG = 0b01001100; not used, yet
	// const uint8_t addressSlaveH = 0b01001110; not used, yet

	// init I2C library
	i2c_init();

	// Configure Ports
	// Slave C. Input B7, B6, A7. All others output
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			      addressSlaveC,
			      1 << PCA9555_A7 ,
			      (1 << PCA9555_B7) | (1 << PCA9555_B6) );

	// Slave D. Input A0, A1, A2, A3, B0, B1, B2. All others output
	PCA9555_write(PCA9555_CommandConfigurationPortA,
			addressSlaveD,
			(1 << PCA9555_A0) | (1 << PCA9555_A1) | (1 << PCA9555_A2) | (1 << PCA9555_A3),
			(1 << PCA9555_B0) | (1 << PCA9555_B1) | (1 << PCA9555_B2));

	// Reverse Inputs
	// Slave A. Reverse B0 and B7
	PCA9555_write(PCA9555_CommandPolarityInversionPortA, addressSlaveA, 0x00, ( 1 << PCA9555_B0 | 1 << PCA9555_B7) );
	// Slave C. Reverse all inputs
	PCA9555_write(PCA9555_CommandPolarityInversionPortA,
	        	  addressSlaveC,
			      1 << PCA9555_A7,
			      (1 << PCA9555_B7) | (1 << PCA9555_B6));

	// Slave D. Reverse all inputs
	PCA9555_write(PCA9555_CommandPolarityInversionPortA,
			      addressSlaveD,
			      (1 << PCA9555_A0) | (1 << PCA9555_A1) | (1 << PCA9555_A2) | (1 << PCA9555_A3),
			      (1 << PCA9555_B0) | (1 << PCA9555_B1) | (1 << PCA9555_B2) );

	/*
	uint8_t pointActualState[NR_OF_POINTS];
	int8_t  pointTargetStateDebounced[NR_OF_POINTS];
	int8_t  buttonStateDebounced[NR_OF_POINTS];

	for ( unsigned int x = 0; x < NR_OF_POINTS; ++x )
	{
		pointActualState[x] = 0U;
		buttonStateDebounced[x] = 0;
	}

	// Initialize. Read actual status of points
    // Reading Port A and B of Slave A
	PCA9555_read(addressSlaveA, &dataSlaveA_A, &dataSlaveA_B);
	{
	   // On startup Set target State to actual State
	   pointActualState[0] = ( dataSlaveA_B & ( 1 << PCA9555_B0) ) >> PCA9555_B0;
	   //pointTargetStateDebounced[0] = ( pointActualState[0] ) ? 1 : -1;
	   pointTargetStateDebounced[0] = pointActualState[0];
	}
	_delay_ms(1000);

	 */

	for (;;)
	{
		//      setOnBoardLed(1);
		// _delay_ms(10);

		/*
        // Reading Port A and B of Slave A
		PCA9555_read(addressSlaveA, &dataSlaveA_A, &dataSlaveA_B);

        // Check whether point is straight (0) or abgezweigt (1)
		pointActualState[0] = ( dataSlaveA_B & ( 1 << PCA9555_B0) ) >> PCA9555_B0;
		uint8_t buttonPressed = 0;
		// Check whether button is pressed
		{
            buttonPressed = ( dataSlaveA_B & ( 1 << PCA9555_B7) ) >> PCA9555_B7;

   	    	// 30 x 5 = 150ms
		    setStateDebounced(100, buttonPressed, &(buttonStateDebounced[0]));
			// Determine point target state
			// 100 x 5 ms = 500ms -> max 2Hz
		    //toggleStateDebounced(100, 0, &pointTargetStateDebounced[0]);
		    toggleStateDebounced(100, buttonStateDebounced[0] > 0, &pointTargetStateDebounced[0]);
		    // toggleStateDebounced(100, buttonPressed, &pointTargetStateDebounced[0]);

		}

        // Set Outputs of Slave A
		{   // Set Outputs of Slave A

			uint8_t dataWriteA_A = 0;
			uint8_t dataWriteA_B = 0;

			// A7 is LED
			// A1 is LED
			// A0 is Relais


			//if ( pointTargetStateDebounced[0] > 0 )
			//{
			//	// dataWriteA_A |= ( 1 << PCA9555_A0);
			//}

			if ( pointActualState[0] == 1 )
			// if ( buttonStateDebounced[0] >= 1 ) // button Pressed
			// if ( buttonPressed ) // button Pressed
			// if ( pointTargetStateDebounced[0] >= 1 )
			{
				dataWriteA_A |= ( 1 << PCA9555_A7);
			}
			if ( pointTargetStateDebounced[0] > 0 )
			{
				dataWriteA_A |= ( 1 << PCA9555_A1 );
				dataWriteA_A |= ( 1 << PCA9555_A0 );
			}

			// Invert output data
			dataWriteA_A ^= ( 1 << PCA9555_A7 | 1 << PCA9555_A1 );
			PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveA, dataWriteA_A, dataWriteA_B);
		}
		 */

		// Read inputs of Slave C
		///PCA9555_read(addressSlaveC, &inputDataSlaveC_A, &inputDataSlaveC_B);
		// Read inputs of Slave D
		///PCA9555_read(addressSlaveD, &inputDataSlaveD_A, &inputDataSlaveD_B);

		//if ( getTs1() )
		{
			setLed1(0);
			setLed2(0);
			setLed3(0);
			setLed4(0);
			setLed5(0);
			setLed6(0);
			setLed7(0);
			setLed8(0);
			setLed9(0);
			setLed10(0);
			setLed11(0);
			setLed12(0);
			setLed13(0);
			setLed14(0);
			setLed15(0);
			setLed16(0);
			setLed17(0);
			setLed18(0);
			setLed19(1);
			setLed20(0);
		}
		// else
		{

			//        setLed1(0);
			//        setLed2(0);
			//        setLed3(0);
			//        setLed4(0);
			//        setLed5(0);
			//        setLed6(0);
			//        setLed7(0);
			//        setLed8(0);
			//        setLed9(0);
			//        setLed10(0);
			//        setLed11(0);
			//        setLed12(0);
			//        setLed13(0);
			//        setLed14(0);
			//        setLed15(0);
			//        setLed16(0);
			//        setLed17(0);
			//        setLed18(0);
			//        setLed19(0);
			//        setLed20(0);
		}

		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveC, outputDataSlaveC_A, outputDataSlaveC_B);
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveD, outputDataSlaveD_A, outputDataSlaveD_B);
		_delay_ms(1000);
		outputDataSlaveC_A = 0;
		outputDataSlaveC_B = 0;
		outputDataSlaveD_A = 0;
		outputDataSlaveD_B = 0;
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveC, outputDataSlaveC_A, outputDataSlaveC_B);
		PCA9555_write(PCA9555_CommandOutputPortA, addressSlaveD, outputDataSlaveD_A, outputDataSlaveD_B);
		_delay_ms(1000);

	};

	return 0;
}


