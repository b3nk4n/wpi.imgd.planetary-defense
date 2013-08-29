///
/// An iterator for ObjectLists
///

#ifndef __OBJECT_LIST_ITERATOR_H__
#define __OBJECT_LIST_ITERATOR_H__

#include "ObjectList.h"

class Object;
class ObjectList;

class ObjectListIterator {

 private:
  ObjectListIterator();	///< Iterator must be given list when created.


  int index;			///< Index into list.
  const ObjectList *p_list;	///< List iterating over.

 public:
  ~ObjectListIterator();

  /// Create iterator, over indicated list.
  ObjectListIterator(const ObjectList *p_l);

  void first();			///< Set iterator to first item in list.
  void next();                  ///< Set iterator to next item in list.
  bool isDone();                ///< Return true if at end of list.

  /// Return pointer to current item in list, NULL if done/empty.
  Object *currentObject();     
};

#endif // __OBJECT_LIST_ITERATOR_H__
