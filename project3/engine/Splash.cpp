/*******************************************************************************
* @file        Splash.cpp
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


/**
 * Creates a new splash screen instance.
 */
Splash::Splash(void)
{
	// setup hardcoded splash sprite
	int frames = 2;
	int width = 47;
	int height = 6;
	Sprite *p_tempSprite = new Sprite(frames);
	p_tempSprite->setWidth(width);
	p_tempSprite->setHeight(height);
	p_tempSprite->setColor(COLOR_BLUE);

	// frame 1       
	string frameData1;
	frameData1 += "   ___________              __                 ";
	frameData1 += "   \\_   _____/___    ____  |__| ____   ____    ";
	frameData1 += "   /    __)_/    \\  /___ \\ |  |/    \\_/ __ \\   ";
	frameData1 += "  /        \\   |  \\/ /_/   >  |   |  \\  ___/   ";
	frameData1 += " /_______  /___|  /\\___   /|__|__/  /\\___  >   ";
	frameData1 += "         \\/     \\/ /_____/        \\/     \\/    ";
	Frame frame1(width, height, frameData1);
	p_tempSprite->addFrame(frame1);

	// frame 2
	string frameData2;
	frameData2 += "___________               __                   ";
	frameData2 += "\\_   _____/ ____    ____ |__| ____   ____      ";
	frameData2 += " |    __)_ /    \\  / ___\\|  |/    \\_/ __ \\     ";
	frameData2 += " |        \\   |  \\/ /_/  >  |   |  \\  ___/     ";
	frameData2 += "/_______  /___|  /\\___  /|__|___|  /\\___  >    ";
	frameData2 += "        \\/     \\//_____/         \\/     \\/     ";
	Frame frame2(width, height, frameData2);
	p_tempSprite->addFrame(frame2);

	// set object attributes
	setSprite(p_tempSprite);
	setSpriteSlowdown(0);
	setType(TYPE_SPLASH);
	setSolidness(SPECTRAL);

	// start off right side of screen
	WorldManager &worldManager = WorldManager::getInstance();
	Box view = worldManager.getViewBoundary();
	Position position(view.getCorner().getX() + view.getHorizontal() + getBox().getHorizontal() / 2,
		view.getCorner().getY() + view.getVertical() / 2);
	setPosition(position);

	// set speed to get to center of screen in 0.5 seconds (15 steps)
	int distance = (view.getHorizontal() / 2)
		+ getBox().getHorizontal() / 2
		+ 12;
	setVelocityX(-1.0f * distance / 15);
	_countdown = 15;

	// regiter for events
	registerInterest(STEP_EVENT);
	registerInterest(KEYBOARD_EVENT);
}

/**
 * Cleans up the splash screens resources.
 */
Splash::~Splash(void)
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
int Splash::eventHandler(Event *p_event)
{
	GameManager &gameManager = GameManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	if (p_event->getType() == KEYBOARD_EVENT)
	{
		gameManager.setGameOver(true);
		worldManager.markForDelete(this);
		setVisibility(false);
		return 1;
	}

	if (p_event->getType() == STEP_EVENT)
	{
		--_countdown;

		// time to launch dragonfly?
		if (_countdown == 0)
		{
			setSpriteIndex(1);
			setVelocityX(0);
			Position endPosition(getPosition().getX() + 24,
				getPosition().getY() + 1);
			new SplashDragonfly(endPosition);
		}

		// splash screen over?
		if (_countdown == -100)
		{
			gameManager.setGameOver(true);
			worldManager.markForDelete(this);
		}

		return 1;
	}

	return 0;
}
