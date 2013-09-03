/* Enemy.h */

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Object.h"
#include "EventCollision.h"
#include "Explosion.h"

using std::string;

class Enemy : public Object
{
private:
	int hitpoints;
	int killscore;
	float powerupSpawnChance;
	int explosionType;

protected:
	int eventHandler(Event *p_event);
	void out(void);
	void moveToStart(void);
	void hit(EventCollision *p_collisionEvent);
	void kill(bool powerup);
	void probablySpawnPowerup(void);
	void decreaseHitpoints(int value);
	virtual void createEnemy(void)=0;

public:
	Enemy(string spriteName, int hitpoints, int killscore, float powerupSpawnChance, int explosionType);
	virtual ~Enemy(void);
};

#endif