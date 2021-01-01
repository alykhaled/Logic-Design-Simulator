#pragma once
#include "Action.h"
#include "../Components/Component.h"
class Copy : public Action
{
private:
	int mX, mY;				// The point clicked by the user
	Component* mComp;		// Pointer to the copied component

public:
	/* Constructor */
	Copy(ApplicationManager* pApp);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Copy();
	};