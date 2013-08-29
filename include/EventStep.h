///
/// A "step" event, generated once per game loop
///

#ifndef __EVENT_STEP_H__
#define __EVENT_STEP_H__

#include "Event.h"

#define STEP_EVENT "__step__"

class EventStep : public Event {

 public:
  EventStep();

};

#endif // __EVENT_STEP_H__
