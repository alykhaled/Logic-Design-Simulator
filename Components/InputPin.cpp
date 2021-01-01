#include "InputPin.h"

InputPin::InputPin()
{}
//GHJHKH
void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::setHasConnection(bool hasConnection)
{
	this->hasConnection = hasConnection;
}

bool InputPin::getHasConnection()
{
	return hasConnection;
}
