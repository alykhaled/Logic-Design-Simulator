#include "Probing.h"

Probing::Probing(ApplicationManager* pApp) : Action(pApp) {

}

void Probing::ReadActionParameters() {

}

void Probing::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Click on the component to check its value");
	int x, y;
	//Wait for User Input
	pIn->GetPointClicked(x, y);

	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		if (dynamic_cast<Gate*>(pManager->getComponents()[i]))
		{
			GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
			if (gfx.x1 <= x && gfx.x2 >= x && gfx.y1 <= y && gfx.y2 >= y)
			{
				GraphicsInfo gfx1 = pManager->getComponents()[i]->getOutputPinPosition();
				if (gfx1.x1 <= x && gfx1.x2 >= x && gfx1.y1 <= y && gfx1.y2 >= y)
				{
					OutputPin* SrcPin = pManager->getComponents()[i]->getOutputPin();
					pOut->PrintInt(SrcPin->getStatus() == HIGH ? 1 : 0);
					break;
				}

				int numinput = pManager->getComponents()[i]->getNumInputs();
				for (int j = 1; j <= numinput; j++)
				{
					GraphicsInfo gfx1 = pManager->getComponents()[i]->getInputPinPosition(j);
					if (gfx1.x1 <= x && gfx1.x2 >= x && gfx1.y1 <= y && gfx1.y2 >= y)
					{
						InputPin* DesPin = pManager->getComponents()[i]->getInputPin(j);
						pOut->PrintInt(DesPin->getStatus() == HIGH ? 1 : 0);
						break;
					}
				}
			}
		}
		else if (dynamic_cast<Connection*>(pManager->getComponents()[i]))
		{
			Connection* conn = dynamic_cast<Connection*>(pManager->getComponents()[i]);
			GraphicsInfo gfx = conn->getPosition();
			if (gfx.x1 <= x && gfx.x2 >= x && (gfx.y1 - 5) <= y && (gfx.y2 + 5) >= y)
			{
				InputPin* DesPin = conn->getDestPin();
				pOut->PrintInt(DesPin->getStatus() == HIGH ? 1 : 0);
				break;
			}
		}
	}
}


void Probing::Undo() {
}


void Probing::Redo() {
}


Probing::~Probing() 
{

}