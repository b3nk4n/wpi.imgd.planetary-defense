/*******************************************************************************
 * @file        Sidebar.h
 * @author      bsautermeister
 * @description Manages sidebar by referencing the player object and displaying
 *              player, construction and other information.
 ******************************************************************************/

#ifndef __SIDEBAR_H__
#define __SIDEBAR_H__

#include "ViewObject.h"
#include "Player.h"

using std::string;

#define TYPE_SIDEBAR "sidebar"

/**
 * Represents the game sidebar.
 */
class Sidebar : public ViewObject
{
private:
	/**
	 * The referenced player.
	 */
	Player *_p_player;

public:
	/**
	 * Creates a sidebar object instance.
	 * @param player The assigned player.
	 */
	Sidebar(Player *p_player);

	/**
	 * Cleans up the sidebars allocated resources.
	 */
	virtual ~Sidebar(void);

	/**
	 * Handles all events.
	 * @param p_event Points to the current event to handle.
	 * @return Return 0 if ignored, else 1 if event was handled.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Renders the visual sidebar.
	 */
	virtual void draw(void);
};

#endif
