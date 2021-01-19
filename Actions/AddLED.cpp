#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{

}
AddLED::AddLED(ApplicationManager* pApp , LED* obj) :Action(pApp)
{
	int yup, ybot;

	//Calculate the rectangle Corners
	int Len = UI.LED_Width;
	int Wdth = UI.LED_Height;

	GraphicsInfo centerPos;
	centerPos = obj->getCenter();
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	Cx = centerPos.x1;
	Cy = centerPos.y1;

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
	obj->setPosition(GInfo);
	pManager->AddComponent(obj);
}

AddLED::~AddLED(void)
{

}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
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
	int Len = UI.LED_Width;
	int Wdth = UI.LED_Height;

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
	LED* pA = new LED(GInfo);
	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);
	pA->setLabel(label);

	pManager->AddComponent(pA);
}

void AddLED::Undo()
{

}

void AddLED::Redo()
{

}