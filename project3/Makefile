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
          TowerDefenseController.cpp \
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
          EventPlayerWin.cpp \
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
          PopupText.cpp \
          EnemyBoss.cpp \
          PlanetMenu.cpp \
          GameOver.cpp
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

Building.o: Building.h EventBuildingChanged.h EventPlayerKilled.h
Bullet.o: Bullet.h Projectile.h Enemy.h
Cell.o: Cell.h Building.h
EnemyBoss.o: EnemyBoss.h Enemy.h
Enemy.o: /usr/include/stdlib.h /usr/include/features.h
Enemy.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Enemy.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
Enemy.o: /usr/include/sys/types.h /usr/include/bits/types.h
Enemy.o: /usr/include/bits/typesizes.h /usr/include/time.h
Enemy.o: /usr/include/endian.h /usr/include/bits/endian.h
Enemy.o: /usr/include/sys/select.h /usr/include/bits/select.h
Enemy.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Enemy.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Enemy.o: /usr/include/alloca.h Enemy.h TowerDefenseController.h
Enemy.o: VirtualCursor.h Grid.h Cell.h Building.h Spawner.h Sidebar.h
Enemy.o: Player.h EventInfo.h EventEnemyInvasion.h EventEnemyKilled.h
Enemy.o: EventDetonation.h EventPlayerKilled.h ExplosionSmall.h Explosion.h
EnemyGoblin.o: EnemyGoblin.h Enemy.h
EnemyOrk.o: EnemyOrk.h Enemy.h
EventBuildingChanged.o: EventBuildingChanged.h
EventDetonation.o: EventDetonation.h
EventEnemyInvasion.o: EventEnemyInvasion.h
EventEnemyKilled.o: EventEnemyKilled.h
EventInfo.o: EventInfo.h
EventPlayerKilled.o: EventPlayerKilled.h
EventPlayerWin.o: EventPlayerWin.h
ExplosionBig.o: ExplosionBig.h Explosion.h
Explosion.o: Explosion.h
ExplosionElectro.o: ExplosionElectro.h Explosion.h
ExplosionSmall.o: ExplosionSmall.h Explosion.h
FragmentationGrenade.o: FragmentationGrenade.h Projectile.h EventDetonation.h
FragmentationGrenade.o: Enemy.h ExplosionBig.h Explosion.h
game.o: /usr/include/stdlib.h /usr/include/features.h
game.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
game.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
game.o: /usr/include/sys/types.h /usr/include/bits/types.h
game.o: /usr/include/bits/typesizes.h /usr/include/time.h
game.o: /usr/include/endian.h /usr/include/bits/endian.h
game.o: /usr/include/sys/select.h /usr/include/bits/select.h
game.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
game.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
game.o: /usr/include/alloca.h GameStart.h EnemyOrk.h Enemy.h Player.h
game.o: Spawner.h Sidebar.h EventInfo.h GameOver.h
GameOver.o: GameOver.h
GameStart.o: Spawner.h Enemy.h Player.h Sidebar.h EventInfo.h PlanetMenu.h
GameStart.o: GameStart.h
GrenadeTower.o: GrenadeTower.h Tower.h Building.h Enemy.h
GrenadeTower.o: FragmentationGrenade.h Projectile.h ExplosionBig.h
GrenadeTower.o: Explosion.h EventDetonation.h
Grid.o: Grid.h Cell.h Building.h
Laser.o: Laser.h Projectile.h Enemy.h
LaserTower.o: LaserTower.h Tower.h Building.h Enemy.h Laser.h Projectile.h
MachineGunTower.o: MachineGunTower.h Tower.h Building.h Enemy.h Bullet.h
MachineGunTower.o: Projectile.h
PlanetMenu.o: Spawner.h Enemy.h TowerDefenseController.h VirtualCursor.h
PlanetMenu.o: Grid.h Cell.h Building.h Sidebar.h Player.h EventInfo.h
PlanetMenu.o: PlanetMenu.h
Player.o: Player.h EventEnemyInvasion.h EventEnemyKilled.h
Player.o: EventPlayerKilled.h EventBuildingChanged.h PlanetMenu.h
PopupText.o: PopupText.h
Projectile.o: Projectile.h
Sidebar.o: Sidebar.h Player.h EventInfo.h SolarBuilding.h Building.h
Sidebar.o: MachineGunTower.h Tower.h Enemy.h LaserTower.h GrenadeTower.h
Sidebar.o: TeslaTower.h TowerDefenseController.h VirtualCursor.h Grid.h
Sidebar.o: Cell.h Spawner.h EventPlayerKilled.h
SolarBuilding.o: SolarBuilding.h Building.h
Spawner.o: Enemy.h Spawner.h EnemyOrk.h EnemyGoblin.h EnemyBoss.h
Spawner.o: EventEnemyKilled.h EventEnemyInvasion.h EventPlayerKilled.h
Spawner.o: EventPlayerWin.h
TeslaTower.o: TeslaTower.h Tower.h Building.h Enemy.h EventDetonation.h
TeslaTower.o: ExplosionElectro.h Explosion.h
Tower.o: /usr/include/math.h /usr/include/features.h /usr/include/sys/cdefs.h
Tower.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Tower.o: /usr/include/gnu/stubs-64.h /usr/include/bits/huge_val.h
Tower.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h Tower.h
Tower.o: Building.h Enemy.h Spawner.h EventPlayerKilled.h
TowerDefenseController.o: TowerDefenseController.h VirtualCursor.h Grid.h
TowerDefenseController.o: Cell.h Building.h Spawner.h Enemy.h Sidebar.h
TowerDefenseController.o: Player.h EventInfo.h EventEnemyKilled.h
TowerDefenseController.o: SolarBuilding.h Tower.h MachineGunTower.h
TowerDefenseController.o: GrenadeTower.h LaserTower.h TeslaTower.h
TowerDefenseController.o: PopupText.h EventPlayerKilled.h EventPlayerWin.h
TowerDefenseController.o: GameOver.h
VirtualCursor.o: VirtualCursor.h
