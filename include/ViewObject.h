///
/// The view object
///

#ifndef __VIEW_OBJECT_H__
#define __VIEW_OBJECT_H__

#include <string>

using std::string;

#include "Event.h"        
#include "Object.h"

/// General location of ViewObject on screen.
enum ViewObjectLocation {
  TOP_LEFT,
  TOP_CENTER,
  TOP_RIGHT,
  BOTTOM_LEFT,
  BOTTOM_CENTER,
  BOTTOM_RIGHT,
};

class ViewObject : public Object {

 private:
  string view_string;   ///< Label for value (e.g. "Points").
  int value;            ///< Value displayed (e.g. points).
  bool border;          ///< True if border around display.
  int color;            ///< Color for text.

 public:
  /// Construct ViewObject. 
  /// Object settings: SPECTRAL, max altitude.
  /// ViewObject defaults: border, top_center, default color, current level.
  ViewObject(int on_level = -1);

  /// Draw view string and value.
  virtual void draw();

  /// Handle "view" event if tag matches view_string (others ignored).
  /// Return 0 if ignored, else 1.
  virtual int eventHandler(Event *p_e);

  /// General location of ViewObject on screen.
  void setLocation(ViewObjectLocation new_location);

  /// Set view value.
  void setValue(int new_value);

  /// Get view value.
  int getValue();

  /// Set view border (true = display border).
  void setBorder(bool new_border);

  /// Get view border (true = display border).
  bool getBorder();

  /// Set view color.
  void setColor(int new_color);

  /// Get view color.
  int getColor();

  /// Set view display string.
  void setViewString(string new_view_string);

  /// Get view display string.
  string getViewString();
};
#endif // __VIEW_OBJECT_H__
