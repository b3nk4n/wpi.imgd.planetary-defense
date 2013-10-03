/*******************************************************************************
 * @file        MapObject.cpp
 * @author      bsautermeister
 * @description Manages the map and the cursor. Also, it is implemented as a
 *              singleton, so e.g. enemies can get map information using this
 *              manager class.
 ******************************************************************************/

#include "MapObject.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"

/**
 * Creates a map object instance.
 */
MapObject::MapObject(void)
{
	//_p_instance = NULL;
	_p_cursor = new VirtualCursor(Position(2,2));
	_p_currentMapData = NULL;

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
	if (p_event->getType() == KEYBOARD_EVENT)
	{
		EventKeyboard *p_eventKeyboard = static_cast<EventKeyboard *>(p_event);

		switch(p_eventKeyboard->getKey())
		{
		case LEFT_KEY:
			// TODO: move cursor left
			break;
		case RIGHT_KEY:
			// TODO: move cursor right
			break;
		case UP_KEY:
			// TODO: move cursor up
			break;
		case DOWN_KEY:
			// TODO: move cursor down
			break;
		}
	}
}

/**
 * Renders the map objects sprite frame. Drawing accounts for: centering,
 * slowdown, advancing sprite frame.
 */
void MapObject::draw(void)
{
	Object::draw();

	//GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	// TODO: render map, if not drawn using the objects sprite file
	// border arround the map?
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
	// unload old map
	if (_p_currentMapData != NULL)
	{
		if (resourceManager.unloadMap(_p_currentMapData->getLabel()))
		{
			logManager.writeLog(LOG_WARNING,
			"MapObject::loadMap()",
				"Previous map with label '%s' could not be unloaded.\n",
				_p_currentMapData->getLabel().c_str());
			return -1;
		}
	}

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

	// set map background as the map object's sprite image
	Sprite *p_background = _p_currentMapData->getBackground();
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
 * Gets the maps width in cells.
 * @return The maps width in cells.
 */
int MapObject::getCellsHorizontal(void)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return 0;

	return _p_currentMapData->getCellsHorizontal();
}

/**
 * Gets the maps height in cells.
 * @return The maps height in cells.
 */
int MapObject::getCellsVertical(void)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return 0;

	return _p_currentMapData->getCellsVertical();
}

/**
 * Gets the maps cell width.
 * @return The maps cell width.
 */
int MapObject::getCellWidth(void)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return 0;

	return _p_currentMapData->getCellWidth();
}

/**
 * Gets the maps cell height.
 * @return The maps cell height.
 */
int MapObject::getCellHeight(void)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return 0;

	return _p_currentMapData->getCellHeight();
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
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return false;

	return _p_currentMapData->isPassable(cellPosition);
}

/**
 * Gets the maps enemy's path position at the given index.
 * @param index The index of the path.
 * @return The position of the enemy path of the map, or (-1, -1) if out of bounds.
 */
Position MapObject::getPathPosition(int index)
{
	// verify map has been loaded
	if (_p_currentMapData == NULL)
		return Position(-1, -1);

	return _p_currentMapData->getPathPosition(index);
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
