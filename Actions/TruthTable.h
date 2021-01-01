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

class TruthTable : public Action
{
private:
	window* TruthWindow;
public:
	TruthTable(ApplicationManager* pApp);
	virtual ~TruthTable(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};