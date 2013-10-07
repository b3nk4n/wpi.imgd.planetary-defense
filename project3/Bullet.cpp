/*******************************************************************************
 * @file        Bullet.cpp
 * @author      kcbryant
 * @description The base class for all bullets, no matter the kind.
 ******************************************************************************/

#include "Bullet.h"
#include "WorldManager.h"
#include "Enemy.h"

/**
 * Creates a new bullet instance.
 * @param origin The origin of the the shot.
 * @param target The target where to shot.
 */
Bullet::Bullet(Position origin, Position target)
  : Projectile("bullet", origin, target, 0.02f, 5)
{

}


/**
 * Is called when a collusion occured.
 * @param p_collisionEvent The collision event.
 */
void Bullet::hit(EventCollision *p_collisionEvent)
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
  
  // delete bullet
  WorldManager &worldManager = WorldManager::getInstance();
  worldManager.markForDelete(this);
}
