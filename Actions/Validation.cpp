#include "Validation.h"
#include "../Components/Gate.h"
#include "../Components/Switch.h"
#include "../Components/LED.h"

Validation::Validation(ApplicationManager* pApp) : Action(pApp)
{

}

Validation::~Validation(void)
{

}

void Validation::ReadActionParameters()
{

}

void Validation::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getComponetsNumber() > 0)
	{
		for (int i = 0; i < pManager->getComponetsNumber(); i++)
		{
			Component* comp = pManager->getComponents()[i];
			if (dynamic_cast<Gate*>(comp))
			{
				if (comp->getOutputPin()->getNumberOfConnections() == 0)
				{
					valid = false;
					break;
				}
				int numinput = pManager->getComponents()[i]->getNumInputs();
				for (int j = 1; j <= numinput; j++)
				{
					if (!comp->getInputPin(j)->getHasConnection())
					{
						valid = false;
						break;
					}
				}
			}

			if (dynamic_cast<Switch*>(comp))
			{
				if (comp->getOutputPin()->getNumberOfConnections() == 0)
				{
					valid = false;
					break;
				}
			}

			if (dynamic_cast<LED*>(comp))
			{
				if (!comp->getInputPin(1)->getHasConnection())
				{
					valid = false;
					break;
				}
			}

		}
	}
	else
	{
		valid = false;
		pOut->PrintMsg("There are No components yet");
	}
	pManager->setIsValid(valid);
}

bool Validation::isValid()
{
	return valid;
}

void Validation::Undo()
{

}

void Validation::Redo()
{

}