#include "stdafx.h"
#include "FileHandler.h"


ofstream FileHandler::Posfile("C:\\Users\\piyush\\Desktop\\GEHealthHack\\Data\\MachineLearning\\Positive\\myPos.txt");
ofstream FileHandler::Negfile("C:\\Users\\piyush\\Desktop\\GEHealthHack\\Data\\MachineLearning\\Negative\\myNeg.txt");


void FileHandler::writePos(string fileName, Rect region)
{
	string data = fileName + 
				 " " +
				  to_string( region.x) + 
				  " " + 
				  to_string( region.y) + 
				  " " + 
				  to_string( region.x +region.width) + 
				  " " + 
				  to_string( region.y +region.height);
	Posfile << data << endl;
}

void FileHandler::writeNeg(Rect region)
{
	string data = "C:\\Users\\piyush\\Desktop\\GEHealthHack\\Data\\MachineLearning\\Positive\\ " + 
				  to_string( region.x) + 
				  " " + 
				  to_string( region.y) + 
				  " " + 
				  to_string( region.x +region.width) + 
				  " " + 
				  to_string( region.y +region.height);
	Negfile << data << endl;
}


