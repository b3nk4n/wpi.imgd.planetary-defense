/* GameOver.h */

#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "ViewObject.h"

class GameOver : public ViewObject
{
private:
	void toCenterOfScreen(void);
	
protected:
	int timeToLive;
	void step(void);

public:
	GameOver(void);
	~GameOver(void);
	void draw(void);
	int eventHandler(Event *p_event);
};

#endif