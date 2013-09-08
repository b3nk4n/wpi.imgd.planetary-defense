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
	$(RM) $(OBJECTS) $(TESTOBJ) $(GAMEBIN) $(TESTBIN) core engine.log Makefile.bak *~ *.stackdump

depend: 
	makedepend *.cpp 2> /dev/null
# DO NOT DELETE

Clock.o: /usr/include/stdio.h /usr/include/features.h /usr/include/libio.h
Clock.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/xlocale.h
Clock.o: Clock.h /usr/include/time.h /usr/include/unistd.h
Clock.o: /usr/include/getopt.h
Event.o: Event.h
EventStep.o: EventStep.h Event.h
GameManager.o: /usr/include/stdio.h /usr/include/features.h
GameManager.o: /usr/include/libio.h /usr/include/_G_config.h
GameManager.o: /usr/include/wchar.h /usr/include/xlocale.h GameManager.h
GameManager.o: /usr/include/time.h Manager.h ObjectList.h Object.h Position.h
GameManager.o: Event.h ObjectListIterator.h LogManager.h utility.h Clock.h
GameManager.o: /usr/include/unistd.h /usr/include/getopt.h WorldManager.h
GameManager.o: EventStep.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/features.h
LogManager.o: /usr/include/libio.h /usr/include/_G_config.h
LogManager.o: /usr/include/wchar.h /usr/include/xlocale.h Manager.h utility.h
Manager.o: Manager.h
Object.o: Object.h Position.h Event.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h LogManager.h /usr/include/stdio.h
Object.o: /usr/include/features.h /usr/include/libio.h
Object.o: /usr/include/_G_config.h /usr/include/wchar.h
Object.o: /usr/include/xlocale.h utility.h
ObjectList.o: /usr/include/stdlib.h /usr/include/features.h
ObjectList.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
ObjectList.o: /usr/include/_G_config.h /usr/include/wchar.h
ObjectList.o: /usr/include/xlocale.h /usr/include/string.h ObjectList.h
ObjectList.o: Object.h Position.h Event.h ObjectListIterator.h LogManager.h
ObjectList.o: Manager.h utility.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h
Position.o: Position.h
TestObject.o: /usr/include/stdlib.h /usr/include/features.h
TestObject.o: /usr/include/alloca.h TestObject.h Object.h Position.h Event.h
TestObject.o: GameManager.h /usr/include/time.h /usr/include/xlocale.h
TestObject.o: Manager.h WorldManager.h ObjectList.h ObjectListIterator.h
TestObject.o: EventStep.h LogManager.h /usr/include/stdio.h
TestObject.o: /usr/include/libio.h /usr/include/_G_config.h
TestObject.o: /usr/include/wchar.h utility.h
UnitTestManager.o: UnitTestManager.h /usr/include/string.h
UnitTestManager.o: /usr/include/features.h /usr/include/xlocale.h
UnitTestManager.o: /usr/include/stdlib.h /usr/include/alloca.h
UnitTestManager.o: /usr/include/stdio.h /usr/include/libio.h
UnitTestManager.o: /usr/include/_G_config.h /usr/include/wchar.h
WorldManager.o: WorldManager.h Manager.h ObjectList.h Object.h Position.h
WorldManager.o: Event.h ObjectListIterator.h LogManager.h
WorldManager.o: /usr/include/stdio.h /usr/include/features.h
WorldManager.o: /usr/include/libio.h /usr/include/_G_config.h
WorldManager.o: /usr/include/wchar.h /usr/include/xlocale.h utility.h
game.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
game.o: LogManager.h /usr/include/stdio.h /usr/include/libio.h
game.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/xlocale.h
game.o: Manager.h utility.h GameManager.h /usr/include/time.h TestObject.h
game.o: Object.h Position.h Event.h
test.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
test.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
test.o: /usr/include/wchar.h /usr/include/xlocale.h LogManager.h Manager.h
test.o: utility.h Clock.h /usr/include/time.h /usr/include/unistd.h
test.o: /usr/include/getopt.h GameManager.h WorldManager.h ObjectList.h
test.o: Object.h Position.h Event.h ObjectListIterator.h TestObject.h
test.o: UnitTestManager.h /usr/include/string.h
utility.o: /usr/include/time.h /usr/include/features.h /usr/include/xlocale.h
utility.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
utility.o: /usr/include/wchar.h utility.h
