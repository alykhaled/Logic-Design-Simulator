#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLACK;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	ClearDrawingArea();
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	//pWind->DrawImage("images\\Menu\\modetoolbar.jpg", 0, UI.ToolBarHeight+ UI.ActionToolBarHeight+5, 1500, 30);
}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;

}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintInt(int msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawInteger(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.ActionToolBarHeight + 5, UI.width, UI.height - UI.StatusBarHeight);
	pWind->SetPen(GRAY, 1);
	for (int i = 80; i < 700; i += 50)
	{
		if (i != 80 && i != 130)
		{
			pWind->DrawLine(0, i, 1500, i);
		}

	}
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ActionToolBarHeight, 1500, UI.ActionToolBarHeight + UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	ClearToolBar();
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item for gates
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2]		= "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_INV]			= "images\\Menu\\Menu_NOT.jpg";
	MenuItemImages[ITM_OR2]			= "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_XOR2]		= "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2]		= "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_NAND2]		= "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_OR3]			= "images\\Menu\\Menu_OR3.jpg";
	MenuItemImages[ITM_NOR2]		= "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_LED]			= "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_SWITCH]		= "images\\Menu\\SwitchOFF.jpg";
	MenuItemImages[ITM_CONNECTION]	= "images\\Menu\\wire.jpg";
	//MenuItemImages[ITM_SIMULATION] = "images\\Menu\\simulation.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	string MenuActionItemImages[ITM_ACTION_CNT];
	MenuActionItemImages[ITM_SIM]	= "Images\\Simulation toolbar\\SIM_SIMULATE.jpg";
	MenuActionItemImages[ITM_DEL]	= "Images\\Simulation toolbar\\SIM_DELETE.jpg";
	MenuActionItemImages[ITM_MOVE]	= "Images\\Simulation toolbar\\SIM_MOVE.jpg";
	MenuActionItemImages[ITM_EDIT]	= "Images\\Simulation toolbar\\SIM_EDIT.jpg";
	MenuActionItemImages[ITM_COPY]	= "Images\\Simulation toolbar\\SIM_COPY.jpg";
	MenuActionItemImages[ITM_PASTE]	= "Images\\Simulation toolbar\\SIM_PASTE.jpg";
	MenuActionItemImages[ITM_CUT]	= "Images\\Simulation toolbar\\SIM_CUT.jpg";
	MenuActionItemImages[ITM_SAVE]	= "Images\\Simulation toolbar\\SIM_SAVE.jpg";
	MenuActionItemImages[ITM_LOAD]	= "Images\\Simulation toolbar\\SIM_LOAD.jpg";
	MenuActionItemImages[ITM_UNDO]	= "Images\\Simulation toolbar\\SIM_UNDO.jpg";
	MenuActionItemImages[ITM_REDO]	= "Images\\Simulation toolbar\\SIM_REDO.jpg";

	for (int i = 0; i < 11; i++)
		pWind->DrawImage(MenuActionItemImages[i], i * UI.ActionToolBarWidth, 0, UI.ActionToolBarWidth, UI.ActionToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	//pWind->DrawLine(0, UI.ToolBarHeight + 5 + UI.ActionToolBarWidth, UI.width, UI.ToolBarHeight + 5 + UI.ActionToolBarWidth);

	//Draw menu item one image at a time
	for (int i = 0; i < 11; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, UI.ActionToolBarHeight, UI.ToolItemWidth, UI.ToolBarHeight);
	
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight + UI.ActionToolBarHeight + 5, UI.width, UI.ToolBarHeight + UI.ActionToolBarHeight + 5);

	
}

void Output::UpdateScreen() {
	pWind->UpdateBuffer();
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	ClearToolBar();
	UI.AppMode = SIMULATION;	//Simulation Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_SIM_CNT];

	MenuItemImages[ITM_TRUTH] = "images\\Simulation toolbar\\SIM_TRUTH_TABLE.jpg";
	MenuItemImages[ITM_PROBING] = "images\\Simulation toolbar\\SIM_PROBING.jpg";
	

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, UI.ActionToolBarHeight, UI.ToolItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar

}
void Output::DrawRectangle(GraphicsInfo r_GfxInfo)
{
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->SetPen(BLACK, 3);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

}
//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates_HI\\Gate_AND2.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw Or2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}
void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_NOT.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOT.jpg";
	//Draw INV gate at Gfx_Info (2nd corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}
void Output::DrawBuff(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_Buff_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Buff.jpg";
	//Draw Buff. at Gfx_Info (3rd corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";
	//Draw NAND2 Gate at Gfx_Info (4th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";
	//Draw NORR2 Gate at Gfx_Info (5th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";
	//Draw XORR2 Gate at Gfx_Info (7th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_XNOR2.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";
	//Draw XNOR2 Gate at Gfx_Info (8th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_XAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XAND2.jpg";
	//Draw AND3 Gate at Gfx_Info (6th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";
	//Draw NOR3 Gate at Gfx_Info (6th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images\\Gates_HI\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR3.jpg";
	//Draw XOR3 Gate at Gfx_Info (6th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected, bool on) const
{
	string GateImage;
	if (on)	
	{
		GateImage = "Images\\Gates\\SwitchON.jpg";
	}
	else
	{
		if (selected)
			GateImage = "Images\\Gates_HI\\SwitchOFF.jpg";
		else
			GateImage = "Images\\Gates\\SwitchOFF.jpg";
	}
	
	//Draw Switch at Gfx_Info (6th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected, bool on) const
{
	string GateImage;
	if (on)
	{
		GateImage = "Images\\Gates\\LED_ON.jpg";
	}
	else
	{
		if (selected)
			GateImage = "Images\\Gates_HI\\LED.jpg";
		else
			GateImage = "Images\\Gates\\LED.jpg";
	}
	
	//Draw LED at Gfx_Info (6th corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
void Output::DrawString(GraphicsInfo r_GfxInfo, string text) const
{
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1, text);
}
void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected,bool on) const
{
	if (on)
	{
		pWind->SetPen(GREEN, 2);
	}
	else
	{
		if (selected)
		{
			pWind->SetPen(RED, 2);
		}
		else
		{
			pWind->SetPen(BLACK, 2);
		}
		
	}
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
	pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);


}

Output::~Output()
{
	delete pWind;
}
