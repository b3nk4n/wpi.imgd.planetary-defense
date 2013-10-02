/*******************************************************************************
 * @file        InputManager.h
 * @author      bsautermeister
 * @description The manager for games user input like keyboard or mouse.
 ******************************************************************************/

#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Manager.h"

/**
 * Class which manages the games user input.
 */
class InputManager : public Manager
{
private:

	/**
	 * Creates a input manager instance.
	 */
	InputManager(void);

	/**
	 * Hides copy constructor.
	 */
	InputManager(InputManager const&);

	/**
	 * Hides assignment operator.
	 */
	void operator=(InputManager const&);

public:
	/**
	 * Cleansup the input manager.
	 */
	~InputManager(void);

	/**
	 * Gets the singleton input manager instance.
	 * @return The singleton input manager instance.
	 */
	static InputManager& getInstance(void);

	/**
	 * Starts up the terminal go capture user input.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	int startUp(void);

	/**
	 * Shuts down the input manager and reverts the terminal input mode.
	 */
	virtual void shutDown(void);

	/**
	 * Validates if event is handles by this manager. Input manager only handles
	 * mouse or keyboard events.
	 * @param eventType The event type name.
	 * @return Returns TRUE if event is handled, else FALSE.
	 */
	 virtual bool isValid(string eventType);

	 /**
	  * Gets the user input from keyboard or mouse. Passes along the
	  * appropriate event for every interested game object.
	  */
	void getInput(void);
};

#endif
