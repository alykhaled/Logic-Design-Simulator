#include "InputPin.h"

InputPin::InputPin()
{}
//GHJHKH
void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

void InputPin::setPinNum(int num)
{
	pinnum = num;
}

int InputPin::getPinNum()
{
	return pinnum;
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
void InputPin::setConnection(Connection* C)
{
	m_Connection = C;
}

Connection* InputPin::getConnection()
{
	return m_Connection;
}

void InputPin::DeleteConnection()
{
	delete m_Connection;
}

