#include "AddSwitch.h"
#include "..\ApplicationManager.h"

AddSwitch::AddSwitch(ApplicationManager* pApp) : Action(pApp)
{

}

AddSwitch::AddSwitch(ApplicationManager* pApp,Switch* obj) : Action(pApp)
{
	Output* pOut = pManager->GetOutput();

	int yup, ybot;

	//Calculate the rectangle Corners
	GraphicsInfo centerPos;
	centerPos = obj->getCenter();
	Cx = centerPos.x1;
	Cy = centerPos.y1;

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	int centerY = Cy;
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	yup = Cy / 100;
	yup *= 100;
	yup += 30;

	ybot = Cy / 100;
	ybot *= 100;
	ybot += 80;
	if (abs((Cy - yup)) > abs(Cy - ybot))
	{
		GInfo.y1 = ybot;
		Cy = ybot;
	}
	else
	{
		GInfo.y1 = yup;
		Cy = yup;
	}

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	/*GraphicsInfo border = GInfo;
	border.x1 -= 5;
	border.x2 += 5;
	border.y1 -= 5;
	border.y2 += 5;*/
	obj->setPosition(GInfo);
	pManager->AddComponent(obj);

}

AddSwitch::~AddSwitch(void)
{

}

void AddSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddSwitch::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;
	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
		if (gfx.x1 <= Cx && gfx.x2 >= Cx && gfx.y1 <= Cy && gfx.y2 >= Cy || (Cy >= 0 && Cy < UI.ToolBarHeight + UI.ActionToolBarHeight))
		{
			pOut->PrintMsg("Invaild Position");
			return;
		}

	}
	if (Cy >= 0 && Cy < UI.ToolBarHeight + UI.ActionToolBarHeight)
	{
		pOut->PrintMsg("Invaild Position");
		return;
	}
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	int centerY = Cy;
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	yup = Cy / 100;
	yup *= 100;
	yup += 5;

	ybot = Cy / 100;
	ybot *= 100;
	ybot += 55;
	if (abs((Cy - yup)) > abs(Cy - ybot))
	{
		GInfo.y1 = ybot;
	}
	else
	{
		GInfo.y1 = yup;
	}
	/*GraphicsInfo border = GInfo;
	border.x1 -= 5;
	border.x2 += 5;
	border.y1 -= 10;
	border.y2 += 5;
	pOut->DrawRectangle(border);*/
	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);
	Switch* pA = new Switch(GInfo, AND2_FANOUT);
	pA->setCenter(Cx, GInfo.y1);
	pA->setLabel(label);

	pManager->AddComponent(pA);
}

void AddSwitch::Undo()
{

}

void AddSwitch::Redo()
{

}