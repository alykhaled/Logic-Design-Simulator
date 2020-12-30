//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	pOut->PrintMsg("Add Label: ");
	pWind->FlushKeyQueue();
	char c;
	keytype kt;
	string text = "";
	kt = pWind->WaitKeyPress(c);
	text += c;
	while (kt != ESCAPE)
	{
		kt = pWind->WaitKeyPress(c);
		if (c == '\r')
		{
			break;
		}
		else if (c == '\b')
		{
			text.pop_back();
		}
		else
		{
			text += c;
		}
		pOut->PrintMsg(text);
	}
	if (kt == ESCAPE)
	{
		return "";
	}
	return text;
}

GraphicsInfo Input::getLastClick()
{
	GraphicsInfo gfx;
	gfx.x1 = lastX;
	gfx.y1 = lastY;
	return gfx;
}

void Input::setLastClick(int x, int y)
{
	lastX = x;
	lastY = y;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() 
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2:			return ADD_AND_GATE_2;
			case ITM_INV:			return ADD_INV;
			case ITM_OR2:			return ADD_OR_GATE_2;
			case ITM_XOR2:			return ADD_XOR_GATE_2;
			case ITM_XNOR2:			return ADD_XNOR_GATE_2;
			case ITM_NAND2:			return ADD_NAND_GATE_2;
			case ITM_OR3:			return ADD_OR_GATE_3;
			case ITM_NOR2:			return ADD_NOR_GATE_2;
			case ITM_LED:			return ADD_LED;
			case ITM_SWITCH:		return ADD_Switch;
			case ITM_CONNECTION:	return ADD_CONNECTION;
			case ITM_EXIT:			return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight + 30)
		{
			return SIM_MODE;

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight + 30 && y < UI.height - UI.StatusBarHeight)
		{
			setLastClick(x, y);
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight + 30)
		{
			return DSN_MODE;
		}

		if (y >= UI.ToolBarHeight + 30 && y < UI.height - UI.StatusBarHeight)
		{
			setLastClick(x, y);
			return SELECT;	//user want to select/unselect a component
		}
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}

Input::~Input()
{
}
