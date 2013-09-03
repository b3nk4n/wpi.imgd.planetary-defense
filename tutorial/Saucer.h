/* Saucer.h */

#ifndef SAUCER_H
#define SAUCER_H

#include "Enemy.h"

class Saucer : public Enemy
{
protected:
	void createEnemy(void);
public:
	Saucer(void);
};

#endif

