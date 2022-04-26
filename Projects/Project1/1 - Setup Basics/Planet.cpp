 #include "Planet.h"


Planet::Planet(ColourValue color, int size, SceneManager* mSceneMgr, SceneNode* parent)
{
    mSize = size;
    mColor = color;
    mParent = parent;

    ManualObject* cube = createCube(mSceneMgr);
    mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mNode->attachObject(cube);
}

ManualObject* Planet::createCube(SceneManager* mSceneMgr)
{
    ManualObject* cube = mSceneMgr->createManualObject();
    cube->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);

    cube->position(-mSize, -mSize, mSize);
    cube->colour(mColor);
    cube->position(mSize, -mSize, mSize);
    cube->colour(mColor);
    cube->position(mSize, mSize, mSize);
    cube->colour(mColor);
    cube->position(-mSize, mSize, mSize);
    cube->colour(mColor);

    cube->position(-mSize, -mSize, -mSize);
    cube->colour(mColor);
    cube->position(mSize, -mSize, -mSize);
    cube->colour(mColor);
    cube->position(mSize, mSize, -mSize);
    cube->colour(mColor);
    cube->position(-mSize, mSize, -mSize);
    cube->colour(mColor);

    // Front face 
    cube->index(0);
    cube->index(1);
    cube->index(2);

    cube->index(0);
    cube->index(2);
    cube->index(3);


    // Back Face
    cube->index(5);
    cube->index(4);
    cube->index(7);

    cube->index(5);
    cube->index(7);
    cube->index(6);

    // Right Face
    cube->index(1);
    cube->index(5);
    cube->index(6);

    cube->index(1);
    cube->index(6);
    cube->index(2);

    // Left Face
    cube->index(4);
    cube->index(0);
    cube->index(3);

    cube->index(4);
    cube->index(3);
    cube->index(7);

    // Top Face
    cube->index(3);
    cube->index(2);
    cube->index(6);

    cube->index(3);
    cube->index(6);
    cube->index(7);

    // Bottom Face
    cube->index(4);
    cube->index(5);
    cube->index(1);

    cube->index(4);
    cube->index(1);
    cube->index(0);



    cube->end();
    return cube;
}

void Planet::move(int x, int y, int z)
{
    mNode->translate(Vector3(x, y, z));
}

void Planet::update(const FrameEvent& evt, int rotationSpeed, int revolutionSpeed)
{
    // Rotation
    if (rotationSpeed > 0)
    {
        Radian rotationAngle = Radian(Degree(rotationSpeed * evt.timeSinceLastFrame));
        mNode->rotate(Vector3(0, 1, 0), rotationAngle);
    }

    // Revolution
    if (revolutionSpeed > 0)
    {
        // Computaion
        // 1st Step
        float oldX = mNode->getPosition().x - mParent->getPosition().x;
        float oldZ = mNode->getPosition().z - mParent->getPosition().z;

  
        // 2nd Step
        Degree revolutionDegrees = Degree(revolutionSpeed * evt.timeSinceLastFrame);

       /* float newX = (mNode->getPosition().x * Math::Cos(Radian(revolutionDegrees))) + (mNode->getPosition().z * Math::Sin(Radian(revolutionDegrees)));
        float newZ = (mNode->getPosition().x * -Math::Sin(Radian(revolutionDegrees))) + (mNode->getPosition().z * Math::Cos(Radian(revolutionDegrees)));*/
         
        float newX = (oldX * Math::Cos(Radian(revolutionDegrees))) + (oldZ * Math::Sin(Radian(revolutionDegrees)));
        float newZ = (oldX * -Math::Sin(Radian(revolutionDegrees))) + (oldZ * Math::Cos(Radian(revolutionDegrees)));

        // 3rd Step
        newX += mParent->getPosition().x;
        newZ += mParent->getPosition().z; 

        // 4th step
        mNode->setPosition(newX, mNode->getPosition().y, newZ);
    }


   
}

SceneNode* Planet::getNode()
{
    return mNode;
}

int Planet::getSize()
{
    return mSize;
}

ColourValue Planet::getColor()
{
    return mColor;
}

void Planet::setNode(SceneNode* node)
{
    mNode = node;
}

void Planet::setSize(int size)
{
    mSize = size;
}

void Planet::setColor(ColourValue color)
{
    mColor = color;
}
