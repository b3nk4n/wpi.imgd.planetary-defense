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
		 InputManager.cpp \
		 LogManager.cpp \
		 Manager.cpp \
		 Object.cpp \
		 ObjectList.cpp \
		 ObjectListIterator.cpp \
		 Position.cpp \
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
Clock.o: /usr/include/stdio.h /usr/include/features.h
Clock.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Clock.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Clock.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Clock.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Clock.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Clock.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Clock.o: Clock.h /usr/include/time.h /usr/include/bits/time.h
Clock.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
Clock.o: /usr/include/bits/confname.h /usr/include/getopt.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h
Event.o: Event.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h Position.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
EventTest.o: EventTest.h Event.h
game.o: /usr/include/stdlib.h /usr/include/features.h
game.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
game.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
game.o: /usr/include/sys/types.h /usr/include/bits/types.h
game.o: /usr/include/bits/typesizes.h /usr/include/time.h
game.o: /usr/include/bits/time.h /usr/include/endian.h
game.o: /usr/include/bits/endian.h /usr/include/sys/select.h
game.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
game.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
game.o: /usr/include/alloca.h LogManager.h /usr/include/stdio.h
game.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
game.o: /usr/include/bits/wchar.h /usr/include/gconv.h
game.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
game.o: Manager.h ObjectList.h Object.h Position.h Event.h
game.o: ObjectListIterator.h utility.h Box.h GameManager.h EventStep.h
game.o: EventKeyboard.h EventMouse.h EventCollision.h EventOut.h TestObject.h
game.o: TestCollidableObject.h
GameManager.o: /usr/include/stdio.h /usr/include/features.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
GameManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
GameManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
GameManager.o: /usr/include/libio.h /usr/include/_G_config.h
GameManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
GameManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
GameManager.o: /usr/include/bits/sys_errlist.h GameManager.h
GameManager.o: /usr/include/time.h /usr/include/bits/time.h Manager.h
GameManager.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
GameManager.o: WorldManager.h GraphicsManager.h /usr/include/curses.h
GameManager.o: /usr/include/ncurses/ncurses_dll.h
GameManager.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
GameManager.o: InputManager.h LogManager.h utility.h Box.h Clock.h
GameManager.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
GameManager.o: /usr/include/bits/confname.h /usr/include/getopt.h EventStep.h
GraphicsManager.o: GraphicsManager.h /usr/include/curses.h
GraphicsManager.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
GraphicsManager.o: /usr/include/features.h /usr/include/sys/cdefs.h
GraphicsManager.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
GraphicsManager.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
GraphicsManager.o: /usr/include/bits/typesizes.h /usr/include/libio.h
GraphicsManager.o: /usr/include/_G_config.h /usr/include/wchar.h
GraphicsManager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
GraphicsManager.o: /usr/include/bits/stdio_lim.h
GraphicsManager.o: /usr/include/bits/sys_errlist.h
GraphicsManager.o: /usr/include/ncurses/unctrl.h
GraphicsManager.o: /usr/include/ncurses/curses.h Manager.h ObjectList.h
GraphicsManager.o: Object.h Position.h Event.h ObjectListIterator.h
GraphicsManager.o: LogManager.h utility.h Box.h
InputManager.o: InputManager.h Manager.h ObjectList.h Object.h Position.h
InputManager.o: Event.h ObjectListIterator.h GraphicsManager.h
InputManager.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
InputManager.o: /usr/include/stdio.h /usr/include/features.h
InputManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
InputManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
InputManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
InputManager.o: /usr/include/libio.h /usr/include/_G_config.h
InputManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
InputManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
InputManager.o: /usr/include/bits/sys_errlist.h /usr/include/ncurses/unctrl.h
InputManager.o: /usr/include/ncurses/curses.h LogManager.h utility.h Box.h
InputManager.o: EventKeyboard.h EventMouse.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/features.h
LogManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
LogManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
LogManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
LogManager.o: /usr/include/libio.h /usr/include/_G_config.h
LogManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
LogManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
LogManager.o: /usr/include/bits/sys_errlist.h Manager.h ObjectList.h Object.h
LogManager.o: Position.h Event.h ObjectListIterator.h utility.h Box.h
Manager.o: /usr/include/stdio.h /usr/include/features.h
Manager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Manager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Manager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Manager.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Manager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Manager.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Manager.o: Manager.h ObjectList.h Object.h Position.h Event.h
Manager.o: ObjectListIterator.h
Object.o: /usr/include/math.h /usr/include/features.h
Object.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Object.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Object.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
Object.o: /usr/include/bits/mathcalls.h Object.h Position.h Event.h
Object.o: WorldManager.h Manager.h ObjectList.h ObjectListIterator.h
Object.o: GameManager.h /usr/include/time.h /usr/include/bits/time.h
Object.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Object.o: InputManager.h LogManager.h /usr/include/stdio.h
Object.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Object.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Object.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Object.o: utility.h Box.h EventStep.h EventKeyboard.h EventMouse.h
ObjectList.o: /usr/include/stdlib.h /usr/include/features.h
ObjectList.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ObjectList.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
ObjectList.o: /usr/include/sys/types.h /usr/include/bits/types.h
ObjectList.o: /usr/include/bits/typesizes.h /usr/include/time.h
ObjectList.o: /usr/include/bits/time.h /usr/include/endian.h
ObjectList.o: /usr/include/bits/endian.h /usr/include/sys/select.h
ObjectList.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
ObjectList.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
ObjectList.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
ObjectList.o: /usr/include/_G_config.h /usr/include/wchar.h
ObjectList.o: /usr/include/bits/wchar.h /usr/include/gconv.h
ObjectList.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ObjectList.o: /usr/include/string.h ObjectList.h Object.h Position.h Event.h
ObjectList.o: ObjectListIterator.h LogManager.h Manager.h utility.h Box.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h
Position.o: Position.h
TestCollidableObject.o: /usr/include/stdlib.h /usr/include/features.h
TestCollidableObject.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
TestCollidableObject.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
TestCollidableObject.o: /usr/include/sys/types.h /usr/include/bits/types.h
TestCollidableObject.o: /usr/include/bits/typesizes.h /usr/include/time.h
TestCollidableObject.o: /usr/include/bits/time.h /usr/include/endian.h
TestCollidableObject.o: /usr/include/bits/endian.h /usr/include/sys/select.h
TestCollidableObject.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
TestCollidableObject.o: /usr/include/sys/sysmacros.h
TestCollidableObject.o: /usr/include/bits/pthreadtypes.h
TestCollidableObject.o: /usr/include/alloca.h TestCollidableObject.h
TestCollidableObject.o: TestObject.h Object.h Position.h Event.h
TestCollidableObject.o: GameManager.h Manager.h ObjectList.h
TestCollidableObject.o: ObjectListIterator.h GraphicsManager.h
TestCollidableObject.o: /usr/include/curses.h
TestCollidableObject.o: /usr/include/ncurses/ncurses_dll.h
TestCollidableObject.o: /usr/include/stdio.h /usr/include/libio.h
TestCollidableObject.o: /usr/include/_G_config.h /usr/include/wchar.h
TestCollidableObject.o: /usr/include/bits/wchar.h /usr/include/gconv.h
TestCollidableObject.o: /usr/include/bits/stdio_lim.h
TestCollidableObject.o: /usr/include/bits/sys_errlist.h
TestCollidableObject.o: /usr/include/ncurses/unctrl.h
TestCollidableObject.o: /usr/include/ncurses/curses.h WorldManager.h
TestCollidableObject.o: EventCollision.h LogManager.h utility.h Box.h
test.o: /usr/include/stdlib.h /usr/include/features.h
test.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
test.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
test.o: /usr/include/sys/types.h /usr/include/bits/types.h
test.o: /usr/include/bits/typesizes.h /usr/include/time.h
test.o: /usr/include/bits/time.h /usr/include/endian.h
test.o: /usr/include/bits/endian.h /usr/include/sys/select.h
test.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
test.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
test.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
test.o: /usr/include/_G_config.h /usr/include/wchar.h
test.o: /usr/include/bits/wchar.h /usr/include/gconv.h
test.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
test.o: LogManager.h Manager.h ObjectList.h Object.h Position.h Event.h
test.o: ObjectListIterator.h utility.h Box.h Clock.h /usr/include/unistd.h
test.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
test.o: /usr/include/getopt.h GameManager.h GraphicsManager.h
test.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
test.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
test.o: WorldManager.h InputManager.h TestObject.h TestCollidableObject.h
test.o: UnitTestManager.h /usr/include/string.h EventStep.h EventTest.h
test.o: EventKeyboard.h EventMouse.h EventOut.h EventCollision.h
TestObject.o: /usr/include/stdlib.h /usr/include/features.h
TestObject.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
TestObject.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
TestObject.o: /usr/include/sys/types.h /usr/include/bits/types.h
TestObject.o: /usr/include/bits/typesizes.h /usr/include/time.h
TestObject.o: /usr/include/bits/time.h /usr/include/endian.h
TestObject.o: /usr/include/bits/endian.h /usr/include/sys/select.h
TestObject.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
TestObject.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
TestObject.o: /usr/include/alloca.h TestObject.h Object.h Position.h Event.h
TestObject.o: GameManager.h Manager.h ObjectList.h ObjectListIterator.h
TestObject.o: GraphicsManager.h /usr/include/curses.h
TestObject.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
TestObject.o: /usr/include/libio.h /usr/include/_G_config.h
TestObject.o: /usr/include/wchar.h /usr/include/bits/wchar.h
TestObject.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
TestObject.o: /usr/include/bits/sys_errlist.h /usr/include/ncurses/unctrl.h
TestObject.o: /usr/include/ncurses/curses.h WorldManager.h EventStep.h
TestObject.o: EventTest.h EventKeyboard.h EventMouse.h EventOut.h
TestObject.o: EventCollision.h LogManager.h utility.h Box.h
UnitTestManager.o: /usr/include/unistd.h /usr/include/features.h
UnitTestManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
UnitTestManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
UnitTestManager.o: /usr/include/bits/posix_opt.h /usr/include/bits/types.h
UnitTestManager.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
UnitTestManager.o: /usr/include/getopt.h UnitTestManager.h
UnitTestManager.o: /usr/include/string.h /usr/include/stdlib.h
UnitTestManager.o: /usr/include/sys/types.h /usr/include/time.h
UnitTestManager.o: /usr/include/bits/time.h /usr/include/endian.h
UnitTestManager.o: /usr/include/bits/endian.h /usr/include/sys/select.h
UnitTestManager.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
UnitTestManager.o: /usr/include/sys/sysmacros.h
UnitTestManager.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
UnitTestManager.o: /usr/include/stdio.h /usr/include/libio.h
UnitTestManager.o: /usr/include/_G_config.h /usr/include/wchar.h
UnitTestManager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
UnitTestManager.o: /usr/include/bits/stdio_lim.h
UnitTestManager.o: /usr/include/bits/sys_errlist.h
utility.o: /usr/include/time.h /usr/include/features.h
utility.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
utility.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
utility.o: /usr/include/bits/time.h /usr/include/bits/types.h
utility.o: /usr/include/bits/typesizes.h /usr/include/stdio.h
utility.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
utility.o: /usr/include/bits/wchar.h /usr/include/gconv.h
utility.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
utility.o: utility.h Position.h Box.h
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h ObjectListIterator.h GraphicsManager.h
WorldManager.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
WorldManager.o: /usr/include/stdio.h /usr/include/features.h
WorldManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
WorldManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
WorldManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
WorldManager.o: /usr/include/libio.h /usr/include/_G_config.h
WorldManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
WorldManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
WorldManager.o: /usr/include/bits/sys_errlist.h /usr/include/ncurses/unctrl.h
WorldManager.o: /usr/include/ncurses/curses.h LogManager.h utility.h Box.h
WorldManager.o: EventStep.h EventCollision.h EventOut.h
