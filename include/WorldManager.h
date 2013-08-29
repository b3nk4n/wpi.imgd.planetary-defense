///
/// The game world manager
///

#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Box.h"
#include "Circle.h"
#include "Line.h"
#include "Manager.h"
#include "ObjectList.h"
#include "Position.h"
#include "SceneGraph.h"

#define MAX_ALTITUDE 4          ///< Drawing order 0 to MAX

class WorldManager : public Manager {

 private:
  WorldManager();               ///< Private since a singleton.
  WorldManager (WorldManager const&);  ///< Don't allow copy.
  void operator=(WorldManager const&); ///< Don't allow assignment.
  int next_level;               ///< Next level to assign (0 means no change).
  SceneGraph scene_graph;       ///< Storage for all objects, Game and View.
  ObjectList deletions;         ///< List of all Objects to delete.
  Object *p_view_following;     ///< Object view is following.
  Box boundary;                 ///< World boundary.
  Box view;                     ///< Player view of world.

 public:
  /// Get the one and only instance of the WorldManager.
  static WorldManager &getInstance();
  
  /// Accept all user-defined events (returns true).
  /// Returns false for other engine events.
  bool isValid(string event_name);

  /// Startup game world (initialize everthing to empty).
  /// Return 0.
  int startUp();

  /// Shutdown game world.
  void shutDown();

  /// Add Object to world.
  /// Return 0 if ok, else -1.
  int insertObject(Object *p_go);

  /// Remove Object from world.
  /// Return 0 if ok, else -1.
  int removeObject(Object *p_go);

  /// Return list of all Objects in world.
  /// Return NULL if list is empty.
  ObjectList getAllObjects(void);

  /// Indicate object is to be deleted at end of current game loop.
  /// Return 0 if ok, else -1.
  int markForDelete(Object *p_o);

  /// Update world.
  /// Update positions of Objects based on their velocities.
  /// Update SceneGraph for those marked for updates.
  /// Lastly, delete Objects marked for deletion.
  void update();

  /// Drawall Objects in view.
  /// Draw bottom up, from -MAX_ALTITUDE to MAX_ALTITUDE
  void draw();

  /// Move Object. 
  /// If no collision with solid, move ok else don't move object.
  /// If p_go is Spectral, move ok.
  /// If move ok, adjust screen if following this Object.
  /// Return 0 if move ok, else -1 if collision with solid.
  int moveObject(Object *p_o, Position where);

  /// Return list of Objects collided with at Position 'where'.
  /// Collisions only with solid Objects.
  /// Does not consider if p_go is solid or not.
  ObjectList isCollision(Object *p_o, Position where);

  /// Return list of all Objects at Position 'where'.  
  /// Does include bounding boxes. Return empty list if none found.
  ObjectList objectsAtPosition(Position where);

  /// Return list of all Objects in Box.
  /// Does include bounding boxes. Return empty list if none found.
  ObjectList objectsInBox(Box box);

  /// Return a list of all Objects on line from point1 to point2.
  /// Does include bounding boxes. Return empty list if none found.
  ObjectList objectsOnLine(Line line);

  /// Return a list of all Objects in circle.
  /// Does include bounding boxes. Return empty list if none found.
  ObjectList objectsInCircle(Circle circle);

  /// Get game world boundary.
  Box getBoundary();

  /// Set game world boundary.
  void setBoundary(Box new_boundary);

  /// Get player view of game world.
  Box getView();

  /// Set player view of game world.
  void setView(Box new_view);

  /// Set view to center screen on Object.
  /// Set to NULL to stop following.
  /// If p_new_view_following not legit, return -1 else return 0.
  int setViewFollowing(Object *p_new_view_following);

  /// Set view to center screen on Position view_pos.
  /// View edge will not go beyond world boundary.
  void setViewPosition(Position view_pos);

  /// Return current game level.
  int getLevel();

  /// Set game level at end of update(). Return 0 if ok, else -1.
  int setLevel(int new_level);

  /// Return reference to SceneGraph.
  SceneGraph &getSceneGraph();
};
 
#endif // __WORLD_MANAGER_H__
