/*******************************************************************************
 * @file        Bullet.h
 * @author      kcbryant
 * @description Bullets that hit enemies
 ******************************************************************************/

#ifndef __BULLET_H__
#define __BULLET_H__

#include <string>
#include "Object.h"
#include "Enemy.h"
#include "Tower.h"
#include "EventCollision.h"

#define TYPE_BULLET "bullet"

/*
* Bullet base class
*/
class Bullet : public Object
{
private:
	/**
	 * Speed of the bullet
	 */
	float _speed;

	/**
	 * radius of the explosion, 0 if none
	 */
	int _radius;

	/**
	 * Damage the bullet does
	 */
	int _damage;

	/**
	 * Type of bullet
	 */
	string _type;

	/**
	 * Target enemy of the bullet
	 */
	Object *_target;

	/**
	 * Tower that spawned this bullet
	 */
	Tower *_spawner;

public:
 	/**
 	 * Creates a new bullet that fires at specified enemy
 	 * @param string, the bullet type
	 * @param float, speed of the bullet
	 * @param int, radius of the explosion
	 * @param int, Damage the bullet causes
	 * @param Tower, that spawned this bullet
 	 * @param Enemy, target enemy of bullet
 	 */
 	Bullet(string type, float speed, int radius, int damage, Tower *spawner, Object *target);

 	/**
 	 * Bullet move towards object
 	 */
 	void flyTo(void);

 	/**
	 * Handle events
	 * @param p_event The event.
	 * @return Returns 1 if event was handled, else 0.
	 */
	virtual int eventHandler(Event *p_event);

	void hit(EventCollision *p_c);

};

#endif //__BULLET_H__