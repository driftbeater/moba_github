/*
 * basic.h
 *
 *  Created on: Oct 30, 2011
 *      Author: gerd
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <inttypes.h>

/** set bit if flag is not 0 */
void    setBit8u(uint8_t* byte, uint8_t position, uint8_t flag);
/** set bit if flag is > 0, clear it if flag is < 0 */
void    setBit8(uint8_t* byte, uint8_t position, int8_t flag);
uint8_t getBit8u(uint8_t  byte, uint8_t position);

#endif /* BASIC_H_ */
