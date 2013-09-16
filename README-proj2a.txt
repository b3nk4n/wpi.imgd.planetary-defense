################################################################################
### Name: Benjamin Sautermeister                                             ###
### Login: bsautermeister                                                    ###
### Date: 09/09/2013                                                         ###
################################################################################
###            IMGD 3000 - PROJECT 2a (Milestone: Dragonfly Egg)             ###
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
3.3 Memory Leaks
3.4 Test Game
4. File and Code Structure
5. Bibliography

################################################################################
1. Intro
################################################################################

### 1.1 Implementation Details

All additional features like a dynamic memory management, log-time-formatting or
different log level of the LogManager, which were mentioned in the Dragonfly
book, were implemented. Also the step event was extended with an additional
'delta' parameter to allow adjusting the game speed on slow running systems or
any other kind of lag. The WorldManagers shutDown was extended by and additional
cleanUp (or more precisely, a call to a new defined clearAllObjects()) to
enusure a 100% memory-leak-free game. This is proven by the tool VALGRIND. 
Last but not least, a light-weight unit testing framework was implemented to
test the engine code completely and automated (see section 3).


### 1.2 Plattform

The first part of the game engine for project 2 was developed using Cygwin on
Windows 8, Debian KDE 12.04 Linux and GIT. The engine will not run on a MacOS
machine, because of the different time-API, which is not implemented because
it couldn't be tested without owning a MacOS system.


################################################################################
2. Build/Compile
################################################################################

The MAKEFILE to build the project is located in the submussion package under the
path:

	./project1/MAKEFILE

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

To test the game engine code automated and completely, unit tests were created
to test almost every feature of the engine.

At first, I considered to use CppUnit as a unit testing framework to get this
easily done. But there were two problems using CppUnit:

    1. Dependencies two a huge external library
    2. CppUnit must be installed using 'automake' and 'autoconf', which are
       not installed on the CCC server.

So I decided to create my own light-weigt unit testing framework, which design
and workflow orientates on a usual xUnit framework.
The workflow of the framework is the following:
    
    1. configuration: The unit testing manager must be configured with the
                      appropriate setup/cleanup functions. Also, the unit test
		      cases (pointer to the functions) must be registered.
    2. setup:         An setup function can be configured, which is called at
                      the startof a whole test run. Here you can startup the 
		      game manager, etc. So this setup function is just called
		      once.
    3. before:        Is called before each single unit test. Here you can reset
                      some states like the log level of the LogManager, etc.
    4. test-run:      The test function is called and verified.
    5. after:         Is called after each single unit test. Here you can do
                      some small cleanup like clearing all world objects.
    6. cleanup:       Last cleanup. Can be used to shut down the game manager.

About 30-40 Unit test cases were currently created.


### 3.3 Memory Leaks

To verify that the code has no memory leaks, the memory debugging tool VALGRIND
was used. To see that, simple start all unit test and/or the test game and
see the results of VALGRIND:

	$ valgrind ./test all
	$ valgrind ./game


### 3.4 Test Game

To test a whole game workflow, a test game (game.cpp) was added which contains
all the required functionalities [DFL, p.91-92]. In Detail, it starts up the
game manager and its gameloop, spawns 4 TestObjects, with two of them have an
unlimited livetime, one of them marks itself for delete after 30 ticks and the
last one sets the game-over-flag after 100 ticks.
The game can be started without any parameters:

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

