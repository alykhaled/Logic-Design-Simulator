#include "TruthTable.h"
TruthTable::TruthTable(ApplicationManager* pApp) : Action(pApp)
{

}

void TruthTable::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	
	int inputRowsNum, inputColumnsNum;
	int ouputRowsNum, ouputColumnsNum;

	int componentsNum = pManager->getComponetsNumber();
	int ledscount = 0;
	int switchsCount = 0;

	Component** comp = pManager->getComponents();

	//Count the LEDs pointers
	for (int i = 0; i < componentsNum; i++)
	{
		if (dynamic_cast<LED*>(comp[i]))
		{
			ledscount++;
		}
	}

	//Count the Switchs pointers
	for (int i = 0; i < componentsNum; i++)
	{
		if (dynamic_cast<Switch*>(comp[i]))
		{
			switchsCount++;
		}
	}

	LED** leds = new LED * [ledscount];
	Switch** switchs = new Switch * [switchsCount];

	int c = 0;
	//Get the LEDs pointers
	for (int i = 0; i < componentsNum; i++)
	{
		if (dynamic_cast<LED*>(comp[i]))
		{
			leds[c] = dynamic_cast<LED*>(comp[i]);
			c++;
		}
	}

	c = 0;
	//Get the Switchs pointers
	for (int i = 0; i < componentsNum; i++)
	{
		if (dynamic_cast<Switch*>(comp[i]))
		{
			switchs[c] = dynamic_cast<Switch*>(comp[i]);
			c++;
		}
	}
	TruthWindow = pOut->CreateWind(500, 500, 100, 100);

	//TruthWindow = pOut->CreateWind(500, 500, 100, 100);
	TruthWindow->ChangeTitle("Truth Table");

	inputRowsNum = pow(2, switchsCount);
	inputColumnsNum = switchsCount;

	int** inputValues = new int* [inputRowsNum];
	for (int i = 0; i < inputRowsNum; i++)
	{
		inputValues[i] = new int[inputColumnsNum];
	}

	int value = 0;
	int m = 1;
	for (int i = inputColumnsNum -1; i >= 0; i--)
	{
		// for (int k = 0; k < m; k++)
		// {
		//     A[j][i] = value;
		//     j++;
		// }
		int filledRow = 0;
		while (filledRow != inputRowsNum)
		{
			for (int j = 0; j < m; j++)
			{
				inputValues[filledRow][i] = value;
				filledRow++;
			}
			value = (value == 0) ? 1 : 0;
		}
		m *= 2;
	}

	TruthWindow->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	TruthWindow->SetPen(UI.MsgColor);	
	int x = 20, y = 5;

	//Printing the values to the screen
	for (int i = 0; i < inputColumnsNum; i++)
	{
		TruthWindow->DrawString(x, y, switchs[i]->getLabel());
		x += 50;
	}

	y = 20;
	x = 20;
	for (int i = 0; i < inputRowsNum; i++)
	{
		for (int j = 0; j < inputColumnsNum; j++)
		{
			TruthWindow->DrawInteger(x, y, inputValues[i][j]);
			x += 50;
		}
		y += 20;
		x = 20;
	}
	x = 20;
	TruthWindow->DrawLine(20 + (50 * inputColumnsNum), 5, 20 + (50 * inputColumnsNum), 500);
	

	ouputRowsNum = pow(2, switchsCount);
	ouputColumnsNum = ledscount;

	int** ouputValues = new int* [ouputRowsNum];
	for (int i = 0; i < ouputRowsNum; i++)
	{
		ouputValues[i] = new int[ouputColumnsNum];
	}
	x = 20 + (50 * inputColumnsNum) + 10, y = 5;

	for (int i = 0; i < ouputColumnsNum; i++)
	{
		TruthWindow->DrawString(x, y, leds[i]->getLabel());
		x += 50;
	}

	x = 20 + (50 * inputColumnsNum) + 10, y = 5;
	y = 20;

	for (int i = 0; i < ouputRowsNum; i++)
	{
		for (int j = 0; j < inputColumnsNum; j++)
		{
			switchs[j]->getOutputPin()->setStatus(inputValues[i][j] == 0 ? LOW : HIGH);
		}
		Action* pAct = new Simulate(pManager);
		pAct->Execute();

		for (int j = 0; j < ouputColumnsNum; j++)
		{
			TruthWindow->DrawInteger(x, y, leds[j]->GetInputPinStatus(1) == HIGH ? 1 : 0);
			x += 50;
		}
		y += 20;
		x = 20 + (50 * inputColumnsNum) + 10;
	}

	int xs, ys;
	TruthWindow->WaitMouseClick(xs,ys);
	TruthWindow->~window();
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