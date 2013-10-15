################################################################################
### Name: Benjamin Sautermeister                                             ###
### Login: bsautermeister                                                    ###
### Date: 09/28/2013                                                         ###
################################################################################
###              IMGD 3000 - PROJECT 2c (Milestone: Dragonfly)               ###
################################################################################

################################################################################
0. Index
################################################################################

1. Intro
1.1 Implementation Details
1.2 Plattform
2. Build/Compile
3. Testing
3.1 Run Tests
3.2 Unit Tests
3.3 Test Game
4. File and Code Structure
5. Bibliography

################################################################################
1. Intro
################################################################################

### 1.1 Implementation Details

In project 2c, all additional features like additional utility functions, the
scene graph (incl. layers and visibility), signal handling, seeds for random
number generator and a splash screen were implemented.
Additionally, following is also implemented:
- Added an transparency character (%) for sprite files to allow transparent
  color to remove some weird visual effects


### 1.2 Plattform

The final part of the game engine for project 2 was developed using Cygwin on
Windows 8, Debian KDE 12.04 Linux and GIT. The engine will not run on a MacOS
machine, because of the different time-API, which is not implemented because
it couldn't be tested without owning a MacOS system.


################################################################################
2. Build/Compile
################################################################################

The MAKEFILE to build the project is located in the submission package under the
path:

	./project2/MAKEFILE

Because the CCC server is a Linux x64 machine, the MAKEFILE runs without
configuration on this platform:

	$ make

To use the MAKEFILE on other platforms, simply add your preferred system as an
additional parameter:

	$ make system=linux32
	$ make system=cygwin
	$ make system=macos

To get the MAKEFILE working, plase check that your Project or correctly
structured. Please see (4. File and code structure) for more details.


################################################################################
3.Testing
################################################################################

### 3.1 Run Tests

To run the unit test, just run the program to see the HELP page:

	$ ./test

To run ALL tests, just use the parameter 'all':

	$ ./test all

To run a single test, please use the unit test ID, which is displayed when you
run all tests. Example:

	$ ./test 5


### 3.2 Unit Tests

The implemented ligh-weight unit-testing framework is still used (currently
with about 180 unit tests), but was refactored a little bit. Most of the output
is now redirected to a file called 'unittests.log', because sind the use of
the graphics device manager and its startup dependecies to the input manager
there were problems with mixing both outputs to the terminal window.


### 3.3 Test Game

To test the visual stuff, a test game was implemeted which shows the collisions
many randomly placed objects, which solidness is HARD(red), SOFT(yellow) or 
SPECTRAL(green). Objects wich react to collisions are blue.
To start the game, simply compile the game and run it. It end automaticly after
about 10-15 seconds seconds.

	$ ./game

Also it tests the automated following camera of an object, sprites and the
splash screen.


################################################################################
4. File and Code Structure
################################################################################

The project folder should be look like the following:

	./
	|- README             # this file here :)
	|- project2/          # contains all project2 specific code and header
	       |              # including the unit test manager
	       |- MAKEFILE
               |- enginex.log # The games log file
	       |- game.cpp    # the test game
	       |- test.cpp    # the unit test application
	       |- Object.cpp
	       |- Object.h
	       |- Position.cpp
	       |- Position.h
	       |- ...


################################################################################
5. Bibliography
################################################################################

[DFL] Prof. Marc Claypool, Dragonfly - Program a Game Engine from Scratch, 2013

