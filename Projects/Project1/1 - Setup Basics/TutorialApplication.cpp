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
    bigYellowSun = new Planet(ColourValue(1, 1, 0), 20, mSceneMgr, nullptr);
    whiteMercury = new Planet(ColourValue(1, 1, 1), 3, mSceneMgr, bigYellowSun->getNode());
    greenVenus = new Planet(ColourValue(0, 1, 0), 5, mSceneMgr, bigYellowSun->getNode());
    blueEarth = new Planet(ColourValue(0, 0, 1), 10, mSceneMgr, bigYellowSun->getNode());
    grayMoon = new Planet(ColourValue(1, 1, 1), 1, mSceneMgr, blueEarth->getNode());
    redMars = new Planet(ColourValue(1, 0, 0), 8, mSceneMgr, bigYellowSun->getNode());
    
    whiteMercury->move(50, 10, 0);
    greenVenus->move(90, 30, 0);
    blueEarth->move(130, 50,0);
    grayMoon->move(170, 50, 0);
    redMars->move(190, 90, 0);
    

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
