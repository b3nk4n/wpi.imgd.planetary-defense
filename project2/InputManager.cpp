/*******************************************************************************
 * @file        InputManager.cpp
 * @author      bsautermeister
 * @description The manager for games user input like keyboard or mouse.
 ******************************************************************************/

#include "InputManager.h"

/**
 * Creates a input manager instance.
 */
InputManager::InputManager(void)
{

}

/**
 * Hides copy constructor.
 */
InputManager::InputManager(InputManager const&)
{

}

/**
 * Hides assignment operator.
 */
void InputManager::operator=(InputManager const&)
{

}

/**
 * Cleansup the input manager.
 */
InputManager::~InputManager(void)
{

}

/**
 * Gets the singleton input manager instance.
 * @return The singleton input manager instance.
 */
InputManager& InputManager::getInstance(void)
{
	static InputManager inputManager;
	return inputManager;
}

/**
 * Starts up the terminal go capture user input.
 * @return Returns 0 if start up was successfull, else negative.
 */
int InputManager::startUp(void)
{
	return -1;
}

/**
 * Shuts down the input manager and reverts the terminal input mode.
 */
void InputManager::shutDown(void)
{

}

/**
 * Validates if event is handles by this manager. Input manager only handles
 * mouse or keyboard events.
 * @param eventType The event type name.
 * @return Returns TRUE if event is handled, else FALSE.
 */
 bool InputManager::isValid(string eventType)
 {
 	return -1;
 }

 /**
  * Gets the user input from keyboard or mouse. Passes along the
  * appropriate event for every interested game object.
  */
void InputManager::getInput(void)
{

}
