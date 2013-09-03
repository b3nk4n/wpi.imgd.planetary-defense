/* GameOver.cpp */

#include "GameOver.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "GameStart.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

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

	timeToLive = getSprite()->getFrameCount() * getSpriteSlowdown();

	// disable collision detection
	setSolidness(SPECTRAL);
}

/**
 * Destructs the game over instance.
 */
GameOver::~GameOver(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	// cleanup HUD objects
	ObjectList viewObjectList = worldManager.getAllObjects();
	ObjectListIterator voit(&viewObjectList);
	for (voit.first(); !voit.isDone(); voit.next())
	{
		ViewObject *p_vo = dynamic_cast<ViewObject *>(voit.currentObject());
		if (p_vo != NULL &&
			(p_vo->getViewString() == "Nukes" ||
			p_vo->getViewString() == "Points" ||
			p_vo->getViewString() == "HP" ||
			p_vo->getViewString() == "GameLevelUpdater"))
		{
			worldManager.markForDelete(p_vo);
		}
	}

	// clean up objects
	ObjectList objectList = worldManager.getAllObjects();
	ObjectListIterator oit(&objectList);
	for (oit.first(); !oit.isDone(); oit.next())
	{
		//Object *p_o = static_cast<ViewObject *>(oit.currentObject());
		Object *p_o = oit.currentObject();
		if (p_o->getType() == "Saucer" ||
			p_o->getType() == "Ufo" ||
			p_o->getType() == "Boss" ||
			p_o->getType() == "Powerup" ||
			p_o->getType() == "Laser" ||
			p_o->getType() == "Buller" ||
			p_o->getType() == "Rocket" ||
			p_o->getType() == "Explosion")
		{
			worldManager.markForDelete(p_o);
		}
	}

	/*// alternative implementation of both loops above
	ObjectList object_list = world_manager.getAllObjects();
  	ObjectListIterator i(&object_list);
  	for (i.first(); !i.isDone(); i.next()) {
    	Object *p_o = i.currentObject();
    	if (p_o -> getType() == "ABC_TYPE!?!" || p_o -> getType() == "ViewObject")
      		world_manager.markForDelete(p_o);
  	}*/

	// back to menu
	worldManager.setLevel(MENU_LEVEL);
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