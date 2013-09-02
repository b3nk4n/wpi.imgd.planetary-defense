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
          GameStart.cpp Projectile.cpp Laser.cpp Rocket.cpp \
          EventDetonation.cpp Powerup.cpp PowerupScore.cpp \
          EventPowerup.cpp PowerupLaser.cpp PowerupRocket.cpp
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

Bullet.o: Bullet.h Projectile.h
EventDetonation.o: EventDetonation.h
EventNuke.o: EventNuke.h
EventPowerup.o: EventPowerup.h
Explosion.o: Explosion.h
GameOver.o: GameOver.h GameStart.h
GameStart.o: GameStart.h Hero.h EventPowerup.h Saucer.h Points.h
Hero.o: Hero.h EventPowerup.h EventNuke.h PowerupScore.h Powerup.h
Hero.o: PowerupLaser.h PowerupRocket.h Bullet.h Projectile.h Laser.h Rocket.h
Hero.o: GameOver.h Explosion.h Points.h
Laser.o: Laser.h Projectile.h
Points.o: Points.h
Powerup.o: Powerup.h Hero.h EventPowerup.h
PowerupLaser.o: PowerupLaser.h Powerup.h Points.h EventPowerup.h
PowerupRocket.o: PowerupRocket.h Powerup.h Points.h EventPowerup.h
PowerupScore.o: PowerupScore.h Powerup.h Points.h EventPowerup.h
Projectile.o: Projectile.h
Rocket.o: Rocket.h Projectile.h EventDetonation.h Explosion.h
Saucer.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Saucer.o: Saucer.h EventNuke.h EventDetonation.h Explosion.h Points.h
Saucer.o: PowerupScore.h Powerup.h
Star.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Star.o: Star.h
game.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
game.o: Star.h GameStart.h
