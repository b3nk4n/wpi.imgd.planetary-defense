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
		 EventTest.cpp \
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
EventStep.o: EventStep.h Event.h
EventTest.o: EventTest.h Event.h
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
GameManager.o: ObjectListIterator.h LogManager.h utility.h Clock.h
GameManager.o: /usr/include/unistd.h /usr/include/sys/unistd.h WorldManager.h
GameManager.o: EventStep.h
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
LogManager.o: utility.h
Manager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Manager.o: /usr/include/sys/types.h /usr/include/machine/types.h
Manager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
Manager.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
Object.o: Object.h Position.h Event.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h GameManager.h /usr/include/time.h
Object.o: /usr/include/_ansi.h /usr/include/newlib.h
Object.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Object.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Object.o: /usr/include/machine/time.h /usr/include/sys/types.h
Object.o: /usr/include/machine/types.h LogManager.h /usr/include/stdio.h
Object.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
Object.o: /usr/include/stdint.h /usr/include/bits/wordsize.h utility.h
Object.o: EventStep.h
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
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h
Position.o: Position.h
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
TestObject.o: ObjectList.h ObjectListIterator.h WorldManager.h EventStep.h
TestObject.o: EventTest.h LogManager.h /usr/include/stdio.h
TestObject.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
TestObject.o: /usr/include/stdint.h /usr/include/bits/wordsize.h utility.h
UnitTestManager.o: UnitTestManager.h /usr/include/string.h
UnitTestManager.o: /usr/include/_ansi.h /usr/include/newlib.h
UnitTestManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
UnitTestManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
UnitTestManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
UnitTestManager.o: /usr/include/machine/_default_types.h
UnitTestManager.o: /usr/include/sys/lock.h /usr/include/sys/cdefs.h
UnitTestManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
UnitTestManager.o: /usr/include/sys/string.h /usr/include/stdlib.h
UnitTestManager.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
UnitTestManager.o: /usr/include/stdio.h /usr/include/sys/types.h
UnitTestManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h ObjectListIterator.h LogManager.h
WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h
WorldManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h utility.h
WorldManager.o: EventStep.h
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
game.o: Position.h Event.h ObjectListIterator.h utility.h GameManager.h
game.o: /usr/include/time.h /usr/include/machine/time.h TestObject.h
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
test.o: Object.h Position.h Event.h ObjectListIterator.h utility.h Clock.h
test.o: /usr/include/time.h /usr/include/machine/time.h /usr/include/unistd.h
test.o: /usr/include/sys/unistd.h GameManager.h WorldManager.h TestObject.h
test.o: UnitTestManager.h /usr/include/string.h /usr/include/sys/string.h
test.o: EventStep.h EventTest.h
utility.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
utility.o: /usr/include/sys/features.h /usr/include/sys/reent.h
utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
utility.o: /usr/include/machine/types.h /usr/include/stdio.h
utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h utility.h
