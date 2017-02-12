#pragma once
#include "opencv2\highgui\highgui.hpp"
using namespace cv;
namespace controller
{
	class MouseController
	{
	public:
	
		static Point2f point;
		static bool addRemovePt;


		static int posX;
		static int posY;
		static void handleMouse(int event, int x, int y, int, void*);

		static bool doWeHaveFirstPoint;
		static bool doWeHaveSecondPoint;

		static bool isRectangleReady;

		

	};
}
