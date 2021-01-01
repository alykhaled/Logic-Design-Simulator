#pragma once
#include "Action.h"
#include "..\GUI\Output.h"
#include "../ApplicationManager.h"

class Validation : public Action
{
private:
	bool valid = true;
public:
	Validation(ApplicationManager* pApp);
	virtual ~Validation(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	bool isValid();
	virtual void Undo();
	virtual void Redo();


};


