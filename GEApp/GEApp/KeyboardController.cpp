#include "stdafx.h"
#include "KeyboardController.h"
#include <iomanip>
#include "Debug.h"

using namespace controller;
using namespace utilities;

bool KeyboardController::isEnterKeyPressed = false;
bool KeyboardController::isSpaceKeyPressed = false;
bool KeyboardController::isOneKeyPressed = false;
bool KeyboardController::isTwoKeyPressed = false;
bool KeyboardController::isThreeKeyPressed = false;
bool KeyboardController::isFourKeyPressed = false;
bool KeyboardController::isFiveKeyPressed = false;
bool KeyboardController::isSixKeyPressed = false;

bool KeyboardController::isTabKeyPressed = false;

void  KeyboardController::handleKeyboard(char key)
{
	switch(key)
	{
		case 27 :exit(1);
		case 13 : isEnterKeyPressed = true;
			
				break;
		case 32 : isSpaceKeyPressed = true;
			
			break;

		case 49:isOneKeyPressed = !isOneKeyPressed;
			
			break;

		case 50:isTwoKeyPressed = !isTwoKeyPressed;
			
			break;

		case 51:isThreeKeyPressed = !isThreeKeyPressed;
			
			break;

			case 52:isFourKeyPressed = !isFourKeyPressed;
			
			break;

		case 53:isFiveKeyPressed = !isFiveKeyPressed;
			
			break;

		case 54:isSixKeyPressed = !isSixKeyPressed;
			
			break;

		case 9:isTabKeyPressed = !isTabKeyPressed;
			
			break;
				

		default : isEnterKeyPressed = false;
				  isSpaceKeyPressed = false;	
				  //isOneKeyPressed = false;
				  //isTwoKeyPressed = false;
				  //isThreeKeyPressed = false;

	}

}