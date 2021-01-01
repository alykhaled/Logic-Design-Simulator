#pragma once
#include"Action.h"
#include "../ApplicationManager.h"
class Paste : public Action
{
private:
	Component* copiedComp;		// Pointer to the pasted component
	Action* Act;			// Add component action

public:
	/* Constructor */
	Paste(ApplicationManager* pApp);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Paste();
};
