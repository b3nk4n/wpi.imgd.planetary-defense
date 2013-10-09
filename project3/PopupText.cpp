/*******************************************************************************
 * @file        PopupText.h
 * @author      bsautermeister
 * @description The upward moving text for text effects.
 ******************************************************************************/

#include "PopupText.h"
#include "EventStep.h"
#include "WorldManager.h"
#include "GraphicsManager.h"

#define TYPE_POPUP_TEXT "popup_text"
#define POPUP_VELOCITY -0.15f
#define POPUP_LIFETIME 25

/**
 * Creates a new popup text instance.
 * @param position The text starting center.
 * @param value The dollar displayed value.
 */
PopupText::PopupText(Position position, int value)
{
	setType(TYPE_POPUP_TEXT);
	setSolidness(SPECTRAL);
	setAltitude(MAX_ALTITUDE);

	setPosition(position);
	_value = value;
	_timeToLive = POPUP_LIFETIME;
	setVelocityY(POPUP_VELOCITY);

	// register events
	registerInterest(STEP_EVENT);
}

/**
 * Handles the events.
 * @param p_event The event.
 */
int PopupText::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		--_timeToLive;

		if (_timeToLive <= 0)
		{
			WorldManager &worldManager = WorldManager::getInstance();
			worldManager.markForDelete(this);
		}
	}
}

/**
 * Renders the popup text.
 */
void PopupText::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();

	graphicsManager.drawStringFormat(getPosition(),
		CENTER_JUSTIFIED,
		"%d $",
		_value);
}
