/* GameStart.cpp */

#include "GameStart.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "EventKeyboard.h"
#include "Hero.h"
#include "Saucer.h"
#include "Points.h"
#include "ViewObject.h"

/**
 * Creates a new game over instance.
 */
GameStart::GameStart(void)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	Sprite *p_tempSprite = resourceManager.getSprite("gamestart");
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"GameStart::GameStart(): Sprite %s not found",
			"gamestart");
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(15);
	}

	toCenterOfScreen();

	// register for events
	registerInterest(KEYBOARD_EVENT);

	// set object type
	setType("GameStart");

	// disable collision detection
	setSolidness(SPECTRAL);
}

/**
 * Starts the game.
 */
void GameStart::start(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	SceneGraph &screneGraph = worldManager.getSceneGraph();

	// will populate play world with objects
	screneGraph.setLevel(PLAY_LEVEL);

	new Hero();

	for (int i = 0; i < INIT_SAUCER_COUNT; ++i)
	{
		new Saucer();
	}

	// score HUD
	new Points();

	// nuke HUD
	ViewObject *p_nukes = new ViewObject();
	p_nukes->setLocation(TOP_LEFT);
	p_nukes->setViewString("Nukes");
	p_nukes->setValue(1);
	p_nukes->setColor(COLOR_YELLOW);

	// revert back to menu
	screneGraph.setLevel(MENU_LEVEL);
	worldManager.setLevel(PLAY_LEVEL);
}

/**
 * Moves the game over text to the center of the screen.
 */
void GameStart::toCenterOfScreen(void)
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
int GameStart::eventHandler(Event *p_event)
{
	if (p_event->getType() == KEYBOARD_EVENT)
	{
		EventKeyboard *p_keyboardEvent = static_cast<EventKeyboard *>(p_event);
		keyboard(p_keyboardEvent);
		return 1;
	}

	return 0;
}

/**
 * Handles keyboard input.
 */
void GameStart::keyboard(EventKeyboard *p_keyboardEvent)
{
	GameManager &gameManager = GameManager::getInstance();

	switch(p_keyboardEvent->getKey())
	{
	case 'p':
		start();
		break;
	case 'q':
		gameManager.setGameOver();
		break;
	}
}

/**
 * Renders the game over object.
 */
void GameStart::draw(void)
{
	Object::draw();
}