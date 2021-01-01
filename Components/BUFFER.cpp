#include "BUFFER.h"


BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFFER::Operate()
{
		if (m_InputPins[0].getStatus() == HIGH)
		{
			m_OutputPin.setStatus(HIGH);
		}
		else {
			m_OutputPin.setStatus(LOW);
		}
}

ActionType BUFFER::getType() {
	return ADD_Buff;
}


// Function Draw
// Draws 2-input AND gate
void BUFFER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuff(m_GfxInfo);
}

//returns status of outputpin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo BUFFER::getInputPinPosition(int n)
{
	return GraphicsInfo();
}

GraphicsInfo BUFFER::getOutputPinPosition()
{
	return GraphicsInfo();
}

//Set status of an input pin ot HIGH or LOW
void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
