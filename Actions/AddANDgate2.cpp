#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{

}

AddANDgate2::AddANDgate2(ApplicationManager* pApp, AND2* obj) : Action(pApp)
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

AddANDgate2::~AddANDgate2(void)
{

}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
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

	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);
	AND2 *pA=new AND2(GInfo, AND2_FANOUT); 
	pA->setLabel(label);
	pA->setCenter(Cx, GInfo.y1);

	pManager->AddComponent(pA);
}

void AddANDgate2::Undo()
{

}

void AddANDgate2::Redo()
{

}