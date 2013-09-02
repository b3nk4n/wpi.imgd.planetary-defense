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
	PowerupRocket(Position spawnPosition);
};

#endif