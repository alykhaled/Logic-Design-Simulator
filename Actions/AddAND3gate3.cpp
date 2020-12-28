#include "AddAND3gate3.h"
#include"..\Components\AND3.h"
#include "..\ApplicationManager.h"


AddAND3gate3::AddAND3gate3(ApplicationManager* pApp) :Action(pApp)
{

}

AddAND3gate3::~AddAND3gate3(void)
{

}

void AddAND3gate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND3 Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddAND3gate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;

	//Calculate the rectangle Corners
	int Len = UI.AND3_Width;
	int Wdth = UI.AND3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	yup = Cy / 100;
	yup--;
	yup *= 100;
	yup -= 55;

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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);

	AND3* pA = new AND3(GInfo, AND3_FANOUT);
	pA->setLabel(label);
	
	pManager->AddComponent(pA);
}

void AddAND3gate3::Undo()
{

}

void AddAND3gate3::Redo()
{

}