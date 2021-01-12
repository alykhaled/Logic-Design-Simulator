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
	Output* pOut = pManager->GetOutput();

	//Calculate the rectangle Corners
	int Len = UI.NAND2_Width;
	int Wdth = UI.NAND2_Height;
	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
		if (gfx.x1 <= Cx && gfx.x2 >= Cx && gfx.y1 <= Cy && gfx.y2 >= Cy)
		{
			pOut->PrintMsg("Invaild Position");
			return;
		}
	}
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

	GraphicsInfo border = GInfo;
	border.x1 -= 3;
	border.x2 += 3;
	border.y1 -= 3;
	border.y2 += 3;
	//pOut->DrawRectangle(border);

	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);

	GraphicsInfo labelgfx = GInfo;
	labelgfx.y1 - 20;

	NAND2* pA = new NAND2(GInfo, AND2_FANOUT);
	pA->setLabel(label);
	pOut->DrawString(labelgfx, label);
	pManager->AddComponent(pA);
}

void AddNAND2gate2::Undo()
{

}

void AddNAND2gate2::Redo()
{

}