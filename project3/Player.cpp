/*******************************************************************************
 * @file        Player.cpp
 * @author      bsautermeister
 * @description Manages the player instance and contains all the players
 *              attributes like scoring, lifes, energy,...
 ******************************************************************************/

#include "Player.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventEnemyInvasion.h"
#include "EventEnemyKilled.h"
#include "EventWaveOver.h"
#include "EventPlayerKilled.h"
#include "EventBuildingChanged.h"
#include "PlanetMenu.h"

// Static pointer used to ensure a single instance of the class.
Player* Player::_p_instance = NULL;

/**
 * Creates a player object instance.
 */
Player::Player(void)
{
	setType(TYPE_PLAYER);

	reset();

	setVisibility(false);

	_pause = false;

	// register for events
	registerInterest(ENEMY_INVASION_EVENT);
	registerInterest(ENEMY_KILLED_EVENT);
	registerInterest(BUILDING_CHANGED_EVENT);
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
	LogManager &logManager = LogManager::getInstance();

	if (p_event->getType() == WAVE_OVER_EVENT)
	{
		_credits = _credits + 100;
		logManager.writeLog(LOG_DEBUG,
			"Player::eventHandler()",
			"Wave over event recieved.",
			_lifes);
	}
	
	if (p_event->getType() == ENEMY_INVASION_EVENT)
	{
		if (_lifes > 0)
			--_lifes;

		if (_lifes <= 0)
		{
			WorldManager &worldManager = WorldManager::getInstance();
			EventPlayerKilled eventKilled;
			worldManager.onEvent(&eventKilled);
		}

		logManager.writeLog(LOG_DEBUG,
			"Player::eventHandler()",
			"Enemy invasion event received. Remaining lifes: %d\n",
			_lifes);

		return 1;
	}

	if (p_event->getType() == ENEMY_KILLED_EVENT)
	{
		EventEnemyKilled *p_eventEnemyKilled = static_cast<EventEnemyKilled *>(p_event);
		_credits += p_eventEnemyKilled->getCredits();

		logManager.writeLog(LOG_DEBUG,
			"Player::eventHandler()",
			"Enemy killed event received. Current credits: %d\n",
			_credits);

		return 1;
	}

	if (p_event->getType() == BUILDING_CHANGED_EVENT)
	{
		EventBuildingChanged *p_eventBuildingChanged = static_cast<EventBuildingChanged *>(p_event);
		
		_credits += p_eventBuildingChanged->getCreditsDelta();
		_energy += p_eventBuildingChanged->getEnergyDelta();

		logManager.writeLog(LOG_DEBUG,
			"Player::eventHandler()",
			"Building changed event received. Current credits: %d and energy: %d\n",
			_credits,
			_energy);

		return 1;
	}

	return 0;
}

/**
 * Resets the player data.
 */
void Player::reset(void)
{
	_lifes = INIT_LIFES;
	_credits = INIT_CREDITS;
	_energy = INIT_ENERGY;
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

/**
 * Adds specified number of credits
 * @param int, number of credits to add
 */
void Player::addCredits(int credits)
{
	_credits = _credits + credits;
}


/**
 * Switch pause on and off
 */
void Player::togPause(void)
{
	if (_pause == false){
		_pause = true;
	}
	else {
		_pause = false;
	}
}

/**
 * Get pause value
 * @return bool, wheether paused or not
 */
bool Player::getPause(void)
{
	return _pause;
}