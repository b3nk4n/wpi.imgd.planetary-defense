///
/// The game manager
///

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <time.h>                     ///< For time_t.
#include "Manager.h"

#define DRAGONFLY_VERSION 2.4
 
#define DEFAULT_FRAME_TIME 33         ///< In milliseconds (33 ms == 30 fps).

class GameManager : public Manager {

 private:
  GameManager();                      ///< Private since a singleton.
  GameManager (GameManager const&);   ///< Don't allow copy.
  void operator=(GameManager const&); ///< Don't allow assignment.
  bool game_over;                     ///< True -> game loop should stop.
  int frame_time;                     ///< Target time per game loop, in millisec.

 public:
  ~GameManager();

  /// Get the singleton instance of the GameManager.
  static GameManager &getInstance();

  /// Startup all GameManager services.
  int startUp();

  /// Startup all GameManager services.
  /// If flush is true, call fflush() after each write (default false).
  int startUp(bool flush);

  /// Startup all GameManager services.
  /// If flush is true, call fflush() after each write (default false).
  /// seed = random seed (default is seed with system time).
  int startUp(bool flush, time_t seed);

  /// Game manager only accepts step events.
  /// Return false if other event.
  bool isValid(string event_name);

  /// Shut down GameManager services.
  void shutDown();

  /// Run the game loop.
  /// fr_time is time between frames.
  void run(int fr_time=DEFAULT_FRAME_TIME);

  /// Indicate game is over, which will stop game loop.
  void setGameOver();

  /// Set game over status to indicated value.
  void setGameOver(bool new_game_over);

  /// Return frame time.  
  /// Frame time is target time for each game loop, in milliseconds.
  int getFrameTime();
};

#endif // __GAME_MANAGER_H__
