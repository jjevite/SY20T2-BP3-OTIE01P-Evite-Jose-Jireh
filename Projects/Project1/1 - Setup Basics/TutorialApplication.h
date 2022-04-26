/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"
#include <OgreManualObject.h>
#include "Planet.h"
#include <vector>


using namespace Ogre;

//---------------------------------------------------------------------------

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);


protected:
    virtual void createScene(void);

    virtual bool frameStarted(const FrameEvent& evt);

private:
    SceneNode* tutorialApplicationNode;
    
    // vector doesnt show up intellisenseee
    Planet* bigYellowSun;
    Planet* whiteMercury;
    Planet* greenVenus;
    Planet* blueEarth;
    Planet* grayMoon;
    Planet* redMars;
    

};

//---------------------------------------------------------------------------

#endif // #ifndef __TutorialApplication_h_

//---------------------------------------------------------------------------
