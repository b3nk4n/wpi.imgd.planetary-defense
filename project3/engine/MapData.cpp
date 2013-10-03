/*******************************************************************************
* @file        MapData.cpp
* @author      bsautermeister
* @description The top down mapdata of the 2D grid engine, containing many cells
*              and a background mapdata.
******************************************************************************/

#include "MapData.h"
#include "LogManager.h"

/**
 * Creates a mapdata instance.
 * @note Hidden constuctor because max frame size must be specified.
 */
MapData::MapData(void)
{
}

/**
 * Creates a new mapdata instance.
 * @param cellsHorizontal The number fo horizontal cells.
 * @param cellsVertical The number fo vertical cells.
 * @param cellWidth The width of a cell.
 * @param cellHeight The height of a cell.
 */
MapData::MapData(int cellsHorizontal, int cellsVertical, int cellWidth, int cellHeight)
{
	_cellsHorizontal = cellsHorizontal;
	_cellsVertical = cellsVertical;
	_cellWidth = cellWidth;
	_cellHeight = cellHeight;

	_label = UNLABELED_MAP_DATA;
	_p_background = NULL;

	_pathPositionsCount = 0;
}

/**
 * Cleans up the mapdatas allocated resources.
 */
MapData::~MapData(void)
{

}

/**
 * Gets the mapdatas width in cells.
 * @return The mapdatas width in cells.
 */
int MapData::getCellsHorizontal(void)
{
	return _cellsHorizontal;
}

/**
 * Gets the mapdatas height in cells.
 * @return The mapdatas height in cells.
 */
int MapData::getCellsVertical(void)
{
	return _cellsVertical;
}

/**
 * Gets the mapdatas cell width.
 * @return The mapdatas cell width.
 */
int MapData::getCellWidth(void)
{
	return _cellWidth;
}

/**
 * Gets the mapdatas cell height.
 * @return The mapdatas cell height.
 */
int MapData::getCellHeight(void)
{
	return _cellHeight;
}

/**
 * Gets the mapdatas background.
 * @return The mapdatas background.
 */
Sprite *MapData::getBackground(void)
{
	return _p_background;
}

/**
 * Sets the mapdatas background.
 * @param p_backgroundSprite The mapdatas background.
 */
void MapData::setBackground(Sprite *p_backgroundSprite)
{
	_p_background = p_backgroundSprite;
}

/**
 * Gets the passable mapdata.
 * @return The passable mapdata in a frame container.
 */
Frame MapData::getPassableMap(void)
{
	return _passableMapData;
}

/**
 * Sets the passable mapdata.
 * @param passableMapData The passable mapdata in a frame container.
 * @return Returns 0 if success, else -1.
 */
int MapData::setPassableMap(Frame passableMapData)
{
	if (passableMapData.getData().length() != _cellsVertical * _cellsHorizontal)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_ERROR,
			"MapData::setPassableMapData()",
			"The data of the passible mapdata has a wrong length.\n");
		return -1;
	}

	_passableMapData = passableMapData;
	return 0;
}

/**
 * Checks whether the cell at the given position is passable.
 * @param cellPosition The cell position.
 * @return Returns TRUE if passable, else FALSE.
 */
bool MapData::isPassable(Position cellPosition)
{
	int locationIndex = cellPosition.getX() + cellPosition.getY() * _passableMapData.getWidth();
	return _passableMapData.getData().at(locationIndex) != CELL_BLOCKED;
}

/**
 * Gets the mapdatas enemy's path position at the given index.
 * @param index The index of the path.
 * @return The position of the enemy path of the mapdata, or (-1, -1) if out of bounds.
 */
Position MapData::getPathPosition(int index)
{
	if (index < 0 || index >= _pathPositionsCount)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_ERROR,
			"MapData::getPathPosition()",
			"Index out of bounds: %d\n",
			index);
		return Position(-1, -1);
	}
	return _path[index];
}

/**
 * Sets the enemy path of the mapdata
 * @param position The position to add
 * @return Returns 0 for success, else -1.
 */
int MapData::addPathPosition(Position position)
{
	if (_pathPositionsCount == MAX_PATH_POSITIONS)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_ERROR,
			"MapData::getPathPosition()",
			"Path positions out of capacity.\n");
		return -1;
	}

	_path[_pathPositionsCount] = position;
	++_pathPositionsCount;
	return 0;
}

/**
 * Gets the number of enemy's path positions.
 * @return The amount path positions of the enemy path.
 */
int MapData::getPathPositionsCount()
{
	return _pathPositionsCount;
}

/**
 * Gets the mapdatas label.
 * @return The mapdatas label.
 */
string MapData::getLabel(void)
{
	return _label;
}

/**
 * Sets the mapdatas label.
 * @param value The mapdatas label.
 */
void MapData::setLabel(string value)
{
	_label = value;
}
