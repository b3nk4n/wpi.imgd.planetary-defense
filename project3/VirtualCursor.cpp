/*******************************************************************************
 * @file        VirtualCursor.cpp
 * @author      bsautermeister
 * @description The virtual cursor in a 2D tile based game world.
 ******************************************************************************/

#include "VirtualCursor.h"
#include "GraphicsManager.h"

/**
 * Creates a virtual cursors instance.
 * @param the position of the cursors in the world.
 */
VirtualCursor::VirtualCursor(Position position)
{
	// setup hardcoded dragonfly splash sprite
	int frames = 2;
	int width = 5;
	int height = 3;
	Sprite *p_tempSprite = new Sprite(frames);
	p_tempSprite->setWidth(width);
	p_tempSprite->setHeight(height);
	p_tempSprite->setColor(COLOR_GREEN);

	// frame 1
	string frameData1;
	frameData1 += "/%%%\\";
	frameData1 += "%%%%%";
	frameData1 += "\\%%%/";
	Frame frame1(width, height, frameData1);
	p_tempSprite->addFrame(frame1);

	// frame 2
	string frameData2;
	frameData2 += "%%-%%";
	frameData2 += "|%%%|";
	frameData2 += "%%-%%";
	Frame frame2(width, height, frameData2);
	p_tempSprite->addFrame(frame2);

	// set object attributes
	setSprite(p_tempSprite);
	setSpriteSlowdown(30);
	setType(TYPE_CURSOR);
	setSolidness(SPECTRAL);
	setAltitude(MAX_ALTITUDE);
	setCentered(false);

	// start and end position
	setPosition(position);
}

/**
 * Cleans up the cursor resources.
 */
VirtualCursor::~VirtualCursor(void)
{

}
