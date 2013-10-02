/*******************************************************************************
* @file        Sprite.cpp
* @author      bsautermeister
* @description The animated sprite to render text-based 2d game objects on
*              the screen, which takes use of the frame class.
******************************************************************************/

#include <string>
#include <stdlib.h>
#include "Sprite.h"
#include "GraphicsManager.h"
#include "LogManager.h"

using std::string;

/**
 * Creates a sprite instance.
 * @note Hidden constuctor because max frame size must be specified.
 */
Sprite::Sprite(void)
{
}

/**
 * Creates a new sprite instance.
 * @param maxFrames The maxium number of frames.
 */
Sprite::Sprite(int maxFrames)
{
	_frameCount = 0;
	_maxFrameCount = maxFrames;
	setWidth(0);
	setHeight(0);
	_color = COLOR_DEFAULT;
	_label = UNLABELED_SPRITE;

	// allocates frames and verify success
	p_frame = new Frame[maxFrames];
	if (p_frame == NULL)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_ERROR,
			"Sprite::Sprite()",
			"Memory for the frames could not be allocated\n");
		_maxFrameCount = 0;
	}
}

/**
 * Cleans up the sprites allocated resources.
 */
Sprite::~Sprite(void)
{
	if (p_frame != NULL)
	{
		delete[] p_frame;
	}
}

/**
 * Gets the sprites width.
 * @return The sprites width.
 */
int Sprite::getWidth(void)
{
	return _width;
}

/**
 * Sets the sprites width.
 * @param value The sprites width.
 */
void Sprite::setWidth(int value)
{
	_width = value;
}

/**
 * Gets the sprites height.
 * @return The sprites height.
 */
int Sprite::getHeight(void)
{
	return _height;
}

/**
 * Sets the sprites height.
 * @param value The sprites height.
 */
void Sprite::setHeight(int value)
{
	_height = value;
}

/**
 * Gets the sprites color.
 * @return The sprites color.
 */
int Sprite::getColor(void)
{
	return _color;
}

/**
 * Sets the sprites color.
 * @param value The sprites color.
 */
void Sprite::setColor(int value)
{
	_color = value;
}

/**
 * Gets the number of frames.
 * @return The number of frames.
 */
int Sprite::getFrameCount(void)
{
	return _frameCount;
}

/**
 * Gets the frame with the specified index.
 * @param frameIndex The frames index.
 * @return The frame at the specified index or an
 *         empty frame if index is out of range.
 */
Frame Sprite::getFrame(int frameIndex)
{
	// verify index is not out of bounds
	if (frameIndex < 0 || frameIndex >= _frameCount)
	{
		Frame empty;
		return empty;
	}
	
	return p_frame[frameIndex];
}

/**
 * Adds a new frame.
 * @param The frame to add.
 * @return Returns 0 if success, else -1.
 */
int Sprite::addFrame(Frame frame)
{
	// verify frame limit is not reached
	if (_frameCount == _maxFrameCount)
		return -1;
	
	// add the frame
	p_frame[_frameCount++] = frame;
	return 0;
}

/**
 * Gets the sprites label.
 * @return The sprites label.
 */
string Sprite::getLabel(void)
{
	return _label;
}

/**
 * Sets the sprites label.
 * @param value The sprites label.
 */
void Sprite::setLabel(string value)
{
	_label = value;
}
