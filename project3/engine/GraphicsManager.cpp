/*******************************************************************************
 * @file        GraphicsManager.cpp
 * @author      bsautermeister
 * @description The graphics manager of the character 2D game engine using the
 *              nCurses library.
 ******************************************************************************/

#include "GraphicsManager.h"
#include "LogManager.h"

 /**
 * Creates a new graphics manager instance.
 */
GraphicsManager::GraphicsManager(void)
{

}

/**
 * Hides copy constructor.
 */
GraphicsManager::GraphicsManager(GraphicsManager const& gm)
{

}

/**
 * Hides equals operator.
 */
void GraphicsManager::operator=(GraphicsManager const& gm)
{

}

/**
 * Gets the singleton graphics manager instance.
 * @return The singleton graphics manager instance.
 */
GraphicsManager& GraphicsManager::getInstance(void)
{
	static GraphicsManager graphicsManager;
	return graphicsManager;
}

/**
 * Starts up the graphics manager and gets the terminal ready
 * for text-based display.
 * @return Returns 0 if start up was successfull, else negative.
 */
int GraphicsManager::startUp(void)
{
	LogManager &logManager = LogManager::getInstance();

	// initialize ncurses
	if (initscr() == NULL)
	{
		logManager.writeLog(LOG_ERROR,
			"GraphicsManager::startUp()",
			"Initialization of Curses failed.\n");
		return -1;
	}

	// make full size window
	if ((_p_buffer = newwin(0, 0 , 0, 0)) == NULL)
	{
		logManager.writeLog(LOG_ERROR,
			"GraphicsManager::startUp()",
			"Windows creation of Curses failed.\n");
		return -1;
	}

	// clear both windows
	int clear1 = clearok(stdscr, TRUE);
	int clear2 = clearok(_p_buffer, TRUE);
	if (clear1 == ERR || clear2 == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"GraphicsManager::startUp()",
			"Window buffer clearing of Curses failed.\n");
		return -1;
	}

	// leave cursor
	if (leaveok(_p_buffer, TRUE) == ERR)
	{
		logManager.writeLog(LOG_ERROR,
			"GraphicsManager::startUp()",
			"Cursor leaving of Curses failed.\n");
		return -1;
	}

	// check color support
	if (has_colors() == TRUE)
	{
		// enable colors
		if (start_color() == ERR)
		{
			logManager.writeLog(LOG_WARNING,
				"GraphicsManager::startUp()",
				"Color table creation of Curses failed.\n");
		}
		else
		{
			// setup color pairs (num, fg, bg)
			int ip1 = init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
			int ip2 = init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
			int ip3 = init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
			int ip4 = init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
			int ip5 = init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
			int ip6 = init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
			int ip7 = init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
			if (ip1 == ERR || ip2 == ERR || ip3 == ERR || ip4 == ERR ||
				ip5 == ERR || ip6 == ERR || ip7 == ERR)
			{
				logManager.writeLog(LOG_WARNING,
					"GraphicsManager::startUp()",
					"Init color pair of Curses failed.\n");
			}
		}
	}

	// make all characters bold
	if (wattron(_p_buffer, A_BOLD) == ERR)
	{
		logManager.writeLog(LOG_WARNING,
			"GraphicsManager::startUp()",
			"Making bold characters of Curses failed.\n");
	}

	_isStarted = true;
	return 0;
}

/**
 * Shuts down the graphics manager and reverts to normal display.
 */
void GraphicsManager::shutDown(void)
{
	// verify manager is started
	if (!_isStarted)
		return;

	LogManager &logManager = LogManager::getInstance();

	// close window handle and exit curses
	if (endwin() == ERR)
	{
		logManager.writeLog(LOG_WARNING,
			"GraphicsManager::shutDown()",
			"Exit of Curses failed.\n");
	}

	_isStarted = false;
}

/**
 * Renders a character on the screen.
 * @param worldPosition the world position.
 * @param symbol The character to draw.
 * @param color the foreground color.
 * @return Returs 0 if ok, else -1.
 */
int GraphicsManager::drawChar(Position worldPosition, char symbol, int color)
{
	// convert to view position
	Position viewPosition = worldToView(worldPosition);

	int colOn = wattron(_p_buffer, COLOR_PAIR(color));

	int res = mvwaddch(_p_buffer, viewPosition.getY(), viewPosition.getX(), symbol);

	if (colOn)
		wattroff(_p_buffer, COLOR_PAIR(color));

	// missing color does not result in an error
	return res == OK;
}

/**
 * Renders a string on the screen.
 * @param worldPosition the world position.
 * @param text The text to draw.
 * @param justification The text justification.
 * @param color the foreground color.
 * @return Returs 0 if ok, else -1.
 */
int GraphicsManager::drawString(Position worldPosition, string text,
	Justification justification, int color)
{
	Position start = worldPosition;
	int textLength = text.length();

	// justify text position
	switch(justification)
	{
	case CENTER_JUSTIFIED:
		start.setX(worldPosition.getX() - textLength / 2);
		break;

	case RIGHT_JUSTIFIED:
		start.setX(worldPosition.getX() - textLength);
		break;

	case LEFT_JUSTIFIED:
		// do nothing
		break;
	}

	// draw char by char
	for (int i = 0; i < textLength; ++i)
	{
		Position tempPos(start.getX() + i, start.getY());

		// draw character and check for errors
		if (drawChar(tempPos, text.at(i), color) == ERR)
			return -1;
	}

	return 0;
}

/**
 * Renders a string on the screen.
 * @param worldPosition the world position.
 * @param format The format string.
 * @param ... The variable number of parameter for the format string.
 * @return Returns 0 if ok, else -1.
 */
int GraphicsManager::drawStringFormat(Position worldPosition, const char *format, ...)
{
	char buffer[256];

	// GET TITLE BY ARGUMENTS
	va_list args;
	// setup argmument stack
	va_start(args, format);
	// write formatted log content including given arguments
	int res = drawStringFormatIntern(worldPosition,
		LEFT_JUSTIFIED,
		COLOR_DEFAULT,
		format, args);
	// cleanup argument stack
	va_end(args);

	return res;
}

/**
 * Renders a string on the screen.
 * @param worldPosition the world position.
 * @param justification The text justification.
 * @param format The format string.
 * @param ... The variable number of parameter for the format string.
 * @return Returns 0 if ok, else -1.
 */
int GraphicsManager::drawStringFormat(Position worldPosition, Justification justification,
	const char *format, ...)
{
	char buffer[256];

	// GET TITLE BY ARGUMENTS
	va_list args;
	// setup argmument stack
	va_start(args, format);
	// write formatted log content including given arguments
	int res = drawStringFormatIntern(worldPosition,
		justification,
		COLOR_DEFAULT,
		format, args);
	// cleanup argument stack
	va_end(args);

	return res;
}

/**
 * Renders a string on the screen.
 * @param worldPosition the world position.
 * @param justification The text justification.
 * @param color the foreground color.
 * @param format The format string.
 * @param ... The variable number of parameter for the format string.
 * @return Returns 0 if ok, else -1.
 */
int GraphicsManager::drawStringFormat(Position worldPosition, Justification justification,
	int color, const char *format, ...)
{
	char buffer[256];

	// GET TITLE BY ARGUMENTS
	va_list args;
	// setup argmument stack
	va_start(args, format);
	// write formatted log content including given arguments
	int res = drawStringFormatIntern(worldPosition,
		justification,
		color,
		format, args);
	// cleanup argument stack
	va_end(args);

	return res;
}

/**
 * Renders a string on the screen.
 * @param worldPosition the world position.
 * @param justification The text justification.
 * @param color the foreground color.
 * @param format The format string.
 * @param args The variable number of parameter for the format string.
 * @return Returns 0 if ok, else -1.
 */
int GraphicsManager::drawStringFormatIntern(Position worldPosition, Justification justification,
	int color, const char *format, va_list args)
{
	char buffer[256];

	// write formatted log content including given arguments
	vsprintf(buffer, format, args);

	// render the string
	string text(buffer);
	return drawString(worldPosition, text,
		justification, color);
}

/**
 * Renders a frame.
 * @param worldPosition The word position.
 * @param frame The frame to render.
 * @param centered Indicates whether the given positin is the center or
 *                 the top left corner.
 * @param color The frames color.
 * @return Returns 0 if ok, else -1.
 */
int GraphicsManager::drawFrame(Position worldPosition, Frame frame, bool centered, int color)
{
	// verify frame is not empty
	if (frame.isEmpty())
		return -1;

	// check centered flag and adjust position
	int offsetX = 0;
	int offsetY = 0;
	if (centered)
	{
		offsetX = frame.getWidth() / 2;
		offsetY = frame.getHeight() / 2;
	}

	string frameData = frame.getData();

	// draw character by character
	for (int y = 0; y < frame.getHeight(); ++y)
	{
		for (int x = 0; x < frame.getWidth(); ++x)
		{
			char drawData = frameData.at(y * frame.getWidth() + x);

			if (drawData != TRANSPARENT_CHAR)
			{
				Position tempPos(worldPosition.getX() - offsetX + x,
					worldPosition.getY() - offsetY + y);
				drawChar(tempPos,
					drawData,
					color);
			}
		}
	}
}

/**
 * Gets the screen horizontal width.
 * @return The screen width.
 */
int GraphicsManager::getHorizontal(void)
{
	return COLS;
}

/**
 * Gets the screen vertical height.
 * @return The screen height.
 */
int GraphicsManager::getVertical(void)
{
	return LINES;
}

/**
 * Renders current display buffer.
 * @return Returns 0 if ok, else -1.
 */
int GraphicsManager::swapBuffers(void)
{
	if (wrefresh(_p_buffer) == ERR)
		return -1;

	// NOTE: active screen won't be cleared
	if (werase(_p_buffer) == ERR)
		return -1;

	return 0;
}

/**
 * Gets the Curses drawing window for additional configuration.
 * @return The Curses drawing window.
 */
WINDOW *GraphicsManager::getBuffer(void)
{
	return _p_buffer;
}

/**
 * Gets the curses color of the given string.
 * @param color The color string.
 * @return The curses color or -1 if unknown.
 */
int GraphicsManager::getColorByString(string color)
{
	if (color == "red")
		return COLOR_RED;
	else if (color == "green")
		return COLOR_GREEN;
	else if (color == "yellow")
		return COLOR_YELLOW;
	else if (color == "blue")
		return COLOR_BLUE;
	else if (color == "magenta")
		return COLOR_MAGENTA;
	else if (color == "cyan")
		return COLOR_CYAN;
	else if (color == "white")
		return COLOR_WHITE;
	else
		return COLOR_DEFAULT;
}
