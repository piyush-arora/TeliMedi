#include "stdafx.h"
#include "MouseController.h"
#include "opencv2\highgui\highgui.hpp"
#include <string>
#include "Debug.h"
#include "RegionOfInterest.h"
#include "VideoController.h"


using namespace controller;
using namespace std;
using namespace utilities;
using namespace cv;


int MouseController::posX;
int MouseController::posY;
bool MouseController::doWeHaveFirstPoint = false;
bool MouseController::doWeHaveSecondPoint = false;
bool MouseController::isRectangleReady = false;
bool MouseController::addRemovePt = false;
Point2f MouseController::point;




 void MouseController::handleMouse(int event, int x, int y, int, void*)
 {
	 if( event == EVENT_LBUTTONDOWN )
    {
        point = Point2f((float)x, (float)y);
        addRemovePt = true;
		//Debug::Log("haha");
    }

	 
	
 }
