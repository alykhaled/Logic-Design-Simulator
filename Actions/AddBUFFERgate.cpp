#include "AddBUFFERgate.h"

AddBUFFERgate::AddBUFFERgate(ApplicationManager * pApp) : Action(pApp)
{

}

//AddBUFFERgate::AddBUFFERgate(ApplicationManager* pApp, Buffer* obj) : Action(pApp)
//{
//	int yup, ybot;
//
//	//Calculate the rectangle Corners
//	int Len = UI.AND2_Width;
//	int Wdth = UI.AND2_Height;
//
//	GraphicsInfo centerPos;
//	centerPos = obj->getCenter();
//	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
//	Cx = centerPos.x1;
//	Cy = centerPos.y1;
//
//	yup = Cy / 100;
//	yup *= 100;
//	yup += 30;
//
//	ybot = Cy / 100;
//	ybot *= 100;
//	ybot += 80;
//
//	if (abs((Cy - yup)) > abs(Cy - ybot))
//	{
//		GInfo.y1 = ybot;
//		Cy = ybot;
//	}
//	else
//	{
//		GInfo.y1 = yup;
//		Cy = yup;
//	}
//
//	GInfo.x1 = Cx - Len / 2;
//	GInfo.x2 = Cx + Len / 2;
//	GInfo.y1 = Cy - Wdth / 2;
//	GInfo.y2 = Cy + Wdth / 2;
//	obj->setPosition(GInfo);
//
//	pManager->AddComponent(obj);
//}

AddBUFFERgate::~AddBUFFERgate(void)
{

}

void AddBUFFERgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Buffer: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBUFFERgate::Execute()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();
	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
		if (gfx.x1 <= Cx && gfx.x2 >= Cx && gfx.y1 <= Cy && gfx.y2 >= Cy)
		{
			pOut->PrintMsg("Invaild Position");
			return;
		}
	}
	//Calculate the rectangle Corners
	int Len = UI.BUFFER_Width;
	int Wdth = UI.BUFFER_Height;

	//Spin the gate to the nearest Line
	int yup, ybot;

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


	string label = pIn->GetSrting(pOut);
	BUFFER* pA = new BUFFER(GInfo, AND2_FANOUT);
	pA->setLabel(label);
	pA->setCenter(Cx, GInfo.y1);

	pManager->AddComponent(pA);
}

void AddBUFFERgate::Undo()
{

}

void AddBUFFERgate::Redo()
{

}

