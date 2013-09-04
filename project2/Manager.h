/* Manager.h */

#ifndef __MANAGER_H__
#define __MANAGER_H__

/**
 * The manager base class.
 */
class Manager
{
protected:
	/**
	 * Indicates whether starting was successful.
	 */
	bool isStarted;

public:
	/**
	 * Creates a new manager instance.
	 */
	Manager(void);
	/**
	 * Cleans up the manager.
	 */
	virtual ~Manager(void);

	/**
	 * Starts up the manager.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	virtual int startUp(void);

	/**
	 * Shuts down the manager.
	 */
	virtual void shutDown(void);

	/**
	 * Gets whether the manager is started.
	 * @return Returns TRUE if start up was successfull.
	 */
	bool isStarted(void);
};

#endif