/* Hitpoints.cpp */

#include "Hitpoints.h"
#include "GraphicsManager.h"
#include "Hero.h"

/**
 * Creates a new hitpoints instance.
 */
Hitpoints::Hitpoints(void)
{
	// setup text
	setLocation(TOP_LEFT);
	setViewString(HITPOINTS_STRING);
	setColor(COLOR_YELLOW);
}

/**
 * Render the hp bar.
 */
void Hitpoints::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	int startX = getPosition().getX() - 15;

	if (startX < 0)
		startX = 0;

	int startY = getPosition().getY();

	for (int i = 0; i < getViewString().length(); ++i)
	{
		graphicsManager.drawCh(Position(startX++, startY), getViewString().at(i), getColor());
	}

	graphicsManager.drawCh(Position(startX++, startY), ' ', getColor());
	graphicsManager.drawCh(Position(startX++, startY), ':', getColor());
	graphicsManager.drawCh(Position(startX++, startY), ' ', getColor());

	for (int i = 0; i < MAX_HITPOINTS; ++i)
	{
		char val;

		if (getValue() - 1 >= i)
			val = '#';
		else
			val = '-';

		for (int j = 0; j < 2; ++j)
			graphicsManager.drawCh(Position(startX++, startY), val, getColor());

	}
}
