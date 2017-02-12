#pragma once
#include "objdetect\objdetect.hpp"
#include<string>

using namespace std;
using namespace cv;
class CascadeClassifierController
{
public:
	CascadeClassifierController(string _fileName);
	~CascadeClassifierController(void);

	CascadeClassifier cascadeClassifier;
	vector<Rect> findObjects(Mat image);
	

	
};

