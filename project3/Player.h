/*******************************************************************************
 * @file        Player.h
 * @author      bsautermeister
 * @description Manages the player instance and contains all the players
 *              attributes like scoring, lifes, energy,...
 ******************************************************************************/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Object.h"

using std::string;

#define TYPE_PLAYER "player"

#define INIT_LIFES 10
#define INIT_CREDITS 1250
#define INIT_ENERGY 10

/**
 * Represents the player and its attributes.
 */
class Player : public Object
{
private:
	/**
	 * The singleton instance variable. Implemented this way with an 
	 * instance variable instead of a local static variable, because 
	 * each object must be created with 'new'.
	 */
	static Player *_p_instance;

	/**
	 * The players lifes.
	 */
	int _lifes;

	/**
	 * The players credits to buy buildings.
	 */
	int _credits;

	/**
	 *	The players energy.
	 */
	int _energy;

    /**
	 * Creates a player object instance.
	 */
	Player(void);

	/**
	 * Hides copy constrctor.
	 */
	Player(Player const&);

	/**
	 * Hides assignment operator.
	 */
	Player& operator=(Player const&);

public:

	/**
	 * Cleans up the player allocated resources.
	 */
	virtual ~Player(void);

	/**
	 * Gets the singleton player object instance.
	 * @note Singleton required, because other instances might access
	 *       the player attributes and also, there is always just one player.
	 * @return The singleton map object instance.
	 */
	static Player* getInstance(void);

	/**
	 * Resets the player data.
	 */
	void reset(void);

	/**
	 * Handles all events.
	 * @param p_event Points to the current event to handle.
	 * @return Return 0 if ignored, else 1 if event was handled.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Indicates whether the player is dead or not.
	 * @return Returns TRUE if the player is dead, else FLASE.
	 */
	bool isDead(void);

	/**
	 * Gets the players lifes.
	 * @return The players lifes.
	 */
	int getLifes(void);

	/**
	 * Gets the players credits.
	 * @return The players credits.
	 */
	int getCredits(void);

	/**
	 * Gets the players energy.
	 * @return The players energy.
	 */
	int getEnergy(void);
};

#endif
