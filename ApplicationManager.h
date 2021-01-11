#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

class Input;
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	bool isValid = true;		
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* selectedComp;
	Component* copiedComp;
	Action* undoAction;

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

public:	
	ApplicationManager(); //constructor

	void setIsValid(bool isValid);

	/* Sets the last copied/cut component */
	void SetCopiedComponent(Component* pComp);

	/* Returns the last copied/cut component */
	Component* GetCopiedComponent() const;

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	Component* getSelectedComponent();
	void setSelectedComponent(Component* selectedComp);

	Component** getComponents();
	int getComponetsNumber();
	//destructor
	~ApplicationManager();
};

#endif