#include "stdafx.h"
#include "OpticalFlowController.h"

using namespace controller;

TermCriteria OpticalFlowController::terminationCriteria(TermCriteria::COUNT | TermCriteria::EPS,20,0.03);
Size OpticalFlowController::winSize(31,31);
vector<uchar> OpticalFlowController::status;
vector<float> OpticalFlowController::error;
vector<Point2f> OpticalFlowController::inputOpticalPoints;
vector<Point2f> OpticalFlowController::outputOpticalPoints;

void OpticalFlowController::calulateOpticalPoints(Mat prevFrame , Mat nextFrame)
{
	calcOpticalFlowPyrLK(prevFrame, nextFrame, inputOpticalPoints, outputOpticalPoints, status, error, winSize,
		3, terminationCriteria, 0, 0.001);


}

