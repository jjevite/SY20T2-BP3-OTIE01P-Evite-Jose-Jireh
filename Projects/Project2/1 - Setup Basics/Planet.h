#pragma once
#include "BaseApplication.h"
#include <string>


using namespace Ogre;

class Planet
{
public:

	// Constructors
	Planet(ColourValue color, ColourValue absorb, float size, SceneManager* mSceneMgr, SceneNode* parent,  std::string
		materialName, const std::string& strName);

	// Create Sphere Function
	ManualObject* createSphere(SceneManager* mSceneMgr, const std::string& strName, const float r, const int nRings = 16, const int nSegments = 16);
	
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
	float mSize;
	ColourValue mColor;
	ColourValue mColorAbsorb;
	SceneNode* mNode;
	SceneNode* mParent;
	std::string mMaterial;
};