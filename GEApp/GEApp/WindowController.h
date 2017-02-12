#pragma once
#include <string>
#include "opencv2\highgui\highgui.hpp"

using namespace std;
using namespace cv;

namespace controller
{
	class WindowController
	{
	private:
		string windowName;

	public:

		WindowController(string _windowName);
		~WindowController(void);

		void display(Mat _image);
	};
}

