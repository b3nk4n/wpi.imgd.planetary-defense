/*******************************************************************************
 * @file        Projectile.h
 * @author      bsautermeister
 * @description The base class for all flying weapons.
 ******************************************************************************/

#include <string>
#include "Projectile.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventOut.h"
#include "EventStep.h"
#include "EventCollision.h"

using std::string;

/**
 * Creates a new projectile instance.
 * @param spriteName The name of the sprite file.
 * @param origin The origin of the the shot.
 * @param target The target where to shot.
 * @param speed The speed of the shot.
 * @param damage The hit damage of the shot.
 */
Projectile::Projectile(string spriteName, Position origin, Position target, float speed, int damage)
{
    // required dragonfly managers
    LogManager &logManager = LogManager::getInstance();
    ResourceManager &resourceManager = ResourceManager::getInstance();
    
    setSolidness(SOFT);
    setType(TYPE_PROJECTILE);
    setAltitude(MAX_ALTITUDE - 1);

    setPosition(origin);
    _target = target;
    _speed = speed;
    _damage = damage;
    _oldDistanceSquared = 99999;

    // setup bullet sprite
    Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
    if (!p_tempSprite)
    {
        logManager.writeLog(
            LOG_ERROR,
            "Projectile::Projectile()",
            "Sprite %s not found",
            spriteName.c_str());
    }
    else
    {
        setSprite(p_tempSprite);
        setSpriteSlowdown(3);
    }

    flyTo(_target);

    // register for events
    registerInterest(STEP_EVENT);
    registerInterest(COLLISION_EVENT);
}

/**
 * Fly towards the target position.
 * @param target The target to fly to.
 */
void Projectile::flyTo(Position target)
{
        // calculate velocity to fly to the enemy
    int dx = target.getX() - getPosition().getX();
    int dy = target.getY() - getPosition().getY();
    float mag = distance(target, getPosition());
    setVelocityX(dx / mag * (_speed));
    setVelocityY(dy / mag * (_speed));
}

/**
 * Handles the projectile events.
 */
int Projectile::eventHandler(Event *p_event)
{
    WorldManager &worldManager = WorldManager::getInstance();

    if (p_event->getType() == STEP_EVENT)
    {
        float newDistanceSquared = distanceSquared(getPosition(), getTarget());

        if (distance(getPosition(), getTarget()) <= 1 ||
            newDistanceSquared > _oldDistanceSquared)
        {
            onTargetReached();
        }
        _oldDistanceSquared = newDistanceSquared;
        return 0; // forwared event
    }

    if (p_event->getType() == OUT_EVENT)
    {
        worldManager.markForDelete(this);
        return 1;
    }

    if (p_event->getType() == COLLISION_EVENT)
    {
        EventCollision *p_collisionEvent = static_cast<EventCollision *>(p_event);
        onHit(p_collisionEvent);
        return 1;
    }

    return 0;
}

/**
 * Gets the speed of the projectile.
 * @return The speed.
 */
float Projectile::getSpeed(void)
{
    return _speed;
}

/**
 * Gets the collision damage.
 * @return The collision damage.
 */
int Projectile::getDamage(void)
{
    return _damage;
}

/**
 * Gets the target position of the projectile.
 * @return The target position.
 */
Position Projectile::getTarget(void)
{
    return _target;
}
