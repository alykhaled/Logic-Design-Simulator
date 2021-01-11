#pragma once
#include "Action.h"
#include "fstream"
using namespace std;
class Load :public Action
{
private:
	ifstream fin;

public:
	/* Constructor */
	Load(ApplicationManager* pApp);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Load();
};

