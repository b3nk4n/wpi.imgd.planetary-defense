///
/// A line segment
///

#ifndef __LINE_H__
#define __LINE_H__

#include "Position.h"

class Line {

 private:
  Position p1;            ///< First endpoint.
  Position p2;            ///< Second endpoint.

 public:

  /// Create line segment from p1 to p2.
  Line(Position init_p1, Position init_p2);

  /// Default line segment is at (0,0).
  Line();
  ~Line();

  Position getP1();             ///< Get first endpoint.
  void setP1(Position new_p1);  ///< Set first endpoint.
  Position getP2();             ///< Get second endpoint.
  void setP2(Position new_p2);  ///< Set second endpoint.
};

#endif //__LINE_H__
