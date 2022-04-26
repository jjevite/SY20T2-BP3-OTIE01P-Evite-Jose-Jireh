 #include "Planet.h"


Planet::Planet(ColourValue color, ColourValue absorb, float size, SceneManager* mSceneMgr, SceneNode* parent, std::string materialName, const std::string& strName)
{
    mSize = size;
    mColor = color;
    mParent = parent;
    mMaterial = materialName;
    mColorAbsorb = absorb;
  


    ManualObject* cube = createSphere(mSceneMgr, strName, size, 16, 16);
    mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mNode->attachObject(cube);

}

ManualObject* Planet::createSphere(SceneManager* mSceneMgr, const std::string& strName, const float r, const int nRings, const int nSegments)
{
    MaterialPtr myManualObjectMaterial = Ogre::MaterialManager::getSingleton().create(mMaterial, "General");
    // Modify some properties of materials
    myManualObjectMaterial->getTechnique(0)->setLightingEnabled(true);
    if (mColor == ColourValue(1.0f, 1.0f, 1.0f, 0.0f))
    {
        myManualObjectMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(1, 1, 0);
    }
    myManualObjectMaterial->getTechnique(0)->getPass(0)->setDiffuse(mColorAbsorb);
    myManualObjectMaterial->getTechnique(0)->getPass(0)->setSpecular(0.1, 0.1, 0.1, 0);

    ManualObject* manual = mSceneMgr->createManualObject(strName);
    manual->begin(mMaterial, RenderOperation::OT_TRIANGLE_LIST);

    float fDeltaRingAngle = (Math::PI / nRings);
    float fDeltaSegAngle = (2 * Math::PI / nSegments);
    unsigned short wVerticeIndex = 0;

    // Generate the group of rings for the sphere
    for (int ring = 0; ring <= nRings; ring++) {
        float r0 = r * sinf(ring * fDeltaRingAngle);
        float y0 = r * cosf(ring * fDeltaRingAngle);

        // Generate the group of segments for the current ring
        for (int seg = 0; seg <= nSegments; seg++) {
            float x0 = r0 * sinf(seg * fDeltaSegAngle);
            float z0 = r0 * cosf(seg * fDeltaSegAngle);

            // Add one vertex to the strip which makes up the sphere
            manual->position(x0, y0, z0);
            manual->normal(Vector3(x0, y0, z0).normalisedCopy());       
            manual->textureCoord((float)seg / (float)nSegments, (float)ring / (float)nRings);

            if (ring != nRings) {
                // each vertex (except the last) has six indicies pointing to it
                manual->index(wVerticeIndex + nSegments + 1);
                manual->index(wVerticeIndex);
                manual->index(wVerticeIndex + nSegments);
                manual->index(wVerticeIndex + nSegments + 1);
                manual->index(wVerticeIndex + 1);
                manual->index(wVerticeIndex);
                wVerticeIndex++;
            }
        }; // end for seg
    } // end for ring
    manual->end();
    return manual;
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
