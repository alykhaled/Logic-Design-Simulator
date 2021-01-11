#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)

	static const int	
		width = 1400, height = 780,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight		= 50,		//Status Bar Height
		ToolBarHeight		= 77,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth		= 100,
		ActionToolBarHeight = 30,
		ActionToolBarWidth	= 40;

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int
		AND2_Width = 83,		//AND2 Gate Image default width
		AND2_Height = 50,		//AND2 Gate Image default height

		AND3_Width = 99,
		AND3_Height = 50,

		NOT_Width = 92,			//NOT Gate Image default width
		NOT_Height = 50,

		BUFFER_Width = 97,
		BUFFER_Height = 50,

		NAND2_Width = 87,		//NAND2 Gate Image default width
		NAND2_Height = 50,

		NAND3_Width = 97,			//OR Gate Image default width
		NAND3_Height = 50,

		XNOR2_Width = 100,		//XNOR2 Gate Image default width
		XNOR2_Height = 50,		//XNOR2 Gate Image default height

		XNOR3_Width = 97,
		XNOR3_Height = 50,

		XOR2_Width = 95,		//XOR2 Gate Image default width
		XOR2_Height = 50,		//XOR2 Gate Image default height

		XOR3_Width = 80,			//OR Gate Image default width
		XOR3_Height = 50,

		OR_Width = 97,			//OR Gate Image default width
		OR_Height = 50,		//OR Gate Image default height

		LED_Width = 38,			//OR Gate Image default width
		LED_Height = 50,		//OR Gate Image default height

		NOR2_Width = 94,			//OR Gate Image default width
		NOR2_Height = 50,		//OR Gate Image default height

		NOR3_Width = 97,			//OR Gate Image default width
		NOR3_Height = 50;
		
		
}UI;	//create a single global object UI

#endif