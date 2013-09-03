/* PowerupRocket.cpp */

#include "PowerupRocket.h"
#include "Points.h"
#include "WorldManager.h"
#include "EventPowerup.h"

using std::string;

/**
 * Creates a new powerup rocket instance.
 */
PowerupRocket::PowerupRocket(Position spawnPosition)
	: Powerup("poweruprocket", POWERUP_ROCKET, spawnPosition)
{
}