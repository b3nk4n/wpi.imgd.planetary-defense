/*******************************************************************************
 * @file        Sidebar.cpp
 * @author      bsautermeister
 * @description Manages sidebar by referencing the player object and displaying
 *              player, construction and other information.
 ******************************************************************************/

#include "Sidebar.h"
#include "EventStep.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "SolarBuilding.h"
#include "MachineGunTower.h"
#include "LaserTower.h"
#include "GrenadeTower.h"
#include "TeslaTower.h"
#include "TowerDefenseController.h"
#include "EventInfo.h"
#include "EventPlayerKilled.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventSkipTime.h"

/**
 * Creates a sidebar object instance.
 * @param player The assigned player.
 */
Sidebar::Sidebar(Player *p_player)
{
	setType(TYPE_PLAYER);
	_p_player = p_player;

	// load building frames
  	_solarFrame = loadFrame("solar");
	_machineGunFrame = loadFrame("mgtower");
	_grenadeFrame = loadFrame("grenadetower");
	_laserFrame = loadFrame("lasertower");
	_teslaFrame = loadFrame("teslatower");

	_lastWaveInfoAvailable = false;
	_nextWaveTimer = 0;

	// register for events
	registerInterest(STEP_EVENT);
	registerInterest(INFO_EVENT);
	registerInterest(PLAYER_KILLED_EVENT);
	registerInterest(WAVE_INFO_EVENT);
	registerInterest(SKIP_TIME_EVENT);
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
		Player *p_player = Player::getInstance();
		if (p_player->getPause() == false){
			if (_nextWaveTimer > 0)
				--_nextWaveTimer;
			return 1;
		}
	} 
	else if (p_event->getType() == PLAYER_KILLED_EVENT)
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
		return 1;
	} 
	else if (p_event->getType() == INFO_EVENT)
	{
		EventInfo *p_eventInfo = static_cast<EventInfo *>(p_event);
		// get a copy of the info.
		_lastInfo = *p_eventInfo;

		return 1;
	}
	else if (p_event->getType() == WAVE_INFO_EVENT)
	{
		EventWaveInfo *p_eventWaveInfo = static_cast<EventWaveInfo *>(p_event);
		// get a copy of the wave info.
		_lastWaveInfo = *p_eventWaveInfo;

		_lastWaveInfoAvailable = true;
		_nextWaveTimer = _lastWaveInfo.getCooldown();

		return 1;
	}
	else if (p_event->getType() == SKIP_TIME_EVENT)
	{
  		if (_nextWaveTimer > 90)
  			_nextWaveTimer = 90;
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

	// player info
	graphcisManager.drawString(pos, "############ PLAYER ############",
		LEFT_JUSTIFIED,
		COLOR_CYAN);
	pos.setY(pos.getY() + 2);

	int lifeColor = COLOR_DEFAULT;

	if (_p_player->getLifes() < 4)
		lifeColor = COLOR_YELLOW;
	if (_p_player->getLifes() < 2)
		lifeColor = COLOR_RED;

	graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, lifeColor, " Lifes:      %5d", _p_player->getLifes());
	pos.setY(pos.getY() + 1);

	int creditsColor = COLOR_DEFAULT;

	if (_p_player->getCredits() < 200)
		lifeColor = COLOR_YELLOW;
	if (_p_player->getCredits() < 100)
		lifeColor = COLOR_RED;

	graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, lifeColor, " Credits:    %5d $", _p_player->getCredits());
	pos.setY(pos.getY() + 1);

	int energyColor = COLOR_DEFAULT;

	if (_p_player->getEnergy() < 5)
		energyColor = COLOR_YELLOW;
	if (_p_player->getEnergy() < 3)
		energyColor = COLOR_RED;

	graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, energyColor, " Energy:     %5d Volt", _p_player->getEnergy());
	pos.setY(pos.getY() + 2);

	// building info
	graphcisManager.drawString(pos, "######## CONSTRUCTIONS  ########",
		LEFT_JUSTIFIED,
		COLOR_CYAN);
	pos.setY(pos.getY() + 2);
	drawBuilding(pos,
		KEY_SOLAR,
		_solarFrame,
		BUILDING_SOLAR,
		INIT_PRICE_SOLAR,
		INIT_ENERGY_SOLAR,
		COLOR_BLUE);
	pos.setY(pos.getY() + 4);
	drawBuilding(pos,
		KEY_MACHINE_GUN,
		_machineGunFrame,
		TOWER_MACHINE_GUN,
		INIT_PRICE_MACHINE_GUN,
		INIT_ENERGY_MACHINE_GUN,
		COLOR_GREEN);
	pos.setY(pos.getY() + 4);
	drawBuilding(pos,
		KEY_GRENADE,
		_grenadeFrame,
		TOWER_GRENADE,
		INIT_PRICE_GRENADE,
		INIT_ENERGY_GRENADE,
		COLOR_CYAN);
	pos.setY(pos.getY() + 4);
	drawBuilding(pos,
		KEY_LASER,
		_laserFrame,
		TOWER_LASER,
		INIT_PRICE_LASER,
		INIT_ENERGY_LASER,
		COLOR_MAGENTA);
	pos.setY(pos.getY() + 4);
	drawBuilding(pos,
		KEY_TESLA,
		_teslaFrame,
		TOWER_TESLA,
		INIT_PRICE_TESLA,
		INIT_ENERGY_TESLA,
		COLOR_RED);
	pos.setY(pos.getY() + 4);

	// special keys
	graphcisManager.drawString(pos, "######### SPECIAL KEYS #########",
		LEFT_JUSTIFIED,
		COLOR_CYAN);
	pos.setY(pos.getY() + 2);
	graphcisManager.drawStringFormat(pos, " [%c] Toggle enemy info", KEY_INFO);
	pos.setY(pos.getY() + 1);
	graphcisManager.drawStringFormat(pos, " [%c] Upgrade tower", KEY_UPGRADE);
	pos.setY(pos.getY() + 1);
	graphcisManager.drawStringFormat(pos, " [%c] Sell building", KEY_SELL);
	pos.setY(pos.getY() + 1);
	graphcisManager.drawStringFormat(pos, " [%c] Skip wave waiting time", KEY_SKIPTIME);
	pos.setY(pos.getY() + 1);
	graphcisManager.drawStringFormat(pos, " [%c] Quit game", KEY_QUITGAME);
	pos.setY(pos.getY() + 2);
	graphcisManager.drawStringFormat(pos, " [SPACE] Pause the Game");
	pos.setY(pos.getY() + 1);
	graphcisManager.drawStringFormat(pos, "You can build and sell in pause");
	pos.setY(pos.getY() + 2);

	// cursor selection info
	graphcisManager.drawString(pos, "############# INFO #############",
		LEFT_JUSTIFIED,
		COLOR_CYAN);
	pos.setY(pos.getY() + 2);

	if (_lastWaveInfoAvailable)
	{
		graphcisManager.drawStringFormat(pos, " Wave:       %d/%d",
			_lastWaveInfo.getCurrentWave(),
			_lastWaveInfo.getTotalWaves());
		pos.setY(pos.getY() + 1);
		if (_nextWaveTimer > 0)
		{
			int arrivalColor = COLOR_DEFAULT;

			if (_nextWaveTimer < 150)
				arrivalColor = COLOR_YELLOW;
			if (_nextWaveTimer < 90)
				arrivalColor = COLOR_RED;

			graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, arrivalColor, " Arrival:    %d sec",
			_nextWaveTimer / 30 + 1);
		}
		else
		{
			graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, COLOR_RED, " Arrival:    %s", "INCOMING!");
		}
		pos.setY(pos.getY() + 1);
		graphcisManager.drawStringFormat(pos, " Name:       %s", _lastWaveInfo.getName().c_str());
		pos.setY(pos.getY() + 1);
		graphcisManager.drawStringFormat(pos, " Count:      %d", _lastWaveInfo.getCount());
		pos.setY(pos.getY() + 2);
	}

	if (_lastInfo.getInfoType() != NONE)
	{
		graphcisManager.drawStringFormat(pos, " Name:       %s", _lastInfo.getName().c_str());
		pos.setY(pos.getY() + 1);
		graphcisManager.drawStringFormat(pos, " Sell price: %5d $", _lastInfo.getSellingPrice());
		pos.setY(pos.getY() + 1);
		graphcisManager.drawStringFormat(pos, " Energy:     %5d Volt", _lastInfo.getSellingEnergy());
		pos.setY(pos.getY() + 1);

		// additional tower data
		if (_lastInfo.getInfoType() == TOWER)
		{
			if (_lastInfo.getLevel() < MAX_UPGRADE_LEVEL)
			{
				graphcisManager.drawStringFormat(pos, " Level:      %5d", _lastInfo.getLevel());
				pos.setY(pos.getY() + 1);

				int upgradeColor = COLOR_GREEN;

				if (_lastInfo.getUpgradePrice() > _p_player->getCredits() ||
					_lastInfo.getUpgradeEnergy() > _p_player->getEnergy())
					upgradeColor = COLOR_RED;

				graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, upgradeColor, " Upgrade:    %5d $, %d Volt", _lastInfo.getUpgradePrice(), _lastInfo.getUpgradeEnergy());
				pos.setY(pos.getY() + 1);
			}
			else
			{
				graphcisManager.drawStringFormat(pos, LEFT_JUSTIFIED, COLOR_GREEN, " Level:        MAX");
				pos.setY(pos.getY() + 2);
			}
			graphcisManager.drawStringFormat(pos, " Fire rate:   %1.2f /sec", 30.0 / _lastInfo.getFireRate());
			pos.setY(pos.getY() + 1);
			graphcisManager.drawStringFormat(pos, " Fire power: %5d", _lastInfo.getFirePower());
			pos.setY(pos.getY() + 1);
			graphcisManager.drawStringFormat(pos, " Fire range: %5d miles", _lastInfo.getFireRange());
			pos.setY(pos.getY() + 2);
		}
		else
		{
			pos.setY(pos.getY() + 4);
		}
	}
	else
	{
		pos.setY(pos.getY() + 7);
	}
}

/**
 * Renders a bulding.
 * @param position The top left position.
 * @param key The keyboard key char.
 * @param frame The frame of the building.
 * @param name The display name of the building.
 * @param credits The cost of the building.
 * @param energy The energy value of the building.
 * @param color The color.
 */
void Sidebar::drawBuilding(Position position, char key,
	Frame frame, string name, int credits, int energy, int color)
{
	GraphicsManager &graphcisManager = GraphicsManager::getInstance();

	position.setY(position.getY() + 1);
	position.setX(position.getX() + 1);
	graphcisManager.drawStringFormat(position, "[%c]", key);
	position.setX(position.getX() + 4);
	position.setY(position.getY() - 1);

	graphcisManager.drawFrame(position,
		frame,
		false,
		color);

	position.setX(position.getX() + frame.getWidth() + 1);
	graphcisManager.drawStringFormat(position, "Name:   %s",
		name.c_str());
	position.setY(position.getY() + 1);

	int priceColor = COLOR_DEFAULT;

	if (_p_player->getCredits() < credits)
		priceColor = COLOR_RED;

	graphcisManager.drawStringFormat(position, LEFT_JUSTIFIED, priceColor, "Price:  %5d $", credits);
	position.setY(position.getY() + 1);

	int energyColor = COLOR_DEFAULT;

	if (_p_player->getEnergy() < energy)
		energyColor = COLOR_RED;

	graphcisManager.drawStringFormat(position, LEFT_JUSTIFIED, energyColor, "Energy: %5d Volt", energy);
}

/**
 * Loads the first frame.
 * @param spriteName The name of the sprite
 * @return The loaded frame in case of success,
 *         else an empty frame.
 */
Frame Sidebar::loadFrame(string spriteName)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	// load solar frame
	Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
  	if (!p_tempSprite)
  	{
  		logManager.writeLog(LOG_ERROR,
  			"Sidebar::Sidebar()",
  			"Loading sprite '%s' failed.\n",
  			spriteName.c_str());
  		Frame empty;
  		return empty;
  	}

  	return p_tempSprite->getFrame(0);
}

/**
 * Gets the width.
 * @return The width.
 */
int Sidebar::getHorizontal(void)
{
	// hard coded
	return 32;
}

/**
 * Gets the height.
 * @return The height.
 */
int Sidebar::getVertical(void)
{
	// hard coded
	return 55;
}
