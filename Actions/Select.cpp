#include "Select.h"
#include "../ApplicationManager.h"
#include "Simulate.h"

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
			if (dynamic_cast<Connection*>(pManager->getComponents()[i]))
			{
				if (gfx.x1 <= gfx1.x1 && gfx.x2 >= gfx1.x1)
				{
					if ((gfx.y1 - 7) < gfx1.y1 && (gfx.y1 + 7) > gfx1.y1)
					{
						pManager->getComponents()[i]->Select();
						pManager->setSelectedComponent(pManager->getComponents()[i]);
						break;
					}
				}
				else if ((gfx.x2 - 7) <= gfx1.x1 && (gfx.x2 + 7) >= gfx1.x1)
				{
					if ((gfx.y1 > gfx.y2) && gfx.y2 < gfx1.y1 && gfx.y1 > gfx1.y1)
					{
						pManager->getComponents()[i]->Select();
						pManager->setSelectedComponent(pManager->getComponents()[i]);
						break;
					}
					else if ((gfx.y1 < gfx.y2) && gfx.y2 > gfx1.y1 && gfx.y1 < gfx1.y1)
					{
						pManager->getComponents()[i]->Select();
						pManager->setSelectedComponent(pManager->getComponents()[i]);
						break;
					}
				}
			}
			else if (gfx.x1 <= gfx1.x1 && gfx.x2 >= gfx1.x1 && gfx.y1 <= gfx1.y1 && gfx.y2 >= gfx1.y1)
			{
				pManager->getComponents()[i]->Select();
				pManager->setSelectedComponent(pManager->getComponents()[i]);
				if (dynamic_cast<Switch*>(pManager->getComponents()[i]) && UI.AppMode == SIMULATION)
				{
					pOut->PrintInt((pManager->getComponents()[i]->GetOutPinStatus() == HIGH) ? 1 : 0);
					Action* pAct = new Simulate(pManager);
					pAct->Execute();
					//pManager->ExecuteAction(SIM_MODE);
					break;
				}
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

