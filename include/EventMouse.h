///
/// A "mouse" event
///

#ifndef __EVENT_MOUSE_H__
#define __EVENT_MOUSE_H__

#include "Event.h"

#define MOUSE_EVENT "__mouse__"

/// Set of mouse actions recognized by Dragonfly.
enum MouseActionList {
  LEFT_BUTTON_CLICK,
  LEFT_BUTTON_DOUBLECLICK,
  RIGHT_BUTTON_CLICK,
  RIGHT_BUTTON_DOUBLECLICK,
  UNDEFINED
};

class EventMouse : public Event {

 private:
  enum MouseActionList mouse_action; ///< Mouse action.
  int mouse_x;                       ///< Mouse x coordinate.
  int mouse_y;                       ///< Mouse y coordinate.

 public:
  EventMouse();

  /// Load mouse event's action.
  void setMouseAction(enum MouseActionList new_mouse_action);

  /// Get mouse event's action.
  enum MouseActionList getMouseAction();

  /// Set mouse event's x coordinate.
  void setMouseX(int new_x);

  /// Set mouse event's y coordinate.
  void setMouseY(int new_y);

  /// Get mouse event's x coordinate.
  int getMouseX();

  /// Get mouse event's y coordinate.
  int getMouseY();
};

#endif // __EVENT_MOUSE_H__
