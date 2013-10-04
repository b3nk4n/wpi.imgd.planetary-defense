/* Laser.cpp */

#include "Laser.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Position.h"
#include "EventOut.h"
#include "EventCollision.h"

/**
 * Creates a new laser instance.
 */
Laser::Laser(Position heroPos)
    : Projectile(heroPos, "laser")
{
    // set object type
    setType("Laser");

    // set vertical speed
    setXVelocity(2);

    // set starting location, based on hero position
    Position tempPos(heroPos.getX() + 5, heroPos.getY());
    setPosition(tempPos);
}

/**
 * Is called when the laser is hitting something.
 */
void Laser::hit(EventCollision *p_collisionEvent)
{
   // nothing happens ... just continue flying...
}

