#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo, bool selected)
{
	m_GfxInfo = r_GfxInfo;	
	this->selected = selected;
}

GraphicsInfo Component::getPosition()
{
	return m_GfxInfo;
}

void Component::setPosition(int Cx, int Cy)
{
	//Gfx info to be used to construct the AND2 gate
	int yup, ybot;
	yup = Cy / 100;
	yup *= 100;
	yup += 30;

	ybot = Cy / 100;
	ybot *= 100;
	ybot += 80;

	if (abs((Cy - yup)) > abs(Cy - ybot))
	{
		m_GfxInfo.y1 = ybot;
		Cy = ybot;
	}
	else
	{
		m_GfxInfo.y1 = yup;
		Cy = yup;
	}

	m_GfxInfo.x1 = Cx - 50 / 2;
	m_GfxInfo.x2 = Cx + 50 / 2;
	m_GfxInfo.y1 = Cy - 83 / 2;
	m_GfxInfo.y2 = Cy + 83 / 2;
}

void Component::setLabel(string label)
{
	m_Label = label;
}

string Component::getLabel()
{
	return m_Label;
}

void Component::Select()
{
	selected = (UI.AppMode == DESIGN) ? !selected : selected;
}

int Component::getID()
{
	return id;
}

void Component::setID(int id)
{
	this->id = id;
}

Component::Component()
{}

Component::~Component()
{}

