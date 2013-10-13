/*******************************************************************************
 * @file        GameControls.cpp
 * @author      kcbryant
 * @description Game instructions screen
 ******************************************************************************/

// engine includes
#include "EventKeyboard.h"
#include "EventStep.h"
#include "GameManager.h"
#include "GameStart.h"
#include "GraphicsManager.h"	// for COLOR_YELLOW
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Box.h"

// game includes
#include "GameControls.h"

/**
 * Create a new GameControls screen
 */
GameControls::GameControls() {
  setType("GameControl");

  _counter = 0;

  // link to "message" sprite
  ResourceManager &resourceManager = ResourceManager::getInstance();
  Sprite *p_temp_sprite = resourceManager.getSprite("gamecontrol");
  setSprite(p_temp_sprite);
  setSpriteSlowdown(0);		  

  // put in center of screen
  WorldManager &world_manager = WorldManager::getInstance();
  Box view = world_manager.getViewBoundary();
  Position position(view.getHorizontal() / 2 , view.getVertical() / 2);
  setPosition(position);
  setSpriteIndex(_counter);

  // register for "keyboard" event
  registerInterest(KEYBOARD_EVENT);
  registerInterest(STEP_EVENT);
}

/**
 * Handle events
 * @param Event, Event being passed to the handler
 * @return int, return 0 if ignored, else 1
 */
int GameControls::eventHandler(Event *p_e) {
   GameManager &gameManager = GameManager::getInstance();

  if (p_e->getType() == STEP_EVENT){
    setSpriteIndex(_counter);
  }
  // keyboard
  if (p_e->getType() == KEYBOARD_EVENT) {
    EventKeyboard *p_keyboard_event = (EventKeyboard *) p_e;
    switch (p_keyboard_event->getKey()) {
    case 'c':
      start();
      break;
    case RIGHT_KEY:
      if (_counter < 7)
      {
        _counter++;
      }
      break;
    case LEFT_KEY:
      if (_counter > 0)
      {
        _counter--;
      }
      break;
    }
    return 1;
  }

  // if we get here, we have ignored this event
  return 0;
}

/**
 * Starts up the world screen
 */
void GameControls::start() {
  
  WorldManager &world_manager = WorldManager::getInstance();
  new GameStart();
  world_manager.markForDelete(this);
}

// override default draw so as not to display "value"
void GameControls::draw() {
  Object::draw();
}
