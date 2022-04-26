/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"
//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{

}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    ManualObject* cube = createCube(10);
    cubeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    cubeNode->attachObject(cube);

    cubeNode->translate(20, 0, 0);


    Light* pointlight = mSceneMgr->createLight();
    pointlight->setType(Light::LightTypes::LT_POINT);
    pointlight->setPosition(Vector3(0, 0, 0));
    pointlight->setDiffuseColour(ColourValue(1.0f, 1.0f, 1.0f));
    pointlight->setSpecularColour(ColourValue(1.0f, 1.0f, 1.0f));
    pointlight->setAttenuation(325, 0.0f, 0.014, 0.0007);
    pointlight->setCastShadows(false);

    mSceneMgr->setAmbientLight(ColourValue(0.1f, 0.1f, 0.1f));
}

ManualObject* TutorialApplication::createCube(float size)
{
    MaterialPtr myManualObjectMaterial = Ogre::MaterialManager::getSingleton().create("manualMaterial", "General");

    // Modify some properties of materials
    myManualObjectMaterial->getTechnique(0)->setLightingEnabled(true);
    myManualObjectMaterial->getTechnique(0)->getPass(0)->setDiffuse(0.5, 1, 1, 0);
    myManualObjectMaterial->getTechnique(0)->getPass(0)->setSpecular(0.3, 0.3, 0.3, 0);

    

    ManualObject* manual = mSceneMgr->createManualObject("manual");
    manual->begin("manualMaterial", RenderOperation::OT_TRIANGLE_LIST);

    // front 
    // 0
    manual->position(-size, -size, size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, 0, 1));

    // 1
    manual->position(size, -size, size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, 0, 1));

    // 2 
    manual->position(size, size, size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, 0, 1));

    // 3
    manual->position(-size, size, size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, 0, 1));

    // back
    // 4
    manual->position(-size, -size, -size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, 0, -1));

    // 5
    manual->position(size, -size, -size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, 0, -1));

    // 6
    manual->position(size, size, -size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, 0, -1));

    // 7
    manual->position(-size, size, -size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, 0, -1));

    // right
    // 8
    manual->position(size, -size, size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(1, 0, 0));

    // 9
    manual->position(size, size, size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(1, 0, 0));

    // 10
    manual->position(size, -size, -size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(1, 0, 0));


    // 11
    manual->position(size, size, -size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(1, 0, 0));


    // left
    // 12
    manual->position(-size, -size, -size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(-1, 0, 0));

    // 13 
    manual->position(-size, -size, size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(-1, 0, 0));

    // 14
    manual->position(-size, size, size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(-1, 0, 0));

    // 15
    manual->position(-size, size, -size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(-1, 0, 0));

    // top
    // 16
    manual->position(-size, size, size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, 1, 0));

    // 17
    manual->position(size, size, -size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, 1, 0));

    // 18
    manual->position(size, size, size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, 1, 0));

    // 19
    manual->position(-size, size, -size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, 1, 0));

    // bottom
    // 20
    manual->position(-size, -size, -size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, -1, 0));

    // 21 
    manual->position(size, -size, -size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, -1, 0));

    // 22
    manual->position(size, -size, size);
    manual->colour(ColourValue::Red);
    manual->normal(Vector3(0, -1, 0));

    // 23
    manual->position(-size, -size, size);
    manual->colour(ColourValue::Blue);
    manual->normal(Vector3(0, -1, 0));


    // Front face 
    manual->index(0);
    manual->index(1);
    manual->index(2);

    manual->index(0);
    manual->index(2);
    manual->index(3);


    // Back Face
    manual->index(5);
    manual->index(4);
    manual->index(7);

    manual->index(5);
    manual->index(7);
    manual->index(6);

    // Right Face
    manual->index(8);
    manual->index(10);
    manual->index(11);

    manual->index(8);
    manual->index(11);
    manual->index(9);

    // Left Face
    manual->index(12);
    manual->index(13);
    manual->index(14);

    manual->index(12);
    manual->index(14);
    manual->index(15);

    // Top Face
    manual->index(16);
    manual->index(18);
    manual->index(17);

    manual->index(16);
    manual->index(17);
    manual->index(19);

    // Bottom Face
    manual->index(20);
    manual->index(21);
    manual->index(22);

    manual->index(20);
    manual->index(22);
    manual->index(23);



    manual->end();
    return manual;
}

bool TutorialApplication::frameStarted(const FrameEvent& evt)
{
    // Movement
     if (mKeyboard->isKeyDown(OIS::KeyCode::KC_L))
    {
        xmovement += speed * evt.timeSinceLastFrame;
    }
    if (mKeyboard->isKeyDown(OIS::KeyCode::KC_J))
    {
        xmovement -= speed * evt.timeSinceLastFrame;
    }
    if (mKeyboard->isKeyDown(OIS::KeyCode::KC_I))
    {

        ymovement += speed * evt.timeSinceLastFrame;
    }
    if (mKeyboard->isKeyDown(OIS::KeyCode::KC_K))
    {
        ymovement -= speed * evt.timeSinceLastFrame;
    }
    if ((mKeyboard->isKeyDown(OIS::KeyCode::KC_K) || mKeyboard->isKeyDown(OIS::KeyCode::KC_L) || mKeyboard->isKeyDown(OIS::KeyCode::KC_J) || mKeyboard->isKeyDown(OIS::KeyCode::KC_I)))
    {
        cubeNode->translate(xmovement, ymovement, 0.0);
    }
    else
    {
        xmovement = 0.0;
        ymovement = 0.0;
    }

    // Rotation
    if (mKeyboard->isKeyDown(OIS::KeyCode::KC_NUMPAD6))
    {
        Radian rotationAngle = Radian(Degree(30 * evt.timeSinceLastFrame));
        cubeNode->rotate(Vector3(0, 1, 0), rotationAngle);
    }
    else if (mKeyboard->isKeyDown(OIS::KeyCode::KC_NUMPAD4))
    {
        Radian rotationAngle = Radian(Degree(-30 * evt.timeSinceLastFrame));
        cubeNode->rotate(Vector3(0, 1, 0), rotationAngle);
    }
    else if (mKeyboard->isKeyDown(OIS::KeyCode::KC_NUMPAD8))
    {
        Radian rotationAngle = Radian(Degree(-30 * evt.timeSinceLastFrame));
        cubeNode->rotate(Vector3(1, 0, 0), rotationAngle);
    }
    else if (mKeyboard->isKeyDown(OIS::KeyCode::KC_NUMPAD2))
    {
        Radian rotationAngle = Radian(Degree(30 * evt.timeSinceLastFrame));
        cubeNode->rotate(Vector3(1, 0, 0), rotationAngle);
    }

    return true;
}
//---------------------------------------------------------------------------


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
