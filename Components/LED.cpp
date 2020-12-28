#include"LED.h"


LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Component(r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
	
}



// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(m_GfxInfo);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}

//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo LED::getInputPinPosition(int n)
{
	return GraphicsInfo();
}

GraphicsInfo LED::getOutputPinPosition()
{
	return GraphicsInfo();
}

OutputPin* LED::getOutputPin()
{
	return nullptr;
}
InputPin* LED::getInputPin(int n)
{
	return &m_InputPin;
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}
