#pragma once
#include <string>
#include <iostream>
using namespace std;


namespace utilities
{
	class Debug
	{
	public:
		static void Log(string data);
		static void Log(bool data);
		static void Log(char* data);


	};
}

