/* EventLevelCommand.h */

#ifndef EVENT_LEVEL_COMMAND_H
#define EVENT_LEVEL_COMMAND_H

#include "Event.h"
#include "Circle.h"

#define LEVEL_COMMAND_EVENT "level_command"

#define COMMAND_STOP_ENEMY 0
#define COMMAND_STOP_BOSS 1
#define COMMAND_BOSS_KILLED 2

class EventLevelCommand : public Event
{
private:
	int command;
public:
	/**
	 * Creates a new level command event.
	 */
	EventLevelCommand(int command);
	/**
	 * Gets the event command.
	 */
	int getCommand(void);
};

#endif