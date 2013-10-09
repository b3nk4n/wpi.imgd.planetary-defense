/*******************************************************************************
 * @file        Laser.cpp
 * @author      bsautermeister
 * @description Laser that flies through enemies with slight damage.
 ******************************************************************************/

#include "Laser.h"
#include "Enemy.h"
#include "WorldManager.h"
#include "EventStep.h"

/**
 * Creates a new laser instance.
 * @param origin The origin of the the shot.
 * @param target The target where to shot.
 * @param firePower The fire power.
 */
Laser::Laser(Position origin, Position target, int firePower)
    : Projectile("laser", origin, target, 2.0f, firePower)
{
    _timeToLive = LASER_LIFE_TIME;
}

/**
 * Handles the laser events.
 */
int Laser::eventHandler(Event *p_event)
{
    WorldManager &worldManager = WorldManager::getInstance();

    if (Projectile::eventHandler(p_event))
        return 1;

    if (p_event->getType() == STEP_EVENT)
    {
        --_timeToLive;

        if (_timeToLive == 0)
        {
            worldManager.markForDelete(this);
        }
        return 1;
    }

    return 0;
}

	/**
 * Is called when a collusion occured.
 * @param p_collisionEvent The collision event.
 */
void Laser::onHit(EventCollision *p_collisionEvent)
{
    // verify that the collision was with an enemy.
    if (p_collisionEvent->getObject1()->getType() != TYPE_ENEMY &&
        p_collisionEvent->getObject2()->getType() != TYPE_ENEMY)
        return;

    // add damage to enemy
    Enemy *p_enemy;
    if (p_collisionEvent->getObject1()->getType() == TYPE_ENEMY)
    {
        p_enemy = static_cast<Enemy *>(p_collisionEvent->getObject1());
    }
    else
    {
        p_enemy = static_cast<Enemy *>(p_collisionEvent->getObject2());
    }
    p_enemy->addDamage(getDamage());
}

/**
 * Is called when a laser reached the target positoin without
 * hitting an enemy.
 */
void Laser::onTargetReached(void)
{
    // do nothing
}
