/* Ufo.cpp */

#include "Ufo.h"
#include "EventLevelCommand.h"
#include "WorldManager.h"

/**
 * Creates a new Ufo instance.
 */
Ufo::Ufo(void)
	: Enemy("ufo", 2, 50, 0.175f, EXPLOSION_LARGE, AUTO_OUT_OF_BOUNDS)
{
	registerInterest(LEVEL_COMMAND_EVENT);

	// set object type
	setType("Ufo");
}

/**
 * Creates a new Ufo.
 */
void Ufo::createEnemy(void)
{
	new Ufo();
}

/**
 * Handles the events.
 */
int Ufo::eventHandler(Event *p_event)
{
	if (Enemy::eventHandler(p_event))
		return 1;

	if (p_event->getType() == LEVEL_COMMAND_EVENT)
	{
		EventLevelCommand *event_levelCommand = static_cast<EventLevelCommand *>(p_event);

		if (event_levelCommand->getCommand() == COMMAND_STOP_ENEMY)
		{
			this->canCreateEnemy = false;

			WorldManager &worldManager = WorldManager::getInstance();

			// delete this enemy, if enemy not visible
			if (this->getPosition().getX() > worldManager.getBoundary().getHorizontal() + 5)
			{
				worldManager.markForDelete(this);
			}
		}

		return 1;
	}

	return 0;
}