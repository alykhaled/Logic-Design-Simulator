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
	Output* pOut = pManager->GetOutput();

	//Delete Connection
	Component* selected = pManager->getSelectedComponent();
	OutputPin* outpin = selected->getOutputPin();
	//for (int i = 0; i < outpin->getNumberOfConnections(); i++)
	//{
	//	delete outpin->getConnenction(i + 1);
	//}
	//for (int i = 0; i < selected->getNumInputs(); i++)
	//{
	//	//delete selected->getInputPin(i + 1)->getConnection();
	//}
	//Delete gate
	delete selected;
	selected = pManager->getComponents()[pManager->getComponetsNumber() - 1];
	//pManager->decreaseComponentNum();
	pOut->ClearDrawingArea();

}

void Delete::Undo()
{

}

void Delete::Redo()
{

}