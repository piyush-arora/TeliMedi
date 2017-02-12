#pragma once

#include <fstream>
#include <string>
#include "opencv2\highgui\highgui.hpp"

using namespace std;
using namespace cv;

class FileHandler
{
public:


	
	static ofstream Posfile;
	static ofstream Negfile;


	
	static void writePos(string fileName,	Rect region);
	static void writeNeg(	Rect region);

};

