#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	int lastX, lastY;
public:
	Input(window*);
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	string GetSrting(Output*);		//Returns a string entered by the user
	buttonstate GetMouseState(const button btMouse, int& x, int& y);
	GraphicsInfo getLastClick();
	void setLastClick(int x, int y);
	ActionType GetUserAction(Output* pOut);

	~Input();
};
