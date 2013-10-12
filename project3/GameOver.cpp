/*******************************************************************************
 * @file        GameOver.cpp
 * @author      kcbryant
 * @description Lose Screen
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

#include "GameOver.h"
/**
 * Create a new Game over
 */
GameOver::GameOver(bool success) {
  setType("GameOver");

  ResourceManager &resourceManager = ResourceManager::getInstance();
  Sprite *p_temp_sprite;
  
  if (success)
    p_temp_sprite = resourceManager.getSprite("gamewin");
  else
    p_temp_sprite = resourceManager.getSprite("gameover");

  setSprite(p_temp_sprite);
  setSpriteSlowdown(15);  

  // put in center of screen
  WorldManager &world_manager = WorldManager::getInstance();
  Box view = world_manager.getViewBoundary();
  Position position(view.getHorizontal() / 2 , view.getVertical() / 2);
  setPosition(position);
  
  registerInterest(STEP_EVENT);
}

  /**
   * Handle events
   * @param Event, Event being passed to the handler
   * @return int, return 0 if ignored, else 1
   */
int GameOver::eventHandler(Event *p_event)
{
  if (p_event->getType() == STEP_EVENT)
  {
    if (getSpriteIndex() == 8)
    {
      GameManager &gameManager = GameManager::getInstance();
      gameManager.setGameOver(true);
    }
  }
}

// override default draw so as not to display "value"
void GameOver::draw() {
  Object::draw();
}
