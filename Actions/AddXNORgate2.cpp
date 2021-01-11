#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"


AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) :Action(pApp)
{

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
	Output* pOut = pManager->GetOutput();

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
	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);

	GraphicsInfo labelgfx = GInfo;
	labelgfx.y1 -= 20;

	pA->setLabel(label);

	pOut->DrawString(labelgfx, label);
	pManager->AddComponent(pA);
}

void AddXNORgate2::Undo()
{

}

void AddXNORgate2::Redo()
{

}