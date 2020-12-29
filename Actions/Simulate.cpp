#include "Simulate.h"

Simulate::Simulate(ApplicationManager* pApp) : Action(pApp)
{

}

void Simulate::ReadActionParameters()
{
	
}

void Simulate::Execute()
{
	UI.AppMode = SIMULATION;
	Output* pOut = pManager->GetOutput();
	pOut->CreateSimulationToolBar();
	
	int componentsNum = pManager->getComponetsNumber();
	int ledscount = 0;
	int switchscount = 0;
	
	Component** comp = pManager->getComponents();
	LED** leds = new LED*[componentsNum];
	Switch** switchs = new Switch *[componentsNum];
	
	//Get the LEDs pointers
	for (int i = 0; i < componentsNum; i++)
	{
		if (dynamic_cast<LED*>(comp[i]))
		{
			leds[ledscount] = dynamic_cast<LED*>(comp[i]);
			ledscount++;
		}
	}
	
	//Get the Switchs pointers
	for (int i = 0; i < componentsNum; i++)
	{
		if (dynamic_cast<Switch*>(comp[i]))
		{
			switchs[switchscount] = dynamic_cast<Switch*>(comp[i]);
			switchscount++;
		}
	}
	;
	//Operate the output of the switch and gates
	OutputPin* outpin;
	GraphicsInfo gfx;
	int c = 0;
	for (int i = 0; i < switchscount; i++)
	{
		outpin = switchs[i]->getOutputPin();
		InputPin* inpin;
		do
		{
			Connection* conn = outpin->getConnenction(1);
			conn->Operate();
			inpin = conn->getDestPin();
			Component* gate = inpin->getComponent();
			gate->Operate();
			outpin = gate->getOutputPin();		
		} while (outpin != nullptr);
		
	}
	LED* led = leds[0];
	InputPin* inpinn = led->getInputPin(0);
}

void Simulate::Undo()
{

}

void Simulate::Redo()
{

}

Simulate::~Simulate(void)
{

}

