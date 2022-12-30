/*
 * debounce.c
 *
 *  Created on: May 24, 2011
 *      Author: gerd
 */

#include "debounce.h"

void toggleStateDebounced(int8_t cycles, uint8_t toggle_, int8_t* debouncedState_)
{
	uint8_t targetState;
	if ( toggle_ && *debouncedState_ >= cycles )
	{
		targetState = 0;
	}
	else if ( toggle_ && *debouncedState_ <= -cycles )
	{
		targetState = 1;
	}
	else
	{
		if ( *debouncedState_ > 0 )
		{
			targetState = 1;
		}
		else
		{
			targetState = 0;
		}
	}
	setStateDebounced(cycles, targetState, debouncedState_);
}



void setStateDebounced(int8_t cycles, uint8_t targetState_, int8_t* stateDebounced_)
{
	if ( targetState_ != 0U )
	{
		// Button now pressed
		if ( *stateDebounced_ <= 0  )
		{
			// Button was "released" before
			if ( *stateDebounced_ <= -cycles )
			{
			   // Button goes from "released" to "pressed"
			   *stateDebounced_ = 1;
			}
			else
			{
			   // Ignore, probably a bouncing problem. Leave state "released"
			   if ( *stateDebounced_ > -cycles )
			   {
			      --(*stateDebounced_);
			   }
			}
		}
		else
		{
			// button was presssed before
			if ( *stateDebounced_ < cycles )
			{
				++(*stateDebounced_);
			}
		}
	}
	else
	{
		// Button now released
		if ( *stateDebounced_ > 0 )
		{
			// _delay_ms(2000);

			// Button was pressed before
			if ( *stateDebounced_ >= cycles )
			{
				// Go to "released" now
				*stateDebounced_ = -1;
			}
			else
			{
				// Bouncing problem. Ignore. Leave "pressed"
				if ( *stateDebounced_ < cycles )
				{
					++(*stateDebounced_);
				}
			}
		}
		else
		{
			// Button was released before
			if ( *stateDebounced_ > -cycles)
			{
				--(*stateDebounced_);
			}
		}
	}

}
