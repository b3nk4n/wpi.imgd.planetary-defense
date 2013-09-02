CC = g++
RM = rm -rf
INCPATH = ../include
ENG = ../lib/libdragonfly.a
ifeq ($(system),windows)
PLATFORM = -DCYGWIN
ENG = ../lib/libdragonfly.a
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
ENG = ../lib/libdragonfly-macos64.a
  else
ENG = ../lib/libdragonfly-linux32.a
  endif
endif
LDFLAGS = -lncurses -lrt # for linux/cygwin
#LDFLAGS = -lncurses      # for macos
GAMESRC = Saucer.cpp Hero.cpp Bullet.cpp Explosion.cpp \
          EventNuke.cpp Points.cpp Star.cpp GameOver.cpp \
          GameStart.cpp
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
GameOver.o: GameOver.h GameStart.h
GameStart.o: GameStart.h Hero.h Saucer.h Points.h
Hero.o: Hero.h EventNuke.h Bullet.h GameOver.h Explosion.h
Points.o: Points.h
Saucer.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Saucer.o: Saucer.h EventNuke.h Explosion.h Points.h
Star.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Star.o: Star.h
game.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
game.o: Star.h GameStart.h
