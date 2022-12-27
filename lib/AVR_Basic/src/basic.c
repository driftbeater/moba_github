/*
 * basic.c
 *
 *  Created on: Oct 30, 2011
 *      Author: gerd
 */

#include "basic.h"

void setBit(uint8_t* byte_, uint8_t position, uint8_t flag)
{
	if ( position >= 0 && position <= 7 )
	{
	   if ( flag )
	   {
	      *byte_ |= ( 1 << position );
	   }
	   else
	   {
	      *byte_ &= ~( 1 << position );
	   }
	}
	else
	{
		; // @todo output
	}
}


uint8_t getBit(uint8_t byte, uint8_t position)
{
	return ( byte & ( 1 << position ) ) >> position;
}
