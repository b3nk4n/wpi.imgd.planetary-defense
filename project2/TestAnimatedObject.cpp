/*******************************************************************************
 * @file        TestAnimatedObject.cpp
 * @author      bsautermeister
 * @description Test animated sprite object used by the simple unit test tool.
 ******************************************************************************/

#include "TestAnimatedObject.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

/**
 * Creates a new animated test object instance.
 */
TestAnimatedObject::TestAnimatedObject(string spriteLabel, int slowdown)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	setType(TYPE_TEST_ANIMATED_OBJECT);

	

	Sprite *p_tempSprite = resourceManager.getSprite(spriteLabel);
	if (!p_tempSprite)
	{
		logManager.writeLog(LOG_WARNING,
			"TestAnimatedObject::TestAnimatedObject()",
			"Sprite with label '%s' not found.\n",
			spriteLabel.c_str());
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(slowdown);
	}
}

/**
 * Renders the test game object.
 */
void TestAnimatedObject::draw(void)
{
	Object::draw();
}
