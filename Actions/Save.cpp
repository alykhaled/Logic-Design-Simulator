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
			GraphicsInfo center = pManager->getComponents()[i]->getCenter();
			ActionType type = pManager->getComponents()[i]->getType();
			string typecomp;
			switch (type)
			{
			case ADD_AND_GATE_2:
				typecomp = "AND2";
				break;

			case ADD_INV:
				typecomp = "NOT";
				break;

			case ADD_OR_GATE_2:
				typecomp = "OR2";
				break;

			case ADD_XOR_GATE_2:
				typecomp = "XOR2";
				break;

			case ADD_LED:
				typecomp = "LED";
				break;

			case ADD_XNOR_GATE_2:
				typecomp = "XNOR2";
				break;

			case ADD_NAND_GATE_2:
				typecomp = "NAND2";
				break;

			case ADD_NOR_GATE_3:
				typecomp = "NOR3";
				break;

			case ADD_AND_GATE_3:
				typecomp = "AND3";
				break;

			case ADD_XOR_GATE_3:
				typecomp = "XOR3";
				break;

			case ADD_NOR_GATE_2:
				typecomp = "NOR2";
				break;

			case ADD_Switch:
				typecomp = "SWITCH";
				break;

			default:
				break;
			}
			fout << typecomp << " " << pManager->getComponents()[i]->getID() << " " << ((pManager->getComponents()[i]->getLabel() == "") ? "$" : pManager->getComponents()[i]->getLabel()) << " " << center.x1 << " " << center.y1 << endl;
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