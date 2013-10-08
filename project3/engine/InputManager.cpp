/*******************************************************************************
 * @file        InputManager.cpp
 * @author      bsautermeister
 * @description The manager for games user input like keyboard or mouse.
 ******************************************************************************/

#include "InputManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"


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
	LogManager &logManager = LogManager::getInstance();
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();

	// verify graphics manager is started
	if (!graphicsManager.isStarted())
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Could not start up input manager because of unstarted "
			"dependent graphics manager\n");
		return -1;
	}

	// enable keyboard
	if (keypad(stdscr, TRUE) == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Keyboard init of Curses failed.\n");
		return -1;
	}


	// disable line buffering
	if (cbreak() == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Disable line buffering of Curses failed.\n");
		return -1;	
	}

	// turn off new line on output
	if (nonl() == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Disabling new line of Curses failed.\n");
		return -1;
	}

	// disable character echo
	if (noecho() == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Disabling character echo of Curses failed.\n");
		return -1;
	}

	// turn off cursor
	if (curs_set(0) == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Disabling terminal cursor of Curses failed.\n");
		return -1;
	}

	// set no delay for input
	if (nodelay(stdscr, TRUE) == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Activating non-blocking input of Curses failed.\n");
		return -1;
	}


	// enable mouse events
	if (mousemask(BUTTON1_CLICKED | BUTTON1_DOUBLE_CLICKED |
		BUTTON2_CLICKED | BUTTON2_DOUBLE_CLICKED,
		NULL) == 0)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Configuring mouse mask of Curses failed.\n");
		return -1;
	}

	_isStarted = true;
	return 0;
}

/**
 * Shuts down the input manager and reverts the terminal input mode.
 */
void InputManager::shutDown(void)
{
	LogManager &logManager = LogManager::getInstance();

	// switch back to normal cursor
	if (curs_set(1) == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"InputManager::startUp()",
			"Activating normal terminal cursor of Curses failed.\n");
	}

	_isStarted = false;
}

/**
 * Validates if event is handles by this manager. Input manager only handles
 * mouse or keyboard events.
 * @param eventType The event type name.
 * @return Returns TRUE if event is handled, else FALSE.
 */
 bool InputManager::isValid(string eventType)
 {
 	return eventType == KEYBOARD_EVENT || eventType == MOUSE_EVENT; 
 }

 /**
  * Gets the user input from keyboard or mouse. Passes along the
  * appropriate event for every interested game object.
  */
void InputManager::getInput(void)
{
	// get character
	int input = getch();

	if (input != ERR)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_DEBUG,
			"InputManager.getInput()",
			"Got input: %d\n",
			input);

		MEVENT mEvent;
		// mouse interaction detected
		if (input == KEY_MOUSE && getmouse(&mEvent) == OK)
		{
			EventMouse mouseEvent;
				mouseEvent.setPosition(
					Position(mEvent.x,
					mEvent.y));

			if (mEvent.bstate & BUTTON1_CLICKED)
			{
				mouseEvent.setMouseAction(LEFT_BUTTON_CLICK);
				onEvent(&mouseEvent);
			}
			else if (mEvent.bstate & BUTTON1_DOUBLE_CLICKED)
			{
				mouseEvent.setMouseAction(LEFT_BUTTON_DOUBLECLICK);
				onEvent(&mouseEvent);
			}
			else if (mEvent.bstate & BUTTON2_CLICKED)
			{
				mouseEvent.setMouseAction(RIGHT_BUTTON_CLICK);
				onEvent(&mouseEvent);
			}
			else if (mEvent.bstate & BUTTON2_DOUBLE_CLICKED)
			{
				mouseEvent.setMouseAction(RIGHT_BUTTON_DOUBLECLICK);
				onEvent(&mouseEvent);
			}
		}
		else // keyboard interaction event 
		{
			EventKeyboard keyboardEvent;
			keyboardEvent.setKey(input);
			onEvent(&keyboardEvent);
		}
	}
}
