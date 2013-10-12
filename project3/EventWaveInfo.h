/*******************************************************************************
 * @file        EventWaveInfo.h
 * @author      bsautermeister
 * @description Wave info event, which is fired for a new wave.
 ******************************************************************************/

#ifndef __EVENT_WAVE_INFO_H__
#define __EVENT_WAVE_INFO_H__

#include <string>
#include "Event.h"

using std::string;

#define WAVE_INFO_EVENT "wave_info"

/**
 * The wave info event class.
 */
class EventWaveInfo : public Event
{
private:
	/**
	 * The total number of waves.
	 */
	int _totalWaves;

	/**
	 * The current wave number.
	 */
	int _currentWave;

	/**
	 * The number of current enemies in this wave.
	 */
	int _count;

	/**
	 * The enemy type of the current wave.
	 */
	string _name;

public:
	/**
	 * Creates a new wave info event instance withd default data.
	 */
	EventWaveInfo(void);

	/**
	 * Creates a new wave info event instance.
	 * @param total The total waves.
	 * @param current The current wave number.
	 * @param count The number of enemies.
	 * @param name The enemy type.
	 */
	EventWaveInfo(int total, int current, int count, string name);

	/**
	 * Gets the total waves.
	 * @return Total waves.
	 */
	int getTotalWaves(void);

	/**
	 * Gets the curent wave number.
	 * @return Current wave number.
	 */
	int getCurrentWave(void);

	/**
	 * Gets the enemies count.
	 * @return The enemies count.
	 */
	int getCount(void);

	/**
	 * Gets the enemy type name.
	 * @return The enemy name.
	 */
	string getName();
};

#endif
