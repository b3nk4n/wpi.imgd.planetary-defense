/*******************************************************************************
 * @file        FragmentationGrenade.cpp
 * @author      bsautermeister
 * @description Fragmentation grenade bullet that releases a detonation
 *              on hot or reached target.
 ******************************************************************************/

#include "FragmentationGrenade.h"
#include "EventDetonation.h"
#include "LogManager.h"
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
 * Destructos the grenade.
 */
FragmentationGrenade::~FragmentationGrenade(void)
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
	LogManager &logManager = LogManager::getInstance();
    WorldManager &worldManager = WorldManager::getInstance();
    EventDetonation event(Circle(getPosition(), DETONATION_RADIUS),
        getDamage());

    logManager.writeLog(LOG_DEBUG,
        "FragmentationGrenade::onTargetReached()",
        "Before onEvent\n");

    worldManager.onEvent(&event); // FIXME: SEG FAULT here under specific conditions
                                  //        (if markForDelete() is uncommented)

    logManager.writeLog(LOG_DEBUG,
        "FragmentationGrenade::onTargetReached()",
        "After onEvent\n");

    new ExplosionBig(getPosition());

    worldManager.markForDelete(this); // <--- ?!?!?!
}
