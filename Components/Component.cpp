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

Component::Component()
{}

Component::~Component()
{}

