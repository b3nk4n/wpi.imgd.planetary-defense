/*******************************************************************************
 * @file        Cannon.cpp
 * @author      bsautermeister
 * @description Cannon bullet that releases a detonation
 *              on hot or reached target.
 ******************************************************************************/

#include "Cannon.h"
#include "EventDetonation.h"

/**
 * Creates a new cannon instance.
 * @param origin The origin of the the shot.
 * @param target The target where to shot.
 */
Cannon::Cannon(Position origin, Position target)
    : Projectile("bullet", origin, target, 1.5f, 1)
{

}

	/**
 * Is called when a collusion occured.
 * @param p_collisionEvent The collision event.
 */
void Cannon::onHit(EventCollision *p_collisionEvent)
{
    WorldManager &worldManager = WorldManager::getInstance();

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

    // splash damage
    EventDetonation event(Circle(getPosition(), DETONATION_RADIUS), DETONATION_DAMAGE);
    worldManager.onEvent(&event);

    // delete cannon projectile
    worldManager.markForDelete(this);
}

/**
 * Is called when a projectile reached the target position without
 * hitting an enemy.
 */
void Cannon::onTargetReached(void)
{
    EventDetonation event(Circle(getPosition(), DETONATION_RADIUS),
        DETONATION_DAMAGE);
    worldManager.onEvent(&event);
}
