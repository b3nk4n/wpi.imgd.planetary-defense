/* PowerupNuke.cpp */

#include "PowerupNuke.h"
#include "Points.h"
#include "WorldManager.h"
#include "EventPowerup.h"

using std::string;

/**
 * Creates a new powerup nuke instance.
 */
PowerupNuke::PowerupNuke(Position spawnPosition)
	: Powerup("powerupnuke", POWERUP_NUKE, spawnPosition)
{
}