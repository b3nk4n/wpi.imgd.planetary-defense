/*******************************************************************************
 * @file        FragmentationGrenade.cpp
 * @author      bsautermeister
 * @description Fragmentation grenade bullet that releases a detonation
 *              on hot or reached target.
 ******************************************************************************/

#include "FragmentationGrenade.h"
#include "EventDetonation.h"
#include "WorldManager.h"
#include "Enemy.h"
#include "ExplosionBig.h"

/**
 * Creates a new frag granate instance.
 * @param origin The origin of the the shot.
 * @param target The target where to shot.
 * @param firePower The fire power.
 */
FragmentationGrenade::FragmentationGrenade(Position origin, Position target, int firePower)
    : Projectile("grenade", origin, target, 2.0f, firePower)
{

}

/**
 * Is called when a collusion occured.
 * @param p_collisionEvent The collision event.
 */
void FragmentationGrenade::onHit(EventCollision *p_collisionEvent)
{
    // do nothing
}

/**
 * Is called when a projectile reached the target position without
 * hitting an enemy.
 */
void FragmentationGrenade::onTargetReached(void)
{
    WorldManager &worldManager = WorldManager::getInstance();
    EventDetonation event(Circle(getPosition(), DETONATION_RADIUS),
        getDamage());
    worldManager.onEvent(&event);

    new ExplosionBig(getPosition());

    worldManager.markForDelete(this);
}
