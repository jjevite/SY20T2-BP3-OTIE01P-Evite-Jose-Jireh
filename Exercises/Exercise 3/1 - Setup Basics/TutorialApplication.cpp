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
    ManualObject* cube = createCube(15);
    cubeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    cubeNode->attachObject(cube);


}
ManualObject* TutorialApplication::createCube(float size)
{
    ManualObject* manual = mSceneMgr->createManualObject("manual");
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);

    manual->position(-size, -size, size);
    manual->colour(ColourValue::Blue);
    manual->position(size, -size, size);
    manual->colour(ColourValue::Red);
    manual->position(size, size, size);
    manual->colour(ColourValue::Blue);
    manual->position(-size, size, size);
    manual->colour(ColourValue::Red);

    manual->position(-size, -size, -size);
    manual->colour(ColourValue::Blue);
    manual->position(size, -size, -size);
    manual->colour(ColourValue::Red);
    manual->position(size, size, -size);
    manual->colour(ColourValue::Blue);
    manual->position(-size, size, -size);
    manual->colour(ColourValue::Red);

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
    manual->index(1);
    manual->index(5);
    manual->index(6);

    manual->index(1);
    manual->index(6);
    manual->index(2);

    // Left Face
    manual->index(4);
    manual->index(0);
    manual->index(3);

    manual->index(4);
    manual->index(3);
    manual->index(7);

    // Top Face
    manual->index(3);
    manual->index(2);
    manual->index(6);

    manual->index(3);
    manual->index(6);
    manual->index(7);

    // Bottom Face
    manual->index(4);
    manual->index(5);
    manual->index(1);

    manual->index(4);
    manual->index(1);
    manual->index(0);



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
