/*******************************************************************************
 * @file        Grid.h
 * @author      bsautermeister
 * @description Grid for a 2D grid system, which contains a bunch of
 *              dynamically allocated cells.
 ******************************************************************************/

#ifndef __GRID_H__
#define __GRID_H__

#include "Cell.h"
#include "MapData.h"

/**
 * Represents a simple 2D grid.
 */
class Grid
{
private:
	/**
	 * The dynamically allocated cells of the grid.
	 */
	Cell *_p_cells;

	/**
	 * The width of the grid.
	 */
	int _width;

	/**
	 * The heigth of the grid.
	 */
	int _height;

	/**
	 * The cell width of the grid.
	 */
	int _cellWidth;

	/**
	 * The cell heigth of the grid.
	 */
	int _cellHeight;

	/**
	 * The top left base position of the grid.
	 */
	Position _corner;

public:
	/**
	 * Creates a new empty grid instance.
	 */
	Grid(void);

	/**
	 * Cleans up the grids resources.
	 */
	~Grid(void);

	/**
	 * Sets up the grid with the given map data.
	 * @param The map data.
	 */
	void setup(MapData *p_mapData);

	/**
	 * Gets the cell at the given position.
	 * @param x The horizontal cell index.
	 * @param y The vertical cell index.
	 * @return The requested cell or NULL.
	 */
	Cell *getCell(int x, int y);

	/**
	 * Gets the cell at the given position.
	 * @param position The cell index position.
	 * @return The requested cell or NULL.
	 */
	Cell *getCell(Position position);

	/**
	 * Gets the width of the grid in cells.
	 * @return The number of cells horizontally.
	 */
	int getWidth(void);

	/**
	 * Gets the height of the grid in cells.
	 * @return The number of cells vertically.
	 */
	int getHeight(void);

	/**
	 * Gets the cell width of the grid.
	 * @return The width of a cell.
	 */
	int getCellWidth(void);

	/**
	 * Gets the cell height of the grid.
	 * @return The height of a cell.
	 */
	int getCellHeight(void);

	/**
	 * Verifies if the cell index position is valid.
	 * @param position The cell position.
	 * @return Returns TRUE if the index position is inside the grid.
	 */
	bool isValidCellPosition(Position position);

	/**
	 * Gets the width.
	 * @return The width.
	 */
	int getHorizontal(void);

	/**
	 * Gets the height.
	 * @return The height.
	 */
	int getVertical(void);

	/**
	 * Sets the base position of the grid.
	 * @param position The position of the grid.
	 */
	void setCorner(Position position);
};

#endif
