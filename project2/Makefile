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
ENGSRC = Manager.cpp \
		 LogManager.cpp \
		 utility.cpp \
		 Clock.cpp
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

LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
LogManager.o: /usr/include/newlib.h /usr/include/sys/config.h
LogManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
LogManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
LogManager.o: /usr/include/machine/_types.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
LogManager.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h Manager.h
LogManager.o: utility.h
Manager.o: Manager.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h LogManager.h
game.o: /usr/include/stdio.h /usr/include/sys/types.h
game.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
game.o: /usr/include/sys/cdefs.h /usr/include/stdint.h
game.o: /usr/include/bits/wordsize.h Manager.h utility.h
utility.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
utility.o: /usr/include/sys/features.h /usr/include/sys/reent.h
utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
utility.o: /usr/include/machine/types.h /usr/include/stdio.h
utility.o: /usr/include/sys/stdio.h /usr/include/sys/cdefs.h
utility.o: /usr/include/stdint.h /usr/include/bits/wordsize.h utility.h
