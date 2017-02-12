#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Debug.h"
#include "CascadeClassifierController.h"
#include "KeyboardController.h"
#include "WindowController.h"
#include "VideoController.h"


using namespace std;
using namespace cv;
using namespace controller;
using namespace utilities; 



 /** @function main */
 int main( int argc, const char** argv )
 {
	//VideoController::loadVideo("C:\\Users\\piyush\\Desktop\\GEHealthHack\\Smile.mp4");  
	 VideoController::loadVideo("C:\\Users\\piyush\\Desktop\\GEHealthHack\\can_tolerate.mp4");  
	 //VideoController::loadVideo("C:\\Users\\piyush\\Desktop\\GEHealthHack\\storyserial1.mp4");  
	// VideoController::loadVideo("C:\\Users\\piyush\\Desktop\\GEHealthHack\\PatientStory.mp4");  
//	 VideoController::loadVideo("C:\\Users\\piyush\\Desktop\\GEHealthHack\\patient_detection.mp4");  
	 

	 WindowController faceWindow("face show");
	 Debug::Log("-------------------------------------------------");
	 Debug::Log("         Welcome To Teli Medi !!!!!");
	 Debug::Log("-------------------------------------------------");
	 Debug::Log("Press 1 to display face");
	 Debug::Log("Press 2 to display mouth");
	 Debug::Log("Press 3 to display eyes");
	 Debug::Log("Press 4 to display search area for eyes");
	 Debug::Log("Press 5 to display improved mouth region");

	 

	while(1)
	{
		VideoController::processVideo();
		KeyboardController::handleKeyboard(waitKey(30));
		
		faceWindow.display(VideoController::frame);
	}
	 
    return 0;
 }