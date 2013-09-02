/* PowerupLaser.h */

#ifndef POWERUP_LASER_H
#define POWERUP_LASER_H

#include <string>
#include "Powerup.h"

using std::string;

#define POWERUP_LASER "LASER"

class PowerupLaser : public Powerup
{
public:
	PowerupLaser(Position spawnPosition);
};

#endif