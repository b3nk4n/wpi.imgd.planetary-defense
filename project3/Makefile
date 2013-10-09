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
          LaserTower.cpp \
          TeslaTower.cpp \
          EventEnemyInvasion.cpp \
          EventPlayerKilled.cpp \
          EventEnemyKilled.cpp \
          EventBuildingChanged.cpp \
          EventDetonation.cpp \
          EventInfo.cpp \
          Projectile.cpp \
          Bullet.cpp \
          FragmentationGrenade.cpp \
          Laser.cpp \
          Spawner.cpp \
          Explosion.cpp \
          ExplosionSmall.cpp \
          ExplosionBig.cpp \
          ExplosionElectro.cpp \
          EnemyGoblin.cpp \
          GameStart.cpp \
          Sidebar.cpp \
          PopupText.cpp
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
Enemy.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Enemy.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Enemy.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Enemy.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Enemy.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Enemy.o: /usr/include/machine/stdlib.h /usr/include/alloca.h Enemy.h
Enemy.o: MapObject.h VirtualCursor.h Grid.h Cell.h Building.h
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
ExplosionElectro.o: ExplosionElectro.h Explosion.h
ExplosionSmall.o: ExplosionSmall.h Explosion.h
FragmentationGrenade.o: FragmentationGrenade.h Projectile.h EventDetonation.h
FragmentationGrenade.o: Enemy.h ExplosionBig.h Explosion.h
game.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
game.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/sys/features.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h GameStart.h
game.o: MapObject.h VirtualCursor.h Grid.h Cell.h Building.h EnemyOrk.h
game.o: Enemy.h Player.h Spawner.h Sidebar.h EventInfo.h
GameStart.o: GameStart.h
GrenadeTower.o: GrenadeTower.h Tower.h Building.h Enemy.h
GrenadeTower.o: FragmentationGrenade.h Projectile.h
Grid.o: Grid.h Cell.h Building.h
Laser.o: Laser.h Projectile.h Enemy.h
LaserTower.o: LaserTower.h Tower.h Building.h Enemy.h Laser.h Projectile.h
MachineGunTower.o: MachineGunTower.h Tower.h Building.h Enemy.h Bullet.h
MachineGunTower.o: Projectile.h
MapObject.o: MapObject.h VirtualCursor.h Grid.h Cell.h Building.h EventInfo.h
MapObject.o: EventEnemyKilled.h Player.h SolarBuilding.h Tower.h Enemy.h
MapObject.o: MachineGunTower.h GrenadeTower.h LaserTower.h TeslaTower.h
MapObject.o: PopupText.h
Player.o: Player.h EventEnemyInvasion.h EventEnemyKilled.h
Player.o: EventPlayerKilled.h EventBuildingChanged.h
PopupText.o: PopupText.h
Projectile.o: Projectile.h
Sidebar.o: Sidebar.h Player.h EventInfo.h SolarBuilding.h Building.h
Sidebar.o: MachineGunTower.h Tower.h Enemy.h LaserTower.h GrenadeTower.h
Sidebar.o: TeslaTower.h MapObject.h VirtualCursor.h Grid.h Cell.h
SolarBuilding.o: SolarBuilding.h Building.h
Spawner.o: Enemy.h Spawner.h EnemyOrk.h EnemyGoblin.h EventEnemyKilled.h
Spawner.o: EventEnemyInvasion.h
TeslaTower.o: TeslaTower.h Tower.h Building.h Enemy.h EventDetonation.h
TeslaTower.o: ExplosionElectro.h Explosion.h
Tower.o: /usr/include/math.h /usr/include/sys/reent.h /usr/include/_ansi.h
Tower.o: /usr/include/newlib.h /usr/include/sys/config.h
Tower.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Tower.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Tower.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Tower.o: Tower.h Building.h Enemy.h Spawner.h
VirtualCursor.o: VirtualCursor.h
