#include "stdafx.h"
#include "Debug.h"

using namespace utilities;
void Debug::Log(string data)
{
	cout <<data<<"\n";
}



void Debug::Log(bool data)
{
	cout <<data<<"\n";
}

void Debug::Log(char* data)
{
	cout <<data<<"\n";
}
