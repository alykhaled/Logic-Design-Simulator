#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "../Components/Connection.h"
class Edit : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int Sx, Sy, Dx, Dy;
	OutputPin* SrcPin;
	InputPin* DesPin;
	GraphicsInfo Gfx;
	bool goodsrc = false, gooddest = false;
	bool mSelected = false;
public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
