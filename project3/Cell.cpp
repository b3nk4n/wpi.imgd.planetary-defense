/*******************************************************************************
 * @file        Cell.cpp
 * @author      bsautermeister
 * @description A cell of the 2D grid system, which has functionality to assign
 *              a game object (building).
 ******************************************************************************/

#include "Cell.h"

/**
 * Creates a new empty and unbocked cell instance.
 */
Cell::Cell(void)
{
	_p_building = NULL;
	_isPassable = true;
}

/**
 * Sets the building to the cell.
 * @param p_building The building object to assign.
 * @return Returns 0 for success or else -1 if not possible or
 *         there is already an assigned building.
 */
int Cell::setBuilding(Object *p_building)
{
	if (!isConstructionPossible())
		return -1;

	_p_building = p_building;
}

/**
 * Gets the assigned building.
 * @return Returns the assigned building or NULL.
 */
Object *Cell::getBuilding(void)
{
	return _p_building;
}

/**
 * Clears the cell by deleting the assigned building.
 */
void Cell::clear(void)
{
	_p_building = NULL;
}

/**
 * Sets whether the cell is passable for buildings.
 * @param value The new cell blocked value.
 */
bool Cell::setPassable(bool value)
{
	_isPassable = value;
}

/**
 * Gets whether the cell is passable for buildings.
 * @return Returns TRUE if cell is constructable, and FALSE if cell 
 *         generally not allows constractions.
 */
bool Cell::isPassable(void)
{
	return _isPassable;
}

/**
 * Gets whether the cell allows to construct a builing.
 * @return Returns TRUE if cell is not blocked and has currently
 *         no placed building, else FALSE.
 */
bool Cell::isConstructionPossible(void)
{
	return _isPassable && _p_building == NULL;
}
