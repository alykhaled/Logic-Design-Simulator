#include "AddNOR3gate3.h"
#include "..\ApplicationManager.h"


AddNOR3gate3::AddNOR3gate3(ApplicationManager* pApp) :Action(pApp)
{

}

AddNOR3gate3::~AddNOR3gate3(void)
{

}

void AddNOR3gate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR3 Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNOR3gate3::Execute()
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
	int Len = UI.NOR3_Width;
	int Wdth = UI.NOR3_Height;

	//Spin the gate to the nearest Line

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

	NOR3* pA = new NOR3(GInfo, NOR3_FANOUT);
	Input* pIn = pManager->GetInput();

	string label = pIn->GetSrting(pOut);
	pA->setLabel(label);

	pManager->AddComponent(pA);
}

void AddNOR3gate3::Undo()
{

}

void AddNOR3gate3::Redo()
{

}