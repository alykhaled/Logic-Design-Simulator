#include "Copy.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"

/* Constructor */
Copy::Copy(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void Copy::ReadActionParameters() {
	
}

/* Executes action */
void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearStatusBar();
	pManager->SetCopiedComponent(pManager->getSelectedComponent());
	pOut->PrintMsg("Copied");
}

/* Undo action */
void Copy::Undo() {
}

/* Redo action */
void Copy::Redo() {
}

/* Destructor */
Copy::~Copy() {
}