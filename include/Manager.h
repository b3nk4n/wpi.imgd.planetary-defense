///
/// The base manager
///

#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "Event.h"
#include "Object.h"
#include "ObjectList.h"
#include "SceneGraph.h"              ///< For MAX_LEVEL

#define MAX_EVENTS 100		     ///< Max number of different events.

class Manager {

 private:
  int event_list_count[MAX_LEVEL+1]; ///< Number of events.
  string event[MAX_LEVEL+1][MAX_EVENTS];       ///< List of events.
  ObjectList obj_list[MAX_LEVEL+1][MAX_EVENTS];///< Objects interested in event

 protected:
  bool is_started;                             ///< True if startUp() success.x
 
  /// Check if event is handled by this Manager.
  /// If handled, return true else false.
  /// (Base Manager always returns false.)
  virtual bool isValid(string event_name);

 public:
  Manager();
  virtual ~Manager();

  /// Send event to all interested objects.
  void onEvent(Event *p_event);
	 
  /// Indicate interest in event.
  /// Return 0 if ok, else -1.
  /// (Note, doesn't check to see if Object is already registered.)
  int registerInterest(Object *p_go, string event_name);

  /// Indicate no more interest in event. 
  /// Return 0 if ok, else -1.
  int unregisterInterest(Object *p_go, string event_name);

  /// Startup Manager. 
  /// Return 0 if ok, else negative number.
  virtual int startUp();

  /// Shutdown Manager.  
  virtual void shutDown();

  /// Return status of is_started (true when startUp() was successful).
  bool isStarted();

};

#endif /// __MANAGER_H__
