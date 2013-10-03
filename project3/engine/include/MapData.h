/*******************************************************************************
 * @file        MapData.h
 * @author      bsautermeister
 * @description The top down mapdata of the 2D grid engine, containing many cells
 *              and a background mapdata.
 ******************************************************************************/

#ifndef __MAP_DATA_H__
#define __MAP_DATA_H__

#include <string>
#include "Frame.h"
#include "Position.h"
#include "Sprite.h"
#include "Object.h"

using std::string;


#define UNLABELED_MAP_DATA "__unlabeled_mapdata__"
#define MAX_PATH_POSITIONS 100
#define CELL_BLOCKED 'X'

/**
 * Represents an 2d mapdata with cells.
 */
class MapData
{
private:
	/**
	 * The number of horizontal cells.
	 */
	int _cellsHorizontal;

	/**
	 * The number of vertical cells.
	 */
	int _cellsVertical;
	/**
	 * The cell width.
	 */
	int _cellWidth;

	/**
	 * The cell height.
	 */
	int _cellHeight;

	/**
	 * The enemy path of the mapdata.
	 */
	Position _path[MAX_PATH_POSITIONS];

	/**
	 * The number of path positions.
	 */
	int _pathPositionsCount;

	/**
	 * Defines the passable cells of the mapdata.
	 * @note: O: passable, X: blocked
	 */
	Frame _passableMapData;

	/**
	 * The background sprite.
	 */
	Sprite *_p_background;

	/**
	 * The text label to identify the mapdata.
	 */
	string _label;

	/**
	 * Creates a mapdata instance.
	 * @note Hidden constuctor because grid size and cell dimensions must be specified.
	 */
	MapData(void);

public:
	/**
	 * Creates a new mapdata instance.
	 * @param cellsHorizontal The number fo horizontal cells.
	 * @param cellsVertical The number fo vertical cells.
	 * @param cellWidth The width of a cell.
	 * @param cellHeight The height of a cell.
	 */
	MapData(int cellsHorizontal, int cellsVertical, int cellWidth, int cellHeight);

	/**
	 * Cleans up the mapdatas allocated resources.
	 */
	~MapData(void);

	/**
	 * Gets the mapdatas width in cells.
	 * @return The mapdatas width in cells.
	 */
	int getCellsHorizontal(void);

	/**
	 * Gets the mapdatas height in cells.
	 * @return The mapdatas height in cells.
	 */
	int getCellsVertical(void);

	/**
	 * Gets the mapdatas cell width.
	 * @return The mapdatas cell width.
	 */
	int getCellWidth(void);

	/**
	 * Gets the mapdatas cell height.
	 * @return The mapdatas cell height.
	 */
	int getCellHeight(void);

	/**
	 * Gets the mapdatas background.
	 * @return The mapdatas background.
	 */
	Sprite *getBackground(void);

	/**
	 * Sets the mapdatas background.
	 * @param p_backgroundSprite The mapdatas background.
	 */
	void setBackground(Sprite *p_backgroundSprite);

	/**
	 * Gets the passable mapdata.
	 * @return The passable mapdata in a frame container.
	 */
	Frame getPassableMap(void);

	/**
	 * Sets the passable mapdata.
	 * @param passableMapData The passable mapdata in a frame container.
	 * @return Returns 0 if success, else -1.
	 */
	int setPassableMap(Frame passableMapData);

	/**
	 * Checks whether the cell at the given position is passable.
	 * @param cellPosition The cell position.
	 * @return Returns TRUE if passable, else FALSE.
	 */
	bool isPassable(Position cellPosition);

	/**
	 * Gets the mapdatas enemy's path position at the given index.
	 * @param index The index of the path.
	 * @return The position of the enemy path of the mapdata, or (-1, -1) if out of bounds.
	 */
	Position getPathPosition(int index);

	/**
	 * Sets the enemy path of the mapdata
	 * @param position The position to add
	 * @return Returns 0 for success, else -1.
	 */
	int addPathPosition(Position position);

	/**
	 * Gets the number of enemy's path positions.
	 * @return The amount path positions of the enemy path.
	 */
	int getPathPositionsCount();

	/**
	 * Gets the mapdatas label.
	 * @return The mapdatas label.
	 */
	string getLabel(void);

	/**
	 * Sets the mapdatas label.
	 * @param value The mapdatas label.
	 */
	void setLabel(string value);
};

#endif
