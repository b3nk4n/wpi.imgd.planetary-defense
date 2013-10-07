/*******************************************************************************
 * @file        Projectile.h
 * @author      bsautermeister
 * @description The base class for all flying weapons.
 ******************************************************************************/
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include "Object.h"
#include "EventCollision.h"

using std::string;

#define TYPE_PROJECTILE "projectile"

/**
 * Represents the base for all flying weapons.
 */
class Projectile : public Object
{
private:
	/**
	 * Speed of the bullet
	 */
	float _speed;

	/**
	 * Damage the bullet does
	 */
	int _damage;

	/**
	 * The target position.
	 */
	Position _target;

protected:
	/**
	 * Is called when the projectile has moved outside the world.
	 */
    void out(void);

    /**
     * Fly towards enemy target
     */
    void flyTo(void);

    /**
     * Is called when a collusion occured.
     */
    virtual void hit(EventCollision * p_collisionEvent) = 0;


public:
	/**
	 * Creates a new projectile instance.
	 * @param spriteName The name of the sprite file.
	 * @param origin The origin of the the shot.
	 * @param target The target where to shot.
	 * @param speed The speed of the shot.
	 * @param damage The hit damage of the shot.
	 */
    Projectile(string spriteName, Position origin, Position target, float speed, int damage);

    /**
	 * Handles the projectile events.
	 */
    int eventHandler(Event *p_event);

    /**
     * Gets the speed of the projectile.
     * @return The speed.
     */
    float getSpeed(void);

    /**
     * Gets the collision damage.
     * @return The collision damage.
     */
    int getDamage(void);

    /**
     * Gets the target position of the projectile.
     * @return The target position.
     */
    Position getTarget(void);
};

#endif
