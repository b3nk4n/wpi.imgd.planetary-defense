################################################################################
## @file        Makefile
## @author      bsautermeister
## @description MAKEFILE FOR DRAGONFLY GAME ENGINE (IMGD 3000)
################################################################################

CC = g++
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
		 Frame.cpp \
		 InputManager.cpp \
		 LogManager.cpp \
		 Manager.cpp \
		 Object.cpp \
		 ObjectList.cpp \
		 ObjectListIterator.cpp \
		 Position.cpp \
		 ResourceManager.cpp \
		 Sprite.cpp \
		 TestCollidableObject.cpp \
		 TestObject.cpp \
		 utility.cpp \
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
EventCollision.o: EventCollision.h Event.h Object.h Position.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h Position.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
EventTest.o: EventTest.h Event.h
Frame.o: Frame.h
GameManager.o: /usr/include/stdio.h /usr/include/_ansi.h
GameManager.o: /usr/include/newlib.h /usr/include/sys/config.h
GameManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
GameManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GameManager.o: /usr/include/machine/_types.h
GameManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
GameManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
GameManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
GameManager.o: GameManager.h /usr/include/time.h /usr/include/machine/time.h
GameManager.o: Manager.h ObjectList.h Object.h Position.h Event.h
GameManager.o: ObjectListIterator.h WorldManager.h GraphicsManager.h
GameManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
GameManager.o: /usr/include/unctrl.h InputManager.h LogManager.h utility.h
GameManager.o: Box.h Clock.h /usr/include/unistd.h /usr/include/sys/unistd.h
GameManager.o: EventStep.h
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
GraphicsManager.o: ObjectListIterator.h LogManager.h utility.h Box.h
InputManager.o: InputManager.h Manager.h ObjectList.h Object.h Position.h
InputManager.o: Event.h ObjectListIterator.h GraphicsManager.h
InputManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
InputManager.o: /usr/include/stdio.h /usr/include/_ansi.h
InputManager.o: /usr/include/newlib.h /usr/include/sys/config.h
InputManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
InputManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
InputManager.o: /usr/include/machine/_types.h
InputManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
InputManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
InputManager.o: /usr/include/unctrl.h LogManager.h utility.h Box.h
InputManager.o: EventKeyboard.h EventMouse.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
LogManager.o: /usr/include/newlib.h /usr/include/sys/config.h
LogManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
LogManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
LogManager.o: /usr/include/machine/_types.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
LogManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
LogManager.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
LogManager.o: utility.h Box.h
Manager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/types.h /usr/include/machine/types.h
Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
Manager.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
Object.o: /usr/include/math.h /usr/include/sys/reent.h /usr/include/_ansi.h
Object.o: /usr/include/newlib.h /usr/include/sys/config.h
Object.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Object.o: Object.h Position.h Event.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h GameManager.h /usr/include/time.h
Object.o: /usr/include/machine/time.h /usr/include/sys/types.h
Object.o: /usr/include/machine/types.h InputManager.h LogManager.h
Object.o: /usr/include/stdio.h /usr/include/sys/stdio.h
Object.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
Object.o: /usr/include/bits/wordsize.h utility.h Box.h EventStep.h
Object.o: EventKeyboard.h EventMouse.h
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
ObjectList.o: Event.h ObjectListIterator.h LogManager.h Manager.h utility.h
ObjectList.o: Box.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h
Position.o: Position.h
ResourceManager.o: ResourceManager.h Manager.h ObjectList.h Object.h
ResourceManager.o: Position.h Event.h ObjectListIterator.h Sprite.h Frame.h
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
Sprite.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
Sprite.o: LogManager.h utility.h Box.h
TestCollidableObject.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
TestCollidableObject.o: /usr/include/_ansi.h /usr/include/newlib.h
TestCollidableObject.o: /usr/include/sys/config.h /usr/include/sys/features.h
TestCollidableObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestCollidableObject.o: /usr/include/machine/_types.h
TestCollidableObject.o: /usr/include/machine/_default_types.h
TestCollidableObject.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
TestCollidableObject.o: /usr/include/alloca.h TestCollidableObject.h
TestCollidableObject.o: TestObject.h Object.h Position.h Event.h
TestCollidableObject.o: GameManager.h /usr/include/time.h
TestCollidableObject.o: /usr/include/machine/time.h /usr/include/sys/types.h
TestCollidableObject.o: /usr/include/machine/types.h Manager.h ObjectList.h
TestCollidableObject.o: ObjectListIterator.h GraphicsManager.h
TestCollidableObject.o: /usr/include/curses.h /usr/include/ncurses_dll.h
TestCollidableObject.o: /usr/include/stdio.h /usr/include/sys/stdio.h
TestCollidableObject.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
TestCollidableObject.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
TestCollidableObject.o: WorldManager.h EventCollision.h LogManager.h
TestCollidableObject.o: utility.h Box.h
TestObject.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
TestObject.o: /usr/include/_ansi.h /usr/include/newlib.h
TestObject.o: /usr/include/sys/config.h /usr/include/sys/features.h
TestObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestObject.o: /usr/include/machine/_types.h
TestObject.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
TestObject.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
TestObject.o: TestObject.h Object.h Position.h Event.h GameManager.h
TestObject.o: /usr/include/time.h /usr/include/machine/time.h
TestObject.o: /usr/include/sys/types.h /usr/include/machine/types.h Manager.h
TestObject.o: ObjectList.h ObjectListIterator.h GraphicsManager.h
TestObject.o: /usr/include/curses.h /usr/include/ncurses_dll.h
TestObject.o: /usr/include/stdio.h /usr/include/sys/stdio.h
TestObject.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
TestObject.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
TestObject.o: WorldManager.h EventStep.h EventTest.h EventKeyboard.h
TestObject.o: EventMouse.h EventOut.h EventCollision.h LogManager.h utility.h
TestObject.o: Box.h
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
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h ObjectListIterator.h GraphicsManager.h
WorldManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h
WorldManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
WorldManager.o: /usr/include/unctrl.h LogManager.h utility.h Box.h
WorldManager.o: EventStep.h EventCollision.h EventOut.h
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
game.o: Position.h Event.h ObjectListIterator.h utility.h Box.h GameManager.h
game.o: /usr/include/time.h /usr/include/machine/time.h EventStep.h
game.o: EventKeyboard.h EventMouse.h EventCollision.h EventOut.h TestObject.h
game.o: TestCollidableObject.h
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
test.o: Object.h Position.h Event.h ObjectListIterator.h utility.h Box.h
test.o: Clock.h /usr/include/time.h /usr/include/machine/time.h
test.o: /usr/include/unistd.h /usr/include/sys/unistd.h GameManager.h
test.o: GraphicsManager.h /usr/include/curses.h /usr/include/ncurses_dll.h
test.o: /usr/include/unctrl.h WorldManager.h InputManager.h TestObject.h
test.o: TestCollidableObject.h UnitTestManager.h /usr/include/string.h
test.o: /usr/include/sys/string.h EventStep.h EventTest.h EventKeyboard.h
test.o: EventMouse.h EventOut.h EventCollision.h
utility.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
utility.o: /usr/include/sys/features.h /usr/include/sys/reent.h
utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
utility.o: /usr/include/machine/types.h /usr/include/stdio.h
utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h utility.h
utility.o: Position.h Box.h
