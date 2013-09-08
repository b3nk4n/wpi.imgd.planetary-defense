## Benjamin Sautermeister
## bsautermeister
## 08/29/2013

CC = g++
RM = rm -rf
INCPATH = ../include
ENG = ../lib/libdragonfly.a
ifeq ($(system),linux32)
ENG = ../lib/libdragonfly-linux32.a
LDFLAGS = -lncurses -lrt
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
ENG = ../lib/libdragonfly-macos64.a
LDFLAGS = -lncurses
  else
    ifeq ($(system),cygwin)
ENG = ../lib/libdragonfly.a
PLATFORM = -DCYGWIN
LDFLAGS = -lncurses -lrt
    else
ENG = ../lib/libdragonfly-linux64.a
LDFLAGS = -lncurses -lrt
    endif
  endif
endif
GAMESRC = Saucer.cpp Hero.cpp Bullet.cpp Explosion.cpp \
          EventNuke.cpp Points.cpp Star.cpp GameOver.cpp \
          GameStart.cpp Projectile.cpp Laser.cpp Rocket.cpp \
          EventDetonation.cpp Powerup.cpp PowerupScore.cpp \
          EventPowerup.cpp PowerupLaser.cpp PowerupRocket.cpp \
          Enemy.cpp Ufo.cpp Hitpoints.cpp PowerupNuke.cpp \
          PowerupDoubleBullet.cpp EventLevelCommand.cpp \
          GameLevelUpdater.cpp Boss.cpp BossBullet.cpp
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
	$(RM) $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~ *.stackdump

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Boss.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Boss.o: Boss.h Enemy.h Explosion.h EventLevelCommand.h BossBullet.h
Boss.o: Projectile.h
BossBullet.o: BossBullet.h Projectile.h
Bullet.o: Bullet.h Projectile.h
Enemy.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Enemy.o: Enemy.h Explosion.h EventNuke.h EventDetonation.h
Enemy.o: EventLevelCommand.h Points.h PowerupScore.h Powerup.h PowerupLaser.h
Enemy.o: PowerupRocket.h PowerupNuke.h PowerupDoubleBullet.h
EventDetonation.o: EventDetonation.h
EventLevelCommand.o: EventLevelCommand.h
EventNuke.o: EventNuke.h
EventPowerup.o: EventPowerup.h
Explosion.o: Explosion.h
GameLevelUpdater.o: GameLevelUpdater.h EventLevelCommand.h GameStart.h
GameLevelUpdater.o: Saucer.h Enemy.h Explosion.h Ufo.h Boss.h
GameOver.o: GameOver.h GameStart.h
GameStart.o: GameStart.h Hero.h EventPowerup.h Saucer.h Enemy.h Explosion.h
GameStart.o: Ufo.h Points.h Hitpoints.h GameLevelUpdater.h
Hero.o: Hero.h EventPowerup.h EventNuke.h PowerupScore.h Powerup.h
Hero.o: PowerupLaser.h PowerupRocket.h PowerupNuke.h PowerupDoubleBullet.h
Hero.o: Bullet.h Projectile.h Laser.h Rocket.h GameOver.h Explosion.h
Hero.o: Points.h Hitpoints.h
Hitpoints.o: Hitpoints.h Hero.h EventPowerup.h
Laser.o: Laser.h Projectile.h
Points.o: /usr/include/stdio.h /usr/include/features.h /usr/include/libio.h
Points.o: /usr/include/_G_config.h /usr/include/wchar.h
Points.o: /usr/include/xlocale.h Points.h
Powerup.o: Powerup.h Hero.h EventPowerup.h
PowerupDoubleBullet.o: PowerupDoubleBullet.h Powerup.h Points.h
PowerupDoubleBullet.o: EventPowerup.h
PowerupLaser.o: PowerupLaser.h Powerup.h Points.h EventPowerup.h
PowerupNuke.o: PowerupNuke.h Powerup.h Points.h EventPowerup.h
PowerupRocket.o: PowerupRocket.h Powerup.h Points.h EventPowerup.h
PowerupScore.o: PowerupScore.h Powerup.h Points.h EventPowerup.h
Projectile.o: Projectile.h
Rocket.o: Rocket.h Projectile.h EventDetonation.h Explosion.h
Saucer.o: Saucer.h Enemy.h Explosion.h EventLevelCommand.h
Star.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
Star.o: Star.h
Ufo.o: Ufo.h Enemy.h Explosion.h EventLevelCommand.h
game.o: /usr/include/stdlib.h /usr/include/features.h /usr/include/alloca.h
game.o: Star.h GameStart.h
