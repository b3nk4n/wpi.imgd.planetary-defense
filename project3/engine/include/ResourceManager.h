/*******************************************************************************
 * @file        ResourceManager.h
 * @author      bsautermeister
 * @description Manages the resources of the game engine.
 ******************************************************************************/

#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <string>
#include "Manager.h"
#include "Sprite.h"
#include "MapData.h"

using std::string;

#define MAX_SPRITES 128
#define MAX_MAPS 32

// delimiters used to parse sprite files -
// the resourece manager 'knows' file format
#define FRAMES_TOKEN "frames"
#define HEIGHT_TOKEN "height"
#define WIDTH_TOKEN "width"
#define COLOR_TOKEN "color"
#define END_FRAME_TOKEN "end"
#define END_SPRITE_TOKEN "eof"
// map delemitters
#define CELLS_HORIZONTAL_TOKEN "cells-horizontal"
#define CELLS_VERTICAL_TOKEN "cells-vertical"
#define CELL_WIDTH_TOKEN "cell-width"
#define CELL_HEIGHT_TOKEN "cell-height"
#define PATH_TOKEN "path"

/**
 * Represents the manager for the game resources.
 */
class ResourceManager : public Manager
{
private:
	/**
	 * The array of sprites.
	 */
	Sprite *_p_sprites[MAX_SPRITES];

	/**
	 * The number of loaded sprites.
	 */
	int _spriteCount;

	/**
	 * The array of maps.
	 */
	MapData *_p_maps[MAX_MAPS];

	/**
	 * The number of loaded maps.
	 */
	int _mapCount;

	/**
	 * Creates a resource manager instance.
	 */
	ResourceManager(void);

	/**
	 * Hides copy constructor.
	 */
	ResourceManager(ResourceManager const&);

	/**
	 * Hides assignment operator.
	 */
	void operator=(ResourceManager const&);

public:
	/**
	 * Cleansup the resource manager.
	 */
	~ResourceManager(void);

	/**
	 * Gets the singleton resource manager instance.
	 * @return The singleton resource manager instance.
	 */
	static ResourceManager& getInstance(void);

	/**
	 * Starts up all resource manager.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	int startUp(void);

	/**
	 * Shuts down the resource manager and frees up any allocated sprite.
	 */
	virtual void shutDown(void);

	/**
	 * Loads the sprite from a file.
	 * @param filename The file name.
	 * @param label The label to identify the sprite.
	 * @return Returns 0 if ok, else -1.
	 */
	int loadSprite(string filename, string label);

	/**
	 * Unloads the sprite.
	 * @param label The label to identify the sprite.
	 * @return Returns 0 if ok, else -1.
	 */
	int unloadSprite(string label);

	/**
	 * Gets the sprite.
	 * @param label The label to identify the sprite.
	 * @return Returns the found sprite, else NULL.
	 */
	Sprite *getSprite(string label);

	/**
	 * Loads the map from a file.
	 * @param filename The file name.
	 * @param label The label to identify the map.
	 * @return Returns 0 if ok, else -1.
	 */
	int loadMap(string filename, string label);

	/**
	 * Unloads the map.
	 * @param label The label to identify the map.
	 * @return Returns 0 if ok, else -1.
	 */
	int unloadMap(string label);

	/**
	 * Gets the map.
	 * @param label The label to identify the map.
	 * @return Returns the found map, else NULL.
	 */
	MapData *getMap(string label);
};

#endif
