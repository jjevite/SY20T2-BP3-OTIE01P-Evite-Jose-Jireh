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

   
    bigYellowSun = new Planet(ColourValue(1.0f, 1.0f, 1.0f, 0.0f), ColourValue(1.0f, 1.0f, 1.0f), 20.0f, mSceneMgr, nullptr, "sunMaterial", "sun");
    whiteMercury = new Planet(ColourValue(0.5f, 0.5f, 0.5f, 0.0f), ColourValue(1.0f, 0.5f, 0.0f),  3.0f, mSceneMgr, bigYellowSun->getNode(), "mercuryMaterial", "mercury");
    greenVenus = new Planet(ColourValue(1.0f, 1.0f, 0.0f, 0.0f), ColourValue(0.0f, 1.0f, 0.0f), 5.0f, mSceneMgr, bigYellowSun->getNode(), "venusMaterial", "venus");

    blueEarth = new Planet(ColourValue(1.0f, 1.0f, 0.0f, 0.0f), ColourValue(0.0f, 0.0f, 1.0f), 10.0f, mSceneMgr, bigYellowSun->getNode(), "earthMaterial", "earth");
    grayMoon = new Planet(ColourValue(1.0f, 1.0f, 0.0f, 0.0f), ColourValue(0.5f, 0.5f, 0.5f), 1.0f, mSceneMgr, blueEarth->getNode(), "moonMaterial", "moon");
    redMars = new Planet(ColourValue(1.0f, 1.0f, 0.0f, 0.0f), ColourValue(1.0f, 0.0f, 0.0f), 8.0f, mSceneMgr, bigYellowSun->getNode(), "marsMaterial", "mars");
  

    Light* pointlight = mSceneMgr->createLight();
    pointlight->setType(Light::LightTypes::LT_POINT);
    pointlight->setPosition(Vector3(0, 0, 0));
    pointlight->setDiffuseColour(ColourValue(1.0f, 1.0f, 1.0f));
    pointlight->setSpecularColour(ColourValue(1.0f, 1.0f, 1.0f));
    pointlight->setAttenuation(325, 0.0f, 0.014, 0.0007);
    pointlight->setCastShadows(false);

    mSceneMgr->setAmbientLight(ColourValue(0.1f, 0.1f, 0.1f, 0));
 

    

    whiteMercury->move(40, 0, 0);
    greenVenus->move(60, 0, 0);
    blueEarth->move(80, 0,0);
    grayMoon->move(100, 0, 0);
    redMars->move(120, 0, 0);
    

}

bool TutorialApplication::frameStarted(const FrameEvent& evt)
{
    bigYellowSun->update(evt, 10, 0);
    whiteMercury->update(evt, 30, 24);
    greenVenus->update(evt, 30, 18);
    blueEarth->update(evt, 30, 6);
    grayMoon->update(evt, 30, 100);
    redMars->update(evt, 30, 2);
  
  

 
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
