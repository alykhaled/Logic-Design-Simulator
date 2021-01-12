#pragma once
#include "Action.h"
#include"../ApplicationManager.h"
class DeleteAction : public Action
{
	public:
		DeleteAction(ApplicationManager* pApp);
		virtual ~DeleteAction(void);
		//Reads parameters required for action to execute
		virtual void ReadActionParameters() ;

		//Execute action (code depends on action type)
		virtual void Execute() ;

		//To undo this action (code depends on action type)
		virtual void Undo() ;

		//To redo this action (code depends on action type)
		virtual void Redo() ;

};

