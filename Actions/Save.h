#pragma once
#include "Action.h"
#include "fstream"
using namespace std;
class Component;
class Save : public Action
{
private:
	ofstream fout;
	Component* comp;

public:
	/* Constructor */
	Save(ApplicationManager* pApp);



	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Save();
};

