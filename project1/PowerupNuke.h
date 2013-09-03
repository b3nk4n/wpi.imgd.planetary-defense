/* PowerupNuke.h */

#ifndef POWERUP_NUKE_H
#define POWERUP_NUKE_H

#include <string>
#include "Powerup.h"

using std::string;

#define POWERUP_NUKE "NUKE"

class PowerupNuke : public Powerup
{
public:
	/**
	 * Creates a new powerup nuke instance.
	 */
	PowerupNuke(Position spawnPosition);
};

#endif
