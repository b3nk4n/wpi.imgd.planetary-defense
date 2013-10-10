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
#include "MapObject.h"
#include "Player.h"
#include "Sidebar.h"

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

  _choice = 4;
  // put in center of screen
  WorldManager &world_manager = WorldManager::getInstance();
  Box view = world_manager.getViewBoundary();
  Position position(view.getHorizontal() / 2 , view.getVertical() / 2);
  setPosition(position);
  setSpriteIndex(_choice);

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
    setSpriteIndex(_choice);
  }

  if (p_event->getType() == KEYBOARD_EVENT)
  {   
     EventKeyboard *p_eventKeyboard = static_cast<EventKeyboard *>(p_event);
     int input = p_eventKeyboard->getKey();

    switch(input)
    {
    case LEFT_KEY:
      if (_choice > 0)
      {
        _choice--;
      }
      else
      {
        _choice = 2;
      }
      break;

    case RIGHT_KEY:
      if (_choice < 2)
      {
        _choice++;
      }
      else
      {
        _choice = 0;
      }
      break;
    case ' ':
      {
          WorldManager &world_manager = WorldManager::getInstance();
          Player *player = Player::getInstance();
          new Sidebar(player);
          MapObject* mapObject = MapObject::getInstance();
          mapObject->loadMap("map2");
          mapObject->loadLevel("level1");
          Spawner* sp = Spawner::Instance();
          world_manager.markForDelete(this);
      }
    }
  }
   
}

/**
 * Starts up the world screen
 */
void PlanetMenu::start() {}

// override default draw so as not to display "value"
void PlanetMenu::draw() {
  Object::draw();
}
