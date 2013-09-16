/*******************************************************************************
* @file        ResourceManager.cpp
* @author      bsautermeister
* @description Manages the resources of the game engine.
******************************************************************************/

#include "ResourceManager.h"

/**
 * Creates a resource manager instance.
 */
ResourceManager::ResourceManager(void)
{

}

/**
 * Hides copy constructor.
 */
ResourceManager::ResourceManager(ResourceManager const& rm)
{
}

/**
 * Hides assignment operator.
 */
void ResourceManager::operator=(ResourceManager const& rm)
{
}

/**
 * Cleansup the resource manager.
 */
ResourceManager::~ResourceManager(void)
{

}

/**
 * Gets the singleton resource manager instance.
 * @return The singleton resource manager instance.
 */
ResourceManager& ResourceManager::getInstance(void)
{
	static ResourceManager resouceManager;
	return resouceManager;
}

/**
 * Starts up all resource manager.
 * @return Returns 0 if start up was successfull, else negative.
 */
int ResourceManager::startUp(void)
{
	return -1;
}

/**
 * Shuts down the resource manager and frees up any allocated sprite.
 */
void ResourceManager::shutDown(void)
{

}

/**
 * Loads the sprite from a file.
 * @param filename The file name.
 * @param label The label to identify the sprite.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::loadSprite(string filename, string label)
{
	return -1;
}

/**
 * Unloads the sprite.
 * @param label The label to identify the sprite.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::unloadSprite(string filename, string label)
{
	return -1;
}

/**
 * Gets the sprite.
 * @param label The label to identify the sprite.
 * @return Returns the found sprite, else NULL.
 */
Sprite *ResourceManager::getSprite(string label)
{
	return NULL;
}
