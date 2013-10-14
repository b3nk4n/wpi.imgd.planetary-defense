/*******************************************************************************
 * @file        EventWaveOver.h
 * @author      kcbryant
 * @description Sends an event when the wave is over
 ******************************************************************************/

#ifndef __EVENT_WAVE_OVER_H__
#define __EVENT_WAVE_OVER_H__

#include "Event.h"

#define WAVE_OVER_EVENT "wave_over"

/**
 * The wave over event class.
 */
class EventWaveOver : public Event
{
public:
	/**
	 * Creates a new wave over event instance.
	 */
	EventWaveOver(void);
};

#endif
