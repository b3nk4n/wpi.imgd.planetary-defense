/*******************************************************************************
* @file        ResourceManager.cpp
* @author      bsautermeister
* @description Manages the resources of the game engine.
******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "ResourceManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"

using std::ifstream;
using std::vector;

// prototypes
int readLineInt(ifstream *p_file, int *p_lineNumber, const char *tag);
float readLineFloat(ifstream *p_file, int *p_lineNumber, const char *tag);
string readLineString(ifstream *p_file, int* p_lineNumber, const char *tag);
Frame readFrame(ifstream *p_file, int *p_lineNumber, int width, int height);
WaveData readWave(ifstream *p_file, int *p_lineNumber);
int parseStringPath(string stringPath, MapData *p_map);
void discardCR(string &text);

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
	_spriteCount = 0;
	_isStarted = true;

	return 0;
}

/**
 * Shuts down the resource manager and frees up any allocated sprite.
 */
void ResourceManager::shutDown(void)
{
	// free up all allocated sprites
	for (int i = 0; i < _spriteCount; ++i)
	{
		delete _p_sprites[i];
	}

	_spriteCount = 0;
	_isStarted = false;
}

/**
 * Loads the sprite from a file.
 * @param filename The file name.
 * @param label The label to identify the sprite.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::loadSprite(string filename, string label)
{
	LogManager &logManager = LogManager::getInstance();

	// verify sprites limit not reached
	if (_spriteCount == MAX_SPRITES)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadSprite()",
			"The sprite limit of %d sprites is reached. Loading sprite failed.\n",
			MAX_SPRITES);
		return -1;
	}

	int lineNumber = 1;
	bool parsingError = false;

	// open sprite file
	ifstream spritefile(filename.c_str());

	if (spritefile.is_open())
	{
		logManager.writeLog(LOG_INFO,
			"ResouceManager::loadSprite()",
			"Opened sprite file '%s'.\n",
			filename.c_str());
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadSprite()",
			"Sprite file '%s' could not be opened.\n",
			filename.c_str());
		return -1;
	}

	// read sprite file header
	int frames = readLineInt(&spritefile, &lineNumber, FRAMES_TOKEN);
	int width = readLineInt(&spritefile, &lineNumber, WIDTH_TOKEN);
	int height = readLineInt(&spritefile, &lineNumber, HEIGHT_TOKEN);
	string colorString = readLineString(&spritefile, &lineNumber, COLOR_TOKEN);
	int color = GraphicsManager::getColorByString(colorString);

	// verify header parsing was successful
	if (frames == -1 || width == -1 || height == -1 || color == -1)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadSprite()",
			"Parsing the header of the sprite file '%s' failed.\n",
			filename.c_str());
		return -1;
	}

	// create sprite
	bool success = false;
	Sprite *p_sprite = new Sprite(frames);

	while (spritefile.good())
	{
		string line;
		Frame frame = readFrame(&spritefile, &lineNumber, width, height);
		
		// verify adding frame did not failed
		if(p_sprite->addFrame(frame))
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager::loadSprite()",
				"Adding frame failed. The number of frames (%d) might be incorrect.\n",
				frames);
			break;
		}

		// an error occured when an empty frame was received
		if (frame.isEmpty())
		{
			break;
		}

		// verify EOF token is reached
		int currentLine;
		try{
			currentLine = spritefile.tellg();
			getline(spritefile, line);
			discardCR(line);
		}
		catch(ifstream::failure e)
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager::loadSprite()",
				"Error line %d: Reading line failed with error: %s\n",
				lineNumber,
				e.what());
			return -1;
		}

		if (line.compare(EOF_TOKEN) == 0)
		{
			success = true;
			break;
		}

		spritefile.seekg(currentLine ,std::ios_base::beg);
	}

	// close sprite file
	spritefile.close();

	// ensure there was no error while parsing the file
	if (!success)
		return -1;

	// verify frames number
	if (frames != p_sprite->getFrameCount())
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadSprite()",
			"Missmatch in number of defined frames in '%s'. Expacted %d, but was %d.\n",
			filename.c_str(),
			frames,
			p_sprite->getFrameCount());
		return -1;
	}

	// configure sprite
	p_sprite->setLabel(label);
	p_sprite->setWidth(width);
	p_sprite->setHeight(height);
	p_sprite->setColor(color);

	// store the sprite
	_p_sprites[_spriteCount++] = p_sprite;

	return 0;
}

/**
 * Unloads the sprite.
 * @param label The label to identify the sprite.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::unloadSprite(string label)
{
	for (int i = _spriteCount - 1; i >= 0; --i)
	{
		if (label == _p_sprites[i]->getLabel())
		{
			// clean up memory
			delete _p_sprites[i];

			// scoot over other sprites
			for (int j = i; j < _spriteCount - 1; ++j)
				_p_sprites[j] = _p_sprites[j + 1];

			--_spriteCount;

			return 0;
		}
	}

	return -1;
}

/**
 * Gets the sprite.
 * @param label The label to identify the sprite.
 * @return Returns the found sprite, else NULL.
 */
Sprite *ResourceManager::getSprite(string label)
{
	for (int i = 0; i < _spriteCount; ++i)
	{
		if (label == _p_sprites[i]->getLabel())
			return _p_sprites[i];
	}

	return NULL;
}

/**
 * Loads the map from a file.
 * @param filename The file name.
 * @param label The label to identify the map.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::loadMap(string filename, string label)
{
	LogManager &logManager = LogManager::getInstance();

	// verify maps limit not reached
	if (_mapCount == MAX_MAPS)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadMap()",
			"The map limit of %d maps is reached. Loading map failed.\n",
			MAX_MAPS);
		return -1;
	}

	int lineNumber = 1;
	bool parsingError = false;

	// open map file
	ifstream mapfile(filename.c_str());

	if (mapfile.is_open())
	{
		logManager.writeLog(LOG_INFO,
			"ResouceManager::loadMap()",
			"Opened map file '%s'.\n",
			filename.c_str());
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadMap()",
			"Map file '%s' could not be opened.\n",
			filename.c_str());
		return -1;
	}

	// read map file header
	int cellsHorizontal = readLineInt(&mapfile, &lineNumber, CELLS_HORIZONTAL_TOKEN);
	int cellsVertical = readLineInt(&mapfile, &lineNumber, CELLS_VERTICAL_TOKEN);
	int cellWidth = readLineInt(&mapfile, &lineNumber, CELL_WIDTH_TOKEN);
	int cellHeight = readLineInt(&mapfile, &lineNumber, CELL_HEIGHT_TOKEN);
	string colorString = readLineString(&mapfile, &lineNumber, COLOR_TOKEN);
	int bgColor = GraphicsManager::getColorByString(colorString);
	string pathString = readLineString(&mapfile, &lineNumber, PATH_TOKEN);

	// verify header parsing was successful
	if (cellsHorizontal == -1 || cellsVertical == -1 || cellWidth == -1 || cellHeight == -1 || bgColor == -1)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadMap()",
			"Parsing the header of the map file '%s' failed.\n",
			filename.c_str());
		return -1;
	}

	// create map
	bool success = false;
	MapData *p_map = new MapData(
		cellsHorizontal,
		cellsVertical,
		cellWidth,
		cellHeight);
	Sprite *p_background = new Sprite(1);

	// LOAD PASSABLE MAP
	string line;
	// uses a frame as container for the passable map
	Frame passableMap = readFrame(&mapfile, &lineNumber, cellsHorizontal, cellsVertical);

	// an error occured when an empty frame was received
	if (!passableMap.isEmpty())
	{
		// verify adding frame did not failed
		if(p_map->setPassableMap(passableMap))
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager::loadMap()",
				"Adding setting up passable map failed.\n");
			return -1;
		}

		// read background image sprite
		Frame mapBackground = readFrame(&mapfile,
			&lineNumber,
			cellsHorizontal * cellWidth,
			cellsVertical * cellHeight);

		// an error occured when an empty frame was received
		if (!mapBackground.isEmpty())
		{
			// verify adding frame did not failed
			if(p_background->addFrame(mapBackground))
			{
				logManager.writeLog(LOG_ERROR,
					"ResouceManager::loadMap()",
					"Adding setting up passable map failed.\n");
				return -1;
			}
		}

		// verify EOF token is reached
		int currentLine;
		try
		{
			currentLine = mapfile.tellg();
			getline(mapfile, line);
			discardCR(line);
		}
		catch(ifstream::failure e)
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager::loadMap()",
				"Error line %d: Reading line failed with error: %s\n",
				lineNumber,
				e.what());
			return -1;
		}

		if (line.compare(EOF_TOKEN) == 0)
		{
			success = true;
		}

		mapfile.seekg(currentLine ,std::ios_base::beg);
	}
	

	// close map file
	mapfile.close();

	// ensure there was no error while parsing the file
	if (!success)
		return -1;

	// configure map background
	p_background->setLabel(label);
	p_background->setWidth(cellsHorizontal * cellWidth);
	p_background->setHeight(cellsVertical * cellHeight);
	p_background->setColor(bgColor);

	// config map
	p_map->setLabel(label);
	p_map->setBackground(p_background);
	// parse path
	if (parseStringPath(pathString, p_map))
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadMap()",
			"Parsing the string path failed.\n");
		return -1;
	}

	// store the map
	_p_maps[_mapCount++] = p_map;

	return 0;
}

/**
 * Unloads the map.
 * @param label The label to identify the map.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::unloadMap(string label)
{
	for (int i = _mapCount - 1; i >= 0; --i)
	{
		if (label == _p_maps[i]->getLabel())
		{
			// unload its assigned background sprite
			Sprite *p_background = _p_maps[i]->getBackground();
			if (p_background != NULL)
				delete p_background;

			// clean up memory
			delete _p_maps[i];

			// scoot over other maps
			for (int j = i; j < _mapCount - 1; ++j)
				_p_maps[j] = _p_maps[j + 1];

			--_mapCount;

			return 0;
		}
	}

	return -1;
}

/**
 * Gets the map.
 * @param label The label to identify the map.
 * @return Returns the found map, else NULL.
 */
MapData *ResourceManager::getMap(string label)
{
	for (int i = 0; i < _mapCount; ++i)
	{
		if (label == _p_maps[i]->getLabel())
			return _p_maps[i];
	}

	return NULL;
}

/**
 * Loads the level from a file.
 * @param filename The file name.
 * @param label The label to identify the level.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::loadLevel(string filename, string label)
{
	LogManager &logManager = LogManager::getInstance();

	// verify levels limit not reached
	if (_levelCount == MAX_LEVELS)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadLevel()",
			"The level limit of %d levels is reached. Loading level failed.\n",
			MAX_LEVELS);
		return -1;
	}

	int lineNumber = 1;
	bool parsingError = false;

	// open level file
	ifstream levelfile(filename.c_str());

	if (levelfile.is_open())
	{
		logManager.writeLog(LOG_INFO,
			"ResouceManager::loadLevel()",
			"Opened level file '%s'.\n",
			filename.c_str());
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadLevel()",
			"Level file '%s' could not be opened.\n",
			filename.c_str());
		return -1;
	}

	// read sprite file header
	int wavesCount = readLineInt(&levelfile, &lineNumber, WAVES_COUNT_TOKEN);

	// verify header parsing was successful
	if (wavesCount == -1)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadLevel()",
			"Parsing the header of the level file '%s' failed.\n",
			filename.c_str());
		return -1;
	}

	// create sprite
	bool success = false;
	LevelData *p_level = new LevelData(wavesCount);

	while (levelfile.good())
	{
		string line;
		WaveData wave = readWave(&levelfile, &lineNumber);

		// verify adding a wave did not failed
		if(p_level->addWave(wave))
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager::loadLevel()",
				"Adding wave failed.\n");
			break;
		}

		// verify EOF token is reached
		int currentLine;
		try
		{
			currentLine = levelfile.tellg();
			getline(levelfile, line);
			discardCR(line);
		}
		catch(ifstream::failure e)
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager::loadLevel()",
				"Error line %d: Reading line failed with error: %s\n",
				lineNumber,
				e.what());
			return -1;
		}

		if (line.compare(EOF_TOKEN) == 0)
		{
			success = true;
			break;
		}

		levelfile.seekg(currentLine ,std::ios_base::beg);
	}

	// close level file
	levelfile.close();

	// ensure there was no error while parsing the file
	if (!success)
		return -1;

	// verify frames number
	if (wavesCount != p_level->getWavesCount())
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager::loadLevel()",
			"Missmatch in number of defined waves in '%s'. Expacted %d, but was %d.\n",
			filename.c_str(),
			wavesCount,
			p_level->getWavesCount());
		return -1;
	}

	// configure level
	p_level->setLabel(label);

	// store the level
	_p_levels[_levelCount++] = p_level;

	return 0;
}

/**
 * Unloads the level.
 * @param label The label to identify the level.
 * @return Returns 0 if ok, else -1.
 */
int ResourceManager::unloadLevel(string label)
{
	for (int i = _levelCount - 1; i >= 0; --i)
	{
		if (label == _p_levels[i]->getLabel())
		{
			// clean up memory
			delete _p_levels[i];

			// scoot over other levels
			for (int j = i; j < _levelCount - 1; ++j)
				_p_levels[j] = _p_levels[j + 1];

			--_levelCount;

			return 0;
		}
	}

	return -1;
}

/**
 * Gets the level.
 * @param label The label to identify the level.
 * @return Returns the found map, else NULL.
 */
LevelData *ResourceManager::getLevel(string label)
{
	for (int i = 0; i < _levelCount; ++i)
	{
		if (label == _p_levels[i]->getLabel())
			return _p_levels[i];
	}

	return NULL;
}

// HELPER FUNCTIONS

/**
 * Reads a single line in the format 'tag number'.
 * @param p_file the input stream.
 * @param p_lineNumber Points to the line number.
 * @param tag The sprites tag name.
 * @return The read 'number' of the specified tag.
 */
int readLineInt(ifstream *p_file, int *p_lineNumber, const char *tag)
{
	LogManager &logManager = LogManager::getInstance();
	p_file->exceptions(ifstream::failbit|ifstream::badbit);

	// verify reading from file is possible
	if (!p_file->good())
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineInt()",
			"Error line %d: Reading an integer line is not possible\n",
			(*p_lineNumber));
		return -1;
	}

	string line;

	// read the line
	try
	{
		getline(*p_file, line);
		discardCR(line);
	}
	catch(ifstream::failure e)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineInt()",
			"Error line %d: Reading line failed with error: %s\n",
			(*p_lineNumber),
			e.what());
		return -1;
	}

	// verify the expacted tag
	if (!line.compare(0, strlen(tag), tag) == 0)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineInt()",
			"Error line %d: Expacted tag '%s' could not be found\n",
			(*p_lineNumber),
			tag);
		return -1;	
	}

	// try to get the value
	int number = atoi(line.substr(strlen(tag) + 1).c_str());

	++(*p_lineNumber);

	return number;
}

/**
 * Reads a single line in the format 'tag number'.
 * @param p_file the input stream.
 * @param p_lineNumber Points to the line number.
 * @param tag The sprites tag name.
 * @return The read 'number' of the specified tag.
 */
float readLineFloat(ifstream *p_file, int *p_lineNumber, const char *tag)
{
	LogManager &logManager = LogManager::getInstance();
	p_file->exceptions(ifstream::failbit|ifstream::badbit);

	// verify reading from file is possible
	if (!p_file->good())
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineFloat()",
			"Error line %d: Reading an float line is not possible\n",
			(*p_lineNumber));
		return -1;
	}

	string line;

	// read the line
	try
	{
		getline(*p_file, line);
		discardCR(line);
	}
	catch(ifstream::failure e)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineFloat()",
			"Error line %d: Reading line failed with error: %s\n",
			(*p_lineNumber),
			e.what());
		return -1;
	}

	// verify the expacted tag
	if (!line.compare(0, strlen(tag), tag) == 0)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineFloat()",
			"Error line %d: Expacted tag '%s' could not be found\n",
			(*p_lineNumber),
			tag);
		return -1;	
	}

	// try to get the value
	float number = (float)atof(line.substr(strlen(tag) + 1).c_str());

	++(*p_lineNumber);

	return number;
}

/**
 * Reads a single line in the format 'tag text'.
 * @param p_file the input stream.
 * @param p_lineNumber Points to the line number.
 * @param tag The sprites tag name.
 * @return The read 'text' of the specified tag.
 */
string readLineString(ifstream *p_file, int *p_lineNumber, const char *tag)
{
	LogManager &logManager = LogManager::getInstance();
	p_file->exceptions(ifstream::failbit|ifstream::badbit);

	// verify reading from file is possible
	if (!p_file->good())
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineString()",
			"Error line %d: Reading a string line is not possible\n",
			(*p_lineNumber));
		return "";
	}

	string line;

	// read the line
	try
	{
		getline(*p_file, line);
		discardCR(line);
	}
	catch(ifstream::failure e)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineString()",
			"Error line %d: Reading line failed with error: %s\n",
			(*p_lineNumber),
			e.what());
		return "";
	}

	// verify the expacted tag
	if (!line.compare(0, strlen(tag), tag) == 0)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readLineString()",
			"Error line %d: Expacted tag '%s' could not be found\n",
			(*p_lineNumber),
			tag);
		return "";	
	}

	// try to get the value
	string text = line.substr(strlen(tag) + 1);

	++(*p_lineNumber);

	return text;
}

/**
 * Reads a frame until 'eof' is reached.
 * @param p_file the input stream.
 * @param p_lineNumber Points to the line number.
 * @param width The frame width.
 * @param height The frame height.
 * @return The read sprite frame or an empty one in case of error.
 */
Frame readFrame(ifstream *p_file, int *p_lineNumber, int width, int height)
{
	LogManager &logManager = LogManager::getInstance();
	string line, frameString;
	bool error = false;
	// activate exceptions
	p_file->exceptions(ifstream::failbit|ifstream::badbit);

	for (int i = 0; i < height; ++i)
	{
		// verify reading from file is possible
		if (!p_file->good())
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager.readFrame()",
				"Error line %d: Reading a line from file is not possible\n",
				(*p_lineNumber));
			error = true;
		}
		else
		{
			try
			{
				getline(*p_file, line);
				discardCR(line);
			}
			catch(ifstream::failure e)
			{
				logManager.writeLog(LOG_ERROR,
					"ResouceManager.readFrame()",
					"Error line %d: Reading line failed with error: %s\n",
					(*p_lineNumber),
					e.what());
				error = true;
			}

			if (line.length() != width)
			{
				logManager.writeLog(LOG_ERROR,
					"ResouceManager.readFrame()",
					"Error line %d: Line length should be %d, but was %d\n",
					(*p_lineNumber),
					width,
					line.length());
				error = true;
			}
		}

		// return an empty frame on error
		if (error)
			break;

		// append string data
		frameString += line;
		++(*p_lineNumber);
	}

	if (!error)
	{
		// verify reading from file is possible
		if (!p_file->good())
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager.readFrame()",
				"Error line %d: Reading a line from file is not possible\n",
				(*p_lineNumber));
			error = true;
		}
		else
		{
			try
			{
				getline(*p_file, line);
				discardCR(line);
			}
			catch(ifstream::failure e)
			{
				logManager.writeLog(LOG_ERROR,
					"ResouceManager.readFrame()",
					"Error line %d: Reading line failed with error: %s\n",
					(*p_lineNumber),
					e.what());
				error = true;
			}

			if (line != END_TOKEN)
			{
				logManager.writeLog(LOG_ERROR,
					"ResouceManager.readFrame()",
					"Error line %d: The expected end token '%s' was not found\n",
					(*p_lineNumber),
					END_TOKEN);
				Frame emptyFrame;
				return emptyFrame;
			}

			++(*p_lineNumber);
		}
	}

	// return an empty frame on error
	if (error)
	{
		Frame emptyFrame;
		return emptyFrame;
	}

	// create and return frame
	Frame frame(width, height, frameString);
	return frame;
}

/**
 * Reads a wave until 'eof' is reached.
 * @param p_file the input stream.
 * @param p_lineNumber Points to the line number.
 * @return The read level wave.
 */
WaveData readWave(ifstream *p_file, int *p_lineNumber)
{
	LogManager &logManager = LogManager::getInstance();
	string line, frameString;
	bool error = false;
	
	string type = readLineString(p_file, p_lineNumber, ENEMY_TYPE_TOKEN);
	int count = readLineInt(p_file, p_lineNumber, ENEMY_COUNT_TOKEN);
	int delay = readLineInt(p_file, p_lineNumber, ENEMY_DELAY_TOKEN);
	int health = readLineInt(p_file, p_lineNumber, ENEMY_HEALTH_TOKEN);
	float speed = readLineFloat(p_file, p_lineNumber, ENEMY_SPEED_TOKEN);
	int credits = readLineInt(p_file, p_lineNumber, ENEMY_CREDITS_TOKEN);

	// verify header parsing was successful
	if (count == -1 || count == -1 || delay == -1 || health == -1 || speed == -1 || credits == -1)
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readWave()",
			"Parsing the wave failed.\n");
		WaveData empty;
		return empty;
	}

	// verify reading from file is possible
	if (!p_file->good())
	{
		logManager.writeLog(LOG_ERROR,
			"ResouceManager.readWave()",
			"Error line %d: Reading a line from file is not possible\n",
			(*p_lineNumber));
		error = true;
	}
	else
	{
		try
		{
			getline(*p_file, line);
			discardCR(line);
		}
		catch(ifstream::failure e)
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager.readWave()",
				"Error line %d: Reading line failed with error: %s\n",
				(*p_lineNumber),
				e.what());
			error = true;
		}

		if (line != END_TOKEN)
		{
			logManager.writeLog(LOG_ERROR,
				"ResouceManager.readWave()",
				"Error line %d: The expected end token '%s' was not found\n",
				(*p_lineNumber),
				END_TOKEN);
			WaveData empty;
			return empty;
		}

		++(*p_lineNumber);
	}

	// return an empty wave data on error
	if (error)
	{
		WaveData empty;
		return empty;
	}

	// create and return frame
	WaveData wave(type,
		count,
		delay,
		health,
		speed,
		credits);
	
	return wave;
}

/**
 * Parses the path in the format 'tag x,y;x,y;x,y;...'.
 * @param stringPath The path as string.
 * @param p_map The map to add the path positions.
 * @return Returns 0 for success, else -1.
 */
int parseStringPath(string stringPath, MapData *p_map)
{
	vector<string> pathList;
	split(stringPath, ';', pathList);

	for (vector<string>::iterator it = pathList.begin(); it != pathList.end(); ++it)
	{
		vector<string> positionList;
		split(*it, ',', positionList);

		// verify position might be correct
		if (positionList.size() != 2)
			return -1;

		int x = atoi(positionList.at(0).c_str());
		int y = atoi(positionList.at(1).c_str());

		p_map->addPathPosition(Position(x,y));
	}

	return 0;
}

/**
 * Removes the return after the new line if it ispresent.
 * @param text The reference to the text to remove the '\r'.
 */
void discardCR(string &text)
{
	if (text.at(text.length() - 1) == '\r')
		text.erase(text.length() - 1);
}

