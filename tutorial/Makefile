CC = g++
RM = rm -rf
INCPATH = ../include
ENG = ../lib/libdragonfly.a
PLATFORM = -DCYGWIN
#PLATFORM = -DMACOS
LDFLAGS = -lncurses -lrt # for linux/cygwin
#LDFLAGS = -lncurses      # for macos
GAMESRC = Saucer.cpp Hero.cpp Bullet.cpp Explosion.cpp \
          EventNuke.cpp Points.cpp Star.cpp
GAME = game.cpp
EXECUTABLE = game
OBJECTS = $(GAMESRC:.cpp=.o)

.PHONE: all clean depend start

all: $(GAMESRC) $(EXECUTABLE) Makefile

$(EXECUTABLE): $(ENG) $(OBJECTS) $(GAME)
	$(CC) $(GAME) $(OBJECTS) $(ENG) $(PLATFORM) -o $@ -I$(INCPATH) $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) -I$(INCPATH) $(PLATFORM) $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Bullet.o: Bullet.h
EventNuke.o: EventNuke.h
Explosion.o: Explosion.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h Saucer.h Hero.h
game.o: Points.h Star.h
Hero.o: Hero.h EventNuke.h Bullet.h
Points.o: Points.h
Saucer.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Saucer.o: /usr/include/_ansi.h /usr/include/newlib.h
Saucer.o: /usr/include/sys/config.h /usr/include/sys/features.h
Saucer.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Saucer.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Saucer.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
Saucer.o: /usr/include/alloca.h Saucer.h EventNuke.h Explosion.h Points.h
Star.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Star.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Star.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Star.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Star.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Star.o: /usr/include/machine/stdlib.h /usr/include/alloca.h Star.h
