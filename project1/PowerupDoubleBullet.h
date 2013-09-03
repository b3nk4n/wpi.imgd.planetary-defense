/* PowerupDoubleBullet.h */

#ifndef POWERUP_DOUBLE_BULLET_H
#define POWERUP_DOUBLE_BULLET_H

#include <string>
#include "Powerup.h"

using std::string;

#define POWERUP_DOUBLE_BULLET "DOUBLE_BULLET"

class PowerupDoubleBullet : public Powerup
{
public:
	/**
	 * Creates a new powerup double bullet instance.
	 */
	PowerupDoubleBullet(Position spawnPosition);
};

#endif