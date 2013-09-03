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
#include "Ufo.h"
#include "Points.h"
#include "Hitpoints.h"
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

	difficulty = MEDIUM_DIFF;
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

	int saucerCount;
	int ufoCount;

	if (difficulty == EASY_DIFF)
	{
		saucerCount = INIT_SAUCER_COUNT_EASY;
		ufoCount = INIT_UFO_COUNT_EASY;
	}
	else if (difficulty == MEDIUM_DIFF)
	{
		saucerCount = INIT_SAUCER_COUNT_MED;
		ufoCount = INIT_UFO_COUNT_MED;
	}
	else
	{
		saucerCount = INIT_SAUCER_COUNT_HARD;
		ufoCount = INIT_UFO_COUNT_HARD;
	}

	for (int i = 0; i < saucerCount; ++i)
	{
		new Saucer();
	}

	for (int i = 0; i < ufoCount; ++i)
	{
		new Ufo();
	}

	// score HUD
	new Points();

	new Hitpoints();

	// nuke HUD
	ViewObject *p_nukes = new ViewObject();
	p_nukes->setLocation(TOP_CENTER);
	p_nukes->setViewString("Nukes");
	p_nukes->setValue(1);
	p_nukes->setColor(COLOR_YELLOW);

	new Hero();

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
	case KEY_LEFT:
		difficulty = difficulty - 1;

		if (difficulty < EASY_DIFF)
			difficulty = HARD_DIFF;
		break;
	case KEY_RIGHT:
		difficulty = difficulty + 1;

		if (difficulty > HARD_DIFF)
			difficulty = EASY_DIFF;
		break;
	}
}

/**
 * Renders the game over object.
 */
void GameStart::draw(void)
{
	Object::draw();

	// draw difficulty
	WorldManager &worldManager = WorldManager::getInstance();
	int startX = worldManager.getBoundary().getHorizontal() / 2 - 7;
	int startY = worldManager.getBoundary().getVertical() / 2 + 9;

	string diffString;

	if (difficulty == EASY_DIFF)
		diffString = EASY_STRING;
	else if (difficulty == MEDIUM_DIFF)
		diffString = MEDIUM_STRING;
	else
		diffString = HARD_STRING;

	string left = "<--  ";
	string right = "  -->";

	GraphicsManager &graphicsManager = GraphicsManager::getInstance();

	for (int i = 0; i < left.length(); ++i)
		graphicsManager.drawCh(Position(startX++, startY), left.at(i), COLOR_RED);

	// diff
	for (int i = 0; i < diffString.length(); ++i)
		graphicsManager.drawCh(Position(startX++, startY), diffString.at(i), COLOR_RED);

	for (int i = 0; i < right.length(); ++i)
		graphicsManager.drawCh(Position(startX++, startY), right.at(i), COLOR_RED);
}