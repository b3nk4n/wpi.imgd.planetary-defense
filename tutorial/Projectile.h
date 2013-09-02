/* Projectile.h */

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include "Object.h"
#include "EventCollision.h"

using std::string;

class Projectile : public Object
{
protected:
    void out(void);
    virtual void hit(EventCollision * p_collisionEvent) = 0;
public:
    Projectile(Position heroPos, string spriteName);
    int eventHandler(Event *p_event);
};

#endif