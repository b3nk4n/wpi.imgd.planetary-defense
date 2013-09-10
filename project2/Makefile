################################################################################
## @file        Manager.h
## @author      bsautermeister
## @description MAKEFILE FOR DRAGONFLY GAME ENGINE (IMGD 3000)
################################################################################

CC = g++
RM = rm -rf
ifeq ($(system),linux32)
LDFLAGS = -lncurses -lrt
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
LDFLAGS = -lncurses
  else
    ifeq ($(system),cygwin)
PLATFORM = -DCYGWIN
LDFLAGS = -lncurses -lrt
    else
LDFLAGS = -lncurses -lrt
    endif
  endif
endif
ENGSRC = Clock.cpp \
		 GameManager.cpp \
		 Event.cpp \
		 EventStep.cpp \
		 LogManager.cpp \
		 Manager.cpp \
		 Object.cpp \
		 ObjectList.cpp \
		 ObjectListIterator.cpp \
		 Position.cpp \
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

$(GAMEBIN): $(ENG) $(OBJECTS) $(GAMESRC)
	$(CC) $(GAMESRC) $(OBJECTS) $(ENG) $(PLATFORM) -o $@ $(LDFLAGS)

$(TESTBIN): $(ENG) $(TESTOBJ) $(TESTSRC)
	$(CC) $(TESTSRC) $(TESTOBJ) $(ENG) $(PLATFORM) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) $(PLATFORM) $< -o $@

clean:
	$(RM) $(OBJECTS) $(TESTOBJ) $(GAMEBIN) $(TESTBIN) core dragonfly.log Makefile.bak *~ *.stackdump

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
Clock.o: Clock.h /usr/include/time.h /usr/include/bits/time.h
Clock.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
Clock.o: /usr/include/bits/confname.h /usr/include/getopt.h
Event.o: Event.h
EventStep.o: EventStep.h Event.h
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
game.o: Manager.h utility.h GameManager.h TestObject.h Object.h Position.h
game.o: Event.h
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
GameManager.o: LogManager.h utility.h Clock.h /usr/include/unistd.h
GameManager.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
GameManager.o: /usr/include/getopt.h WorldManager.h EventStep.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/features.h
LogManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
LogManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
LogManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
LogManager.o: /usr/include/libio.h /usr/include/_G_config.h
LogManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
LogManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
LogManager.o: /usr/include/bits/sys_errlist.h Manager.h utility.h
Manager.o: Manager.h
Object.o: Object.h Position.h Event.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h LogManager.h /usr/include/stdio.h
Object.o: /usr/include/features.h /usr/include/sys/cdefs.h
Object.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Object.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
Object.o: /usr/include/bits/typesizes.h /usr/include/libio.h
Object.o: /usr/include/_G_config.h /usr/include/wchar.h
Object.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Object.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Object.o: utility.h
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
ObjectList.o: ObjectListIterator.h LogManager.h Manager.h utility.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h
Position.o: Position.h
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
test.o: LogManager.h Manager.h utility.h Clock.h /usr/include/unistd.h
test.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
test.o: /usr/include/getopt.h GameManager.h WorldManager.h ObjectList.h
test.o: Object.h Position.h Event.h ObjectListIterator.h TestObject.h
test.o: UnitTestManager.h /usr/include/string.h
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
TestObject.o: GameManager.h Manager.h WorldManager.h ObjectList.h
TestObject.o: ObjectListIterator.h EventStep.h LogManager.h
TestObject.o: /usr/include/stdio.h /usr/include/libio.h
TestObject.o: /usr/include/_G_config.h /usr/include/wchar.h
TestObject.o: /usr/include/bits/wchar.h /usr/include/gconv.h
TestObject.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
TestObject.o: utility.h
UnitTestManager.o: UnitTestManager.h /usr/include/string.h
UnitTestManager.o: /usr/include/features.h /usr/include/sys/cdefs.h
UnitTestManager.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
UnitTestManager.o: /usr/include/gnu/stubs-64.h /usr/include/stdlib.h
UnitTestManager.o: /usr/include/sys/types.h /usr/include/bits/types.h
UnitTestManager.o: /usr/include/bits/typesizes.h /usr/include/time.h
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
utility.o: utility.h
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h ObjectListIterator.h LogManager.h
WorldManager.o: /usr/include/stdio.h /usr/include/features.h
WorldManager.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
WorldManager.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
WorldManager.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
WorldManager.o: /usr/include/libio.h /usr/include/_G_config.h
WorldManager.o: /usr/include/wchar.h /usr/include/bits/wchar.h
WorldManager.o: /usr/include/gconv.h /usr/include/bits/stdio_lim.h
WorldManager.o: /usr/include/bits/sys_errlist.h utility.h
