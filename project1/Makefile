## Benjamin Sautermeister
## bsautermeister
## 08/29/2013

CC = g++
RM = rm -rf
INCPATH = ../include
ENG = ../lib/libdragonfly.a
ifeq ($(system),linux32)
ENG = ../lib/libdragonfly-linux32.a
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
ENG = ../lib/libdragonfly-macos64.a
LDFLAGS = -lncurses
  else
    ifeq ($(system),linux64)
ENG = ../lib/libdragonfly-linux64.a
    else
PLATFORM = -DCYGWIN
ENG = ../lib/libdragonfly.a
    endif
  endif
endif
LDFLAGS = -lncurses -lrt # for linux/cygwin
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

BossBullet.o: BossBullet.h Projectile.h
Boss.o: /usr/include/stdlib.h /usr/include/features.h
Boss.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Boss.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Boss.o: /usr/include/sys/types.h /usr/include/bits/types.h
Boss.o: /usr/include/bits/typesizes.h /usr/include/time.h
Boss.o: /usr/include/endian.h /usr/include/bits/endian.h
Boss.o: /usr/include/sys/select.h /usr/include/bits/select.h
Boss.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Boss.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Boss.o: /usr/include/alloca.h Boss.h Enemy.h Explosion.h EventLevelCommand.h
Boss.o: BossBullet.h Projectile.h
Bullet.o: Bullet.h Projectile.h
Enemy.o: /usr/include/stdlib.h /usr/include/features.h
Enemy.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Enemy.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Enemy.o: /usr/include/sys/types.h /usr/include/bits/types.h
Enemy.o: /usr/include/bits/typesizes.h /usr/include/time.h
Enemy.o: /usr/include/endian.h /usr/include/bits/endian.h
Enemy.o: /usr/include/sys/select.h /usr/include/bits/select.h
Enemy.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Enemy.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Enemy.o: /usr/include/alloca.h Enemy.h Explosion.h EventNuke.h
Enemy.o: EventDetonation.h EventLevelCommand.h Points.h PowerupScore.h
Enemy.o: Powerup.h PowerupLaser.h PowerupRocket.h PowerupNuke.h
Enemy.o: PowerupDoubleBullet.h
EventDetonation.o: EventDetonation.h
EventLevelCommand.o: EventLevelCommand.h
EventNuke.o: EventNuke.h
EventPowerup.o: EventPowerup.h
Explosion.o: Explosion.h
game.o: /usr/include/stdlib.h /usr/include/features.h
game.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
game.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
game.o: /usr/include/sys/types.h /usr/include/bits/types.h
game.o: /usr/include/bits/typesizes.h /usr/include/time.h
game.o: /usr/include/endian.h /usr/include/bits/endian.h
game.o: /usr/include/sys/select.h /usr/include/bits/select.h
game.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
game.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
game.o: /usr/include/alloca.h Star.h GameStart.h
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
Points.o: /usr/include/stdio.h /usr/include/features.h
Points.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Points.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Points.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Points.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Points.o: /usr/include/bits/wchar.h /usr/include/gconv.h
Points.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Points.o: Points.h
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
Star.o: /usr/include/stdlib.h /usr/include/features.h
Star.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Star.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Star.o: /usr/include/sys/types.h /usr/include/bits/types.h
Star.o: /usr/include/bits/typesizes.h /usr/include/time.h
Star.o: /usr/include/endian.h /usr/include/bits/endian.h
Star.o: /usr/include/sys/select.h /usr/include/bits/select.h
Star.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Star.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Star.o: /usr/include/alloca.h Star.h
Ufo.o: Ufo.h Enemy.h Explosion.h EventLevelCommand.h
