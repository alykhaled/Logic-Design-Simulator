#include "Connection.h"

//Connection::Connection(const GraphicsInfo& r_GfxInfo, Component* pS, Component* pD, int Pin)
//{
//	SrcCmpnt = pS;
//	DstCmpnt = pD;
//}

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin) :Component(r_GfxInfo)

{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}

ActionType Connection::getType() {
	return ActionType::ADD_CONNECTION;
}

void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}

InputPin* Connection::getInputPin(int n)
{
	return nullptr;
}

OutputPin* Connection::getOutputPin()
{
	return nullptr;
}

GraphicsInfo Connection::getInputPinPosition(int n)
{
	return GraphicsInfo();
}

GraphicsInfo Connection::getOutputPinPosition()
{
	return GraphicsInfo();
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	if (DstPin->getStatus() == HIGH)
	{
		on = true;
	}
	else
	{
		on = false;
	}
	pOut->DrawConnection(m_GfxInfo,selected,on);
}

GraphicsInfo Connection::getCenter()
{
	return GraphicsInfo();
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

int Connection::getNumInputs()
{
	return 1;
}
