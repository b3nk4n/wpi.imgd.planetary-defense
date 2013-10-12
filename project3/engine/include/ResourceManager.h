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
#include "LevelData.h"
#include "WaveData.h"

using std::string;

#define MAX_SPRITES 128
#define MAX_MAPS 32
#define MAX_LEVELS 100

// delimiters used to parse sprite files
#define FRAMES_TOKEN "frames"
#define HEIGHT_TOKEN "height"
#define WIDTH_TOKEN "width"
#define COLOR_TOKEN "color"
#define END_TOKEN "end"
#define EOF_TOKEN "eof"
// map delimitters
#define CELLS_HORIZONTAL_TOKEN "cells-horizontal"
#define CELLS_VERTICAL_TOKEN "cells-vertical"
#define CELL_WIDTH_TOKEN "cell-width"
#define CELL_HEIGHT_TOKEN "cell-height"
#define PATH_TOKEN "path"
// level delimitters
#define WAVES_COUNT_TOKEN "waves-count"
#define ENEMY_TYPE_TOKEN "type"
#define ENEMY_COUNT_TOKEN "count"
#define ENEMY_DELAY_TOKEN "delay"
#define ENEMY_HEALTH_TOKEN "health"
#define ENEMY_SPEED_TOKEN "speed"
#define ENEMY_CREDITS_TOKEN "credits"

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
	 * The array of levels.
	 */
	LevelData *_p_levels[MAX_LEVELS];

	/**
	 * The number of loaded levels.
	 */
	int _levelCount;

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

	/**
	 * Loads the level from a file.
	 * @param filename The file name.
	 * @param label The label to identify the level.
	 * @return Returns 0 if ok, else -1.
	 */
	int loadLevel(string filename, string label);

	/**
	 * Unloads the level.
	 * @param label The label to identify the level.
	 * @return Returns 0 if ok, else -1.
	 */
	int unloadLevel(string label);

	/**
	 * Gets the level.
	 * @param label The label to identify the level.
	 * @return Returns the found map, else NULL.
	 */
	LevelData *getLevel(string label);
};

#endif
