/*******************************************************************************
 * @file        Manager.cpp
 * @author      bsautermeister
 * @description The game engines manger base class which defines the basic
 *              structure of all manager classes.
 ******************************************************************************/

#include "Manager.h"

/**
 * Creates a new manager instance.
 */
Manager::Manager(void)
{
	_isStarted = false;
}
/**
 * Cleans up the manager.
 */
Manager::~Manager(void)
{
}

/**
 * Gets whether the manager is started.
 * @return Returns TRUE if start up was successfull.
 */
bool Manager::isStarted(void)
{
	return this->_isStarted;
}
