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
	//Operate the output of the switch and gates
	OutputPin* outpin;
	GraphicsInfo gfx;
	int c = 0;
	//for (int i = 0; i < switchscount; i++)
	//{
	//	outpin = switchs[i]->getOutputPin();
	//	Connection* conn;
	//	InputPin* inpin;
	//	do
	//	{
	//		int numOfConnection = outpin->getNumberOfConnections();
	//		for (int j = 1; j < numOfConnection+1; j++)
	//		{
	//			Connection* connection = outpin->getConnenction(j);
	//			conn->Operate();
	//			inpin = connection->getDestPin();
	//			Component* gate = inpin->getComponent();
	//			//InputPin* inpinnn = gate->getInputPin(1);
	//			gate->Operate();
	//			outpin = gate->getOutputPin();
	//		}
	//				
	//	} while (outpin != nullptr);
	//	
	//}


	for (int i = 0; i < switchscount; i++)
	{
		outpin = switchs[i]->getOutputPin();
		Connection* conn;
		InputPin* inpin;
		
		//do
		//{
		//	int numOfConnection = outpin->getNumberOfConnections();
		//	for (int j = 1; j < numOfConnection + 1; j++)
		//	{
		//		Connection* connection = outpin->getConnenction(j);
		//		connection->Operate();
		//		inpin = connection->getDestPin();
		//		Component* gate = inpin->getComponent();
		//		//InputPin* inpinnn = gate->getInputPin(1);
		//		gate->Operate();
		//		outpin = gate->getOutputPin();
		//	}
		//} while (outpin != nullptr);
		
		int numOfConnection = outpin->getNumberOfConnections();
		for (int j = 1; j < numOfConnection + 1; j++)
		{
			Connection* connection = outpin->getConnenction(j);
			simulate(outpin, connection);
		}
	}

}

//Recursion Function to simulate every connection
void Simulate::simulate(OutputPin* outpin, Connection* connection)
{
	OutputPin *newpin;
	if (outpin == nullptr && connection->getOutputPin() == nullptr)
	{
		return;
	}

	connection->Operate();
	InputPin * inpin = connection->getDestPin();
	Component* gate = inpin->getComponent();
	//InputPin* inpinnn = gate->getInputPin(1);
	gate->Operate();
	newpin = gate->getOutputPin();

	if (newpin == nullptr)
	{
		return;
	}

	int numOfConnection = newpin->getNumberOfConnections();

	for (int i = 0; i < numOfConnection; i++)
	{
		Connection* connectionnn = newpin->getConnenction(i+1);
		simulate(newpin, connectionnn);
	}
	return;
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

