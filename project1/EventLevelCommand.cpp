/* EventLevelCommand.cpp */

#include "EventLevelCommand.h"

/**
 * Creates a new level command event.
 */
EventLevelCommand::EventLevelCommand(int command)
{
	setType(LEVEL_COMMAND_EVENT);
	this->command = command;
}

/**
 * Gets the level command.
 */
int EventLevelCommand::getCommand(void)
{
	return this->command;
}
