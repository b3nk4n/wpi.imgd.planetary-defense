///
/// The input manager
///

#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Manager.h"

class InputManager : public Manager {

 private:
  InputManager();                      ///< Private since a singleton.
  InputManager (InputManager const&);  ///< Don't allow copy.
  void operator=(InputManager const&); ///< Don't allow assignment.

 public:
  /// Get the one and only instance of the InputManager.
  static InputManager &getInstance();

  /// Input manager only accepts keyboard and mouse events.
  /// Return false if not one of them.
  bool isValid(string event_name);

  /// Get terminal ready to capture input.  
  /// Return 0 if ok, else return negative num.
  int startUp();

  /// Revert back to normal terminal mode.
  void shutDown();

  /// Get input from the keyboard and mouse.
  /// For each object interested, pass event along.
  void getInput();
};

#endif //__INPUT_MANAGER_H__
