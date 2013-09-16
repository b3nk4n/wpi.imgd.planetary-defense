################################################################################
### Name: Benjamin Sautermeister                                             ###
### Login: bsautermeister                                                    ###
### Date: 09/15/2013                                                         ###
################################################################################
###           IMGD 3000 - PROJECT 2b (Milestone: Dragonfly Naiad)            ###
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

All additional features like drawing layers or disallowing movement onto soft
objects were implemented.
Additionally, following is also implemented:
- printf()-like rendering for the GraphicsManagers drawString()-method
- Instead of calling the out/collision eventHandler functions directly (like in
  [DFL, p.128/130]), a second onEvent() method was implemented in the managers
  base class to ensure that events are only called for objects which are really
  registered/interested in OUT or COLLISION events.


### 1.2 Plattform

The second part of the game engine for project 2 was developed using Cygwin on
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
with about 80 unit tests), but was refactored a little bit. Most of the output
is now redirected to a file called 'unittests.log', because sind the use of
the graphics device manager and its startup dependecies to the input manager
there were problems with mixing both outputs to the terminal window.


### 3.3 Test Game

To test the visual stuff, a test game was implemeted wich shows the collisions
some objects, which solidness is HARD(red), SOFT(yellow) or SPECTRAL(green).
Objects wich react to collisions are blue.
To start the game, simply compile the game and run it. It end automaticly after
about 5 seconds.

	$ ./game


################################################################################
4. File and Code Structure
################################################################################

The project folder should be look like the following:

	./
	|- README            # this file here :)
	|- project2/         # contains all project2 specific code and header
	       |             # including the unit test manager
	       |- MAKEFILE
	       |- game.cpp   # the test game
	       |- test.cpp   # the unit test application
	       |- Object.cpp
	       |- Object.h
	       |- Position.cpp
	       |- Position.h
	       |- ...


################################################################################
5. Bibliography
################################################################################

[DFL] Prof. Marc Claypool, Dragonfly - Program a Game Engine from Scratch, 2013

