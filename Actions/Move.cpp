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
	GraphicsInfo gfx = pIn->getLastClick();

	int x = gfx.x1, prvX = x, dx = 0;
	int y = gfx.y1, prvY = y, dy = 0;

	while (pIn->GetMouseState(LEFT_BUTTON, x, y) == BUTTON_DOWN) {


		if (x != prvX || y != prvY) {

			dx = x - gfx.x1;
			dy = y - gfx.y1;
			GraphicsInfo prvCoord = pManager->getSelectedComponent()->getPosition();

			pManager->getSelectedComponent()->setPosition(x,y);
			prvX = x;
			prvY = y;
		}
		pOut->ClearDrawingArea();

		pOut->UpdateScreen();
		pManager->UpdateInterface();
	}
	//Clear Status Bar
	pOut->ClearStatusBar();

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