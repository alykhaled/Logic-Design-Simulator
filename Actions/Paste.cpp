#include "Paste.h"

/* Constructor */
Paste::Paste(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void Paste::ReadActionParameters() {
}

/* Executes action */
void Paste::Execute() {
	Output* pOut = pManager->GetOutput();
	copiedComp = pManager->GetCopiedComponent();
	pManager->ExecuteAction(pManager->getActionType());
}

/* Undo action */
void Paste::Undo() {

}

/* Redo action */
void Paste::Redo() {

}

/* Destructor */
Paste::~Paste() {
}