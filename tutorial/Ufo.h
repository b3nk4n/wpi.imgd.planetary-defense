/* Ufo.h */

#ifndef UFO_H
#define UFO_H

#include "Enemy.h"

class Ufo : public Enemy
{
protected:
	void createEnemy(void);
public:
	Ufo(void);
};

#endif