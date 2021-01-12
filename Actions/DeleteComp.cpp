#include "DeleteComp.h"
DeleteComp::DeleteComp(ApplicationManager* pApp) :Action(pApp)
{

}

DeleteComp::~DeleteComp(void)
{

}

void DeleteComp::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


}

void DeleteComp::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	//Delete Connection
	pManager->Delete();
	pOut->ClearDrawingArea();

}

void DeleteComp::Undo()
{

}

void DeleteComp::Redo()
{

}