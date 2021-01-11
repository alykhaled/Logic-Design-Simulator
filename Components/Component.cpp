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

void Component::setPosition(GraphicsInfo GfxInfo)
{
	this->m_GfxInfo = GfxInfo;
}

void Component::setLabel(string label)
{
	m_Label = label;
}

string Component::getLabel()
{
	return m_Label;
}

GraphicsInfo Component::getCenter()
{
	GraphicsInfo gfx;
	gfx.x1 = centerx;
	gfx.y1 = centery;

	return gfx;
}

void Component::DrawLabel(Output* out)
{
	GraphicsInfo labelPos = m_GfxInfo;
	labelPos.y1 -= 20;
	out->DrawString(labelPos, m_Label);
	
}

void Component::setCenter(int cx,int cy)
{
	centerx = cx;
	centery = cy;
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

