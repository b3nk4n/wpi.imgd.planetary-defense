################################################################################
## @file        Makefile
## @author      bsautermeister
## @description MAKEFILE FOR ENGINEX (DRAGONFLY remake) GAME ENGINE (IMGD 3000)
################################################################################

CC = g++ -g
INCPATH = engine/include
RM = rm -rf
ifeq ($(system),linux32)
LDFLAGS = -lncurses -lrt -lm
else
  ifeq ($(system),macos)
PLATFORM = -DMACOS
LDFLAGS = -lncurses -lm
  else
    ifeq ($(system),cygwin)
PLATFORM = -DCYGWIN
LDFLAGS = -lncurses -lrt -lm
    else
LDFLAGS = -lncurses -lrt -lm
    endif
  endif
endif
ENG = engine/lib/libenginex.a
GAMESRC = Cell.cpp \
		  Grid.cpp \
		  VirtualCursor.cpp \
          MapObject.cpp \
          Enemy.cpp \
          EnemyOrk.cpp \
          Player.cpp \
          Building.cpp \
          SolarBuilding.cpp \
          Tower.cpp \
          MachineGunTower.cpp \
          GrenadeTower.cpp \
          EventEnemyInvasion.cpp \
          EventPlayerKilled.cpp \
          EventEnemyKilled.cpp \
          EventBuildingChanged.cpp \
          EventDetonation.cpp \
          EventInfo.cpp \
          Projectile.cpp \
          Bullet.cpp \
          FragmentationGrenade.cpp \
          Spawner.cpp \
          Explosion.cpp \
          ExplosionSmall.cpp \
          ExplosionBig.cpp \
          EnemyGoblin.cpp \
          GameStart.cpp
GAME = game.cpp
GAMEBIN = $(GAME:.cpp=)
OBJECTS = $(GAMESRC:.cpp=.o)

.PHONE: all clean depend start

all: $(GAME) $(GAMEBIN) Makefile

$(GAMEBIN): $(ENG) $(OBJECTS) $(GAME) $(GAMESRC)
	$(CC) $(GAME) $(OBJECTS) $(ENG) $(PLATFORM) -o $@ -I$(INCPATH) $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) $(PLATFORM) -I$(INCPATH) $< -o $@

clean:
	$(RM) $(OBJECTS) $(GAMEBIN) core *.log Makefile.bak *~ *.stackdump

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Building.o: Building.h EventBuildingChanged.h
Bullet.o: Bullet.h Projectile.h Enemy.h
Cell.o: Cell.h Building.h
Enemy.o: Enemy.h MapObject.h VirtualCursor.h Grid.h Cell.h Building.h
Enemy.o: EventEnemyInvasion.h EventEnemyKilled.h EventDetonation.h
Enemy.o: EventInfo.h Spawner.h ExplosionSmall.h Explosion.h
EnemyGoblin.o: EnemyGoblin.h Enemy.h
EnemyOrk.o: EnemyOrk.h Enemy.h
EventBuildingChanged.o: EventBuildingChanged.h
EventDetonation.o: EventDetonation.h
EventEnemyInvasion.o: EventEnemyInvasion.h
EventEnemyKilled.o: EventEnemyKilled.h
EventInfo.o: EventInfo.h
EventPlayerKilled.o: EventPlayerKilled.h
Explosion.o: Explosion.h
ExplosionBig.o: ExplosionBig.h Explosion.h
ExplosionSmall.o: ExplosionSmall.h Explosion.h
FragmentationGrenade.o: FragmentationGrenade.h Projectile.h EventDetonation.h
FragmentationGrenade.o: Enemy.h ExplosionBig.h Explosion.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h MapObject.h
game.o: VirtualCursor.h Grid.h Cell.h Building.h EnemyOrk.h Enemy.h Player.h
game.o: Spawner.h
GrenadeTower.o: GrenadeTower.h Tower.h Building.h Enemy.h
GrenadeTower.o: FragmentationGrenade.h Projectile.h MapObject.h
GrenadeTower.o: VirtualCursor.h Grid.h Cell.h
Grid.o: Grid.h Cell.h Building.h
MachineGunTower.o: MachineGunTower.h Tower.h Building.h Enemy.h Bullet.h
MachineGunTower.o: Projectile.h MapObject.h VirtualCursor.h Grid.h Cell.h
MapObject.o: MapObject.h VirtualCursor.h Grid.h Cell.h Building.h EventInfo.h
MapObject.o: Player.h SolarBuilding.h MachineGunTower.h Tower.h Enemy.h
MapObject.o: GrenadeTower.h
Player.o: Player.h EventEnemyInvasion.h EventEnemyKilled.h
Player.o: EventPlayerKilled.h EventBuildingChanged.h
Projectile.o: Projectile.h
SolarBuilding.o: SolarBuilding.h Building.h
Spawner.o: Enemy.h Spawner.h EnemyOrk.h EnemyGoblin.h EventEnemyKilled.h
Spawner.o: EventEnemyInvasion.h
Tower.o: /usr/include/math.h /usr/include/sys/reent.h /usr/include/_ansi.h
Tower.o: /usr/include/newlib.h /usr/include/sys/config.h
Tower.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Tower.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Tower.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Tower.o: Tower.h Building.h Enemy.h Spawner.h
VirtualCursor.o: VirtualCursor.h
