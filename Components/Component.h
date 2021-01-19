#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "InputPin.h"

//Base class for classes Gate, Switch, and LED.
class InputPin;
class OutputPin;

class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int centerx, centery;	//The coordinates of the center 
	bool selected = false;	//Selection state
	bool on = false;		//ON/OFF state
	int id;					//the ID of the component
public:
	Component(const GraphicsInfo &r_GfxInfo, bool selected = false);
	virtual void Operate() = 0;							//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;				//for each component to Draw itself
	GraphicsInfo getPosition();							//Get the coordinates
	void setPosition(GraphicsInfo GfxInfo);				//Get the coordinates
	virtual int GetOutPinStatus()=0;					//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;				//returns status of Inputpin # n if SWITCH, return -1
	virtual GraphicsInfo getInputPinPosition(int n) = 0;//return the Input Pin position accoridng to number of pin
	virtual GraphicsInfo getOutputPinPosition() = 0;	//return the Output Pin position
	virtual InputPin* getInputPin(int n) = 0;			//return the Input Pin pointer accoridng to number of pin
	virtual OutputPin* getOutputPin() = 0;				//return the Input Pin pointer
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual int getNumInputs() = 0;						//return number of inputs
	void setLabel(string label);						//change the label of the component
	string getLabel();									//return the label of the component
	virtual void DrawLabel(Output* out);				//Draw the label
	virtual GraphicsInfo getCenter();					//return the center of the component
	virtual void setCenter(int cx, int cy);				//change the center of the component
	virtual void Select();								//change the state of the gate to selected
	virtual ActionType getType() = 0;					//return the type of the component
	virtual int getID();								//return the ID of the component
	virtual void setID(int id);							//change the ID of the component
	//virtual void save(ofstream &fout) = 0;
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
