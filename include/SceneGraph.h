///
/// A scene graph
///

#ifndef __SCENE_GRAPH_H__
#define __SCENE_GRAPH_H__

#include "Object.h"
#include "ObjectList.h"

#define MAX_ALTITUDE 4
#define MAX_LEVEL 100  // Objects on level 0 are persistent

class SceneGraph {

 private:
  int level;			          ///< "Level" game is on
  ObjectList objects[MAX_LEVEL+1];        ///< All objects
  ObjectList solid_objects[MAX_LEVEL+1];  ///< Solid objects
  ObjectList visible_objects[MAX_LEVEL+1][MAX_ALTITUDE+1]; ///< Visible objects
  
 public:
  SceneGraph();
  ~SceneGraph();
  
  /// Insert Object into SceneGraph.
  int insertObject(Object *p_o);

  /// Remove Object from SceneGraph.
  int removeObject(Object *p_o);

  /// Return all Objects. Empty list if none.
  ObjectList allObjects();

  /// Return all solid Objects. Empty list if none.
  ObjectList solidObjects();

  /// Return all visible Objects at altitude. Empty list if none.
  ObjectList visibleObjects(int altitude);

  /// Set game level. Return 0 if ok, else -1.
  int setLevel(int new_level);

  /// Return current game level.
  int getLevel();

  /// Re-position Object in SceneGraph to new altitude.
  /// Return 0 if ok, else -1.
  int updateAltitude(Object *p_o, int new_alt);

  // Re-position Object in SceneGraph to new solidness.
  // Return 0 if ok, else -1.
  int updateSolidness(Object *p_go, Solidness new_solidness);

  // Re-position Object in SceneGraph to new visibility.
  // Return 0 if ok, else -1.
  int updateVisibility(Object *p_vo, bool new_visibility);

  // Re-position Object in SceneGraph to new persistence.
  // Return 0 if ok, else -1.
  int updatePersistence(Object *p_go, bool new_persistence);
};
  
#endif // __SCENE_GRAPH_H__
