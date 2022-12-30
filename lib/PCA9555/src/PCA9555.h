/*
 * PCA9555.h
 *
 *  Created on: Apr 25, 2011
 *      Author: gerd
 */

#ifndef PCA9555_H_
#define PCA9555_H_

#include <inttypes.h>

// PCA9555
extern const uint8_t PCA9555_CommandInputPortA;
// extern const uint8_t PCA9555_CommandInputPortB;
extern const uint8_t PCA9555_CommandOutputPortA;
// extern const uint8_t PCA9555_CommandOutputPortB;
extern const uint8_t PCA9555_CommandPolarityInversionPortA;
// extern const uint8_t PCA9555_CommandPolarityInversionPortB;
extern const uint8_t PCA9555_CommandConfigurationPortA;
// extern const uint8_t PCA9555_CommandConfigurationPortB;

extern const uint8_t PCA9555_A0;
extern const uint8_t PCA9555_A1;
extern const uint8_t PCA9555_A2;
extern const uint8_t PCA9555_A3;
extern const uint8_t PCA9555_A4;
extern const uint8_t PCA9555_A5;
extern const uint8_t PCA9555_A6;
extern const uint8_t PCA9555_A7;
extern const uint8_t PCA9555_B0;
extern const uint8_t PCA9555_B1;
extern const uint8_t PCA9555_B2;
extern const uint8_t PCA9555_B3;
extern const uint8_t PCA9555_B4;
extern const uint8_t PCA9555_B5;
extern const uint8_t PCA9555_B6;
extern const uint8_t PCA9555_B7;

extern void PCA9555_write(uint8_t command_, uint8_t slaveAddress, uint8_t dataPortA_, uint8_t dataPortB);
extern void PCA9555_read(uint8_t slaveAddress_, uint8_t* dataPortA, uint8_t* dataPortB);
//extern void PCA9555_configurePorts(uint8_t slaveAddress_, uint8_t dataPortA_, uint8_t dataPortB_);
//extern void PCA9555_writeData(uint8_t slaveAddress_, uint8_t dataPortA_, uint8_t dataPortB_);

#endif /* PCA9555_H_ */
