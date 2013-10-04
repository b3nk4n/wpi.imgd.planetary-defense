/* PowerupRocket.h */

#ifndef POWERUP_ROCKET_H
#define POWERUP_ROCKET_H

#include <string>
#include "Powerup.h"

using std::string;

#define POWERUP_ROCKET "ROCKET"

class PowerupRocket : public Powerup
{
public:
	/**
	 * Creates a new powerup rocket instance.
	 */
	PowerupRocket(Position spawnPosition);
};

#endif
