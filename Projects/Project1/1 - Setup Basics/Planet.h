#pragma once
#include "BaseApplication.h"
#include <OgreManualObject.h>

using namespace Ogre;

class Planet
{
public:

	// Constructors
	Planet(ColourValue color, int size, SceneManager* mSceneMgr, SceneNode* parent);

	// CreateCube Function
	ManualObject* createCube(SceneManager* mSceneMgr);
	
	// Functions
	void move(int x, int y, int z);
	void update(const FrameEvent& evt, int rotationSpeed, int revolutionSpeed);

	// Accesors
	SceneNode* getNode();
	int getSize();
	ColourValue getColor();

	void setNode(SceneNode* node);
	void setSize(int size);
	void setColor(ColourValue color);

private:
	int mSize;
	ColourValue mColor;
	SceneNode* mNode;
	SceneNode* mParent;
};

