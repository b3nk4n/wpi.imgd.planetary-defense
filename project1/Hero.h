/* Hero.h */

#ifndef HERO_H
#define HERO_H

#include "Object.h"
#include "EventKeyboard.h"
#include "EventPowerup.h"
#include "EventCollision.h"

enum WeaponType
{
	DEFAULT,
	LASER,
	ROCKET,
	DOUBLE
};

#define MAX_HITPOINTS 5
#define UPGRADED_WEAPON_STEPS 450

class Hero : public Object
{
private:
	void releaseBigHeroExplosion(void);
	
protected:
	int fireSlowdown;
	int fireCountdown;
	int nukeCount;

	int hitpoints;
	
	WeaponType weaponType;
	int upgradedWeaponCounter;

	/**
	 * Handles keyboard events.
	 */
	void keyboard(EventKeyboard *p_keyboard_event);
	/**
	 * Is called when a powerup was collected.
	 */
	void powerupCollected(EventPowerup *p_powerup_event);
	/**
	 * Moves the hero vertically.
	 */
	void move(int dx, int dy);
	/**
	 * Moves the hero back to the start position.
	 */
	void moveToStart(void);
	/**
	 * Updates the hero every frame.
	 */
	void step(void);
	/**
	 * Fires the current weapon.
	 */
	void fire(void);
	/**
	 * Hero releases a nuke to destory all enemies.
	 */
	void nuke(void);
	/**
	 * Is called when a collision has happened.
	 */
	void hit(EventCollision *p_collisionEvent);
	/**
	 * Sets the hitpoints and updates the display view.
	 */
	void setHitpoints(int hp);

public:
	/**
	 * Creates a new hero instance.
	 */
	Hero(void);
	/**
	 * End game when hero is destroyed.
	 */
	~Hero(void);
	/**
	 * Handles all events.
	 */
	int eventHandler(Event *p_e);
};

#endif