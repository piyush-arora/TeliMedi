#pragma once
#include "opencv2\video\tracking.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\video\video.hpp"

using namespace cv;


namespace controller
{
	class OpticalFlowController
	{
		public: 
			static TermCriteria terminationCriteria;
			static Size winSize;
			static vector<uchar> status;
			static vector<float> error;
			static vector<Point2f> inputOpticalPoints;
			static vector<Point2f> outputOpticalPoints;

			static void calulateOpticalPoints(Mat prevFrame , Mat nextFrame	);

	
	};
}

