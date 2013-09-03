/* Enemy.h */

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Object.h"
#include "EventCollision.h"
#include "Explosion.h"

#define AUTO_OUT_OF_BOUNDS -1

using std::string;

class Enemy : public Object
{
private:
	int hitpoints;
	int killscore;
	float powerupSpawnChance;
	int explosionType;
	int maxOutOfBoundsOffset;

protected:
	bool canCreateEnemy;
	/**
	 * Handles the events.
	 */
	virtual int eventHandler(Event *p_event);
	/**
	 * Checks and handles if the enemy is out of the left side of screen.
	 */
	void out(void);
	/**
	 * Moves the enemy back to the start position.
	 */
	void moveToStart(void);
	/**
	 * Is called when a collision has happened.
	 */
	void hit(EventCollision *p_collisionEvent);
	/**
	 * Kills this object and releases an explosion.
	 */
	void kill(bool powerup);
	/**
	 * Probably spawns a power up with given spawn chance.
	 */
	void probablySpawnPowerup(void);
	/**
	 * Decreases the hit points and kills the enemy, if neccessary.
	 */
	void decreaseHitpoints(int value);

	/**
	 * Creates an enemy of this type.
	 */
	virtual void createEnemy(void)=0;

public:
	/**
	 * Creates a new enemy instance.
	 */
	Enemy(string spriteName, int hitpoints, int killscore, float powerupSpawnChance, int explosionType, int maxOutOfBoundsOffset);
	/**
	 * Destructs the enemy.
	 */
	virtual ~Enemy(void);
};

#endif