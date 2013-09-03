/* PowerupLaser.cpp */

#include "PowerupLaser.h"
#include "Points.h"
#include "WorldManager.h"
#include "EventPowerup.h"

using std::string;

/**
 * Creates a new powerup laser instance.
 */
PowerupLaser::PowerupLaser(Position spawnPosition)
	: Powerup("poweruplaser", POWERUP_LASER, spawnPosition)
{
}