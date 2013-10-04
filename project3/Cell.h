/*******************************************************************************
 * @file        Cell.h
 * @author      bsautermeister
 * @description A cell of the 2D grid system, which has functionality to assign
 *              a game object (building).
 ******************************************************************************/

#ifndef __CELL_H__
#define __CELL_H__

#include "Building.h"
#include "Position.h"

/**
 * Represents a cell in a 2D grid system.
 */
class Cell
{
private:
	/**
	 * The assigned game object (building).
	 */
	Building *_p_building;

	/**
	 * Indicates whether the cell is not blocked for buildings.
	 */
	bool _isPassable;

	/**
	 * The center position of the cell.
	 */
	Position _center;

public:
	/**
	 * Creates a new empty and unbocked cell instance.
	 */
	Cell(void);

	/**
	 * Sets the building to the cell.
	 * @param p_building The building object to assign.
	 * @return Returns 0 for success or else -1 if not possible or
	 *         there is already an assigned building.
	 */
	int setBuilding(Building *p_building);

	/**
	 * Gets the assigned building.
	 * @return Returns the assigned building or NULL.
	 */
	Building *getBuilding(void);

	/**
	 * Clears the cell by deleting the assigned building.
	 */
	void clear(void);

	/**
	 * Sets whether the cell is passable for buildings.
	 * @param value The new cell blocked value.
	 */
	bool setPassable(bool value);

	/**
	 * Gets whether the cell is passable for buildings.
	 * @return Returns TRUE if cell is constructable, and FALSE if cell 
	 *         generally not allows constractions.
	 */
	bool isPassable(void);

	/**
	 * Gets whether the cell allows to construct a builing.
	 * @return Returns TRUE if cell is not blocked and has currently
	 *         no placed building, else FALSE.
	 */
	bool isConstructionPossible(void);

	Position getCenter(void);

	void setCenter(Position position);
};

#endif
