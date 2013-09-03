/* Projectile.cpp */

#include "Projectile.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Position.h"
#include "EventOut.h"
#include "EventCollision.h"

/**
 * Creates a new bullet instance.
 */
Projectile::Projectile(Position heroPos, string spriteName)
{
    // required dragonfly managers
    LogManager &logManager = LogManager::getInstance();
    ResourceManager &resourceManager = ResourceManager::getInstance();
    
    // setup bullet sprite
    Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
    if (!p_tempSprite)
    {
        logManager.writeLog(
            "Projectile::Projectile(): Sprite %s not found",
            spriteName.c_str());
    }
    else
    {
        setSprite(p_tempSprite);
        setSpriteSlowdown(5);
    }
}

/**
 * Handles the bullet events.
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
 * Is called when bullet has moved outside the world.
 */
void Projectile::out(void)
{
    WorldManager &worldManager = WorldManager::getInstance();
    worldManager.markForDelete(this);
}