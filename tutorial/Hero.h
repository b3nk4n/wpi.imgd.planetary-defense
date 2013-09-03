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
	ROCKET
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

	void keyboard(EventKeyboard *p_keyboard_event);
	void powerupCollected(EventPowerup *p_powerup_event);
	void move(int dy);
	void moveToStart(void);
	void step(void);
	void fire(void);
	void nuke(void);
	void hit(EventCollision *p_collisionEvent);
	void setHitpoints(int hp);

public:
	Hero(void);
	~Hero(void);
	int eventHandler(Event *p_e);
};

#endif