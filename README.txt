################################################################################
### Name: Benjamin Sautermeister                                             ###
### Login: bsautermeister                                                    ###
### Date: 09/03/2013                                                         ###
################################################################################
###                          IMGD 3000 - PROJECT 1                           ###
################################################################################

################################################################################
0. Index
################################################################################

1. Platform
2. Build/Compile
3. File and code structure
4. Final thoughts and improvements proposals to Dragonfly
5. Bibliography

################################################################################
1. Platform
################################################################################

Tha game for project 1 (called SpacepiXX, a minimalistic ported version of my
space shooter for Windows Phone and Windows 8 [SPX]) was developed using Cygwin 
on Windows 8, Debian KDE 12.04 Linux and GIT.


################################################################################
2. Build/Compile
################################################################################

The MAKEFILE to build the project is located in the submussion package under the
path:

	./project1/MAKEFILE

Because Cygwin on Windows 8 was the main development platform, the default
MAKEFILE runs without configuration on this platform:

	$ make

To use the MAKEFILE on other platforms, simply add your preferred system as an
additional parameter:

	$ make system=linux32
	$ make system=linux64
	$ make system=macos

To get the MAKEFILE working, plase check that your Project or correctly
structured. Please see (3. File and code structure) for more details.


################################################################################
3. File and code structure
################################################################################

The project folder should be look like the following:

	./
	|- lib/              # dragonfly libraries (X!)
	|- include/          # dragonfly headers   (X!)
	|- GAME              # the game description of all extensions
	|- README            # this file here :)
	|- project1/         # contains all project1 specific code and header files
	       |- MAKEFILE
	       |- game.cpp
	       |- Hero.cpp
	       |- Hero.h
	       |- Boss.cpp
	       |- Boss.h
	       |- ...

------
(X!) according to the submission page [SUB], we need NOT include all lib and 
     include files of dragonfly. So, these directories do not exist in the
     submission and must be added manually.


################################################################################
5. Final thoughts and improvements proposals to Dragonfly
################################################################################

Because there can never be too much constructive criticism, I would like to add
some personal thoughts to Dragonfly, which came to my mind during developing my
game using this engie. Maybe these improvements could have any effect to the
next version of Dragonfly:

There are huge delays between one and the next keyboard event. I think this is
because of the the use of OS-triggered keyboard events. To be able to control
the player more smoothly, is would be better to have the ability to access all
currently pressed keys inside the step() function.

	// pseudo code
	void step()
	{
		if (inputManager.isPressed(KEY_LEFT))
		{
			// to something...
		}
	}

Another solution could be to bind actions onto specific input types, which is
really helpful if you have many input devides.

	// pseudo code
	void setupInput()
	{
		bind(KEY_LEFT, &move(-1));
		bind(KEY_A, &move(-1));
		bind(KEY_RIGHT, &move(1));
		bind(KEY_D, &move(1));
	}

Also possible would be a combination of both solutions.

	#define LEFT_ACTION 1
	#define RIGHT_ACTION 2

	// pseudo code
	void setupInput()
	{
		bind(KEY_LEFT, LEFT_ACTION);
		bind(KEY_A, LEFT_ACTION);
		bind(KEY_RIGHT, RIGHT_ACTION);
		bind(KEY_D, RIGHT_ACTION);
	}

	// pseudo code
	void step()
	{
		if (inputManager.isPressed(LEFT_ACTION))
		{
			// to something...
		}
		if (inputManager.isPressed(RIGHT_ACTION))
		{
			// to something...
		}
	}

These solutions could help to allow smooth moving using the keyboard. In
addition, multiple keys at the same time would be possible and the huge delay
between the first and the second event call would disappear.


################################################################################
5. Bibliography
################################################################################

[SPX] Benjamin Sautermeister, SpacepiXX, 2011
      Weblink:
      http://bsautermeister.de/spacepixx/

[SUB] Prof. Mark Claypool, IMGD 3000 Project 1 - Submission, 2013
      Weblink:
      http://web.cs.wpi.edu/~imgd3000/a13/projects/proj1/index.html#submission
