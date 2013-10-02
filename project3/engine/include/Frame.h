/*******************************************************************************
 * @file        Frame.h
 * @author      bsautermeister
 * @description The text based 2D frame for an animated game object.
 ******************************************************************************/

#ifndef __FRAME_H__
#define __FRAME_H__

#include <string>

using std::string;

/**
 * Represents a frame of an animation.
 */
class Frame
{
private:
	/**
	 * The frame width.
	 */
	int _width;

	/**
	 * The frame height.
	 */
	int _height;

	/**
	 * All frame characters stored in a single string.
	 */
	string _data;

public:
	/**
	 * Creates the instance of an empty frame.
	 */
	Frame(void);

	/**
	 * Creates a frame instance.
	 * @param width The frame width.
	 * @param height The frame height.
	 * @param data The frame string data.
	 */
	Frame(int width, int height, string data);

	/**
	 * Gets the frame width.
	 * @return The frame width.
	 */
	int getWidth(void);

	/**
	 * Sets the frame width.
	 * @param value The frame width.
	 */
	void setWidth(int value);

	/**
	 * Gets the frame height.
	 * @return The frame height.
	 */
	int getHeight(void);

	/**
	 * Sets the frame height.
	 * @param value The frame height.
	 */
	void setHeight(int value);

	/**
	 * Gets the frame data.
	 * @return The frame string data.
	 */
	string getData(void);

	/**
	 * Sets the frame data.
	 * @param data The string frame data.
	 */
	void setData(string data);

	/**
	 * Gets whether the frame is empty.
	 * @return Returns TRUE, if the frame is empty, else FALSE.
	 */
	bool isEmpty(void);
};

#endif
