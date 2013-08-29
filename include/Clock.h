///
/// The clock, for timing (such as in the game loop)
///

#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <time.h>

class Clock {

 private:
  struct timespec prev_ts;

 public:
  /// Sets prev_ts to current time.
  Clock();

  /// Return time elapsed since delta() was called.
  /// Units are microseconds.
  long int delta(void);

  /// Return time elapsed since delta() was last called.
  /// Units are microseconds.
  long int split(void);

};

#endif // __CLOCK_H__
