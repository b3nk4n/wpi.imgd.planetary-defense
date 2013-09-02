/* Powerup.h */

#ifndef POWERUP_H
#define POWERUP_H

#include <string>
#include "Object.h"
#include "EventCollision.h"

using std::string;

class Powerup : public Object
{
private:
	string powerupId;
	
protected:
	void collect();
	void hit(EventCollision * p_collisionEvent);
	void out(void);
	
public:
	Powerup(string spriteName, string powerupId, Position spawnPosition);
	int eventHandler(Event *p_event);
	string getPowerupId(void);
};

#endif