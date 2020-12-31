#include "TruthTable.h"
TruthTable::TruthTable(ApplicationManager* pApp) : Action(pApp)
{

}

void TruthTable::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	TruthWindow = pOut->CreateWind(500, 500, 100, 100);
	TruthWindow->ChangeTitle("Truth Table");
	TruthWindow->DrawString(100, 0, "x");
}

void TruthTable::Execute()
{
	ReadActionParameters();
}

void TruthTable::Undo()
{

}

void TruthTable::Redo()
{

}

TruthTable::~TruthTable(void)
{

}