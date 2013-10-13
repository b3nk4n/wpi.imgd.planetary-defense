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
#include "EventInfo.h"
#include "EventWaveInfo.h"

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

	/**
	 * The frame for a solar panel.
	 */
	Frame _solarFrame;

	/**
	 * The frame for a machine gun tower.
	 */
	Frame _machineGunFrame;

	/**
	 * The frame for a grenade tower.
	 */
	Frame _grenadeFrame;

	/**
	 * The frame for a laser tower.
	 */
	Frame _laserFrame;

	/**
	 * The frame for a tesla tower.
	 */
	Frame _teslaFrame;

	/**
	 * The copy of the last info event.
	 */
	EventInfo _lastInfo;

	/**
	 * The copy of the last wave info event.
	 */
	EventWaveInfo _lastWaveInfo;

	/**
	 * The time for the next wave.
	 */
	int _nextWaveTimer;

	/**
	 * Indicates whether a wave info is available to render.
	 */
	bool _lastWaveInfoAvailable;

	/**
	 * Loads the first frame.
	 * @param spriteName The name of the sprite
	 * @return The loaded frame in case of success,
	 *         else an empty frame.
	 */
	Frame loadFrame(string spriteName);

	/**
	 * Renders a bulding.
	 * @param position The top left position.
	 * @param key The keyboard key char.
	 * @param frame The frame of the building.
	 * @param name The display name of the building.
	 * @param credits The cost of the building.
	 * @param energy The energy value of the building.
	 */
	void drawBuilding(Position position, char key,
		Frame frame, string name, int credits, int energy);

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

	/**
	 * Gets the width.
	 * @return The width.
	 */
	int getHorizontal(void);

	/**
	 * Gets the height.
	 * @return The height.
	 */
	int getVertical(void);
};

#endif
