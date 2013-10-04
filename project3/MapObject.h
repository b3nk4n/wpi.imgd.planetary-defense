/*******************************************************************************
 * @file        MapObject.h
 * @author      bsautermeister
 * @description Manages the map and the cursor. Also, it is implemented as a
 *              singleton, so e.g. enemies can get map information using this
 *              manager class.
 ******************************************************************************/

#ifndef __MAP_OBJECT_H__
#define __MAP_OBJECT_H__

#include <string>
#include "MapData.h"
#include "Sprite.h"
#include "Object.h"
#include "VirtualCursor.h"
#include "Grid.h"

using std::string;

#define TYPE_MAP_OBJECT "map_object"

/**
 * Manages 2D maps and allows virtual cursor navigation.
 */
class MapObject : public Object
{
private:
	/**
	 * The map data.
	 */
	MapData *_p_currentMapData;

	/**
	 * The singleton instance variable. Implemented this way with an 
	 * instance variable instead of a local static variable, because 
	 * each object must be created with 'new'.
	 */
	//static MapObject *_p_instance;

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

   //MapObject(void);  // Private so that it can  not be called
   MapObject(MapObject const&){};             // copy constructor is private
   MapObject& operator=(MapObject const&){};  // assignment operator is private
   static MapObject* m_oInstance;

public:
	static MapObject* Instance(); 

	/**
	 * Creates a map object instance.
	 */
	MapObject(void);

	/**
	 * Cleans up the map manager allocated resources.
	 */
	~MapObject(void);

	/**
	 * Gets the singleton map object instance.
	 * @note Singleton required, because other objects like enemies should have
	 *       access to the map object properties.
	 * @return The singleton map object instance.
	 */
	//static MapObject* getInstance(void);

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
	 * Gets the maps enemy's path position at the given index.
	 * @param index The index of the path.
	 * @return The position of the enemy path of the map, or (-1, -1) if out of bounds.
	 */
	Position getPathPosition(int index);

	/**
	 * Gets the number of enemy's path positions.
	 * @return The amount path positions of the enemy path, or -1 if error.
	 */
	int getPathPositionsCount();
};

#endif
