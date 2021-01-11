#include "Move.h"
#include "..\ApplicationManager.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{

}

Move::~Move(void)
{

}

void Move::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");
	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);
	//if (pManager->getComponetsNumber() > 0)
	//{
	//	//Print Action Message
	//	pOut->PrintMsg("Select source pin");

	//	//Wait for User Input
	//	pIn->GetPointClicked(x1, y1);

	//	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	//	{
	//		GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
	//		if (gfx.x1 <= x1 && gfx.x2 >= x1 && gfx.y1 <= y1 && gfx.y2 >= y1)
	//		{
	//			pOut->PrintMsg("Done");
	//			pIn->GetPointClicked(x2, y2);
	//			pManager->getComponents()[i]->setPosition(x2, y2);
	//			pManager->UpdateInterface();
	//			break;
	//		}
	//	}



	//}
	//GraphicsInfo gfx = pIn->getLastClick();
	//int mStartX,mStartY;
	//GraphicsInfo last = pIn->getLastClick();
	//mStartX = last.x1;
	//mStartY = last.y1;
	//int x = mStartX, prvX = x, dx = 0;
	//int y = mStartY, prvY = y, dy = 0;
	//pIn->GetButtonState(LEFT_BUTTON, x, y);

	//int minX = 0;
	//int maxX = UI.width;
	//int minY = UI.ToolBarHeight + 100;
	//int maxY = UI.height - UI.StatusBarHeight;


	//// Reading the mouse input from the user
	//while (pIn->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN) {

	//	if (x < minX || x > maxX) x = prvX;
	//	if (y < minY || y > maxY) y = prvY;

	//	dx = x - mStartX;
	//	dy = y - mStartY;

	//	if (x != prvX || y != prvY)
	//	{		
	//		GraphicsInfo prvCoord = pManager->getSelectedComponent()->getPosition();
	//		GraphicsInfo newCoord = prvCoord;
	//		newCoord.x1 += dx;
	//		newCoord.x2 += dx;
	//		newCoord.y1 += dy;
	//		newCoord.y2 += dy;

	//		pManager->getSelectedComponent()->setPosition(newCoord);
	//		prvX = x;
	//		prvY = y;
	//	}
	//	pOut->ClearDrawingArea();

	//	//pOut->UpdateScreen();
	//	pManager->UpdateInterface();
	//}
	////Clear Status Bar
	//pOut->ClearStatusBar();

}

void Move::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
}

void Move::Undo()
{

}

void Move::Redo()
{

}