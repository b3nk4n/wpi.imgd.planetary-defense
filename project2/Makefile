################################################################################
## @file        Makefile
## @author      bsautermeister
## @description MAKEFILE FOR ENGINEX (DRAGONFLY remake) GAME ENGINE (IMGD 3000)
################################################################################

CC = g++ -g
RM = rm -rf
ifeq ($(system),linux32)
LDFLAGS = -lncurses -lrt -lm
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
LDFLAGS = -lncurses -lm
  else
    ifeq ($(system),cygwin)
PLATFORM = -DCYGWIN
LDFLAGS = -lncurses -lrt -lm
    else
LDFLAGS = -lncurses -lrt -lm
    endif
  endif
endif
ENGSRC = Box.cpp \
		 Circle.cpp \
		 Clock.cpp \
		 GameManager.cpp \
		 GraphicsManager.cpp \
		 Event.cpp \
		 EventCollision.cpp \
		 EventKeyboard.cpp \
		 EventMouse.cpp \
		 EventOut.cpp \
		 EventStep.cpp \
		 EventTest.cpp \
		 EventView.cpp \
		 Frame.cpp \
		 InputManager.cpp \
		 Line.cpp \
		 LogManager.cpp \
		 Manager.cpp \
		 Object.cpp \
		 ObjectList.cpp \
		 ObjectListIterator.cpp \
		 Position.cpp \
		 ResourceManager.cpp \
		 SceneGraph.cpp \
		 Splash.cpp \
		 SplashDragonfly.cpp \
		 Sprite.cpp \
		 TestCollidableObject.cpp \
		 TestAnimatedObject.cpp \
		 TestObject.cpp \
		 utility.cpp \
		 ViewObject.cpp \
		 WorldManager.cpp 
GAMESRC = game.cpp
TESTSRC = test.cpp
UNITTESTSRC =  UnitTestManager.cpp
GAMEBIN = $(GAMESRC:.cpp=)
TESTBIN = $(TESTSRC:.cpp=)
OBJECTS = $(ENGSRC:.cpp=.o)
TESTOBJ = $(ENGSRC:.cpp=.o) $(UNITTESTSRC:.cpp=.o)

.PHONE: all clean depend start

all: $(GAMESRC) $(GAMEBIN) $(TESTBIN) Makefile

$(GAMEBIN):  $(OBJECTS) $(GAMESRC)
	$(CC) $(GAMESRC) $(OBJECTS) $(PLATFORM) -o $@ $(LDFLAGS)

$(TESTBIN): $(TESTOBJ) $(TESTSRC)
	$(CC) $(TESTSRC) $(TESTOBJ) $(PLATFORM) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) $(PLATFORM) $< -o $@

clean:
	$(RM) $(OBJECTS) $(TESTOBJ) $(GAMEBIN) $(TESTBIN) core *.log Makefile.bak *~ *.stackdump

depend: 
	makedepend *.cpp 2> /dev/null
# DO NOT DELETE

Box.o: Box.h Position.h
Circle.o: Circle.h Position.h
Clock.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Clock.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Clock.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Clock.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Clock.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Clock.o: /usr/include/sys/types.h /usr/include/machine/types.h
Clock.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Clock.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Clock.h
Clock.o: /usr/include/time.h /usr/include/machine/time.h
Clock.o: /usr/include/unistd.h /usr/include/sys/unistd.h
Event.o: Event.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h Sprite.h
EventCollision.o: Frame.h Box.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h Position.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
EventTest.o: EventTest.h Event.h
EventView.o: EventView.h Event.h
Frame.o: Frame.h
GameManager.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
GameManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GameManager.o: /usr/include/sys/config.h /usr/include/sys/features.h
GameManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GameManager.o: /usr/include/machine/_types.h
GameManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameManager.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
GameManager.o: /usr/include/stdio.h /usr/include/sys/types.h
GameManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
GameManager.o: /usr/include/bits/wordsize.h /usr/include/signal.h
GameManager.o: /usr/include/sys/signal.h GameManager.h /usr/include/time.h
GameManager.o: /usr/include/machine/time.h Manager.h ObjectList.h Object.h
GameManager.o: Position.h Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
GameManager.o: WorldManager.h SceneGraph.h GraphicsManager.h
GameManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
GameManager.o: /usr/include/unctrl.h InputManager.h ResourceManager.h
GameManager.o: LogManager.h utility.h Line.h Circle.h Splash.h Clock.h
GameManager.o: /usr/include/unistd.h /usr/include/sys/unistd.h EventStep.h
GraphicsManager.o: GraphicsManager.h /usr/include/curses.h
GraphicsManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
GraphicsManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GraphicsManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GraphicsManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
GraphicsManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
GraphicsManager.o: /usr/include/machine/_default_types.h
GraphicsManager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
GraphicsManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
GraphicsManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
GraphicsManager.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
GraphicsManager.o: Manager.h ObjectList.h Object.h Position.h Event.h
GraphicsManager.o: Sprite.h Frame.h Box.h ObjectListIterator.h LogManager.h
GraphicsManager.o: utility.h Line.h Circle.h Splash.h GameManager.h
GraphicsManager.o: /usr/include/time.h /usr/include/machine/time.h
InputManager.o: InputManager.h Manager.h ObjectList.h Object.h Position.h
InputManager.o: Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
InputManager.o: GraphicsManager.h /usr/include/curses.h
InputManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
InputManager.o: /usr/include/_ansi.h /usr/include/newlib.h
InputManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
InputManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
InputManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
InputManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
InputManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
InputManager.o: /usr/include/unctrl.h LogManager.h utility.h Line.h Circle.h
InputManager.o: Splash.h GameManager.h /usr/include/time.h
InputManager.o: /usr/include/machine/time.h EventKeyboard.h EventMouse.h
Line.o: Line.h Position.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
LogManager.o: /usr/include/newlib.h /usr/include/sys/config.h
LogManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
LogManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
LogManager.o: /usr/include/machine/_types.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
LogManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
LogManager.o: ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
LogManager.o: ObjectListIterator.h utility.h Line.h Circle.h Splash.h
LogManager.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
Manager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/types.h /usr/include/machine/types.h
Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
Manager.o: ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
Manager.o: ObjectListIterator.h
Object.o: /usr/include/math.h /usr/include/sys/reent.h /usr/include/_ansi.h
Object.o: /usr/include/newlib.h /usr/include/sys/config.h
Object.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Object.o: Object.h Position.h Event.h Sprite.h Frame.h Box.h WorldManager.h
Object.o: Manager.h ObjectList.h ObjectListIterator.h SceneGraph.h
Object.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
Object.o: /usr/include/sys/types.h /usr/include/machine/types.h
Object.o: InputManager.h GraphicsManager.h /usr/include/curses.h
Object.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
Object.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Object.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Object.o: /usr/include/unctrl.h LogManager.h utility.h Line.h Circle.h
Object.o: Splash.h EventStep.h EventKeyboard.h EventMouse.h
ObjectList.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
ObjectList.o: /usr/include/_ansi.h /usr/include/newlib.h
ObjectList.o: /usr/include/sys/config.h /usr/include/sys/features.h
ObjectList.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ObjectList.o: /usr/include/machine/_types.h
ObjectList.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ObjectList.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
ObjectList.o: /usr/include/stdio.h /usr/include/sys/types.h
ObjectList.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ObjectList.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
ObjectList.o: /usr/include/bits/wordsize.h /usr/include/string.h
ObjectList.o: /usr/include/sys/string.h ObjectList.h Object.h Position.h
ObjectList.o: Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
ObjectList.o: LogManager.h Manager.h utility.h Line.h Circle.h Splash.h
ObjectList.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h Sprite.h Frame.h Box.h
Position.o: Position.h
ResourceManager.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
ResourceManager.o: /usr/include/_ansi.h /usr/include/newlib.h
ResourceManager.o: /usr/include/sys/config.h /usr/include/sys/features.h
ResourceManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ResourceManager.o: /usr/include/machine/_types.h
ResourceManager.o: /usr/include/machine/_default_types.h
ResourceManager.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
ResourceManager.o: /usr/include/alloca.h /usr/include/string.h
ResourceManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
ResourceManager.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h
ResourceManager.o: ResourceManager.h Manager.h ObjectList.h Object.h
ResourceManager.o: Position.h Event.h Sprite.h Frame.h Box.h
ResourceManager.o: ObjectListIterator.h GraphicsManager.h
ResourceManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
ResourceManager.o: /usr/include/stdio.h /usr/include/sys/types.h
ResourceManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ResourceManager.o: /usr/include/unctrl.h LogManager.h utility.h Line.h
ResourceManager.o: Circle.h Splash.h GameManager.h /usr/include/time.h
ResourceManager.o: /usr/include/machine/time.h
SceneGraph.o: SceneGraph.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
SceneGraph.o: ObjectList.h ObjectListIterator.h LogManager.h
SceneGraph.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
SceneGraph.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
SceneGraph.o: /usr/include/sys/features.h /usr/include/sys/reent.h
SceneGraph.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
SceneGraph.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
SceneGraph.o: /usr/include/sys/types.h /usr/include/machine/types.h
SceneGraph.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
SceneGraph.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
SceneGraph.o: utility.h Line.h Circle.h Splash.h GameManager.h
SceneGraph.o: /usr/include/time.h /usr/include/machine/time.h
Splash.o: Splash.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
Splash.o: GraphicsManager.h /usr/include/curses.h /usr/include/ncurses_dll.h
Splash.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Splash.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Splash.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Splash.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Splash.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Splash.o: /usr/include/sys/types.h /usr/include/machine/types.h
Splash.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Splash.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Splash.o: /usr/include/unctrl.h Manager.h ObjectList.h ObjectListIterator.h
Splash.o: WorldManager.h SceneGraph.h GameManager.h /usr/include/time.h
Splash.o: /usr/include/machine/time.h SplashDragonfly.h EventStep.h
Splash.o: EventKeyboard.h
SplashDragonfly.o: Splash.h Object.h Position.h Event.h Sprite.h Frame.h
SplashDragonfly.o: Box.h GraphicsManager.h /usr/include/curses.h
SplashDragonfly.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
SplashDragonfly.o: /usr/include/_ansi.h /usr/include/newlib.h
SplashDragonfly.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
SplashDragonfly.o: /usr/include/sys/features.h /usr/include/sys/reent.h
SplashDragonfly.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
SplashDragonfly.o: /usr/include/machine/_default_types.h
SplashDragonfly.o: /usr/include/sys/lock.h /usr/include/sys/types.h
SplashDragonfly.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
SplashDragonfly.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
SplashDragonfly.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
SplashDragonfly.o: Manager.h ObjectList.h ObjectListIterator.h WorldManager.h
SplashDragonfly.o: SceneGraph.h GameManager.h /usr/include/time.h
SplashDragonfly.o: /usr/include/machine/time.h SplashDragonfly.h EventStep.h
SplashDragonfly.o: EventKeyboard.h
Sprite.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Sprite.o: /usr/include/_ansi.h /usr/include/newlib.h
Sprite.o: /usr/include/sys/config.h /usr/include/sys/features.h
Sprite.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Sprite.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Sprite.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
Sprite.o: /usr/include/alloca.h Sprite.h Frame.h GraphicsManager.h
Sprite.o: /usr/include/curses.h /usr/include/ncurses_dll.h
Sprite.o: /usr/include/stdio.h /usr/include/sys/types.h
Sprite.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Sprite.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Sprite.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h Manager.h
Sprite.o: ObjectList.h Object.h Position.h Event.h Box.h ObjectListIterator.h
Sprite.o: LogManager.h utility.h Line.h Circle.h Splash.h GameManager.h
Sprite.o: /usr/include/time.h /usr/include/machine/time.h
TestAnimatedObject.o: TestAnimatedObject.h TestObject.h Object.h Position.h
TestAnimatedObject.o: Event.h Sprite.h Frame.h Box.h GraphicsManager.h
TestAnimatedObject.o: /usr/include/curses.h /usr/include/ncurses_dll.h
TestAnimatedObject.o: /usr/include/stdio.h /usr/include/_ansi.h
TestAnimatedObject.o: /usr/include/newlib.h /usr/include/sys/config.h
TestAnimatedObject.o: /usr/include/machine/ieeefp.h
TestAnimatedObject.o: /usr/include/sys/features.h /usr/include/sys/reent.h
TestAnimatedObject.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
TestAnimatedObject.o: /usr/include/machine/_default_types.h
TestAnimatedObject.o: /usr/include/sys/lock.h /usr/include/sys/types.h
TestAnimatedObject.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
TestAnimatedObject.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
TestAnimatedObject.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
TestAnimatedObject.o: Manager.h ObjectList.h ObjectListIterator.h
TestAnimatedObject.o: WorldManager.h SceneGraph.h LogManager.h utility.h
TestAnimatedObject.o: Line.h Circle.h Splash.h GameManager.h
TestAnimatedObject.o: /usr/include/time.h /usr/include/machine/time.h
TestAnimatedObject.o: ResourceManager.h
TestCollidableObject.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
TestCollidableObject.o: /usr/include/_ansi.h /usr/include/newlib.h
TestCollidableObject.o: /usr/include/sys/config.h /usr/include/sys/features.h
TestCollidableObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestCollidableObject.o: /usr/include/machine/_types.h
TestCollidableObject.o: /usr/include/machine/_default_types.h
TestCollidableObject.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
TestCollidableObject.o: /usr/include/alloca.h TestCollidableObject.h
TestCollidableObject.o: TestObject.h Object.h Position.h Event.h Sprite.h
TestCollidableObject.o: Frame.h Box.h GameManager.h /usr/include/time.h
TestCollidableObject.o: /usr/include/machine/time.h /usr/include/sys/types.h
TestCollidableObject.o: /usr/include/machine/types.h Manager.h ObjectList.h
TestCollidableObject.o: ObjectListIterator.h GraphicsManager.h
TestCollidableObject.o: /usr/include/curses.h /usr/include/ncurses_dll.h
TestCollidableObject.o: /usr/include/stdio.h /usr/include/sys/stdio.h
TestCollidableObject.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
TestCollidableObject.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
TestCollidableObject.o: WorldManager.h SceneGraph.h EventCollision.h
TestCollidableObject.o: EventView.h LogManager.h utility.h Line.h Circle.h
TestCollidableObject.o: Splash.h
TestObject.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
TestObject.o: /usr/include/_ansi.h /usr/include/newlib.h
TestObject.o: /usr/include/sys/config.h /usr/include/sys/features.h
TestObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestObject.o: /usr/include/machine/_types.h
TestObject.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
TestObject.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
TestObject.o: TestObject.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
TestObject.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
TestObject.o: /usr/include/sys/types.h /usr/include/machine/types.h Manager.h
TestObject.o: ObjectList.h ObjectListIterator.h GraphicsManager.h
TestObject.o: /usr/include/curses.h /usr/include/ncurses_dll.h
TestObject.o: /usr/include/stdio.h /usr/include/sys/stdio.h
TestObject.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
TestObject.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
TestObject.o: WorldManager.h SceneGraph.h EventStep.h EventTest.h
TestObject.o: EventKeyboard.h EventMouse.h EventOut.h EventView.h
TestObject.o: EventCollision.h LogManager.h utility.h Line.h Circle.h
TestObject.o: Splash.h
UnitTestManager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
UnitTestManager.o: /usr/include/_ansi.h /usr/include/newlib.h
UnitTestManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
UnitTestManager.o: /usr/include/sys/features.h /usr/include/sys/types.h
UnitTestManager.o: /usr/include/machine/_types.h
UnitTestManager.o: /usr/include/machine/_default_types.h
UnitTestManager.o: /usr/include/sys/_types.h /usr/include/sys/lock.h
UnitTestManager.o: /usr/include/machine/types.h UnitTestManager.h
UnitTestManager.o: /usr/include/string.h /usr/include/sys/reent.h
UnitTestManager.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
UnitTestManager.o: /usr/include/bits/wordsize.h /usr/include/sys/string.h
UnitTestManager.o: /usr/include/stdlib.h /usr/include/machine/stdlib.h
UnitTestManager.o: /usr/include/alloca.h /usr/include/stdio.h
UnitTestManager.o: /usr/include/sys/stdio.h
ViewObject.o: ViewObject.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ViewObject.o: GraphicsManager.h /usr/include/curses.h
ViewObject.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
ViewObject.o: /usr/include/_ansi.h /usr/include/newlib.h
ViewObject.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ViewObject.o: /usr/include/sys/features.h /usr/include/sys/reent.h
ViewObject.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ViewObject.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ViewObject.o: /usr/include/sys/types.h /usr/include/machine/types.h
ViewObject.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
ViewObject.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
ViewObject.o: /usr/include/unctrl.h Manager.h ObjectList.h
ViewObject.o: ObjectListIterator.h WorldManager.h SceneGraph.h LogManager.h
ViewObject.o: utility.h Line.h Circle.h Splash.h GameManager.h
ViewObject.o: /usr/include/time.h /usr/include/machine/time.h EventView.h
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
WorldManager.o: SceneGraph.h GraphicsManager.h /usr/include/curses.h
WorldManager.o: /usr/include/ncurses_dll.h /usr/include/stdio.h
WorldManager.o: /usr/include/_ansi.h /usr/include/newlib.h
WorldManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
WorldManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
WorldManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
WorldManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
WorldManager.o: /usr/include/unctrl.h LogManager.h utility.h Line.h Circle.h
WorldManager.o: Splash.h GameManager.h /usr/include/time.h
WorldManager.o: /usr/include/machine/time.h EventStep.h EventCollision.h
WorldManager.o: EventOut.h EventMouse.h EventKeyboard.h ViewObject.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h LogManager.h
game.o: /usr/include/stdio.h /usr/include/sys/types.h
game.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
game.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
game.o: /usr/include/bits/wordsize.h Manager.h ObjectList.h Object.h
game.o: Position.h Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
game.o: utility.h Line.h Circle.h Splash.h GameManager.h /usr/include/time.h
game.o: /usr/include/machine/time.h ResourceManager.h WorldManager.h
game.o: SceneGraph.h GraphicsManager.h /usr/include/curses.h
game.o: /usr/include/ncurses_dll.h /usr/include/unctrl.h EventStep.h
game.o: EventKeyboard.h EventMouse.h EventCollision.h EventOut.h TestObject.h
game.o: TestCollidableObject.h TestAnimatedObject.h ViewObject.h
test.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
test.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
test.o: /usr/include/sys/features.h /usr/include/sys/reent.h
test.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
test.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
test.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
test.o: /usr/include/stdio.h /usr/include/sys/types.h
test.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
test.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
test.o: /usr/include/bits/wordsize.h LogManager.h Manager.h ObjectList.h
test.o: Object.h Position.h Event.h Sprite.h Frame.h Box.h
test.o: ObjectListIterator.h utility.h Line.h Circle.h Splash.h GameManager.h
test.o: /usr/include/time.h /usr/include/machine/time.h Clock.h
test.o: /usr/include/unistd.h /usr/include/sys/unistd.h GraphicsManager.h
test.o: /usr/include/curses.h /usr/include/ncurses_dll.h
test.o: /usr/include/unctrl.h WorldManager.h SceneGraph.h InputManager.h
test.o: TestObject.h TestCollidableObject.h UnitTestManager.h
test.o: /usr/include/string.h /usr/include/sys/string.h EventStep.h
test.o: EventTest.h EventView.h EventKeyboard.h EventMouse.h EventOut.h
test.o: EventCollision.h ResourceManager.h ViewObject.h
utility.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
utility.o: /usr/include/sys/features.h /usr/include/sys/reent.h
utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
utility.o: /usr/include/machine/types.h /usr/include/stdio.h
utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
utility.o: /usr/include/math.h utility.h Position.h Box.h Line.h Circle.h
utility.o: Object.h Event.h Sprite.h Frame.h Splash.h GameManager.h Manager.h
utility.o: ObjectList.h ObjectListIterator.h WorldManager.h SceneGraph.h
