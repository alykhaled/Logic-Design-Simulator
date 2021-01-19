#include "Delete.h"
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
	pOut->ClearDrawingArea();

	//Delete Gate
	Component* selected = pManager->getSelectedComponent();
	Component** compList = pManager->getComponents();
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
	int compCount = pManager->getComponetsNumber();
	for (int i = 0; i < compCount; i++)
	{
		if (dynamic_cast<Connection*>(compList[i]))
		{
			if (dynamic_cast<Connection*>(compList[i])->getSourcePin() == selected->getOutputPin())
			{
				delete compList[i];
				compList[i] = pManager->getComponents()[pManager->getComponetsNumber() - 1];
				pManager->decreaseComponentNum();
				continue;
			}
			int numOfInput = selected->getNumInputs();
			for (int j = 0; j < numOfInput; j++)
			{
				if (dynamic_cast<Connection*>(compList[i])->getDestPin() == selected->getInputPin(j+1))
				{
					delete compList[i];
					compList[i] = pManager->getComponents()[pManager->getComponetsNumber() - 1];
					pManager->decreaseComponentNum();
				}
			}
		}
	}

	for (int i = 0; i < compCount; i++)
	{
		if (selected == compList[i])
		{
			delete compList[i];
			compList[i] = pManager->getComponents()[pManager->getComponetsNumber() - 1];
			pManager->decreaseComponentNum();
		}
	}
	
	pManager->setComponents(compList);
	pOut->ClearDrawingArea();


}

void DeleteComp::Undo()
{

}

void DeleteComp::Redo()
{

}