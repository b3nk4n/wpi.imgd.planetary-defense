///
/// Text for splash screen
/// 

#ifndef __SPLASH_H__
#define __SPLASH_H__

#include "EventStep.h"
#include "Object.h"	

class Splash : public Object {

 private:
  int countdown;

 public:
  Splash();
  ~Splash();
  int eventHandler(Event *p_e);
};
 
#endif // __SPLASH_H__
