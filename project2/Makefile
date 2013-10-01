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
EventCollision.o: EventCollision.h Event.h Object.h Position.h Sprite.h
EventCollision.o: Frame.h Box.h
Event.o: Event.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h Position.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
EventTest.o: EventTest.h Event.h
EventView.o: EventView.h Event.h
Frame.o: Frame.h
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
game.o: Manager.h ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h
game.o: Box.h ObjectListIterator.h utility.h Line.h Circle.h Splash.h
game.o: GameManager.h ResourceManager.h WorldManager.h SceneGraph.h
game.o: GraphicsManager.h /usr/include/curses.h
game.o: /usr/include/ncurses/ncurses_dll.h /usr/include/ncurses/unctrl.h
game.o: /usr/include/ncurses/curses.h EventStep.h EventKeyboard.h
game.o: EventMouse.h EventCollision.h EventOut.h TestObject.h
game.o: TestCollidableObject.h TestAnimatedObject.h ViewObject.h
GameManager.o: /usr/include/stdlib.h /usr/include/features.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
GameManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
GameManager.o: /usr/include/sys/types.h /usr/include/bits/types.h
GameManager.o: /usr/include/bits/typesizes.h /usr/include/time.h
GameManager.o: /usr/include/bits/time.h /usr/include/endian.h
GameManager.o: /usr/include/bits/endian.h /usr/include/sys/select.h
GameManager.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
GameManager.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
GameManager.o: /usr/include/alloca.h /usr/include/stdio.h
GameManager.o: /usr/include/libio.h /usr/include/_G_config.h
GameManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
GameManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
GameManager.o: /usr/include/bits/sys_errlist.h /usr/include/signal.h
GameManager.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
GameManager.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
GameManager.o: /usr/include/bits/sigstack.h /usr/include/bits/sigthread.h
GameManager.o: GameManager.h Manager.h ObjectList.h Object.h Position.h
GameManager.o: Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
GameManager.o: WorldManager.h SceneGraph.h GraphicsManager.h
GameManager.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
GameManager.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
GameManager.o: InputManager.h ResourceManager.h LogManager.h utility.h Line.h
GameManager.o: Circle.h Splash.h Clock.h /usr/include/unistd.h
GameManager.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
GameManager.o: /usr/include/getopt.h EventStep.h
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
GraphicsManager.o: Object.h Position.h Event.h Sprite.h Frame.h Box.h
GraphicsManager.o: ObjectListIterator.h LogManager.h utility.h Line.h
GraphicsManager.o: Circle.h Splash.h GameManager.h /usr/include/time.h
GraphicsManager.o: /usr/include/bits/time.h
InputManager.o: InputManager.h Manager.h ObjectList.h Object.h Position.h
InputManager.o: Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
InputManager.o: GraphicsManager.h /usr/include/curses.h
InputManager.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
InputManager.o: /usr/include/features.h /usr/include/sys/cdefs.h
InputManager.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
InputManager.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
InputManager.o: /usr/include/bits/typesizes.h /usr/include/libio.h
InputManager.o: /usr/include/_G_config.h /usr/include/wchar.h
InputManager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
InputManager.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
InputManager.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
InputManager.o: LogManager.h utility.h Line.h Circle.h Splash.h GameManager.h
InputManager.o: /usr/include/time.h /usr/include/bits/time.h EventKeyboard.h
InputManager.o: EventMouse.h
Line.o: Line.h Position.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/features.h
LogManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
LogManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
LogManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
LogManager.o: /usr/include/libio.h /usr/include/_G_config.h
LogManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
LogManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
LogManager.o: /usr/include/bits/sys_errlist.h Manager.h ObjectList.h Object.h
LogManager.o: Position.h Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
LogManager.o: utility.h Line.h Circle.h Splash.h GameManager.h
LogManager.o: /usr/include/time.h /usr/include/bits/time.h
Manager.o: /usr/include/stdio.h /usr/include/features.h
Manager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Manager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Manager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Manager.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Manager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Manager.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Manager.o: Manager.h ObjectList.h Object.h Position.h Event.h Sprite.h
Manager.o: Frame.h Box.h ObjectListIterator.h
Object.o: /usr/include/math.h /usr/include/features.h
Object.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Object.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Object.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
Object.o: /usr/include/bits/mathcalls.h Object.h Position.h Event.h Sprite.h
Object.o: Frame.h Box.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h SceneGraph.h GameManager.h /usr/include/time.h
Object.o: /usr/include/bits/time.h /usr/include/bits/types.h
Object.o: /usr/include/bits/typesizes.h InputManager.h GraphicsManager.h
Object.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
Object.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Object.o: /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h
Object.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Object.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
Object.o: LogManager.h utility.h Line.h Circle.h Splash.h EventStep.h
Object.o: EventKeyboard.h EventMouse.h
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
ObjectList.o: Sprite.h Frame.h Box.h ObjectListIterator.h LogManager.h
ObjectList.o: Manager.h utility.h Line.h Circle.h Splash.h GameManager.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h Sprite.h Frame.h Box.h
Position.o: Position.h
ResourceManager.o: /usr/include/stdlib.h /usr/include/features.h
ResourceManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ResourceManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
ResourceManager.o: /usr/include/sys/types.h /usr/include/bits/types.h
ResourceManager.o: /usr/include/bits/typesizes.h /usr/include/time.h
ResourceManager.o: /usr/include/bits/time.h /usr/include/endian.h
ResourceManager.o: /usr/include/bits/endian.h /usr/include/sys/select.h
ResourceManager.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
ResourceManager.o: /usr/include/sys/sysmacros.h
ResourceManager.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
ResourceManager.o: /usr/include/string.h ResourceManager.h Manager.h
ResourceManager.o: ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h
ResourceManager.o: Box.h ObjectListIterator.h GraphicsManager.h
ResourceManager.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
ResourceManager.o: /usr/include/stdio.h /usr/include/libio.h
ResourceManager.o: /usr/include/_G_config.h /usr/include/wchar.h
ResourceManager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
ResourceManager.o: /usr/include/bits/stdio_lim.h
ResourceManager.o: /usr/include/bits/sys_errlist.h
ResourceManager.o: /usr/include/ncurses/unctrl.h
ResourceManager.o: /usr/include/ncurses/curses.h LogManager.h utility.h
ResourceManager.o: Line.h Circle.h Splash.h GameManager.h
SceneGraph.o: SceneGraph.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
SceneGraph.o: ObjectList.h ObjectListIterator.h LogManager.h
SceneGraph.o: /usr/include/stdio.h /usr/include/features.h
SceneGraph.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
SceneGraph.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
SceneGraph.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
SceneGraph.o: /usr/include/libio.h /usr/include/_G_config.h
SceneGraph.o: /usr/include/wchar.h /usr/include/bits/wchar.h
SceneGraph.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
SceneGraph.o: /usr/include/bits/sys_errlist.h Manager.h utility.h Line.h
SceneGraph.o: Circle.h Splash.h GameManager.h /usr/include/time.h
SceneGraph.o: /usr/include/bits/time.h
Splash.o: Splash.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
Splash.o: GraphicsManager.h /usr/include/curses.h
Splash.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
Splash.o: /usr/include/features.h /usr/include/sys/cdefs.h
Splash.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Splash.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
Splash.o: /usr/include/bits/typesizes.h /usr/include/libio.h
Splash.o: /usr/include/_G_config.h /usr/include/wchar.h
Splash.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Splash.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Splash.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
Splash.o: Manager.h ObjectList.h ObjectListIterator.h WorldManager.h
Splash.o: SceneGraph.h GameManager.h /usr/include/time.h
Splash.o: /usr/include/bits/time.h SplashDragonfly.h EventStep.h
Splash.o: EventKeyboard.h
SplashDragonfly.o: Splash.h Object.h Position.h Event.h Sprite.h Frame.h
SplashDragonfly.o: Box.h GraphicsManager.h /usr/include/curses.h
SplashDragonfly.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
SplashDragonfly.o: /usr/include/features.h /usr/include/sys/cdefs.h
SplashDragonfly.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
SplashDragonfly.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
SplashDragonfly.o: /usr/include/bits/typesizes.h /usr/include/libio.h
SplashDragonfly.o: /usr/include/_G_config.h /usr/include/wchar.h
SplashDragonfly.o: /usr/include/bits/wchar.h /usr/include/gconv.h
SplashDragonfly.o: /usr/include/bits/stdio_lim.h
SplashDragonfly.o: /usr/include/bits/sys_errlist.h
SplashDragonfly.o: /usr/include/ncurses/unctrl.h
SplashDragonfly.o: /usr/include/ncurses/curses.h Manager.h ObjectList.h
SplashDragonfly.o: ObjectListIterator.h WorldManager.h SceneGraph.h
SplashDragonfly.o: GameManager.h /usr/include/time.h /usr/include/bits/time.h
SplashDragonfly.o: SplashDragonfly.h EventStep.h EventKeyboard.h LogManager.h
SplashDragonfly.o: utility.h Line.h Circle.h
Sprite.o: /usr/include/stdlib.h /usr/include/features.h
Sprite.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Sprite.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Sprite.o: /usr/include/sys/types.h /usr/include/bits/types.h
Sprite.o: /usr/include/bits/typesizes.h /usr/include/time.h
Sprite.o: /usr/include/bits/time.h /usr/include/endian.h
Sprite.o: /usr/include/bits/endian.h /usr/include/sys/select.h
Sprite.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Sprite.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Sprite.o: /usr/include/alloca.h Sprite.h Frame.h GraphicsManager.h
Sprite.o: /usr/include/curses.h /usr/include/ncurses/ncurses_dll.h
Sprite.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Sprite.o: /usr/include/wchar.h /usr/include/bits/wchar.h /usr/include/gconv.h
Sprite.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Sprite.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
Sprite.o: Manager.h ObjectList.h Object.h Position.h Event.h Box.h
Sprite.o: ObjectListIterator.h LogManager.h utility.h Line.h Circle.h
Sprite.o: Splash.h GameManager.h
TestAnimatedObject.o: TestAnimatedObject.h TestObject.h Object.h Position.h
TestAnimatedObject.o: Event.h Sprite.h Frame.h Box.h GraphicsManager.h
TestAnimatedObject.o: /usr/include/curses.h
TestAnimatedObject.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
TestAnimatedObject.o: /usr/include/features.h /usr/include/sys/cdefs.h
TestAnimatedObject.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
TestAnimatedObject.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
TestAnimatedObject.o: /usr/include/bits/typesizes.h /usr/include/libio.h
TestAnimatedObject.o: /usr/include/_G_config.h /usr/include/wchar.h
TestAnimatedObject.o: /usr/include/bits/wchar.h /usr/include/gconv.h
TestAnimatedObject.o: /usr/include/bits/stdio_lim.h
TestAnimatedObject.o: /usr/include/bits/sys_errlist.h
TestAnimatedObject.o: /usr/include/ncurses/unctrl.h
TestAnimatedObject.o: /usr/include/ncurses/curses.h Manager.h ObjectList.h
TestAnimatedObject.o: ObjectListIterator.h WorldManager.h SceneGraph.h
TestAnimatedObject.o: LogManager.h utility.h Line.h Circle.h Splash.h
TestAnimatedObject.o: GameManager.h /usr/include/time.h
TestAnimatedObject.o: /usr/include/bits/time.h ResourceManager.h
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
TestCollidableObject.o: TestObject.h Object.h Position.h Event.h Sprite.h
TestCollidableObject.o: Frame.h Box.h GameManager.h Manager.h ObjectList.h
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
TestCollidableObject.o: SceneGraph.h EventCollision.h EventView.h
TestCollidableObject.o: LogManager.h utility.h Line.h Circle.h Splash.h
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
test.o: Sprite.h Frame.h Box.h ObjectListIterator.h utility.h Line.h Circle.h
test.o: Splash.h GameManager.h Clock.h /usr/include/unistd.h
test.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
test.o: /usr/include/getopt.h GraphicsManager.h /usr/include/curses.h
test.o: /usr/include/ncurses/ncurses_dll.h /usr/include/ncurses/unctrl.h
test.o: /usr/include/ncurses/curses.h WorldManager.h SceneGraph.h
test.o: InputManager.h TestObject.h TestCollidableObject.h UnitTestManager.h
test.o: /usr/include/string.h EventStep.h EventTest.h EventView.h
test.o: EventKeyboard.h EventMouse.h EventOut.h EventCollision.h
test.o: ResourceManager.h ViewObject.h
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
TestObject.o: Sprite.h Frame.h Box.h GameManager.h Manager.h ObjectList.h
TestObject.o: ObjectListIterator.h GraphicsManager.h /usr/include/curses.h
TestObject.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
TestObject.o: /usr/include/libio.h /usr/include/_G_config.h
TestObject.o: /usr/include/wchar.h /usr/include/bits/wchar.h
TestObject.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
TestObject.o: /usr/include/bits/sys_errlist.h /usr/include/ncurses/unctrl.h
TestObject.o: /usr/include/ncurses/curses.h WorldManager.h SceneGraph.h
TestObject.o: EventStep.h EventTest.h EventKeyboard.h EventMouse.h EventOut.h
TestObject.o: EventView.h EventCollision.h LogManager.h utility.h Line.h
TestObject.o: Circle.h Splash.h
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
utility.o: /usr/include/math.h /usr/include/bits/huge_val.h
utility.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
utility.o: utility.h Position.h Box.h Line.h Circle.h Object.h Event.h
utility.o: Sprite.h Frame.h Splash.h GameManager.h Manager.h ObjectList.h
utility.o: ObjectListIterator.h WorldManager.h SceneGraph.h SplashDragonfly.h
utility.o: LogManager.h
ViewObject.o: ViewObject.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ViewObject.o: GraphicsManager.h /usr/include/curses.h
ViewObject.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
ViewObject.o: /usr/include/features.h /usr/include/sys/cdefs.h
ViewObject.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
ViewObject.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
ViewObject.o: /usr/include/bits/typesizes.h /usr/include/libio.h
ViewObject.o: /usr/include/_G_config.h /usr/include/wchar.h
ViewObject.o: /usr/include/bits/wchar.h /usr/include/gconv.h
ViewObject.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ViewObject.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
ViewObject.o: Manager.h ObjectList.h ObjectListIterator.h WorldManager.h
ViewObject.o: SceneGraph.h LogManager.h utility.h Line.h Circle.h Splash.h
ViewObject.o: GameManager.h /usr/include/time.h /usr/include/bits/time.h
ViewObject.o: EventView.h
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h Sprite.h Frame.h Box.h ObjectListIterator.h
WorldManager.o: SceneGraph.h GraphicsManager.h /usr/include/curses.h
WorldManager.o: /usr/include/ncurses/ncurses_dll.h /usr/include/stdio.h
WorldManager.o: /usr/include/features.h /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
WorldManager.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
WorldManager.o: /usr/include/bits/typesizes.h /usr/include/libio.h
WorldManager.o: /usr/include/_G_config.h /usr/include/wchar.h
WorldManager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
WorldManager.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
WorldManager.o: /usr/include/ncurses/unctrl.h /usr/include/ncurses/curses.h
WorldManager.o: LogManager.h utility.h Line.h Circle.h Splash.h GameManager.h
WorldManager.o: /usr/include/time.h /usr/include/bits/time.h EventStep.h
WorldManager.o: EventCollision.h EventOut.h EventMouse.h EventKeyboard.h
WorldManager.o: ViewObject.h
