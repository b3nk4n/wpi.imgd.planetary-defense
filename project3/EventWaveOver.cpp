/*******************************************************************************
 * @file        EventWaveOver
 * @author      kcbryant
 * @description wave over event, which is fired when a wave finishes
 ******************************************************************************/

#include "EventWaveOver.h"

/**
 * Creates a new wave over event instance.
 */
EventWaveOver::EventWaveOver(void)
{
	setType(WAVE_OVER_EVENT);
}
