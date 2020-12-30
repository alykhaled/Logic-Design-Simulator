#include "Select.h"
#include "../ApplicationManager.h"

Select::Select(ApplicationManager* pApp) : Action(pApp)
{

}

void Select::ReadActionParameters()
{

}

void Select::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	GraphicsInfo gfx1 = pIn->getLastClick();
	if (pManager->getComponetsNumber() > 0)
	{
		for (int i = 0; i < pManager->getComponetsNumber(); i++)
		{
			GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
			if (gfx.x1 <= gfx1.x1 && gfx.x2 >= gfx1.x1 && gfx.y1 <= gfx1.y1 && gfx.y2 >= gfx1.y2)
			{
				pManager->getComponents()[i]->Select();
			}
		}
	}
}

void Select::Undo()
{

}

void Select::Redo()
{

}

Select::~Select(void)
{

}

