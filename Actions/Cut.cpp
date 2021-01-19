#include "Cut.h"
#include "../GUI/Input.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"

/* Constructor */
Cut::Cut(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void Cut::ReadActionParameters() {

}

/* Executes action */
void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearStatusBar();
	pManager->SetCopiedComponent(pManager->getSelectedComponent());
	pManager->setActionType(pManager->getSelectedComponent()->getType());
	pManager->ExecuteAction(DEL);
	pOut->PrintMsg("Done!");
}

/* Undo action */
void Cut::Undo() {
}

/* Redo action */
void Cut::Redo() {
}

/* Destructor */
Cut::~Cut() {
}
