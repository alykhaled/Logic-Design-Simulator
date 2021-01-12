#pragma once
#include "Component.h"
#include "OutputPin.h"

class Switch :
	public Component
{
private:
	OutputPin m_OutputPin;
	bool on = false;
public:
	Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual ActionType getType();
	virtual string getName();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual GraphicsInfo getInputPinPosition(int n);
	virtual GraphicsInfo getOutputPinPosition();
	virtual OutputPin* getOutputPin();
	virtual InputPin* getInputPin(int n);
	virtual void setInputPinStatus(int n, STATUS s);
	virtual int getNumInputs();	//set status of Inputpin # n, to be used by connection class.
	virtual void Select();
	virtual void savefunc(ofstream& fout);
	virtual void loadfunc(ifstream& fin);

};





