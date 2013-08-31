/* GameStart.h */

#ifndef GAME_START_H
#define GAME_START_H

#include "ViewObject.h"
#include "EventKeyboard.h"

#define INIT_SAUCER_COUNT 16

class GameStart : public ViewObject
{
private:
	void toCenterOfScreen(void);
	
protected:
	void start(void);
	void keyboard(EventKeyboard *p_keyboardEvent);

public:
	GameStart(void);
	void draw(void);
	int eventHandler(Event *p_event);
};

#endif