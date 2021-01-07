#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"
#include "../Components/Gate.h"

AddConnection::AddConnection(ApplicationManager* pApp) : Action(pApp)
{

}

AddConnection::~AddConnection(void)
{

}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool goodsrc = false;
	if (pManager->getComponetsNumber() > 0)
	{
		//Print Action Message
		pOut->PrintMsg("Select source pin");

		//Wait for User Input
		pIn->GetPointClicked(Sx, Sy);

		for (int i = 0; i < pManager->getComponetsNumber(); i++)
		{
			GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
			if (gfx.x1 <= Sx && gfx.x2 >= Sx && gfx.y1 <= Sy && gfx.y2 >= Sy)
			{
				GraphicsInfo gfx1 = pManager->getComponents()[i]->getOutputPinPosition();
				if (gfx1.x1 <= Sx && gfx1.x2 >= Sx && gfx1.y1 <= Sy && gfx1.y2 >= Sy)
				{
					SrcPin = pManager->getComponents()[i]->getOutputPin();
					SrcPin->setComponent(pManager->getComponents()[i]);
					Gfx.x1 = gfx1.x2;
					Gfx.y1 = gfx1.y1 + 25;
					pOut->PrintMsg("Done, select the Destination");
					goodsrc = true;
					break;
				}
			}
		}

		if (!goodsrc)
		{
			SrcPin = NULL;
			DesPin = NULL;
			pOut->PrintMsg("Invalid Source");
			return;
		}

		pIn->GetPointClicked(Dx, Dy);
		for (int i = 0; i < pManager->getComponetsNumber(); i++)
		{
			GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
			if (gfx.x1 <= Dx && gfx.x2 >= Dx && gfx.y1 <= Dy && gfx.y2 >= Dy)
			{
				int numinput = pManager->getComponents()[i]->getNumInputs();
				for (int j = 1; j <= numinput; j++)
				{
					GraphicsInfo gfx1 = pManager->getComponents()[i]->getInputPinPosition(j);
					if (gfx1.x1 <= Dx && gfx1.x2 >= Dx && gfx1.y1 <= Dy && gfx1.y2 >= Dy)
					{
						Gfx.x2 = gfx1.x1;
						DesPin = pManager->getComponents()[i]->getInputPin(j);
						DesPin->setHasConnection(true);
						if (numinput == 1)
						{
							Gfx.y2 = gfx1.y1 + 25;
						}
						else if (numinput == 2)
						{
							if (j == 1)
							{
								Gfx.y2 = gfx1.y1 + 12;
							}
							else
							{
								Gfx.y2 = gfx1.y2 - 14;
							}
						}
						else
						{
							Gfx.y2 = gfx1.y1 + 25;

						}
						pOut->PrintInt(j);
						//pOut->PrintMsg("Done");
						gooddest = true;
						break;
					}
				}
			}
		}

		if (!gooddest)
		{
			SrcPin = NULL;
			DesPin = NULL;
			pOut->PrintMsg("Invalid Destination");
			return;
		}

	}
	else
	{
		SrcPin = NULL;
		DesPin = NULL;
		pOut->PrintMsg("There are No components yet");
	}


}

void AddConnection::Execute()
{
	ReadActionParameters();
	if (SrcPin != NULL && DesPin != NULL)
	{
		Connection* connection = new Connection(Gfx, SrcPin, DesPin);;
		SrcPin->ConnectTo(connection);
		pManager->AddComponent(connection);
	}
}

void AddConnection::Undo()
{

}

void AddConnection::Redo()
{

}