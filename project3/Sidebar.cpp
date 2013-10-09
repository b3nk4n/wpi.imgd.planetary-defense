/*******************************************************************************
 * @file        Sidebar.cpp
 * @author      bsautermeister
 * @description Manages sidebar by referencing the player object and displaying
 *              player, construction and other information.
 ******************************************************************************/

#include "Sidebar.h"
#include "EventStep.h"
#include "GraphicsManager.h"

/**
 * Creates a sidebar object instance.
 * @param player The assigned player.
 */
Sidebar::Sidebar(Player *p_player)
{
	setType(TYPE_PLAYER);
	_p_player = p_player;

	setPosition(Position(52, 2));

	// register for events
	registerInterest(STEP_EVENT);
}

/**
 * Cleans up the sidebars allocated resources.
 */
Sidebar::~Sidebar(void)
{

}

/**
 * Handles all events.
 * @param p_event Points to the current event to handle.
 * @return Return 0 if ignored, else 1 if event was handled.
 */
int Sidebar::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		// TODO: ???
		return 1;
	}

	return 0;
}

/**
 * Renders the visual sidebar.
 */
void Sidebar::draw(void)
{
	// verify player set
	if (_p_player == NULL)
		return;

	GraphicsManager &graphcisManager = GraphicsManager::getInstance();

	Position pos = getPosition();
	pos.setY(pos.getY() + 2);
	graphcisManager.drawStringFormat(pos, "Lifes: %d", _p_player->getLifes());
	pos.setY(pos.getY() + 2);
	graphcisManager.drawStringFormat(pos, "Credits: %d", _p_player->getCredits());
	pos.setY(pos.getY() + 2);
	graphcisManager.drawStringFormat(pos, "Energy: %d", _p_player->getEnergy());
}
