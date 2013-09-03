/* Ufo.h */

#ifndef UFO_H
#define UFO_H

#include "Enemy.h"

class Ufo : public Enemy
{
protected:
	/**
	 * Creates a new Ufo.
	 */
	void createEnemy(void);
public:
	/**
	 * Creates a new Ufo instance.
	 */
	Ufo(void);
};

#endif