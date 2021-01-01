#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND2::Operate()
{
	int ones = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
		{
			ones++;
		}
	}
	if (ones == 2)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType NAND2::getType() {
	return ADD_NAND_GATE_2;
}


// Function Draw
// Draws 2-input AND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo NAND2::getInputPinPosition(int n)
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x2 -= UI.NAND2_Width / 2;
	if (n == 1)
	{
		gfx.y2 -= 25;
	}
	else
	{
		gfx.y1 += 25;
	}

	return gfx;
}

GraphicsInfo NAND2::getOutputPinPosition()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.NAND2_Width / 2;
	return gfx;
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

