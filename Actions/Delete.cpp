#include "Delete.h"
Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{

}

Delete::~Delete(void)
{

}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
}

void Delete::Undo()
{

}

void Delete::Redo()
{

}