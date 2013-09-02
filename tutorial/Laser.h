/* Laser.h */

#ifndef LASER_H
#define LASER_H

#include "Projectile.h"

class Laser : public Projectile
{
protected:
    void hit(EventCollision * p_collisionEvent);
public:
    Laser(Position heroPos);
};

#endif