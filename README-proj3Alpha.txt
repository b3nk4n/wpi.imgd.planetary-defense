################################################################################
###                          PLANETARY DEFENSE                               ###
################################################################################
### Names: Benjamin Sautermeister, Kyle Bryant                               ###
### Login: bsautermeister, kcbryant                                          ###
### Date: 10/10/2013                                                         ###
################################################################################
###           IMGD 3000 - PROJECT 3  (Milestone: Dragonfly Spawn)            ###
################################################################################

################################################################################
0. Index
################################################################################

1. Intro
1.1 Platform
2. Build/Compile
3. Execution
3.1 Running the Game
3.2 Game Contents
3.3 Known Issues
4. File and Code Structure
5. Repository

################################################################################
1. Intro
################################################################################

### 1.1 Platform

Planetary Defense, a tower defense game for project 3 was developed using Cygwin on
Windows 8, Debian KDE 12.04 Linux and GIT. The engine will not run on a MacOS
machine, because of the different time-API, which is not implemented because
it couldn't be tested without owning a MacOS system.


################################################################################
2. Build/Compile
################################################################################

There are two makefiles that must be compiled to run the project. One is the engine MAKEFILE, the other is a MAKEFILE for the game.
path:

	./project3/engine/MAKEFILE
	./project3/MAKEFILE

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
3. Execution
################################################################################

### 3.1 Running the Game

To run "Planetary Defense" simply type the below command into the terminal window.

	$ ./game

### 3.2 Game Contents

- Main Menu
	- Planet Menu
		- Map One
			- 3 Enemy Types and a Enemy Spawner
			- 5 Towers (purchased with # keys)
			- Map and Cursor (arrow keys to move)
			- Volts (like population in age of empires, need solar panels to increase)
			- Money (gained by killing enemies)
			- Game Over Screen 
	- Quit

### 3.3 Known Issues

- Game may seg fault randomly when playing
- After lose screen, player cannot select a new planet without a seg fault
- Balancing is way off at the moment. May seem quite hard.
- 

################################################################################
4. File and Code Structure
################################################################################

The project folder should be look like the following:

	./
	|- README            # this file here :)
	|- project3/         # contains all project3 specific code and header
	       |             # including the unit test manager
	       |- MAKEFILE
	       |- game.cpp   # Planetary Defense
	       |- Tower.cpp
	       |- Tower.h
	       |- Player.cpp
	       |- Player.h
	       |- engine/
	            |- MAKEFILE
	       		|- Object.cpp
	       		|- Object.h
	       		|- etc...

################################################################################
5. Repository
################################################################################

bitbucket.org was used as a git repository for this project. 

