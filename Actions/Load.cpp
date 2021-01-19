#include "Load.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"
#include "../Components/Connection.h"
#include "AddANDgate2.h"
#include "AddNAND2gate2.h"
#include "AddORgate2.h"
#include "AddNOR3gate3.h"
#include "AddXORgate2.h"
#include "AddNORgate2.h"
#include "AddXOR3gate3.h"
#include "AddXNORgate2.h"
#include "AddAND3gate3.h"
#include "AddNOTgate.h"
#include "AddConnection.h"
#include "AddSwitch.h"
#include "AddLED.h"

/* Constructor */
Load::Load(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void Load::ReadActionParameters() {

}

/* Executes action */
void Load::Execute()
{
	fin.open("savedFolder.txt");

	if (fin.is_open())
	{

	}
	OutputPin* SrcPin;
	InputPin* DesPin;
	string typecomp,label;
	
	int count,id, x, y;
	fin >> count;
	for (int i = 0; i < count; i++)
	{
		fin >> typecomp;
		fin >> id;
		fin >> label;
		GraphicsInfo position;
		fin >> position.x1;
		fin >> position.y1;
		if (typecomp == "AND2") {
			AND2* obj = new AND2(position, 5);
			obj->setCenter(position.x1, position.y1);
			obj->setLabel(label);
			AddANDgate2* ss = new AddANDgate2(pManager, obj);
		}
		else if (typecomp == "NOT") {

		}
		else if (typecomp == "OR2") {

		}
		else if (typecomp == "XOR2") {

		}
		else if (typecomp == "LED") {
			LED* obj = new LED(position);
			obj->setCenter(position.x1, position.y1);
			obj->setLabel(label);
			AddLED* ss = new AddLED(pManager, obj);
		}
		else if (typecomp == "XNOR2") {

		}
		else if (typecomp == "NAND2") {

		}
		else if (typecomp == "NOR3") {

		}
		else if (typecomp == "AND3") {

		}
		else if (typecomp == "XOR3") {

		}
		else if (typecomp == "NOR2") {
			NOR2* obj = new NOR2(position, 5);
			obj->setCenter(position.x1, position.y1);
			obj->setLabel(label);
			AddNORgate2* ss = new AddNORgate2(pManager, obj);
		}
		else if (typecomp == "SWITCH") {
			
			Switch* obj = new Switch(position,5);
			obj->setCenter(position.x1, position.y1);
			obj->setLabel(label);
			AddSwitch* ss = new AddSwitch(pManager,obj);
		}
	}
	fin >> typecomp;
	int src = 0, des, pinnum;

	while (fin >> src,src != -1) {
		GraphicsInfo Gfx;
		fin >> des;
		fin >> pinnum;
		for (int i = 0; i < pManager->getComponetsNumber(); i++)
		{
			if (!dynamic_cast<Connection*>(pManager->getComponents()[i]))
			{
				if (pManager->getComponents()[i]->getID() == src)
				{
					SrcPin = pManager->getComponents()[i]->getOutputPin();
					Gfx.x1 = pManager->getComponents()[i]->getPosition().x2;
					Gfx.y1 = pManager->getComponents()[i]->getPosition().y1 + 25;
				}
				else if (pManager->getComponents()[i]->getID() == des)
				{
					Gfx.x2 = pManager->getComponents()[i]->getPosition().x1;
					DesPin = pManager->getComponents()[i]->getInputPin(pinnum);
					DesPin->setHasConnection(true);
					if (pManager->getComponents()[i]->getNumInputs() == 1)
					{
						Gfx.y2 = pManager->getComponents()[i]->getPosition().y1 + 25;
					}
					else if (pManager->getComponents()[i]->getNumInputs() == 2)
					{
						if (pinnum == 1)
						{
							Gfx.y2 = pManager->getComponents()[i]->getPosition().y1 + 12;
						}
						else
						{
							Gfx.y2 = pManager->getComponents()[i]->getPosition().y2 - 14;
						}
					}
					else
					{
						Gfx.y2 = pManager->getComponents()[i]->getPosition().y1 + 25;

					}
				}
			}
		}

		AddConnection* ss = new AddConnection(pManager,Gfx,SrcPin, DesPin, pinnum);
	}

	pManager->GetOutput()->ClearDrawingArea();
	pManager->GetOutput()->PrintMsg("File loaded successfully...");
	fin.close();
}

/* Undo action */
void Load::Undo() {
}

/* Redo action */
void Load::Redo() {
}

/* Destructor */
Load::~Load() {
}