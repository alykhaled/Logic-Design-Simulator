#include "Xor2.h"
Xor2::Xor2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Xor2::Operate()
{
	int count = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
		{
			count++;
		}
	}
	if (count % 2 == 0)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType Xor2::getType() {
	return ADD_XOR_GATE_2;
}
string Xor2::getName()
{
	return "Xor2";
}
GraphicsInfo Xor2::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.XOR2_Width / 2;
	gfx.y1 += UI.XOR2_Height / 2;
	return gfx;
}


// Function Draw
// Draws 3-input AND gate
void Xor2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo);
}

//returns status of outputpin
int Xor2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int Xor2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo Xor2::getInputPinPosition(int n)
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x2 -= UI.XOR2_Width / 2;
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

GraphicsInfo Xor2::getOutputPinPosition()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.XOR2_Width / 2;
	return gfx;
}

//Set status of an input pin ot HIGH or LOW
void Xor2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void Xor2::savefunc(ofstream& fout)
{
	fout << "Xor2" << " " << id << " " << ((getLabel() == "") ? "$" : getLabel()) << "" << centerx<<" " << centery << endl;

}

