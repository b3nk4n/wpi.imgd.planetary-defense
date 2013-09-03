/* PowerupScore.cpp */

#include "PowerupScore.h"
#include "Points.h"
#include "WorldManager.h"
#include "EventPowerup.h"

using std::string;

/**
 * Creates a new powerup score instance.
 */
PowerupScore::PowerupScore(Position spawnPosition)
	: Powerup("powerupscore", POWERUP_SCORE, spawnPosition)
{
}
