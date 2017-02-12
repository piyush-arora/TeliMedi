#include "stdafx.h"
#include "CascadeClassifierController.h"


CascadeClassifierController::CascadeClassifierController(string _fileName)
{
	cascadeClassifier.load( _fileName );

}


vector<Rect> CascadeClassifierController::findObjects(Mat _image)
{
	vector<Rect> detectedObjects;
	cascadeClassifier.detectMultiScale( 
										_image, // Matrix of the type CV_8U containing an image where objects are detected.
										detectedObjects, //Vector of rectangles where each rectangle contains the detected object.
										1.1,//Parameter specifying how much the image size is reduced at each image scale.
										1,//Parameter specifying how many neighbors each candidate rectangle should have to retain it.
										0|CV_HAAR_SCALE_IMAGE,//flags
										Size(50, 50)//Minimum possible object size. Objects smaller than that are ignored.
									  );
	return detectedObjects;
}


CascadeClassifierController::~CascadeClassifierController(void)
{
}
