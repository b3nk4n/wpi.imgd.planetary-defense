/* GameOver.cpp */

#include "GameOver.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "EventStep.h"

/**
 * Creates a new game over instance.
 */
GameOver::GameOver(void)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	Sprite *p_tempSprite = resourceManager.getSprite("gameover");
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"GameOver::GameOver(): Sprite %s not found",
			"gameover");
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(15);
	}

	toCenterOfScreen();

	// register for events
	registerInterest(STEP_EVENT);

	// set object type
	setType("GameOver");

	timeToLive = getSprite()->getFrameCount() * 15;

	// disable collision detection
	setSolidness(SPECTRAL);
}

/**
 * Destructs the game over instance.
 */
GameOver::~GameOver(void)
{
	GameManager &gameManager = GameManager::getInstance();
	gameManager.setGameOver();
}

/**
 * Moves the game over text to the center of the screen.
 */
void GameOver::toCenterOfScreen(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Position tempPos(worldManager.getBoundary().getCorner().getX() +
		worldManager.getBoundary().getHorizontal() / 2,
		worldManager.getBoundary().getCorner().getY() +
		worldManager.getBoundary().getVertical() / 2);
	setPosition(tempPos);
}

/**
 * Handles the events.
 */
int GameOver::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		step();
		return 1;
	}

	return 0;
}

/**
 * Updates the game over object.
 */
void GameOver::step(void)
{
	--timeToLive;

	if (timeToLive <= 0)
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}
}

/**
 * Renders the game over object.
 */
void GameOver::draw(void)
{
	Object::draw();
}