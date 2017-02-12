#include "stdafx.h"
#include "WindowController.h"
#include "MouseController.h"

using namespace controller;


WindowController::WindowController(string _windowName)
{
	windowName = _windowName;
	//namedWindow(windowName,WINDOW_NORMAL);
	namedWindow(windowName);
	setMouseCallback(windowName,MouseController::handleMouse,0);
}

void WindowController::display(Mat _image)
{
	imshow(windowName,_image);
}

WindowController::~WindowController(void)
{
}
