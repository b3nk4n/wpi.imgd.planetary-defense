///
/// The base event
///

#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

#define UNDEFINED_EVENT "__undefined__"

using std::string;

class Event {

 private:
  string event_type;	//< Holds event type

 public:
  /// Create base event
  Event();

  /// Destructor
  virtual ~Event();

  /// Set the event type
  void setType(string new_type);  

  /// Get the event type
  string getType();

}; 

#endif // __EVENT_H__
