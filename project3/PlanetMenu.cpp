/*******************************************************************************
 * @file        PlanetMenu.cpp
 * @author      kcbryant
 * @description Planet selection screen
 ******************************************************************************/

// engine includes
#include "EventKeyboard.h"
#include "EventStep.h"
#include "GameManager.h"
#include "GraphicsManager.h"	// for COLOR_YELLOW
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Box.h"
#include "EventStep.h"
#include "Spawner.h"
#include "TowerDefenseController.h"
#include "Player.h"

// game includes
#include "PlanetMenu.h"

/**
 * Create a new GameStart
 */
PlanetMenu::PlanetMenu() {
  setType("PlanetMenu");

  // link to "message" sprite
  ResourceManager &resourceManager = ResourceManager::getInstance();
  Sprite *p_temp_sprite = resourceManager.getSprite("planet1");
  setSprite(p_temp_sprite);
  setSpriteSlowdown(0);		  

  _choiceMap = 3;
  _choiceLevel = 0;
  // put in center of screen
  WorldManager &world_manager = WorldManager::getInstance();
  Box view = world_manager.getViewBoundary();
  Position position(view.getHorizontal() / 2 , view.getVertical() / 2);
  setPosition(position);
  setSpriteIndex(_choiceMap);

  // register for "keyboard" event
  registerInterest(KEYBOARD_EVENT);
  registerInterest(STEP_EVENT);
}

/**
 * Handle events
 * @param Event, Event being passed to the handler
 * @return int, return 0 if ignored, else 1
 */
int PlanetMenu::eventHandler(Event *p_event) {

  
  if (p_event->getType() == STEP_EVENT)
  {
    setSpriteIndex(_choiceMap);
    return 1;
  }

  if (p_event->getType() == KEYBOARD_EVENT)
  {   
     EventKeyboard *p_eventKeyboard = static_cast<EventKeyboard *>(p_event);
     int input = p_eventKeyboard->getKey();

    switch(input)
    {
    case LEFT_KEY:
      if (_choiceMap > 0)
      {
        _choiceMap--;
      }
      else
      {
        _choiceMap = 2;
      }
      break;

    case RIGHT_KEY:
      if (_choiceMap < 2)
      {
        _choiceMap++;
      }
      else
      {
        _choiceMap = 0;
      }
      break;

    case UP_KEY:
      if (_choiceLevel > 0)
      {
        _choiceLevel--;
      }
      else
      {
        _choiceLevel = 2;
      }
      break;

    case DOWN_KEY:
      if (_choiceLevel < 2)
      {
        _choiceLevel++;
      }
      else
      {
        _choiceLevel = 0;
      }
      break;

    case SPACE_KEY:
      if (_choiceMap == 3)
      {
        _choiceMap = 0;
      }
      else
      {
        start();
      }
      break;
    }
    return 1;
  }

  return 0;
}

/**
 * Starts up the world screen
 */
void PlanetMenu::start()
{
  WorldManager &world_manager = WorldManager::getInstance();
  world_manager.markForDelete(this);

  TowerDefenseController* tdController = TowerDefenseController::getInstance();
  tdController->reset();

  // select map
  if (_choiceMap == 0)
    tdController->loadMap("map1");
  else if (_choiceMap == 1)
    tdController->loadMap("map2");
  else
    tdController->loadMap("map3");

  //select level
  if (_choiceLevel == 0)
    tdController->loadLevel("level1");
  else if (_choiceLevel == 1)
    tdController->loadLevel("level2");
  else
    tdController->loadLevel("level3");
}

// override default draw so as not to display "value"
void PlanetMenu::draw() {
  Object::draw();

  if (getSprite() == NULL)
    return;

  GraphicsManager &graphicsManager = GraphicsManager::getInstance();

  Position levelPos = getPosition();
  levelPos.setY(levelPos.getY() + getSprite()->getHeight() / 2 + 3);

  string levelText;
  if (_choiceLevel == 0)
    levelText = " EASY ";
  else if (_choiceLevel == 1)
    levelText = "MEDIUM";
  else
    levelText = " HARD ";

  graphicsManager.drawStringFormat(
    levelPos, 
    CENTER_JUSTIFIED, 
    getSprite()->getColor(),
    "SELECTED DIFFICULTY : %8s", levelText.c_str());
}
