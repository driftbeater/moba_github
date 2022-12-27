/*
 * debounce.h
 *
 *  Created on: May 24, 2011
 *      Author: gerd
 */

#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

#include <inttypes.h>

void setStateDebounced(int8_t cycles, uint8_t targetState, int8_t* debouncedState);
void toggleStateDebounced(int8_t cycles, uint8_t toggle, int8_t* debouncedState);

#endif /* DEBOUNCE_H_ */
