#include "INVERTER.h"

INVERTER::INVERTER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INVERTER::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	else {
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType INVERTER::getType() {
	return ADD_INV;
}
string INVERTER::getName()
{
	return "Inverter";
}
GraphicsInfo INVERTER::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.NOT_Height / 2;
	gfx.y1 += UI.NOT_Height / 2;
	return gfx;
}


// Function Draw
// Draws 2-input AND gate
void INVERTER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINV(m_GfxInfo,selected);
}

//returns status of outputpin
int INVERTER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INVERTER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo INVERTER::getInputPinPosition(int n)
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x2 -= UI.NOT_Width / 2;
	return gfx;
}

GraphicsInfo INVERTER::getOutputPinPosition()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.NOT_Width / 2;
	return gfx;
}

//Set status of an input pin ot HIGH or LOW
void INVERTER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void INVERTER::savefunc(ofstream& fout)
{
	fout << "INVERTER" << " " << id << " " << ((getLabel() == "") ? "$" : getLabel()) << " " << centerx<<" "<< centery << endl;

}
