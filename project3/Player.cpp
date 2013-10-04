/*******************************************************************************
* @file        Player.cpp
* @author      bsautermeister
* @description Manages the player instance and contains all the players
*              attributes like scoring, lifes, energy,...
******************************************************************************/

#include "Player.h"

// Static pointer used to ensure a single instance of the class.
Player* Player::_p_instance = NULL;

/**
 * Creates a player object instance.
 */
Player::Player(void)
{
	setType(TYPE_PLAYER);

	_lifes = INIT_LIFES;
	_credits = INIT_CREDITS;
	_energy = INIT_ENERGY;
}

/**
 * Hides copy constrctor.
 */
Player::Player(Player const&)
{
}

/**
 * Hides assignment operator.
 */
Player& Player::operator=(Player const&)
{
}

/**
 * Cleans up the player allocated resources.
 */
Player::~Player(void)
{
}

/**
 * Gets the singleton player object instance.
 * @note Singleton required, because other instances might access
 *       the player attributes and also, there is always just one player.
 * @return The singleton map object instance.
 */
Player* Player::getInstance(void)
{
	if (!_p_instance)
		_p_instance = new Player();
	return _p_instance;
}

/**
 * Handles all events.
 * @param p_event Points to the current event to handle.
 * @return Return 0 if ignored, else 1 if event was handled.
 */
int Player::eventHandler(Event *p_event)
{

}

/**
 * Suppresses rendering of the player. (TODO: OR RENDER SIDEBAR ???)
 */
void Player::draw(void)
{
	// TODO: sidebar rendering here ???
}

/**
 * Indicates whether the player is dead or not.
 * @return Returns TRUE if the player is dead, else FLASE.
 */
bool Player::isDead(void)
{
	return _lifes > 0;
}

/**
 * Gets the players lifes.
 * @return The players lifes.
 */
int Player::getLifes(void)
{
	return _lifes;
}

/**
 * Gets the players credits.
 * @return The players credits.
 */
int Player::getCredits(void)
{
	return _credits;
}

/**
 * Gets the players energy.
 * @return The players energy.
 */
int Player::getEnergy(void)
{
	return _energy;
}
