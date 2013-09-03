CC = g++
RM = rm -rf
INCPATH = ../include
ENG = ../lib/libdragonfly.a
ifeq ($(system),linux32)
PLATFORM = -DCYGWIN
ENG = ../lib/libdragonfly-linux32.a
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
ENG = ../lib/libdragonfly-macos64.a
  else
  	ifeq ($(system),linux64)
ENG = ../lib/libdragonfly-linux64.a
    else
ENG = ../lib/libdragonfly.a
	endif
  endif
endif
LDFLAGS = -lncurses -lrt # for linux/cygwin
#LDFLAGS = -lncurses      # for macos
GAMESRC = Saucer.cpp Hero.cpp Bullet.cpp Explosion.cpp \
          EventNuke.cpp Points.cpp Star.cpp GameOver.cpp \
          GameStart.cpp Projectile.cpp Laser.cpp Rocket.cpp \
          EventDetonation.cpp Powerup.cpp PowerupScore.cpp \
          EventPowerup.cpp PowerupLaser.cpp PowerupRocket.cpp \
          Enemy.cpp Ufo.cpp Hitpoints.cpp PowerupNuke.cpp
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
Enemy.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Enemy.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Enemy.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Enemy.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Enemy.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Enemy.o: /usr/include/machine/stdlib.h /usr/include/alloca.h Enemy.h
Enemy.o: Explosion.h EventNuke.h EventDetonation.h Points.h PowerupScore.h
Enemy.o: Powerup.h PowerupLaser.h PowerupRocket.h
EventDetonation.o: EventDetonation.h
EventNuke.o: EventNuke.h
EventPowerup.o: EventPowerup.h
Explosion.o: Explosion.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h Star.h
game.o: GameStart.h
GameOver.o: GameOver.h GameStart.h
GameStart.o: GameStart.h Hero.h EventPowerup.h Saucer.h Enemy.h Explosion.h
GameStart.o: Ufo.h Points.h Hitpoints.h
Hero.o: Hero.h EventPowerup.h EventNuke.h PowerupScore.h Powerup.h
Hero.o: PowerupLaser.h PowerupRocket.h Bullet.h Projectile.h Laser.h Rocket.h
Hero.o: GameOver.h Explosion.h Points.h
Hitpoints.o: Hitpoints.h Hero.h EventPowerup.h
Laser.o: Laser.h Projectile.h
Points.o: Points.h
Powerup.o: Powerup.h Hero.h EventPowerup.h
PowerupLaser.o: PowerupLaser.h Powerup.h Points.h EventPowerup.h
PowerupRocket.o: PowerupRocket.h Powerup.h Points.h EventPowerup.h
PowerupScore.o: PowerupScore.h Powerup.h Points.h EventPowerup.h
Projectile.o: Projectile.h
Rocket.o: Rocket.h Projectile.h EventDetonation.h Explosion.h
Saucer.o: Saucer.h Enemy.h Explosion.h
Star.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Star.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Star.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Star.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Star.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Star.o: /usr/include/machine/stdlib.h /usr/include/alloca.h Star.h
Ufo.o: Ufo.h Enemy.h Explosion.h
