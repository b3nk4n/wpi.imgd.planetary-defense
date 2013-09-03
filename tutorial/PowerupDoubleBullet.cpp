/* PowerupDoubleBullet.cpp */

#include "PowerupDoubleBullet.h"
#include "Points.h"
#include "WorldManager.h"
#include "EventPowerup.h"

using std::string;

/**
 * Creates a new powerup double bullet instance.
 */
PowerupDoubleBullet::PowerupDoubleBullet(Position spawnPosition)
	: Powerup("powerupdoublebullet", POWERUP_DOUBLE_BULLET, spawnPosition)
{
}