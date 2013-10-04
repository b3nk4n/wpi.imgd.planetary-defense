/*******************************************************************************
 * @file        MapObject.cpp
 * @author      bsautermeister
 * @description Manages the map and the cursor. Also, it is implemented as a
 *              singleton, so e.g. enemies can get map information using this
 *              manager class.
 ******************************************************************************/

#include <stddef.h>  // defines NULL
#include "MapObject.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"

MapObject* MapObject::m_oInstance = NULL;  // Global static pointer used to ensure a single instance of the class.


MapObject* MapObject::Instance()
{
   if (!m_oInstance)   // Only allow one instance of class to be generated.
      m_oInstance = new MapObject;

   return m_oInstance;
}
/**
 * Creates a map object instance.
 */
MapObject::MapObject(void)
{
	//_p_instance = NULL;
	_p_currentMapData = NULL;
	_selectedCell = Position(0, 0);
	_p_cursor = new VirtualCursor(_selectedCell);

	setCentered(false);

	// register for interest:
	registerInterest(KEYBOARD_EVENT);
}

/**
 * Cleans up the map manager allocated resources.
 */
MapObject::~MapObject(void)
{
	if (_p_cursor != NULL)
		delete _p_cursor;
}

/**
 * Gets the singleton map object instance.
 * @note Singleton required, because other objects like enemies should have
 *       access to the map object properties.
 * @return The singleton map object instance.
 */
/*MapObject* MapObject::getInstance(void)
{
	//if (_p_instance == NULL)
		_p_instance = new MapObject();
	return _p_instance;
}*/

/**
 * Handles all events.
 * @param p_event Points to the current event to handle.
 * @return Return 0 if ignored, else 1 if event was handled.
 */
int MapObject::eventHandler(Event *p_event)
{
	LogManager &logManager = LogManager::getInstance();

	if (p_event->getType() == KEYBOARD_EVENT)
	{
		EventKeyboard *p_eventKeyboard = static_cast<EventKeyboard *>(p_event);

		switch(p_eventKeyboard->getKey())
		{
		case LEFT_KEY:
			moveCursor(-1, 0);
			logManager.writeLog(LOG_DEBUG,
				"MapObject::eventHandler()",
				"Cursor moved left by keyboard.\n");
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
		default:
			logManager.writeLog(LOG_DEBUG,
				"MapObject::eventHandler()",
				"Unknown key pressed: %d\n",
				p_eventKeyboard->getKey());
			break;
		}
	}
}

/**
 * Loads a new map from the resource manager.
 * @note The map must be loaded in resource manager previously.
 * @param mapLabel The label name of the map to load.
 * @return Returns 0 if ok, else -1.
 */
int MapObject::loadMap(string mapLabel)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	// load new map
	MapData *p_tempMap = resourceManager.getMap(mapLabel);
	if (!p_tempMap)
	{
		logManager.writeLog(LOG_WARNING,
			"MapObject::loadMap()",
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
		setAltitude(MIN_ALTITUDE);
	}
	else
	{
		logManager.writeLog(LOG_WARNING,
			"MapObject::loadMap()",
			"Map background sprite could not be received.\n");
		return -1;
	}

	return 0;
}

/**
 * Gets the selected relative cell index position.
 * @return The selected cell index position.
 */
Position MapObject::getSelectedCell(void)
{
	return _selectedCell;
}

/**
 * Tries to selects the cell at the given relative index position
 * with the cursor.
 * @param position The selected cell index position. 
 */
void MapObject::setSelectedCell(Position position)
{
	int x = position.getX();
	int y = position.getY();

	if (x < 0 || x > _grid.getWidth() - 1 ||
		y < 0 || y > _grid.getHeight() - 1)
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
void MapObject::moveCursor(int deltaX, int deltaY)
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
int MapObject::getCellsHorizontal(void)
{
	return _grid.getWidth();
}

/**
 * Gets the maps height in cells.
 * @return The maps height in cells.
 */
int MapObject::getCellsVertical(void)
{
	return _grid.getWidth();
}

/**
 * Gets the maps cell width.
 * @return The maps cell width.
 */
int MapObject::getCellWidth(void)
{
	return _grid.getCellWidth();
}

/**
 * Gets the maps cell height.
 * @return The maps cell height.
 */
int MapObject::getCellHeight(void)
{
	return _grid.getHeight();
}

/**
 * Gets the maps background.
 * @return The maps background.
 */
Sprite *MapObject::getBackground(void)
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
bool MapObject::isPassable(Position cellPosition)
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
Position MapObject::getPathCellPosition(int index)
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
Position MapObject::getPathPosition(int index)
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
int MapObject::getPathPositionsCount()
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return -1;

	return _p_currentMapData->getPathPositionsCount();
}