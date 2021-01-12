#include "Switch.h"

Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Component(r_GfxInfo) , m_OutputPin(r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Switch::Operate()
{
	
}
ActionType Switch::getType() {
	return ADD_Switch;
}
string Switch::getName()
{
	return "Switch";
}

// Function Draw
// Draws 2-input AND gate
void Switch::Draw(Output* pOut)
{
	/*GraphicsInfo border = m_GfxInfo;
	border.x1 -= 5;
	border.x2 += 5;
	border.y1 -= 5;
	border.y2 += 5;
	pOut->DrawRectangle(border);*/

	if (UI.AppMode == DESIGN)
	{
		pOut->DrawSwitch(m_GfxInfo, selected, false);
	}
	else
	{
		if (on)
		{
			pOut->DrawSwitch(m_GfxInfo, false, on);
		}
		else
		{
			pOut->DrawSwitch(m_GfxInfo, false, false);
		}
	}
	//Call output class and pass gate drawing info to it.
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return -1;
}
GraphicsInfo Switch::getInputPinPosition(int n)
{
	return GraphicsInfo();
}
GraphicsInfo Switch::getOutputPinPosition()
{
	return m_GfxInfo;
}

OutputPin* Switch::getOutputPin()
{
	return &m_OutputPin;
}
InputPin* Switch::getInputPin(int n)
{
	return nullptr;
}
//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	
}

int Switch::getNumInputs()
{
	return 0;
}

void Switch::Select()
{
	if (UI.AppMode == DESIGN)
	{
		selected = !selected;
	}
	else
	{
		on = !on;
		m_OutputPin.setStatus((m_OutputPin.getStatus() == LOW) ? HIGH : LOW);
	}
}
