#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Component; //Forward class declaration
class Connection;
class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	int pinnum;
	bool hasConnection = false;
	Connection* m_Connection;
public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	void setPinNum(int num);
	int getPinNum();
	Component* getComponent();	//returns the component of this input pin
	void setHasConnection(bool hasConnection);
	bool getHasConnection();
	void setConnection(Connection* C);
	Connection* getConnection();
	void DeleteConnection();
};

#endif