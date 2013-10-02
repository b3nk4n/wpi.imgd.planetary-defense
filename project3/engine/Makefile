################################################################################
## @file        Makefile
## @author      bsautermeister
## @description MAKEFILE FOR ENGINEX (DRAGONFLY remake) GAME ENGINE (IMGD 3000)
################################################################################

CC = g++ -g
CLIB = ar -cvq
LIBFLDR = lib
INCPATH = include
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
ENG = libenginex.a
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

all: $(GAMESRC) $(GAMEBIN) $(TESTBIN) $(ENG) Makefile

$(ENG): $(OBJECTS)
	$(CLIB) $(ENG) $(OBJECTS)
	mv $(ENG) $(LIBFLDR)/$(ENG)

$(GAMEBIN): $(OBJECTS) $(GAMESRC)
	$(CC) $(GAMESRC) $(OBJECTS) $(PLATFORM) -o $@ -I$(INCPATH) $(LDFLAGS)

$(TESTBIN): $(TESTOBJ) $(TESTSRC)
	$(CC) $(TESTSRC) $(TESTOBJ) $(PLATFORM) -o $@ -I$(INCPATH) $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) $(PLATFORM) -I$(INCPATH) $< -o $@

clean:
	$(RM) $(OBJECTS) $(TESTOBJ) $(GAMEBIN) $(TESTBIN) $(LIBFLDR)/$(ENG) core *.log Makefile.bak *~ *.stackdump

depend: 
	makedepend *.cpp 2> /dev/null
# DO NOT DELETE

Clock.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Clock.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Clock.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Clock.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Clock.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Clock.o: /usr/include/sys/types.h /usr/include/machine/types.h
Clock.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Clock.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
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
GameManager.o: /usr/include/sys/signal.h
Manager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/types.h /usr/include/machine/types.h
Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Object.o: /usr/include/math.h /usr/include/sys/reent.h /usr/include/_ansi.h
Object.o: /usr/include/newlib.h /usr/include/sys/config.h
Object.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
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
ObjectList.o: /usr/include/sys/string.h
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
Sprite.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Sprite.o: /usr/include/_ansi.h /usr/include/newlib.h
Sprite.o: /usr/include/sys/config.h /usr/include/sys/features.h
Sprite.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Sprite.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Sprite.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
Sprite.o: /usr/include/alloca.h
test.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
test.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
test.o: /usr/include/sys/features.h /usr/include/sys/reent.h
test.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
test.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
test.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
test.o: /usr/include/stdio.h /usr/include/sys/types.h
test.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
test.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
test.o: /usr/include/bits/wordsize.h
TestCollidableObject.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
TestCollidableObject.o: /usr/include/_ansi.h /usr/include/newlib.h
TestCollidableObject.o: /usr/include/sys/config.h /usr/include/sys/features.h
TestCollidableObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestCollidableObject.o: /usr/include/machine/_types.h
TestCollidableObject.o: /usr/include/machine/_default_types.h
TestCollidableObject.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
TestCollidableObject.o: /usr/include/alloca.h
TestObject.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
TestObject.o: /usr/include/_ansi.h /usr/include/newlib.h
TestObject.o: /usr/include/sys/config.h /usr/include/sys/features.h
TestObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestObject.o: /usr/include/machine/_types.h
TestObject.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
TestObject.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
UnitTestManager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
UnitTestManager.o: /usr/include/_ansi.h /usr/include/newlib.h
UnitTestManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
UnitTestManager.o: /usr/include/sys/features.h /usr/include/sys/types.h
UnitTestManager.o: /usr/include/machine/_types.h
UnitTestManager.o: /usr/include/machine/_default_types.h
UnitTestManager.o: /usr/include/sys/_types.h /usr/include/sys/lock.h
UnitTestManager.o: /usr/include/machine/types.h
utility.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
utility.o: /usr/include/sys/features.h /usr/include/sys/reent.h
utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
utility.o: /usr/include/machine/types.h /usr/include/stdio.h
utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
utility.o: /usr/include/math.h
