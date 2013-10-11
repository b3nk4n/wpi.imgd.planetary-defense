/*******************************************************************************
 * @file        TowerDefenseController.h
 * @author      bsautermeister
 * @description Manages the map and the cursor. Also, it is implemented as a
 *              singleton, so e.g. enemies can get map information using this
 *              manager class.
 ******************************************************************************/

#ifndef __MAP_OBJECT_H__
#define __MAP_OBJECT_H__

#include <string>
#include "MapData.h"
#include "LevelData.h"
#include "Sprite.h"
#include "Object.h"
#include "VirtualCursor.h"
#include "Grid.h"
#include "Spawner.h"
#include "Sidebar.h"

using std::string;

#define TYPE_MAP_OBJECT "map_object"
#define KEY_INFO 'i'
#define KEY_SELL 's'

/**
 * Manages 2D maps and allows virtual cursor navigation.
 */
class TowerDefenseController : public Object
{
private:

	/**
	 * The singleton instance variable. Implemented this way with an 
	 * instance variable instead of a local static variable, because 
	 * each object must be created with 'new'.
	 */
	static TowerDefenseController *_p_instance;

	/**
	 * The map data.
	 */
	MapData *_p_currentMapData;

	/**
	 * The virtual cursor on the map
	 */
	VirtualCursor *_p_cursor;

	/**
	 * The relative index position of the selected cell.
	 */
	Position _selectedCell;

	/**
	 * The worlds grid.
	 */
	Grid _grid;

	/**
	 * The enemy spawner;
	 */
	Spawner *_p_spawner;

	/**
	 * The map sidebar.
	 */
	Sidebar *_p_sidebar;

	/**
	 * The player.
	 */
	Player *_p_player;

    /**
	 * Creates a map object instance.
	 */
	TowerDefenseController(void);

	/**
	 * Hides copy constrctor.
	 */
	TowerDefenseController(TowerDefenseController const&);

	/**
	 * Hides assignment operator.
	 */
	TowerDefenseController& operator=(TowerDefenseController const&);

	/**
	 * Fires an appropriate info event.
	 */
	void infoUpdate(void);

public:

	/**
	 * Cleans up the map manager allocated resources.
	 */
	virtual ~TowerDefenseController(void);

	/**
	 * Gets the singleton map object instance.
	 * @note Singleton required, because other objects like enemies should have
	 *       access to the map object properties.
	 * @return The singleton map object instance.
	 */
	static TowerDefenseController* getInstance(void);

	/**
	 * Resets the dower defense game.
	 */
	void reset(void);

	/**
	 * Handles all events.
	 * @param p_event Points to the current event to handle.
	 * @return Return 0 if ignored, else 1 if event was handled.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Loads a new map from the resource manager.
	 * @note The map must be loaded in resource manager previously.
	 * @param mapLabel The label name of the map to load.
	 * @return Returns 0 if ok, else -1.
	 */
	int loadMap(string mapLabel);

	/**
	 * Loads a new level from the resource manager.
	 * @note The level must be loaded in resource manager previously.
	 * @param levelLabel The label name of the level to load.
	 * @return Returns 0 if ok, else -1.
	 */
	int loadLevel(string levelLabel);

	/**
	 * Gets the selected relative cell index position.
	 * @return The selected cell index position.
	 */
	Position getSelectedCell(void);

	/**
	 * Tries to selects the cell at the given relative index position
	 * with the cursor.
	 * @param position The selected cell index position. 
	 */
	void setSelectedCell(Position position);

	/**
	 * Tries to oves the cursor by the given amount of cells.
	 * @param deltaX The delta x to move in cells.
	 * @param deltaY The delta y to move in cells.
	 */
	void moveCursor(int deltaX, int deltaY);

	/**
	 * Gets the maps width in cells.
	 * @return The maps width in cells.
	 */
	int getCellsHorizontal(void);

	/**
	 * Gets the maps height in cells.
	 * @return The maps height in cells.
	 */
	int getCellsVertical(void);

	/**
	 * Gets the maps cell width.
	 * @return The maps cell width.
	 */
	int getCellWidth(void);

	/**
	 * Gets the maps cell height.
	 * @return The maps cell height.
	 */
	int getCellHeight(void);

	/**
	 * Gets the maps background.
	 * @return The maps background.
	 */
	Sprite *getBackground(void);

	/**
	 * Checks whether the cell at the given position is passable.
	 * @param cellPosition The cell position.
	 * @return Returns TRUE if passable, else FALSE.
	 */
	bool isPassable(Position cellPosition);

	/**
	 * Gets the maps enemy's path cell index position at the given index.
	 * @param index The index of the path.
	 * @return The index position of the enemy path of the map, or (-1, -1) if out of bounds.
	 */
	Position getPathCellPosition(int index);

	/**
	 * Gets the maps enemy's path world position at the given index.
	 * @param index The index of the path.
	 * @return The world position of the enemy path of the map, or (-1, -1) if out of bounds.
	 */
	Position getPathPosition(int index);

	/**
	 * Gets the number of enemy's path positions.
	 * @return The amount path positions of the enemy path, or -1 if error.
	 */
	int getPathPositionsCount();
};

#endif
