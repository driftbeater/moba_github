/*
 * PCA9555.c
 *
 *  Created on: May 19, 2011
 *      Author: gerd
 */

#include "PCA9555.h"
#include "i2cmaster.h"

// PCA9555
const uint8_t PCA9555_CommandInputPortA = 0x00;
const uint8_t PCA9555_CommandInputPortB = 0x01;
const uint8_t PCA9555_CommandOutputPortA = 0x02;
const uint8_t PCA9555_CommandOutputPortB = 0x03;
const uint8_t PCA9555_CommandPolarityInversionPortA = 0x04;
const uint8_t PCA9555_CommandPolarityInversionPortB = 0x05;
const uint8_t PCA9555_CommandConfigurationPortA = 0x06;
const uint8_t PCA9555_CommandConfigurationPortB = 0x07;

const uint8_t PCA9555_A0 = 0U;
const uint8_t PCA9555_A1 = 1U;
const uint8_t PCA9555_A2 = 2U;
const uint8_t PCA9555_A3 = 3U;
const uint8_t PCA9555_A4 = 4U;
const uint8_t PCA9555_A5 = 5U;
const uint8_t PCA9555_A6 = 6U;
const uint8_t PCA9555_A7 = 7U;
const uint8_t PCA9555_B0 = 0U;
const uint8_t PCA9555_B1 = 1U;
const uint8_t PCA9555_B2 = 2U;
const uint8_t PCA9555_B3 = 3U;
const uint8_t PCA9555_B4 = 4U;
const uint8_t PCA9555_B5 = 5U;
const uint8_t PCA9555_B6 = 6U;
const uint8_t PCA9555_B7 = 7U;

void PCA9555_write(uint8_t command_, uint8_t slaveAddress_, uint8_t dataPortA_, uint8_t dataPortB_)
{
	if ( command_ != PCA9555_CommandInputPortA &&
		 command_ != PCA9555_CommandInputPortB &&
		 command_ != PCA9555_CommandOutputPortA &&
		 command_ != PCA9555_CommandPolarityInversionPortA &&
		 command_ != PCA9555_CommandConfigurationPortA )
	{
		// reset();
		for (;;) ;
	}
    i2c_start_wait(slaveAddress_ + I2C_WRITE);
    i2c_write(command_);
    // Cast necessary in order to prevent warning "large integer implicitly truncated to unsigned type" due to bug in gcc.
	// Write to configuration port 0
    i2c_write(dataPortA_);
    // Set all B's to input
    i2c_write(dataPortB_);
    i2c_stop();
}

void PCA9555_read(uint8_t slaveAddress_, uint8_t* dataPortA_, uint8_t* dataPortB_)
{
    i2c_start_wait(slaveAddress_ + I2C_WRITE);
    i2c_write(PCA9555_CommandInputPortA);
    i2c_rep_start(slaveAddress_ + I2C_READ);
    *dataPortA_ = i2c_readAck();
    *dataPortB_ = i2c_readNak();
    i2c_stop();
}



void PCA9555_configurePorts(uint8_t slaveAddress_, uint8_t dataPortA_, uint8_t dataPortB_)
{
    i2c_start_wait(slaveAddress_ + I2C_WRITE);
    i2c_write(PCA9555_CommandConfigurationPortA);
    // Cast necessary in order to prevent warning "large integer implicitly truncated to unsigned type" due to bug in gcc.
	// Write to configuration port 0
    i2c_write(dataPortA_);
    // Set all B's to input
    i2c_write(dataPortB_);
    i2c_stop();
}



void PCA9555_writeData(uint8_t slaveAddress_, uint8_t dataPortA_, uint8_t dataPortB_)
{
	i2c_start_wait(slaveAddress_ + I2C_WRITE);
	i2c_write(PCA9555_CommandOutputPortA);
	// Write to Port A
	i2c_write(dataPortA_);
	// Write to Port B
	i2c_write(dataPortB_);
	i2c_stop();
}
