/*******************************************************************************
 * @file        Frame.cpp
 * @author      bsautermeister
 * @description The text based 2D frame for an animated game object.
 ******************************************************************************/

#include "Frame.h"

/**
 * Creates the instance of an empty frame.
 */
Frame::Frame(void)
{
	setWidth(0);
	setHeight(0);
	setData("");
}

/**
 * Creates a frame instance.
 * @param width The frame width.
 * @param height The frame height.
 * @param data The frame string data.
 */
Frame::Frame(int width, int height, string data)
{
	setWidth(width);
	setHeight(height);
	setData(data);
}

/**
 * Gets the frame width.
 * @return The frame width.
 */
int Frame::getWidth(void)
{
	return _width;
}

/**
 * Sets the frame width.
 * @param value The frame width.
 */
void Frame::setWidth(int value)
{
	_width = value;
}

/**
 * Gets the frame height.
 * @return The frame height.
 */
int Frame::getHeight(void)
{
	return _height;
}

/**
 * Sets the frame height.
 * @param value The frame height.
 */
void Frame::setHeight(int value)
{
	_height = value;
}

/**
 * Gets the frame data.
 * @return The frame string data.
 */
string Frame::getData(void)
{
	return _data;
}

/**
 * Sets the frame data.
 * @param data The string frame data.
 */
void Frame::setData(string data)
{
	_data = data;
}

/**
 * Gets whether the frame is empty.
 * @return Returns TRUE, if the frame is empty, else FALSE.
 */
bool Frame::isEmpty(void)
{
	return _data.empty();
}
