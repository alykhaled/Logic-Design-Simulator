#pragma once
#include "Component.h"
#include "InputPin.h"
class LED: public Component
{
private:
	InputPin m_InputPin;
	bool on = false;
public:
	LED(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual ActionType getType();
	virtual string getName();
	virtual GraphicsInfo getCenter();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual GraphicsInfo getInputPinPosition(int n);
	virtual GraphicsInfo getOutputPinPosition();
	virtual OutputPin* getOutputPin();
	virtual InputPin* getInputPin(int n);
	virtual int getNumInputs();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void savefunc(ofstream& fout);
	virtual void loadfunc(ifstream& fin);
};




