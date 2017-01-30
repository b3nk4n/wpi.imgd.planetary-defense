<div align="center">
  <img src="https://github.com/bsautermeister/wpi.imgd.planetary-defense/blob/master/assets/logo.png" alt="Planetary Defense"><br>
</div>
---
# PLANETARY DEFENSE

### @authors: Benjamin Sautermeister, Kyle Bryant
### @version: 10/14/2013
### @lecture: IMGD 3000 - PROJECT 3  (FINAL)
---

# Index

1. Intro
 1.1 Platform
2. Build/Compile
3. Execution
 3.1 Running the Game
 3.2 Game Controls
 3.3 Game Contents
 3.4 Additional Featurs
4. File and Code Structure
5. Repository

## 1. Intro

### 1.1 Platform

Planetary Defense, a tower defense game for project 3 was developed using Cygwin 
on Windows 8, Debian KDE 12.04 Linux and GIT. The engine will not run on a MacOS
machine, because of the different time-API, which is not implemented because
it couldn't be tested without owning a MacOS system.


## 2. Build/Compile

There are two makefiles that must be compiled to run the project. One is the 
engine MAKEFILE, the other is a MAKEFILE for the game.
path:

```
./project3/engine/MAKEFILE    # this one first to create the library!
./project3/MAKEFILE
```

Because the CCC server is a Linux x64 machine, the MAKEFILE runs without
configuration on this platform:

```
$ make
```

To use the MAKEFILE on other platforms, simply add your preferred system as an
additional parameter:

```
$ make system=linux32
$ make system=cygwin
$ make system=macos
```

To get the MAKEFILE working, plase check that your Project or correctly
structured. Please see (4. File and code structure) for more details.



## 3. Execution


### 3.1 Running the Game

To run "Planetary Defense" simply type the below command into the terminal window.

```
$ ./game
```

NOTE: Please start the game in FULL SCREEN TERMINAL !!! =)

### 3.2 Game Controls

- After starting the game, press P to start
- In the planet screen, select the map/planet and the difficulty
    - LEFT/RIGHT --> change planet
    - UP/DOWN    --> chane difficulty
    - SPACE      --> SELECT
- In game controls
	- ARROW KEYS  --> move virtual cursor
	- Number Keys --> place builing (1 = solor, 2 = mgtower,... [see sidebar])
	- 'i'         --> toggle enemy info
	- 's'         --> sell building
	- 'q'         --> quit game

### 3.3 Game Contents

- Main Menu
	- Planet Menu
		- Tower Defens Game
			- 3 Maps
			- 3 Levels (EASY = 10 Waves, MEDIUM = 20 Waves, HARD = 30 Waves)
			- 3 Enemy Types (Goblin, Ork Boss)
			- 5 Towers
			- Map and virtual Cursor 
			- Volts (need solar panels to increase)
			- Credits (gained by killing enemies)
	- Quit

### 3.4 Additional Featurs

The game engines resource manager was extended to load maps and level information
specific for tower defens games. So it is possible for the user to modify or add
additional maps or levels.


## 4. File and Code Structure

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


## 5. Repository

In this project, we used 'bitbucket.org' as a GIT repository for collaboration. 
