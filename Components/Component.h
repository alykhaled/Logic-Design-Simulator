#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "InputPin.h"
#include <fstream>
#include<string>
using namespace std;

//Base class for classes Gate, Switch, and LED.
class InputPin;
class OutputPin;

class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int centerx, centery;
	bool selected = false;
	bool on = false;
	int id;
	int ID;
	string typeComp, Label;
	GraphicsInfo GFX;
public:
	Component(const GraphicsInfo &r_GfxInfo, bool selected = false);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	GraphicsInfo getPosition();				//Get the coordinates
	void setPosition(GraphicsInfo GfxInfo);				//Get the coordinates
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual GraphicsInfo getInputPinPosition(int n) = 0;
	virtual GraphicsInfo getOutputPinPosition() = 0;
	virtual InputPin* getInputPin(int n) = 0;
	virtual OutputPin* getOutputPin() = 0;
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual int getNumInputs() = 0;
	void setLabel(string label);
	string getLabel();
	virtual void DrawLabel(Output* out);
	virtual GraphicsInfo getCenter();
	virtual void setCenter(int cx, int cy);
	virtual void Select();
	virtual ActionType getType() = 0;
	virtual int getID();
	virtual void setID(int id);
	virtual void savefunc(ofstream& fout) = 0;
	virtual void loadfunc(ifstream& fin) = 0;

	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
