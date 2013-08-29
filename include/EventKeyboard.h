///
/// A "keyboard" event
/// 

#ifndef __EVENT_KEYBOARD_H__
#define __EVENT_KEYBOARD_H__

#include "Event.h"

#define KEYBOARD_EVENT "__keyboard__"

class EventKeyboard : public Event {

 private:
  int key_val;			///< Stores key value.

 public:
  EventKeyboard();

  /// Set key in event.
  void setKey(int new_key);

  /// Get key from event.
  int getKey();

};

#endif // __EVENT_KEYBOARD_H__
