/* PowerupScore.h */

#ifndef POWERUP_SCORE_H
#define POWERUP_SCORE_H

#include <string>
#include "Powerup.h"

using std::string;

#define POWERUP_SCORE "SCORE"

class PowerupScore : public Powerup
{
public:
	/**
	 * Creates a new powerup score instance.
	 */
	PowerupScore(Position spawnPosition);
};

#endif
