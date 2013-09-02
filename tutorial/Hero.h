/* Hero.h */

#ifndef HERO_H
#define HERO_H

#include "Object.h"
#include "EventKeyboard.h"
#include "EventPowerup.h"

enum WeaponType
{
	DEFAULT,
	LASER,
	ROCKET
};

#define UPGRADED_WEAPON_STEPS 450

class Hero : public Object
{
private:
	void releaseBigHeroExplosion(void);
	
protected:
	int fireSlowdown;
	int fireCountdown;
	int nukeCount;
	
	WeaponType weaponType;
	int upgradedWeaponCounter;

	void keyboard(EventKeyboard *p_keyboard_event);
	void powerupCollected(EventPowerup *p_powerup_event);
	void move(int dy);
	void moveToStart(void);
	void step(void);
	void fire(void);
	void nuke(void);

public:
	Hero(void);
	~Hero(void);
	int eventHandler(Event *p_e);
};

#endif