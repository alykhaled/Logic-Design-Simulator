#pragma once
#include "Action.h"
class Cut : public Action
{
private:
				// The point clicked by the user
		// Pointer to the copied component

public:
	/* Constructor */
	Cut(ApplicationManager* pApp);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Cut();
};