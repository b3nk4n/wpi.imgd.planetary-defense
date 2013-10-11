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
		 LevelData.cpp \
		 Line.cpp \
		 LogManager.cpp \
		 Manager.cpp \
		 MapData.cpp \
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
		 WaveData.cpp \
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

Clock.o: /usr/include/stdio.h /usr/include/features.h
Clock.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Clock.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Clock.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Clock.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Clock.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Clock.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
game.o: /usr/include/stdlib.h /usr/include/features.h
game.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
game.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
game.o: /usr/include/sys/types.h /usr/include/bits/types.h
game.o: /usr/include/bits/typesizes.h /usr/include/time.h
game.o: /usr/include/endian.h /usr/include/bits/endian.h
game.o: /usr/include/sys/select.h /usr/include/bits/select.h
game.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
game.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
game.o: /usr/include/alloca.h
GameManager.o: /usr/include/stdlib.h /usr/include/features.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
GameManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
GameManager.o: /usr/include/sys/types.h /usr/include/bits/types.h
GameManager.o: /usr/include/bits/typesizes.h /usr/include/time.h
GameManager.o: /usr/include/endian.h /usr/include/bits/endian.h
GameManager.o: /usr/include/sys/select.h /usr/include/bits/select.h
GameManager.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
GameManager.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
GameManager.o: /usr/include/alloca.h /usr/include/stdio.h
GameManager.o: /usr/include/libio.h /usr/include/_G_config.h
GameManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
GameManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
GameManager.o: /usr/include/bits/sys_errlist.h /usr/include/signal.h
GameManager.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
GameManager.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
GameManager.o: /usr/include/bits/sigstack.h /usr/include/bits/sigthread.h
Manager.o: /usr/include/stdio.h /usr/include/features.h
Manager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Manager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Manager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Manager.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Manager.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Manager.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Object.o: /usr/include/math.h /usr/include/features.h
Object.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Object.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Object.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
Object.o: /usr/include/bits/mathcalls.h
ObjectList.o: /usr/include/stdlib.h /usr/include/features.h
ObjectList.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ObjectList.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
ObjectList.o: /usr/include/sys/types.h /usr/include/bits/types.h
ObjectList.o: /usr/include/bits/typesizes.h /usr/include/time.h
ObjectList.o: /usr/include/endian.h /usr/include/bits/endian.h
ObjectList.o: /usr/include/sys/select.h /usr/include/bits/select.h
ObjectList.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
ObjectList.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
ObjectList.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
ObjectList.o: /usr/include/_G_config.h /usr/include/wchar.h
ObjectList.o: /usr/include/bits/wchar.h /usr/include/gconv.h
ObjectList.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ObjectList.o: /usr/include/string.h
ResourceManager.o: /usr/include/stdlib.h /usr/include/features.h
ResourceManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ResourceManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
ResourceManager.o: /usr/include/sys/types.h /usr/include/bits/types.h
ResourceManager.o: /usr/include/bits/typesizes.h /usr/include/time.h
ResourceManager.o: /usr/include/endian.h /usr/include/bits/endian.h
ResourceManager.o: /usr/include/sys/select.h /usr/include/bits/select.h
ResourceManager.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
ResourceManager.o: /usr/include/sys/sysmacros.h
ResourceManager.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
ResourceManager.o: /usr/include/string.h
Sprite.o: /usr/include/stdlib.h /usr/include/features.h
Sprite.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Sprite.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Sprite.o: /usr/include/sys/types.h /usr/include/bits/types.h
Sprite.o: /usr/include/bits/typesizes.h /usr/include/time.h
Sprite.o: /usr/include/endian.h /usr/include/bits/endian.h
Sprite.o: /usr/include/sys/select.h /usr/include/bits/select.h
Sprite.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Sprite.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Sprite.o: /usr/include/alloca.h
TestCollidableObject.o: /usr/include/stdlib.h /usr/include/features.h
TestCollidableObject.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
TestCollidableObject.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
TestCollidableObject.o: /usr/include/sys/types.h /usr/include/bits/types.h
TestCollidableObject.o: /usr/include/bits/typesizes.h /usr/include/time.h
TestCollidableObject.o: /usr/include/endian.h /usr/include/bits/endian.h
TestCollidableObject.o: /usr/include/sys/select.h /usr/include/bits/select.h
TestCollidableObject.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
TestCollidableObject.o: /usr/include/sys/sysmacros.h
TestCollidableObject.o: /usr/include/bits/pthreadtypes.h
TestCollidableObject.o: /usr/include/alloca.h
test.o: /usr/include/stdlib.h /usr/include/features.h
test.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
test.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
test.o: /usr/include/sys/types.h /usr/include/bits/types.h
test.o: /usr/include/bits/typesizes.h /usr/include/time.h
test.o: /usr/include/endian.h /usr/include/bits/endian.h
test.o: /usr/include/sys/select.h /usr/include/bits/select.h
test.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
test.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
test.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
test.o: /usr/include/_G_config.h /usr/include/wchar.h
test.o: /usr/include/bits/wchar.h /usr/include/gconv.h
test.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
TestObject.o: /usr/include/stdlib.h /usr/include/features.h
TestObject.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
TestObject.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
TestObject.o: /usr/include/sys/types.h /usr/include/bits/types.h
TestObject.o: /usr/include/bits/typesizes.h /usr/include/time.h
TestObject.o: /usr/include/endian.h /usr/include/bits/endian.h
TestObject.o: /usr/include/sys/select.h /usr/include/bits/select.h
TestObject.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
TestObject.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
TestObject.o: /usr/include/alloca.h
UnitTestManager.o: /usr/include/unistd.h /usr/include/features.h
UnitTestManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
UnitTestManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
UnitTestManager.o: /usr/include/bits/posix_opt.h /usr/include/bits/types.h
UnitTestManager.o: /usr/include/bits/typesizes.h /usr/include/bits/confname.h
UnitTestManager.o: /usr/include/getopt.h
utility.o: /usr/include/time.h /usr/include/bits/types.h
utility.o: /usr/include/features.h /usr/include/sys/cdefs.h
utility.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
utility.o: /usr/include/gnu/stubs-64.h /usr/include/bits/typesizes.h
utility.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
utility.o: /usr/include/wchar.h /usr/include/bits/wchar.h
utility.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
utility.o: /usr/include/bits/sys_errlist.h /usr/include/math.h
utility.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
utility.o: /usr/include/bits/mathcalls.h
