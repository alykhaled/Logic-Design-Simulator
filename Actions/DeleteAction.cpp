#include "DeleteAction.h"
DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{

}

DeleteAction::~DeleteAction(void)
{

}

void DeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


}

void DeleteAction::Execute()
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

void DeleteAction::Undo()
{

}

void DeleteAction::Redo()
{

}