///
/// The base game world object
///

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include "Box.h"             ///< Objects have a bounding box.
#include "Event.h"           ///< Objects can handle events.
#include "Position.h"        ///< Objects need a location.
#include "Sprite.h"          ///< Objects (often) have sprites.

#define MAX_OBJ_EVENTS 100   ///< Max events Object can be interested in.

using std::string;           // Introduce "string" into namespace

enum Solidness {
  HARD,      ///< Object causes collisions and impedes.
  SOFT,      ///< Object causes collision, but doesn't impede.
  SPECTRAL    ///< Object doesn't cause collisions.
};
 
class Object {

 private:
  bool is_visible;            ///< If true, object gets drawn.
  bool is_persistent;         ///< If true, object active on all levels.
  int event_count;            ///< Keep track of interested events.
  string event_name[MAX_OBJ_EVENTS]; ///< Event names.
  Box box;                    ///< Box for sprite boundary & collisions.
  Position pos;               ///< Position in the game world.
  string type;                ///< User-defined identification.
  Sprite *p_sprite;           ///< Sprite associated with object.
  bool sprite_center;         ///< True if sprite centered on object.
  int sprite_index;           ///< Current index frame for sprite.
  int sprite_slowdown;        ///< Slowdown rate (1 = no slowdown, 0 = stop).
  int sprite_slowdown_count;  ///< Slowdown counter.
  int altitude;               ///< 0 to MAX_ALTITUDE (lower drawn first).
  Solidness solidness;        ///< Solidness state of object.
  bool no_soft;               ///< True if won't move on soft objects.
  float x_velocity;           ///< Horizontal speed in spaces per game step.
  float x_velocity_countdown; ///< Countdown to horizontal movement.
  float y_velocity;           ///< Vertical speed in spaces per game step.
  float y_velocity_countdown; ///< Countdown to vertical movement.

 public:
  Object(int on_level = -1);

  /// Destroy object, unregistering for any interested events.
  virtual ~Object();

  ///< Return True if object is HARD or SOFT, else False.
  bool isSolid();    

  /// Set object solidness, with checks for consistency.  
  /// Return 0 if ok, else -1.
  int setSolidness(Solidness new_solid);

  /// Return object solidness.
  Solidness getSolidness();

  /// Set visibility of object.  Objects not visible are not drawn.
  /// Return 0 if ok, else -1.
  int setVisibility(bool visible);

  /// Return visibility of object.  Objects not visible are not drawn.
  bool isVisible();

  /// Set persistence of object. Persistent objects are active across all
  /// levels.  Return 0 if ok, else -1.
  int setPersistence(bool persistent);
  
  /// Return true if object persistent, else false. Persistent objects 
  /// are active across all levels. 
  bool isPersistent();

  /// Set object altitude, with checks for range [0, MAX_ALTITUDE].
  /// Return 0 if ok, else -1.
  int setAltitude(int new_altitude);
   
  /// Return object altitude.
  int getAltitude();
   
  /// Set x velocity.
  void setXVelocity(float new_x_velocity);

  /// Get x velocity.
  float getXVelocity();

  /// Set y velocity.
  void setYVelocity(float new_y_velocity);

  /// Get y velocity.
  float getYVelocity();

  /// Perform 1 step of velocity in horizontal direction.
  /// Return horizontal distance moved this step.
  int getXVelocityStep();

  /// Perform 1 step of velocity in vertical direction.
  /// Return vertical distance moved this step.
  int getYVelocityStep();

  /// Get "allow soft" setting.
  bool getNoSoft();

  /// Set "allow soft" setting.
  void setNoSoft(bool new_no_soft);

  /// Set bounding box.
  void setBox(Box new_box);

  /// Get bounding box.
  Box getBox();

  /// Set type identifier of object.
  void setType(string new_type);

  /// Get type identifier of object.
  string getType();

  /// Set Position of object.
  void setPosition(Position new_pos);

  /// Get Position of object.
  Position getPosition();

  /// Handle event (default is to ignore everything).
  /// Return 0 if ignored, else 1.
  virtual int eventHandler(Event *p_event);

  /// Register for interest in event.  
  /// Keeps track of manager and event.  
  /// Return 0 if ok, else -1.
  int registerInterest(string event);

  /// Unregister for interest in event.  
  /// Return 0 if ok, else -1.
  int unregisterInterest(string event);

  /// Draw single sprite frame.
  /// Drawing accounts for: centering, slowdown, advancing Sprite Frame
  virtual void draw();

  /// Set Sprite associated with this object to new one.
  /// Set bounding box to size of sprite.
  void setSprite(Sprite *p_new_sprite);

  /// Set object Sprite to new one.
  /// If set_box is true, set bounding box to size of Sprite.
  void setSprite(Sprite *p_new_sprite, bool set_box);

  /// Return pointer to Sprite associated with this object.
  Sprite *getSprite();

  /// Indicates if sprite is centered at object Position (pos).
  bool isCentered();

  /// Set Sprite to be centered at object Position (pos).
  void setCentered(bool centered);

  /// Return index of current Sprite frame to be displayed.
  int getSpriteIndex();

  /// Set index of current Sprite frame to be displayed.
  void setSpriteIndex(int new_sprite_index);

  /// Slows down sprite animations.
  /// new_sprite_slowdown is in multiples of WorldManager frame time.
  void setSpriteSlowdown(int new_sprite_slowdown);
  int getSpriteSlowdown();
  void setSpriteSlowdownCount(int new_sprite_slowdown_count);
  int getSpriteSlowdownCount();
};

#endif // __OBJECT_H__
