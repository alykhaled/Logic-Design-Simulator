#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddNAND2gate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNOR3gate3.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddConnection.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddLED.h"
#include "Actions\Simulate.h"
#include "Actions\Select.h"
#include "Actions\TruthTable.h"
#include "Actions\Copy.h"
#include "Actions\Paste.h"
#include "Actions\Probing.h"



ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
void ApplicationManager::setIsValid(bool isValid)
{
	this->isValid = isValid;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
void ApplicationManager::SetCopiedComponent(Component* pComp) {
	copiedComp = pComp;
}

/* Returns the last copied/cut component */
Component* ApplicationManager::GetCopiedComponent() const {
	return copiedComp;
}
Component** ApplicationManager::getComponents()
{
	return CompList;
}
int ApplicationManager::getComponetsNumber()
{
	return CompCount;
}
//////////////////////////////////////////////////////////////////
Component* ApplicationManager::getSelectedComponent()
{
	return selectedComp;
}
void ApplicationManager::setSelectedComponent(Component* selectedComp)
{
	this->selectedComp = selectedComp;
}
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_INV:
			pAct = new AddNOTgate(this);
			break;
		
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		
		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNAND2gate2(this);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNOR3gate3(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new TruthTable(this);
			break;

		case ADD_XOR_GATE_3:
			pAct = new Paste(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new TruthTable(this);
			break;
		
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;

		case SIM_MODE:
			ExecuteAction(VALIDATION);
			if (isValid)
			{
				OutputInterface->CreateSimulationToolBar();
				pAct = new Simulate(this);
			}
			else
			{
				OutputInterface->PrintMsg("Invalid Circuit");
			}
			break;
		
		case DSN_MODE:
			OutputInterface->CreateDesignToolBar();
			UI.AppMode = DESIGN;
			break;
		case SELECT:
			pAct = new Select(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;
		
		case PASTE:
			pAct = new Paste(this);
			break;
		case Create_TruthTable:
			pAct = new Probing(this);
			break;
		case VALIDATION:
			pAct = new Validation(this);
			break;
	
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}