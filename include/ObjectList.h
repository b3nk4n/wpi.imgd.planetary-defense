///
/// A list of Objects
///

#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

#include "Object.h"
#include "ObjectListIterator.h"

class Object;
class ObjectListIterator;

class ObjectList {

 private:
  int count;                  ///< Count of objects in list.
  int max_count;              ///< Maximum objects in list (variable).
  Object **p_item;            ///< Array of pointers to objects.

 public:
  friend class ObjectListIterator;           ///< Iterators can access.
  ObjectListIterator createIterator() const; ///< Create an iterator.

  ObjectList();
  ~ObjectList();

  /// Copy contructor (does deep copy).
  ObjectList(const ObjectList &other);

  /// Assignment operator (does deep copy).
  ObjectList &operator=(const ObjectList &rhs);

  /// Insert object pointer in list.
  /// Return 0 if ok, else -1.
  int insert(Object *p_o);

  /// Remove  object pointer from list,
  /// Return 0 if found, else -1.
  int remove(Object *p_o);

  /// Clear the list (setting count to 0).
  void clear();

  /// Return count of number of objects in list.
  int getCount(void);

  /// Return true if list is empty, else false.
  bool isEmpty();

  /// Return true if list is full, else false.
  bool isFull();

  /// Add two lists, second appended to first.
  ObjectList operator+(ObjectList);
};

#endif // __OBJECT_LIST_H__
