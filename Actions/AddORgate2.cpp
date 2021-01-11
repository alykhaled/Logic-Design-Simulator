#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{

}

AddORgate2::~AddORgate2(void)
{

}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;
	Output* pOut = pManager->GetOutput();

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

	/*GraphicsInfo border = GInfo;
	border.x1 -= 3;
	border.x2 += 3;
	border.y1 -= 3;
	border.y2 += 3;*/
	//pOut->DrawRectangle(border);

	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);

	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	pA->setLabel(label);
	pManager->AddComponent(pA);
}

void AddORgate2::Undo()
{

}

void AddORgate2::Redo()
{

}