#pragma once
#include "action.h"
#include "..\GUI\Output.h"

class InputPin;
class OutputPin;

class AddConnection : public Action
{
private:
	int Sx, Sy, Dx, Dy;
	OutputPin* SrcPin;
	InputPin* DesPin;
	GraphicsInfo Gfx;
	bool goodsrc = false, gooddest = false;
	bool mSelected = false;

public:
	AddConnection(ApplicationManager* pApp);
	AddConnection(ApplicationManager* pApp,GraphicsInfo Gfx, OutputPin* SrcPin, InputPin* DesPin,int pinnum);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

