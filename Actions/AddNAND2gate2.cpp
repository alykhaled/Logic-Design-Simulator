#include "AddNAND2gate2.h"
#include"..\Components\NAND2.h"
#include "..\ApplicationManager.h"


AddNAND2gate2::AddNAND2gate2(ApplicationManager* pApp) :Action(pApp)
{

}

AddNAND2gate2::~AddNAND2gate2(void)
{

}

void AddNAND2gate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND2 Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNAND2gate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;

	//Calculate the rectangle Corners
	int Len = UI.NAND2_Width;
	int Wdth = UI.NAND2_Height;

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
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);


	NAND2* pA = new NAND2(GInfo, NAND2_FANOUT);
	pA->setLabel(label);

	pManager->AddComponent(pA);
}

void AddNAND2gate2::Undo()
{

}

void AddNAND2gate2::Redo()
{

}