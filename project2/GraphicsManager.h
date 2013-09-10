/*******************************************************************************
 * @file        GraphicsManager.h
 * @author      bsautermeister
 * @description The graphics manager of the character 2D game engine using the
 *              nCurses library.
 ******************************************************************************/

#ifndef __GRAPHICS_MANAGER_H__
#define __GRAPHICS_MANAGER_H__

#ifdef CYGWIN
#include <ncurses/curses.h>
#else
#include <curses.h>
#endif

#include <string>
#include "Manager.h"
#include "Position.h"

using std::string;

#define COLOR_DEFAULT COLOR_WHITE

/**
 * The supported text justifications.
 */
enum Justification
{
	LEFT_JUSTIFIED,
	CENTER_JUSTIFIED,
	RIGHT_JUSTIFIED
};

/**
 * The manager for 2d character graphics.
 */
class GraphicsManager : public Manager
{
private:
	/**
	 * The screen rendering buffer.
	 */
	WINDOW *_p_buffer;

	/**
	 * Creates a new graphics manager instance.
	 */
	GraphicsManager(void);

	/**
	 * Hides copy constructor.
	 */
	GraphicsManager(GraphicsManager const&);

	/**
	 * Hides equals operator.
	 */
	void operator=(GraphicsManager const&);

	/**
	 * Renders a string on the screen.
	 * @param worldPosition the world position.
	 * @param justification The text justification.
	 * @param color the foreground color.
	 * @param format The format string.
	 * @param args The variable number of parameter for the format string.
	 * @return Returns 0 if ok, else -1.
	 */
	int drawStringFormat(Position worldPosition, Justification justification,
		int color, const char *format, va_list args);

public:
	/**
	 * Gets the singleton graphics manager instance.
	 * @return The singleton graphics manager instance.
	 */
	static GraphicsManager& getInstance(void);

	/**
	 * Starts up the graphics manager and gets the terminal ready
	 * for text-based display.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	virtual int startUp(void);

	/**
	 * Shuts down the graphics manager and reverts to normal display.
	 */
	virtual void shutDown(void);

	/**
	 * Renders a character on the screen.
	 * @param worldPosition the world position.
	 * @param symbol The character to draw.
	 * @param color the foreground color.
	 * @return Returs 0 if ok, else -1.
	 */
	int drawChar(Position worldPosition, char symbol, int color=COLOR_DEFAULT);

	/**
	 * Renders a string on the screen.
	 * @param worldPosition the world position.
	 * @param text The text to draw.
	 * @param justification The text justification.
	 * @param color the foreground color.
	 * @return Returs 0 if ok, else -1.
	 */
	int drawString(Position worldPosition, string text,
		Justification justifigation, int color=COLOR_DEFAULT);

	/**
	 * Renders a string on the screen.
	 * @param worldPosition the world position.
	 * @param format The format string.
	 * @param ... The variable number of parameter for the format string.
	 * @return Returns 0 if ok, else -1.
	 */
	int drawStringFormat(Position worldPosition, const char *format, ...);

	/**
	 * Renders a string on the screen.
	 * @param worldPosition the world position.
	 * @param justification The text justification.
	 * @param format The format string.
	 * @param ... The variable number of parameter for the format string.
	 * @return Returns 0 if ok, else -1.
	 */
	int drawStringFormat(Position worldPosition, Justification justification,
		const char *format, ...);

	/**
	 * Renders a string on the screen.
	 * @param worldPosition the world position.
	 * @param justification The text justification.
	 * @param color the foreground color.
	 * @param format The format string.
	 * @param ... The variable number of parameter for the format string.
	 * @return Returns 0 if ok, else -1.
	 */
	int drawStringFormat(Position worldPosition, Justification justification,
		int color, const char *format, ...);

	/**
	 * Gets the screen horizontal width.
	 * @return The screen width.
	 */
	int getHorizontal(void);

	/**
	 * Gets the screen vertical height.
	 * @return The screen height.
	 */
	int getVertical(void);

	/**
	 * Renders current display buffer.
	 * @return Returns 0 if ok, else -1.
	 */
	int swapBuffers(void);

	/**
	 * Gets the Curses drawing window for additional configuration.
	 * @return The Curses drawing window.
	 */
	WINDOW *getBuffer(void);
};

#endif
