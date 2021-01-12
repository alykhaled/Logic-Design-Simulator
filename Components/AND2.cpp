#include "AND2.h"
#include "Component.h"


AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == LOW)
		{
			m_OutputPin.setStatus(LOW);
			break;
		}
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType AND2::getType()
{
	return ADD_AND_GATE_2;
}

// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo,selected);

}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

GraphicsInfo AND2::getInputPinPosition(int n)
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x2 -= UI.AND2_Width / 2;
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

GraphicsInfo AND2::getOutputPinPosition()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.AND2_Width / 2;
	return gfx;
}
void AND2::savefunc(ofstream& fout)
{
	fout << "AND2" << " " << id << " " << ((getLabel() == "") ? "$" : getLabel()) << " " << centerx<< " " << centery << endl;

}

//void AND2::loadfunc(ifstream& fin)
{
	//fin>>typeComp>>
}
