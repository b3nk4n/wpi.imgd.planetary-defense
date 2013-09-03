/* GameStart.h */

#ifndef GAME_START_H
#define GAME_START_H

#include "ViewObject.h"
#include "EventKeyboard.h"

#define INIT_SAUCER_COUNT_EASY 10
#define INIT_UFO_COUNT_EASY 2
#define INIT_SAUCER_COUNT_MED 15
#define INIT_UFO_COUNT_MED 3
#define INIT_SAUCER_COUNT_HARD 20
#define INIT_UFO_COUNT_HARD 4

#define MENU_LEVEL 1
#define PLAY_LEVEL 2

#define EASY_STRING " EASY "
#define MEDIUM_STRING "MEDIUM"
#define HARD_STRING " HARD "


#define EASY_DIFF 0
#define MEDIUM_DIFF 1
#define HARD_DIFF 2


class GameStart : public ViewObject
{
private:
	int difficulty;
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