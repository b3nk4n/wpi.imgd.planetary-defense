///
/// The log manager
/// 

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>

#include "Manager.h"
#include "utility.h"

#define LOGFILE_NAME "dragonfly.log"

class LogManager : public Manager {

 private:
  LogManager();                      ///< Private since a singleton.
  LogManager (LogManager const&);    ///< Don't allow copy.
  void operator=(LogManager const&); ///< Don't allow assignment.
  bool do_flush;                     ///< True if fflush after each write.
  FILE *fp;                          ///< Pointer to log file.

 public:
  ~LogManager();

  /// Get the one and only instance of the LogManager.
  static LogManager &getInstance();

  /// Start up LogManager (open logfile "dragonfly.log").
  /// If flush is true, then call fflush() afer each write.
  int startUp(bool flush=false);

  /// Shut down LogManager (close logfile).
  void shutDown();

  /// Write to logfile.
  /// Supports printf() formatting of strings.
  /// Return bytes written (excluding time), -1 if error
  int writeLog(const char *fmt, ...);
};

#endif // __LOG_MANAGER_H__
