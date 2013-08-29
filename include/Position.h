///
/// A 2-d (x,y) position
///

#ifndef __POSITION_H__
#define __POSITION_H__

class Position {

 private:
  int x; 			///< Horizontal coordinate in 2d world.
  int y; 			///< Vertical coordinate in 2d world.

 public:

  /// Create object at 2-d location (x,y).  
  Position(int init_x, int init_y);

  /// Default 2-d (x,y) location is (0,0).
  Position();

  int getX();			    ///< Get horizontal coordinate.
  void setX(int new_x);		    ///< Set horizontal coordinate.
  int getY();			    ///< Get vertical coordinate.
  void setY(int new_y);		    ///< Set vertical coordinate.
  void setXY(int new_x, int new_y);  ///< Set horizontal & vertical coordinates.
};

#endif //__POSITION_H__
