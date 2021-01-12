#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"


AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) :Action(pApp)
{

}

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp, XNOR2* obj):Action(pApp)
{
	int yup, ybot;

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

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

AddXNORgate2::~AddXNORgate2()
{
}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR2 Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;

	//Calculate the rectangle Corners
	int Len = UI.XNOR2_Width;
	int Wdth = UI.XNOR2_Height;

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
	XNOR2* pA = new XNOR2(GInfo, XNOR2_FANOUT);

	pManager->AddComponent(pA);
}

void AddXNORgate2::Undo()
{

}

void AddXNORgate2::Redo()
{

}