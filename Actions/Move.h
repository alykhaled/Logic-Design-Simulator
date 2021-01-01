#pragma once
#include "Action.h"
#include "../Defs.H"
#include "../GUI/UI_Info.h"
#include "../Components/LED.h"
#include "../ApplicationManager.h"
#include "../Components/Switch.h"
#include "../Components/Connection.h"
#include "../Components/Gate.h"
#include "Simulate.h"

class Move : public Action
{
public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};