#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
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

Component::Component()
{}

Component::~Component()
{}

