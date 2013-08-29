///
/// A "view" event
///

#ifndef __EVENT_VIEW_H__
#define __EVENT_VIEW_H__

#include "Event.h"

#define VIEW_EVENT "__view__"

class EventView : public Event {

 private:
  string tag;     ///< Tag to associate.
  int value;      ///< Value for view.
  bool delta;     ///< True if change in value, else replace value

 public:
  /// Create view event with tag VIEW_EVENT, value 0 and delta false.
  EventView();

  /// Create view event with tag, value and delta as indicated.
  EventView(string new_tag, int new_value, bool new_delta);

  /// Set tag to new tag.
  void setTag(string new_tag);

  /// Get tag.
  string getTag();

  /// Set value to new value.
  void setValue(int new_value);

  /// Get value.
  int getValue();

  /// Set delta to new delta.
  void setDelta(bool new_delta);

  /// Get delta.
  bool getDelta();
};

#endif /// __EVENT_VIEW_H__
