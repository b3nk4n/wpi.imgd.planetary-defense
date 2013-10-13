/*******************************************************************************
 * @file        TowerDefenseController.cpp
 * @author      bsautermeister
 * @description Manages the map and the cursor. Also, it is implemented as a
 *              singleton, so e.g. enemies can get map information using this
 *              manager class.
 ******************************************************************************/

#include "TowerDefenseController.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "EventKeyboard.h"
#include "EventInfo.h"
#include "EventEnemyKilled.h"
#include "Player.h"
#include "SolarBuilding.h"
#include "Building.h"
#include "Tower.h"
#include "MachineGunTower.h"
#include "GrenadeTower.h"
#include "LaserTower.h"
#include "TeslaTower.h"
#include "PopupText.h"
#include "EventPlayerKilled.h"
#include "EventPlayerWin.h"
#include "EventSkipTime.h"
#include "GameOver.h"
#include "Player.h"
#include "utility.h"

// Static pointer used to ensure a single instance of the class.
TowerDefenseController* TowerDefenseController::_p_instance = NULL;

/**
 * Creates a map object instance.
 */
TowerDefenseController::TowerDefenseController(void)
{
	_p_currentMapData = NULL;
	_p_spawner = NULL;
	_selectedCell = Position(0, 0);
	_p_cursor = NULL;
	_p_sidebar = NULL;
	_p_player = NULL;

	setCentered(false);

	// register for interest:
	registerInterest(KEYBOARD_EVENT);
	registerInterest(ENEMY_KILLED_EVENT);
	registerInterest(PLAYER_KILLED_EVENT);
	registerInterest(PLAYER_WIN_EVENT);
}

/**
 * Hides copy constrctor.
 */
TowerDefenseController::TowerDefenseController(TowerDefenseController const &mo)
{
}

/**
 * Hides assignment operator.
 */
TowerDefenseController& TowerDefenseController::operator=(TowerDefenseController const &mo)
{
}

/**
 * Cleans up the map manager allocated resources.
 */
TowerDefenseController::~TowerDefenseController(void)
{
	if (_p_cursor != NULL)
		delete _p_cursor;

	if (_p_spawner != NULL)
		delete _p_spawner;

	if (_p_sidebar != NULL)
		delete _p_sidebar;

	if (_p_player != NULL)
		delete _p_player;
}

/**
 * Gets the singleton map object instance.
 * @note Singleton required, because other objects like enemies should have
 *       access to the map object properties.
 * @return The singleton map object instance.
 */
TowerDefenseController* TowerDefenseController::getInstance(void)
{
	if (!_p_instance)
		_p_instance = new TowerDefenseController();
	return _p_instance;
}

/**
 * Resets the dower defense game.
 */
void TowerDefenseController::reset(void)
{
	if (_p_cursor != NULL)
		delete _p_cursor;

	if (_p_spawner != NULL)
		delete _p_spawner;

	if (_p_sidebar != NULL)
		delete _p_sidebar;

	if (_p_player != NULL)
		delete _p_player;

	_p_spawner = new Spawner();
	_selectedCell = Position(0, 0);
	_p_cursor = new VirtualCursor(_selectedCell);
	_p_player = Player::getInstance();
	_p_player->reset();
	_p_sidebar = new Sidebar(_p_player);

	setVisibility(true);

	// TODO: reset grid?
}

/**
 * Handles all events.
 * @param p_event Points to the current event to handle.
 * @return Return 0 if ignored, else 1 if event was handled.
 */
int TowerDefenseController::eventHandler(Event *p_event)
{	
	if (p_event->getType() == PLAYER_KILLED_EVENT)
	{
		this->setVisibility(false);
		_p_sidebar->setVisibility(false);
		_p_cursor->setVisibility(false);
		_p_spawner->stop();

		for (int i = 0; i < STARS_COUNT; ++i)
		{
			_stars[i].setVisibility(false);
		}

		// show game over screen
		new GameOver(false);
	}
	else if (p_event->getType() == PLAYER_WIN_EVENT)
	{
		this->setVisibility(false);
		_p_sidebar->setVisibility(false);
		_p_cursor->setVisibility(false);
		_p_spawner->stop();

		for (int i = 0; i < STARS_COUNT; ++i)
		{
			_stars[i].setVisibility(false);
		}

		// show game over screen
		new GameOver(true);
	} 
	else if (p_event->getType() == KEYBOARD_EVENT)
	{
		Cell *p_cell;
		Building *p_building;
		EventKeyboard *p_eventKeyboard = static_cast<EventKeyboard *>(p_event);
		Player *p_player = Player::getInstance();
		WorldManager &worldManager = WorldManager::getInstance();
		LogManager &logManager = LogManager::getInstance();

		int input = p_eventKeyboard->getKey();

		switch(input)
		{
		case LEFT_KEY:
			moveCursor(-1, 0);
			break;

		case RIGHT_KEY:
			moveCursor(1, 0);
			break;

		case UP_KEY:
			moveCursor(0, -1);
			break;

		case DOWN_KEY:
			moveCursor(0, 1);
			break;

		case KEY_SOLAR:
			p_cell = _grid.getCell(_selectedCell);
			if (p_cell->isConstructionPossible() &&
				p_player->getCredits() >= INIT_PRICE_SOLAR)
			{
				Building *p_building = new SolarBuilding();
				p_cell->setBuilding(p_building);

				// display popup text
				new PopupText(p_building->getPosition(), -p_building->getPrice());
			}
			break;

		case KEY_MACHINE_GUN:
			p_cell = _grid.getCell(_selectedCell);
			if (p_cell->isConstructionPossible() &&
				p_player->getCredits() >= INIT_PRICE_MACHINE_GUN &&
				p_player->getEnergy() >= (INIT_ENERGY_MACHINE_GUN * -1))
			{
				Building *p_building = new MachineGunTower();
				p_cell->setBuilding(p_building);

				// display popup text
				new PopupText(p_building->getPosition(), -p_building->getPrice());
			}
			break;

		case KEY_GRENADE:
			p_cell = _grid.getCell(_selectedCell);
			if (p_cell->isConstructionPossible() &&
				p_player->getCredits() >= INIT_PRICE_GRENADE &&
				p_player->getEnergy() >= (INIT_ENERGY_GRENADE * -1))
			{
				Building *p_building = new GrenadeTower();
				p_cell->setBuilding(p_building);

				// display popup text
				new PopupText(p_building->getPosition(), -p_building->getPrice());
			}
			break;

		case KEY_LASER:
			p_cell = _grid.getCell(_selectedCell);
			if (p_cell->isConstructionPossible() &&
				p_player->getCredits() >= INIT_PRICE_LASER &&
				p_player->getEnergy() >= (INIT_ENERGY_LASER * -1))
			{
				Building *p_building = new LaserTower();
				p_cell->setBuilding(p_building);

				// display popup text
				new PopupText(p_building->getPosition(), -p_building->getPrice());
			}
			break;

		case KEY_TESLA:
			p_cell = _grid.getCell(_selectedCell);
			if (p_cell->isConstructionPossible() &&
				p_player->getCredits() >= INIT_PRICE_TESLA &&
				p_player->getEnergy() >= (INIT_ENERGY_TESLA * -1))
			{
				Building *p_building = new TeslaTower();
				p_cell->setBuilding(p_building);

				// display popup text
				new PopupText(p_building->getPosition(), -p_building->getPrice());
			}
			break;

		case KEY_SELL:
			p_cell = _grid.getCell(_selectedCell);
			p_building = p_cell->getBuilding();
			
			// if there is a building on this cell,
			if (p_building != NULL)
			{
				// check if it is solar, and player has sufficient energy
				if (p_building->getName() == BUILDING_SOLAR &&
					p_player->getEnergy() < p_building->getEnergy())
					break;

				p_cell->clear();
				worldManager.markForDelete(p_building);

				// display popup text
				new PopupText(p_building->getPosition(), p_building->getSellingPrice());
			}
			break;

		case KEY_UPGRADE:
			p_cell = _grid.getCell(_selectedCell);
			p_building = p_cell->getBuilding();
			
			// if there is a building on this cell,
			if (p_building != NULL)
			{
				// check if it is solar, and player has sufficient energy
				if (!p_building->canUpgrade(p_player->getCredits(), p_player->getEnergy()))
					break;

				// display popup text
				new PopupText(p_building->getPosition(), p_building->getUpgradePrice());

				p_building->upgrade();
			}
			break;

		case KEY_INFO:
			Enemy::setShowInfo(!Enemy::getShowInfo());
			break;

		case KEY_QUITGAME:
			{
				EventPlayerKilled killedEvent;
				worldManager.onEvent(&killedEvent);
			}
			break;

		case KEY_SKIPTIME:
			{
				EventSkipTime skipTimeEvent;
				worldManager.onEvent(&skipTimeEvent);
			}
			break;
		}

		// update sidebar for changes by firing an info event
		if (input != KEY_INFO)
			infoUpdate();

		return 1;
	}
	else if (p_event->getType() == ENEMY_KILLED_EVENT)
	{
		EventEnemyKilled *p_eventEnemyKilled = static_cast<EventEnemyKilled *>(p_event);

		// display popup text
		new PopupText(p_eventEnemyKilled->getPosition(), p_eventEnemyKilled->getCredits());
	}

	return 0;
}

/**
 * Renders the map with a filled background screen.
 */
void TowerDefenseController::draw(void)
{
	// fill background:
	WorldManager &worldManager = WorldManager::getInstance();
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();

	int screenX = worldManager.getViewBoundary().getHorizontal();
	int screenY = worldManager.getViewBoundary().getVertical();
	int gridX = _grid.getHorizontal() + MAP_SIDEBAR_BORDER;
	int gridY = _grid.getVertical();
	int sidebarX = _p_sidebar->getHorizontal();
	int sidebarY = _p_sidebar->getVertical();
	int gameX = gridX + sidebarX;
	int gameY = MAX(gridY, sidebarY);

	Position topLeft(screenX / 2 - gameX / 2,
		screenY / 2 - gameY / 2);
	Position bottomRight(topLeft.getX() + gridX + sidebarX,
		gameY);
	
	// top
	for (int x = 0; x < worldManager.getViewBoundary().getHorizontal(); ++x)
	{
		for (int y = 0; y < topLeft.getY() - 1; ++y)
		{
			graphicsManager.drawChar(Position(x,y),
				'#',
				COLOR_CYAN);
		}
	}

	// bottom
	for (int x = 0; x < worldManager.getViewBoundary().getHorizontal(); ++x)
	{
		for (int y = bottomRight.getY() + 4; y < worldManager.getViewBoundary().getVertical(); ++y)
		{
			graphicsManager.drawChar(Position(x,y),
				'#',
				COLOR_CYAN);
		}
	}

	// left
	for (int x = 0; x < topLeft.getX() - 1; ++x)
	{
		for (int y = topLeft.getY() - 1; y <= bottomRight.getY() + 4; ++y)
		{
			graphicsManager.drawChar(Position(x,y),
				'#',
				COLOR_CYAN);
		}
	}

	// right
	for (int x = bottomRight.getX() + 1; x < worldManager.getViewBoundary().getHorizontal(); ++x)
	{
		for (int y = topLeft.getY() - 1; y < bottomRight.getY() + 4; ++y)
		{
			graphicsManager.drawChar(Position(x,y),
				'#',
				COLOR_CYAN);
		}
	}

	// seperator
	for (int x = topLeft.getX() + gridX - 3; x <= topLeft.getX() + gridX - 2; ++x)
	{
		for (int y = topLeft.getY() - 1; y <= bottomRight.getY() + 4; ++y)
		{
			graphicsManager.drawChar(
				Position(
					x,
					y),
				'#',
				COLOR_CYAN);
		}
	}

	Object::draw();
}

/**
 * Loads a new map from the resource manager.
 * @note The map must be loaded in resource manager previously.
 * @param mapLabel The label name of the map to load.
 * @return Returns 0 if ok, else -1.
 */
int TowerDefenseController::loadMap(string mapLabel)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	// load new map
	MapData *p_tempMap = resourceManager.getMap(mapLabel);
	if (!p_tempMap)
	{
		logManager.writeLog(LOG_WARNING,
			"TowerDefenseController::loadMap()",
			"Map with label '%s' not found.\n",
			mapLabel.c_str());
		return -1;
	}

	_p_currentMapData = p_tempMap;
	_grid.setup(p_tempMap);

	// set map background as the map object's sprite image
	Sprite *p_background = p_tempMap->getBackground();
	if (p_background != NULL)
	{
		setSprite(p_background);
		setSpriteSlowdown(0);
		setType(TYPE_MAP_OBJECT);
		setSolidness(SPECTRAL);
		setAltitude(MIN_ALTITUDE + 1);
	}
	else
	{
		logManager.writeLog(LOG_WARNING,
			"TowerDefenseController::loadMap()",
			"Map background sprite could not be received.\n");
		return -1;
	}

	// set map and sidebar position
	WorldManager &worldManager = WorldManager::getInstance();
	int screenX = worldManager.getViewBoundary().getHorizontal();
	int screenY = worldManager.getViewBoundary().getVertical();
	int gridX = _grid.getHorizontal() + MAP_SIDEBAR_BORDER;
	int gridY = _grid.getVertical();
	int sidebarX = _p_sidebar->getHorizontal();
	int sidebarY = _p_sidebar->getVertical();
	int gameX = gridX + sidebarX;
	int gameY = MAX(gridY, sidebarY);

	Position mapPosition(screenX / 2 - gameX / 2,
		screenY / 2 - gameY / 2);
	Position sidebarPosition(mapPosition.getX() + gridX,
		mapPosition.getY());

	setPosition(mapPosition);
	_p_sidebar->setPosition(sidebarPosition);
	_p_cursor->setPosition(getPosition());
	_grid.setCorner(getPosition());

	// init stars
	for (int i = 0; i < STARS_COUNT; ++i)
	{
		Box mapBounds(mapPosition, _grid.getHorizontal(), _grid.getVertical());
		_stars[i].setBounds(mapBounds);
	}

	return 0;
}

/**
 * Loads a new level from the resource manager.
 * @note The level must be loaded in resource manager previously.
 * @param levelLabel The label name of the level to load.
 * @return Returns 0 if ok, else -1.
 */
int TowerDefenseController::loadLevel(string levelLabel)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	// load new level
	LevelData *p_tempLevel = resourceManager.getLevel(levelLabel);
	if (!p_tempLevel)
	{
		logManager.writeLog(LOG_WARNING,
			"TowerDefenseController::loadLevel()",
			"Level with label '%s' not found.\n",
			levelLabel.c_str());
		return -1;
	}

	_p_spawner->start(p_tempLevel);
	return 0;
}

/**
 * Gets the selected relative cell index position.
 * @return The selected cell index position.
 */
Position TowerDefenseController::getSelectedCell(void)
{
	return _selectedCell;
}

/**
 * Tries to selects the cell at the given relative index position
 * with the cursor.
 * @param position The selected cell index position. 
 */
void TowerDefenseController::setSelectedCell(Position position)
{
	int x = position.getX();
	int y = position.getY();

	if (x < 0 || x > _grid.getWidth() - 1 ||
		y < 0 || y > _grid.getHeight() - 1)
		return;

	// verify cursor position has changes
	if (position == _selectedCell)
		return;

	_selectedCell = position;

	Position cellViewPosition(getPosition().getX() + x * _grid.getCellWidth(),
		getPosition().getY() + y * _grid.getCellHeight());

	_p_cursor->setPosition(cellViewPosition);
}

/**
	 * Tries to oves the cursor by the given amount of cells.
	 * @param deltaX The delta x to move in cells.
	 * @param deltaY The delta y to move in cells.
	 */
void TowerDefenseController::moveCursor(int deltaX, int deltaY)
{
	Position tempSelected = getSelectedCell();
	tempSelected.setX(tempSelected.getX() + deltaX);
	tempSelected.setY(tempSelected.getY() + deltaY);

	setSelectedCell(tempSelected);
}

/**
 * Gets the maps width in cells.
 * @return The maps width in cells.
 */
int TowerDefenseController::getCellsHorizontal(void)
{
	return _grid.getWidth();
}

/**
 * Gets the maps height in cells.
 * @return The maps height in cells.
 */
int TowerDefenseController::getCellsVertical(void)
{
	return _grid.getWidth();
}

/**
 * Gets the maps cell width.
 * @return The maps cell width.
 */
int TowerDefenseController::getCellWidth(void)
{
	return _grid.getCellWidth();
}

/**
 * Gets the maps cell height.
 * @return The maps cell height.
 */
int TowerDefenseController::getCellHeight(void)
{
	return _grid.getHeight();
}

/**
 * Gets the maps background.
 * @return The maps background.
 */
Sprite *TowerDefenseController::getBackground(void)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return NULL;

	return _p_currentMapData->getBackground();
}

/**
 * Checks whether the cell at the given position is passable.
 * @param cellPosition The cell position.
 * @return Returns TRUE if passable, else FALSE.
 */
bool TowerDefenseController::isPassable(Position cellPosition)
{
	// verify cell position
	if (!_grid.isValidCellPosition(cellPosition))
		return false;

	return _grid.getCell(cellPosition)->isPassable();
}

/**
 * Gets the maps enemy's path cell index position at the given index.
 * @param index The index of the path.
 * @return The index position of the enemy path of the map, or (-1, -1) if out of bounds.
 */
Position TowerDefenseController::getPathCellPosition(int index)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return Position(-1, -1);

	return _p_currentMapData->getPathPosition(index);
}

/**
 * Gets the maps enemy's path world position at the given index.
 * @param index The index of the path.
 * @return The world position of the enemy path of the map, or (-1, -1) if out of bounds.
 */
Position TowerDefenseController::getPathPosition(int index)
{
	if (_p_currentMapData == NULL)
		return Position(-1, -1);

	Position pathPosition = getPathCellPosition(index);
	Position cellViewPosition(getPosition().getX() + 2 + pathPosition.getX() * _grid.getCellWidth(),
		getPosition().getY() + 1 + pathPosition.getY()  * _grid.getCellHeight());

	return cellViewPosition;
}

/**
 * Gets the number of enemy's path positions.
 * @return The amount path positions of the enemy path, or -1 if error.
 */
int TowerDefenseController::getPathPositionsCount()
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return -1;

	return _p_currentMapData->getPathPositionsCount();
}

/**
 * Fires an appropriate info event.
 */
void TowerDefenseController::infoUpdate(void)
{
	Cell *p_currentCell = _grid.getCell(_selectedCell);
	if (p_currentCell != NULL)
	{
		WorldManager &worldManager = WorldManager::getInstance();
		Building *p_building  = p_currentCell->getBuilding();

		if (p_building == NULL)
		{
			EventInfo eventInfo;
			worldManager.onEvent(&eventInfo);
		}
		else
		{
			// try check if it is an tower
			Tower *p_tower = dynamic_cast<Tower *>(p_building);

			// if it is a tower
			if (p_tower != NULL) 
			{
				EventInfo eventInfo(p_tower->getName(),
					p_tower->getSellingEnergy(),
					p_tower->getUpgradeEnergy(),
					p_tower->getSellingPrice(),
					p_tower->getUpgradePrice(),
					p_tower->getLevel(),
					p_tower->getFireRate(),
					p_tower->getFirePower(),
					p_tower->getFireRange());
				worldManager.onEvent(&eventInfo);
			}
			else // else it is just a building
			{
				EventInfo eventInfo(p_building->getName(),
					p_building->getSellingEnergy(),
					p_building->getSellingPrice());
				worldManager.onEvent(&eventInfo);
			}
		}
	}
}
