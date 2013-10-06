/*******************************************************************************
* @file        Bullet.cpp
* @author      kcbryant
* @description The base class for all bullets, no matter the kind.
******************************************************************************/

#include <string>
#include "LogManager.h"
#include "Bullet.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Enemy.h"
#include "Tower.h"
#include "EventStep.h"
#include "Object.h"
#include "EventCollision.h"
#include "EventOut.h"

/**
 * Creates a new bullet that fires at specified enemy
 * @param string, the bullet type
 * @param float, speed of the bullet
 * @param int, radius of the explosion
 * @param int, damage the bullet causes
 * @param Tower, that spawned bullet
 * @param Enemy, target enemy of bullet
 */
Bullet::Bullet(string type, float speed, int radius, int damage, Tower *spawner, Object *target)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	setType(TYPE_BULLET);
	_type = type;
	_speed = speed;
	_radius = radius;
  _damage = damage;
	_spawner = spawner;
	_target = target;

	Sprite *p_tempSprite = resourceManager.getSprite(type);
  	if (!p_tempSprite)
  	{
  		logManager.writeLog(LOG_ERROR,
  			"Bullet::Bullet()",
  			"Loading sprite failed.\n");
  	}
  	else
  	{
  		setSprite(p_tempSprite);
    	setSpriteSlowdown(10);	
  	}
  	setPosition(spawner->getPosition());
    flyTo();
    // register for events
    registerInterest(STEP_EVENT);
}

void Bullet::flyTo(void)
{
    // adjust velocity/direction
  int currentX = getPosition().getX();
  int currentY = getPosition().getY();
  int nextX = _target->getPosition().getX();
  int nextY = _target->getPosition().getY();

  if (nextY > currentY)
  {
    setVelocityY(_speed);
  }
  else if (nextY < currentY)
  {
    setVelocityY(-_speed);
  }
  if (nextX > currentX)
  {
    setVelocityX(_speed);
  }
  else
  {
    setVelocityX(-_speed);
  }
}

/**
 * Handle events
 * @param p_event The event.
 * @return Returns 1 if event was handled, else 0.
 */
int Bullet::eventHandler(Event *p_event)
{
  if (p_event->getType() == STEP_EVENT)
  {   
      flyTo();
      return 1;
  }

  if (p_event->getType() == COLLISION_EVENT)
  {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.markForDelete(_target);
    world_manager.markForDelete(this);
    //EventCollision *p_collision_event = static_cast <EventCollision *> (p_event);
    //hit(p_collision_event);
    return 1;
  }

  return 0;
}


// if saucer and player collide, mark both for deletion
void Bullet::hit(EventCollision *p_c) {

        WorldManager &world_manager = WorldManager::getInstance();
        world_manager.markForDelete(_target);
        world_manager.markForDelete(this);
}