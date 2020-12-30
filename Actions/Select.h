#pragma once
#include "Action.h"
#include "../Components/Switch.h"

class Select : public Action
{
private:
	int x, y;
public:
	Select(ApplicationManager* pApp);
	virtual ~Select(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

