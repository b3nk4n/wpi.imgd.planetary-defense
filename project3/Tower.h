/*******************************************************************************
 * @file        Tower.h
 * @author      kcbryant
 * @description Base Class for Towers
 * @lastEdit 	10/4/2013
 ******************************************************************************/
 #ifndef __TOWER_H__
 #define __TOWER_H__

//Engine Includes
 #include "Object.h"
 #include "Position.h"


/*
* Base Class for all tower units
*/
 class Tower : public Object
 {
 private:
 	/**
 	 * rate at witch the tower shoots
 	 */
 	int _fireRate;

 	/**
 	 * Cost of the tower
 	 */
 	int _cost;

 	/**
 	 * The amount of damage a bullet does 
 	 */
 	int _damage

 public:
 	/**
 	 * Creates a new tower object
 	 */
 	Tower(void);

 	/**
 	 * Cleans the tower object
 	 */
 	~Tower(void);
	
};

#endif // __TOWER_H__
