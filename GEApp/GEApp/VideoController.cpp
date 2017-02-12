#include "stdafx.h"
#include "VideoController.h"
#include "Debug.h"
#include <iomanip>
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\video\video.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "CascadeClassifierController.h"
#include "DataCreator.h"
#include "KeyboardController.h"
#include "MouseController.h"
#include "RegionOfInterest.h"
#include "FileHandler.h"
#include "OpticalFlowController.h"


using namespace controller;
using namespace utilities;

VideoCapture VideoController::video;

Mat VideoController::frame;
Mat VideoController::currFrame;
Mat VideoController::currGrayFrame;
Mat VideoController::prevFrame;
Mat VideoController::prevGrayFrame;

CascadeClassifierController VideoController::faceDetector("lbpcascade_frontalface_improved.xml");
CascadeClassifierController VideoController::eyesDetector("haarcascade_eye.xml");
CascadeClassifierController VideoController::mouthDetector("haarcascade_smile.xml");
CascadeClassifierController VideoController::disComfortDetector("disComfort.xml");
CascadeClassifierController VideoController::smileDetector("smile.xml");

vector<Rect> VideoController::faces;
vector<Rect> VideoController::eyes;
vector<Rect> VideoController::mouth;
vector<Rect> VideoController::disComfort;
vector<Rect> VideoController::smile;

int VideoController::startVideoAt = 0;

void VideoController::loadVideo(string _fileName)
{
	video.open(_fileName);
	//video.open(0);
	if(video.isOpened() == false)
	{
		Debug::Log("Cant load video !!!!!");
		waitKey(0);
		exit(1);
	}
	//video.set(CV_CAP_PROP_POS_MSEC ,startVideoAt * 1000);
		
}
void VideoController::processVideo()
{
	video >> frame;
	if(frame.empty() == true)
	{
		Debug::Log("reached end of frame!!!!");
		waitKey(0);
		exit(1);
	}
	
	processFrame();
	std::swap(OpticalFlowController::inputOpticalPoints, OpticalFlowController::outputOpticalPoints);
	cv::swap(prevGrayFrame, currGrayFrame);
	
}

void VideoController::processFrame()
{
	

	cvtColor(frame,currGrayFrame,CV_BGR2GRAY);
	if( MouseController::addRemovePt  )
     {
		 
            vector<Point2f> tmp;
			tmp.push_back(MouseController::point);
			cornerSubPix( currGrayFrame, tmp, Size(31,31), Size(-1,-1), OpticalFlowController::terminationCriteria);
            OpticalFlowController::outputOpticalPoints.push_back(tmp[0]);
			MouseController::addRemovePt = false;
     }
	if( ! OpticalFlowController::inputOpticalPoints.empty() )
        {
            vector<uchar> status;
            vector<float> err;
            if(prevGrayFrame.empty())
				currGrayFrame.copyTo(prevGrayFrame);
			OpticalFlowController::calulateOpticalPoints(prevGrayFrame,currGrayFrame);
			rectangle(frame,Rect(OpticalFlowController::outputOpticalPoints[0].x -50,OpticalFlowController::outputOpticalPoints[0].y-50,100,100),Scalar(0,0,255));

	}

	/*
	if(MouseController ::isRectangleReady)
	{
		rectangle(frame,RegionOfInterest::point1,RegionOfInterest::point2,Scalar(255,0,0));
	}

	*/
	
	// If tab key is pressed , then only start searching for face
	if(KeyboardController::isTabKeyPressed)
	{
		// detect face
		faces = faceDetector.findObjects(VideoController::frame);
	
		// if we got the face
		if(faces.size() > 0 && faces[0].x > 40 && faces[0].y > 40 && faces[0].x + faces[0].width + 40 < frame.cols && faces[0].y + faces[0].height + 40 < frame.rows)
		{
	
			// create the bigger face region 
			Rect faceBigRect = Rect(faces[0].x - 40 ,faces[0].y - 40 ,faces[0].width + 80 , faces[0].height + 80);

			// get the bigger face image
			Mat faceBigImage = frame(faceBigRect);

			// if button one is pressed then only display face
			KeyboardController::isOneKeyPressed ?rectangle(frame , faceBigRect,Scalar(0,0,255)) : rectangle(frame , Rect(0,0,0,0),Scalar(0,0,255));
			/*if(KeyboardController::isOneKeyPressed)
			{
				for(int i=0;i<faces.size();i++)
				{
					rectangle(frame , faces[i],Scalar(0,0,255));
					string name(i,char(i+ 64));
					putText(frame, name, cvPoint(faces[i].x+faces[i].width/2,faces[i].y +faces[i].height/2), 
					FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,255), 1, CV_AA);
				}
			
			}*/


			// Create the bigger region for eyes to be searched but smaller than big face region
			Rect EyesBigRect = Rect(faceBigRect.x,faceBigRect.y,faceBigRect.width,faceBigRect.height/2);

			// get the big eye image
			Mat EyesBigImage = frame(EyesBigRect);
			
			// show the big search region for eyes if 4 is pressed
			// if button one is pressed then only display face
			KeyboardController::isFourKeyPressed ?rectangle(frame , EyesBigRect,Scalar(0,0,255)) : rectangle(frame , Rect(0,0,0,0),Scalar(0,0,255));

			// detect eyes
					eyes = eyesDetector.findObjects(EyesBigImage);
			//// draw eyes
			if(eyes.size() > 1 && KeyboardController::isThreeKeyPressed)
			{
				rectangle(EyesBigImage,eyes[0],Scalar(255,0,0));
				rectangle(EyesBigImage,eyes[1],Scalar(255,0,0));
			}


			// Get the region to search for mouth
			Rect MouthBigRect = Rect(faceBigRect.x ,faceBigRect.y + faceBigRect.height/2,faceBigRect.width,faceBigRect.height/2);

			// show the big search region for eyes if 5 is pressed
			// if button one is pressed then only display face
			//KeyboardController::isFiveKeyPressed ?rectangle(frame , MouthBigRect,Scalar(0,0,255)) : rectangle(frame , Rect(0,0,0,0),Scalar(0,0,255));

			// get the big mouth image
			Mat MouthBigImage = frame(MouthBigRect);

			// detect mouth
			mouth = mouthDetector.findObjects(MouthBigImage);
			
			if(mouth.size() > 0 && KeyboardController::isTwoKeyPressed)
			{
				rectangle(MouthBigImage,mouth[0],Scalar(255,0,0));

				
			}

			// show mouth
			if(mouth.size()>0)
			{
				
				//KeyboardController::isFiveKeyPressed ? rectangle(MouthBigImage,mouthRegion,Scalar(255,0,0)):rectangle(MouthBigImage,Rect(0,0,0,0),Scalar(255,0,0));;
				//imshow("big",MouthBigImage);

				Rect improvedMouseRegion = Rect(
													MouthBigRect.x + MouthBigRect.width/4,
													MouthBigRect.y + MouthBigRect.height/12,
													MouthBigRect.width - MouthBigRect.width/4,
													MouthBigRect.height -MouthBigRect.height/4
				
													);

				Mat imrpovedMouth = frame(improvedMouseRegion);

				imshow("improve " ,imrpovedMouth);

				//detect discomfort
			//	disComfort = disComfortDetector.findObjects(MouthBigImage);
				//disComfort = disComfortDetector.findObjects(imrpovedMouth);
			//	disComfort.size() >0 ? Debug::Log("discomfort detected!!!!!"): Debug::Log("Patient is fine");				

				//detect smile
				smile = smileDetector.findObjects(MouthBigImage);
				cout<<smile.size();
				//smile.size() >0 ? Debug::Log("smile detected!!!!!"): Debug::Log("Patient is fine");				
				
				// For training
				if(KeyboardController::isEnterKeyPressed)
				{
					string savedImageName  = "C:\\Users\\piyush\\Desktop\\GEHealthHack\\Data\\MachineLearning\\Positive\\" + to_string(DataCreator::positveImageCounter) + ".jpg";
					imwrite(savedImageName,MouthBigImage);
					DataCreator::positveImageCounter++;
					FileHandler::writePos(to_string(DataCreator::positveImageCounter) + ".jpg",mouth[0]);
				}
			}
						

			
		}

	}

			
}
