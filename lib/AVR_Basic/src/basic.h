/*
 * basic.h
 *
 *  Created on: Oct 30, 2011
 *      Author: gerd
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <inttypes.h>

void    setBit(uint8_t* byte, uint8_t position, uint8_t flag);
uint8_t getBit(uint8_t  byte, uint8_t position);

#endif /* BASIC_H_ */
