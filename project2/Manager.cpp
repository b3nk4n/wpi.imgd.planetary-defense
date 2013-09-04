/* Manager.cpp */

#include "Manager.h"

/**
 * Creates a new manager instance.
 */
Manager::Manager(void)
{

}
/**
 * Cleans up the manager.
 */
Manager::~Manager(void)
{

}

/**
 * Starts up the manager.
 * @return Returns 0 if start up was successfull, else negative.
 */
int Manager::startUp(void)
{
	return -1;
}

/**
 * Shuts down the manager.
 */
void Manager::shutDown(void)
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