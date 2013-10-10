/*******************************************************************************
* @file        Grid.cpp
* @author      bsautermeister
* @description Grid for a 2D grid system, which contains a bunch of
*              dynamically allocated cells.
******************************************************************************/

#include "Grid.h"

/**
 * Creates a new empty grid instance.
 */
Grid::Grid(void)
{
	_p_cells = NULL;
	_width = 0;
	_height = 0;
}

/**
 * Cleans up the grids resources.
 */
Grid::~Grid(void)
{
	if (_p_cells != NULL)
		delete[] _p_cells;
}

/**
 * Sets up the grid with the given map data.
 * @param The map data.
 */
void Grid::setup(MapData *p_mapData)
{
	_width = p_mapData->getCellsHorizontal();
	_height = p_mapData->getCellsVertical();
	_cellWidth = p_mapData->getCellWidth();
	_cellHeight = p_mapData->getCellHeight();

	if (_p_cells != NULL)
		delete[] _p_cells;
	
	_p_cells = new Cell[_width * _height];

	// setup passable
	for (int x = 0; x < _width; ++x)
	{
		for (int y = 0; y < _height; ++y)
		{
			Cell *cell = getCell(x, y);
			bool isPassable = p_mapData->isPassable(Position(x,y));
			cell->setPassable(isPassable);
			Position centerCell(x * _cellWidth + _cellWidth / 2,
				y * _cellHeight + _cellHeight / 2);
			cell->setCenter(centerCell);
		}
	}
}

/**
 * Gets the cell at the given position.
 * @param x The horizontal cell index.
 * @param y The vertical cell index.
 * @return The requested cell or NULL.
 */
Cell *Grid::getCell(int x, int y)
{
	getCell(Position(x, y));
}

/**
 * Gets the cell at the given position.
 * @param position The cell index position.
 * @return The requested cell or NULL.
 */
Cell *Grid::getCell(Position position)
{
	
	if (!isValidCellPosition(position))
		return NULL;

	return &(_p_cells[position.getX() + position.getY() * _width]);
}

/**
 * Gets the width of the grid in cells.
 * @return The number of cells horizontally.
 */
int Grid::getWidth(void)
{
	return _width;
}

/**
 * Gets the height of the grid in cells.
 * @return The number of cells vertically.
 */
int Grid::getHeight(void)
{
	return _height;
}

/**
 * Gets the cell width of the grid.
 * @return The width of a cell.
 */
int Grid::getCellWidth(void)
{
	return _cellWidth;
}

/**
 * Gets the cell height of the grid.
 * @return The height of a cell.
 */
int Grid::getCellHeight(void)
{
	return _cellHeight;
}

/**
 * Verifies if the cell index position is valid.
 * @param position The cell position.
 * @return Returns TRUE if the index position is inside the grid.
 */
bool Grid::isValidCellPosition(Position position)
{
	return position.getX() >= 0 && position.getX() < _width ||
		position.getY() >= 0 && position.getY() < _height;
}

/**
 * Gets the width.
 * @return The width.
 */
int Grid::getHorizontal(void)
{
	return _width * _cellWidth;
}

/**
 * Gets the height.
 * @return The height.
 */
int Grid::getVertical(void)
{
	return _height * _cellHeight;
}
