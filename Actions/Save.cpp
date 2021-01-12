#include "Save.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"
#include "../Components/Gate.h"
#include "../Components/Connection.h"


/* Constructor */
Save::Save(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void Save::ReadActionParameters() {

}

/* Executes action */
void Save::Execute()
{
	fout.open("savedFolder.txt");
	int numOfGates = 0;
	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		if (!dynamic_cast<Connection*>(pManager->getComponents()[i]))
		{
			numOfGates++;
		}
	}

	fout << numOfGates << endl;

	for (int i = 0; i < pManager->getComponetsNumber(); i++) {
		if (!dynamic_cast<Connection*>(pManager->getComponents()[i]))
		{
			pManager->getComponents()[i]->savefunc(fout);
			
		}
	}

	fout << "Connections" << endl;
	
	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		if (dynamic_cast<Connection*>(pManager->getComponents()[i])) 
		{
			Connection* conn = dynamic_cast<Connection*>(pManager->getComponents()[i]);
			int srcID = conn->getSourcePin()->getComponent()->getID();
			int DesID = conn->getDestPin()->getComponent()->getID();
			fout << srcID << " " << DesID << " " << conn->getDestPin()->getPinNum() << endl;
		}
	}
	fout << "-1" << endl;
	pManager->GetOutput()->PrintMsg("File saved successfully...");
	fout.close();

}

/* Undo action */
void Save::Undo() {
}

/* Redo action */
void Save::Redo() {
}

/* Destructor */
Save::~Save() {
}