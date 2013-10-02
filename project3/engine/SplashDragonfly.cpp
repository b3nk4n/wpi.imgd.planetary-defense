/*******************************************************************************
 * @file        SplashDragonfly.cpp
 * @author      bsautermeister
 * @description The dragonfly splash screen.
 ******************************************************************************/

#include "Splash.h"
#include "Sprite.h"
#include "Frame.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "SplashDragonfly.h"
#include "EventStep.h"
#include "EventKeyboard.h"
#include "LogManager.h"

/**
 * Creates a new splash screen instance.
 * @param endPosition The end position.
 */
SplashDragonfly::SplashDragonfly(Position endPosition)
{
	// setup hardcoded dragonfly splash sprite
	int frames = 2;
	int width = 9;
	int height = 6;
	Sprite *p_tempSprite = new Sprite(frames);
	p_tempSprite->setWidth(width);
	p_tempSprite->setHeight(height);
	p_tempSprite->setColor(COLOR_GREEN);

	// frame 1
	string frameData1;
	frameData1 += "%%*%%%.%%";
	frameData1 += "*%%%%%%.%";
	frameData1 += "%%.%*%%%%";
	frameData1 += "%%%%%%*%%";
	frameData1 += "%%*%.%%%.";
	frameData1 += "%%.%%%*%%";
	Frame frame1(width, height, frameData1);
	p_tempSprite->addFrame(frame1);

	// frame 2
	string frameData2;
	frameData2 += "%.%%*%%.%";
	frameData2 += "%%%.%%%%*";
	frameData2 += "%*%%%*%.%";
	frameData2 += "%%.%*%%%%";
	frameData2 += "%*%%%%%*%";
	frameData2 += ".%%%*.%%.";
	Frame frame2(width, height, frameData2);
	p_tempSprite->addFrame(frame2);

	// set object attributes
	setSprite(p_tempSprite);
	setSpriteSlowdown(2);
	setType(TYPE_SPLASH_DRAGONFLY);
	setSolidness(SPECTRAL);

	// start and end position
	WorldManager &worldManager = WorldManager::getInstance();
	Box view = worldManager.getViewBoundary();
	Position startPosition(endPosition.getX(),
		view.getCorner().getY() + view.getVertical() + 6);
	setPosition(startPosition);
	_endPosition = endPosition;

	// set speed to get to end in 1 sec
	setVelocityY(-1.0f * (startPosition.getY() - _endPosition.getY()) / 30);
	_countdown = 30;

	// regiter for events
	registerInterest(STEP_EVENT);
	registerInterest(KEYBOARD_EVENT);
}

/**
 * Cleans up the splash screens resources.
 */
SplashDragonfly::~SplashDragonfly(void)
{
	// unregister events
	unregisterInterest(STEP_EVENT);
	unregisterInterest(KEYBOARD_EVENT);

	// delete sprite manually since not managed by the resource manager
	delete getSprite();
}

/**
 * Handles the splash screen events.
 * @param p_event The event.
 * @return Returns 0 for success, else -1.
 */
int SplashDragonfly::eventHandler(Event *p_event)
{
	GameManager &gameManager = GameManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	if (p_event->getType() == KEYBOARD_EVENT)
	{
		worldManager.markForDelete(this);
		return 1;
	}

	if (p_event->getType() == STEP_EVENT)
	{
		--_countdown;

		// time to launch dragonfly?
		if (_countdown <= 0 &&
			getPosition().getY() <= _endPosition.getY())
		{
			// stop
			setVelocityY(0);
		}

		// change to Y resting dragonfly
		if (_countdown == -15)
		{
			// delete current sprite manually since not managed by resource manager
			delete getSprite();

			// create Y sprite
			int frames = 1;
			int width = 9;
			int height = 6;
			Sprite *p_tempSprite = new Sprite(frames);
			p_tempSprite->setWidth(width);
			p_tempSprite->setHeight(height);
			p_tempSprite->setColor(COLOR_GREEN);

			// frame 1
			string frameData1;
			frameData1 += "____  ___";
			frameData1 += "\\   \\/  /";
			frameData1 += " \\     / ";
			frameData1 += " /     \\ ";
			frameData1 += "/___/\\  \\";
			frameData1 += "      \\_/";
			Frame frame1(width, height, frameData1);
			int res1 = p_tempSprite->addFrame(frame1);

			setSprite(p_tempSprite);
			setSpriteIndex(0);
			setPosition(getPosition());
		}

		// splash screen over
		if (_countdown == -70)
		{
			worldManager.markForDelete(this);
		}

		return 1;
	}

	return 0;
}

/**
 * Renders the splash X and the text.
 */
void SplashDragonfly::draw(void)
{
	Object::draw();

	if (_countdown <= -15)
	{
		GraphicsManager &graphicsManager = GraphicsManager::getInstance();
		Position pos(getPosition().getX() - 47, getPosition().getY() + 2);
		graphicsManager.drawString(pos,
			"Because eveything with an X sound awesome!",
			LEFT_JUSTIFIED,
			COLOR_WHITE);
	}
}
