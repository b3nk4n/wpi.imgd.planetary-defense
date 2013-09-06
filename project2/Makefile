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
		 LogManager.cpp \
		 Manager.cpp \
		 Object.cpp \
		 ObjectList.cpp \
		 ObjectListIterator.cpp \
		 Position.cpp \
		 utility.cpp	 
GAME = game.cpp
EXECUTABLE = game
OBJECTS = $(ENGSRC:.cpp=.o)

.PHONE: all clean depend start

all: $(GAMESRC) $(EXECUTABLE) Makefile

$(EXECUTABLE): $(ENG) $(OBJECTS) $(GAME)
	$(CC) $(GAME) $(OBJECTS) $(ENG) $(PLATFORM) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) $(PLATFORM) $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE) core engine.log Makefile.bak *~ *.stackdump

depend: 
	makedepend *.cpp 2> /dev/null
# DO NOT DELETE

Clock.o: /usr/include/stdio.h /usr/include/features.h /usr/include/libio.h
Clock.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/xlocale.h
Clock.o: Clock.h /usr/include/time.h /usr/include/unistd.h
Clock.o: /usr/include/getopt.h
GameManager.o: /usr/include/stdio.h /usr/include/features.h
GameManager.o: /usr/include/libio.h /usr/include/_G_config.h
GameManager.o: /usr/include/wchar.h /usr/include/xlocale.h GameManager.h
GameManager.o: /usr/include/time.h Manager.h LogManager.h utility.h Clock.h
GameManager.o: /usr/include/unistd.h /usr/include/getopt.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/features.h
LogManager.o: /usr/include/libio.h /usr/include/_G_config.h
LogManager.o: /usr/include/wchar.h /usr/include/xlocale.h Manager.h utility.h
Manager.o: Manager.h
Object.o: Object.h Position.h
ObjectList.o: /usr/include/stdlib.h /usr/include/features.h
ObjectList.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
ObjectList.o: /usr/include/_G_config.h /usr/include/wchar.h
ObjectList.o: /usr/include/xlocale.h /usr/include/string.h ObjectList.h
ObjectList.o: Object.h Position.h ObjectListIterator.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
Position.o: Position.h
game.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
game.o: /usr/include/string.h /usr/include/xlocale.h LogManager.h
game.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
game.o: /usr/include/wchar.h Manager.h utility.h Clock.h /usr/include/time.h
game.o: /usr/include/unistd.h /usr/include/getopt.h GameManager.h
game.o: ObjectList.h Object.h Position.h ObjectListIterator.h
utility.o: /usr/include/time.h /usr/include/features.h /usr/include/xlocale.h
utility.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
utility.o: /usr/include/wchar.h utility.h
