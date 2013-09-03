/* Saucer.cpp */

#include "Saucer.h"
#include "LogManager.h"
#include "EventLevelCommand.h"
#include "WorldManager.h"

/**
 * Creates a new saucer instance.
 */
Saucer::Saucer(void)
	: Enemy("saucer", 1, 10, 0.01f, EXPLOSION_SMALL, AUTO_OUT_OF_BOUNDS)
{
	registerInterest(LEVEL_COMMAND_EVENT);

	// set object type
	setType("Saucer");
}

/**
 * Creates a new Saucer.
 */
void Saucer::createEnemy(void)
{
	new Saucer();
}

/**
 * Handles the events.
 */
int Saucer::eventHandler(Event *p_event)
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