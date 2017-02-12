#pragma once
#include "opencv2\highgui\highgui.hpp"
#include "CascadeClassifierController.h"
#include <string>


using namespace cv;
using namespace std;

namespace controller
{
	class VideoController
	{
	private:
			static void processFrame();
			
			static Mat prevFrame;
			static Mat currFrame;

			static Mat prevGrayFrame;
			static Mat currGrayFrame;

			

	public:
			
			static string filePath;
			static int startVideoAt;
			static VideoCapture video;
			static Mat frame;
			static void loadVideo(string fileName);
			static void processVideo();
			
			static CascadeClassifierController faceDetector;
			static vector<Rect> faces;

			static CascadeClassifierController eyesDetector;
			static vector<Rect> eyes;

			static CascadeClassifierController mouthDetector;
			static vector<Rect> mouth;

			static CascadeClassifierController disComfortDetector;
			static vector<Rect> disComfort;

			static CascadeClassifierController smileDetector;
			static vector<Rect> smile;

	};
}
