/*******************************************************************************
 * @file        Sprite.h
 * @author      bsautermeister
 * @description The animated sprite to render text-based 2d game objects on
 *              the screen, which takes use of the frame class.
 ******************************************************************************/

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <string>
#include "Frame.h"

using std::string;

/**
 * Represents an animated 2d sprite.
 */
class Sprite
{
private:
	/**
	 * The sprites width.
	 */
	int _width;

	/**
	 * The sprites height.
	 */
	int _height;

	/**
	 * The maximum number of frames the sprite can have.
	 */
	int _maxFrameCount;

	/**
	 * The number of frames.
	 */
	int _frameCount;

	/**
	 * The optional color for the entire spirte.
	 */
	int _color;

	/**
	 * The dynamic array of frames.
	 */
	Frame *p_frame;

	/**
	 * The text label to identify the sprite.
	 */
	string _label;

	/**
	 * Creates a sprite instance.
	 * @note Hidden constuctor because max frame size must be specified.
	 */
	Sprite(void);

public:
	/**
	 * Creates a new sprite instance.
	 * @param maxFrames The maxium number of frames.
	 */
	Sprite(int maxFrames);

	/**
	 * Cleans up the sprites allocated resources.
	 */
	~Sprite(void);

	/**
	 * Gets the sprites width.
	 * @return The sprites width.
	 */
	int getWidth(void);

	/**
	 * Sets the sprites width.
	 * @param value The sprites width.
	 */
	void setWidth(int value);

	/**
	 * Gets the sprites height.
	 * @return The sprites height.
	 */
	int getHeight(void);

	/**
	 * Sets the sprites height.
	 * @param value The sprites height.
	 */
	void setHeight(int value);

	/**
	 * Gets the sprites color.
	 * @return The sprites color.
	 */
	int getColor(void);

	/**
	 * Sets the sprites color.
	 * @param value The sprites color.
	 */
	void setColor(int value);

	/**
	 * Gets the number of frames.
	 * @return The number of frames.
	 */
	int getFrameCount(void);

	/**
	 * Gets the frame with the specified index.
	 * @param frameIndex The frames index.
	 * @return The frame at the specified index or an
	 *         empty frame if index is out of range.
	 */
	Frame getFrame(int frameIndex);

	/**
	 * Adds a new frame.
	 * @param The frame to add.
	 * @return Returns 0 if success, else -1.
	 */
	int addFrame(Frame frame);

	/**
	 * Gets the sprites label.
	 * @return The sprites label.
	 */
	string getLabel(void);

	/**
	 * Sets the sprites label.
	 * @param value The sprites label.
	 */
	void setLabel(string value);
};

#endif