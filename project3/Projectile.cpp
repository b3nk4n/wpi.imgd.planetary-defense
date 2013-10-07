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

    setPosition(origin);
    _target = target;
    _speed = speed;
    _damage = damage;

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
        setSpriteSlowdown(5);
    }

    // calculate velocity to fly to the enemy
    int dx = _target.getX() - getPosition().getX();
    int dy = _target.getY() - getPosition().getY();
    float mag = distance(_target, getPosition());
    setVelocityX(dx / mag * _speed);
    setVelocityY(dy / mag * _speed);
}

/**
 * Is called when the projectile has moved outside the world.
 */
void Projectile::out(void)
{
    WorldManager &worldManager = WorldManager::getInstance();
    worldManager.markForDelete(this);
}

/**
 * Handles the projectile events.
 */
int Projectile::eventHandler(Event *p_event)
{
    if (p_event->getType() == OUT_EVENT)
    {
        out();
        return 1;
    }

    if (p_event->getType() == COLLISION_EVENT)
    {
        EventCollision *p_collisionEvent = static_cast<EventCollision *>(p_event);
        hit(p_collisionEvent);
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
