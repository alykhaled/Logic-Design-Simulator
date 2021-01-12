#include"LED.h"


LED::LED(const GraphicsInfo& r_GfxInfo) :Component(r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPin.setComponent(this);
	m_InputPin.setPinNum(1);
}


void LED::Operate()
{
	
}

ActionType LED::getType() {
	return ADD_LED;
}
string LED::getName()
{
	return "LED";
}
GraphicsInfo LED::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.LED_Height / 2;
	gfx.y1 += UI.LED_Height / 2;
	return gfx;
}

// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut)
{
	on = (m_InputPin.getStatus() == HIGH) ? true : false;
	if (UI.AppMode == DESIGN)
	{
		pOut->DrawLED(m_GfxInfo, selected, false);
	}
	else
	{
		pOut->DrawLED(m_GfxInfo, false, on);
	}
	//Call output class and pass gate drawing info to it.
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

	return m_GfxInfo;
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

int LED::getNumInputs()
{
	return 1;
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}
