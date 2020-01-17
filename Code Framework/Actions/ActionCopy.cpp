#include "ActionCopy.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
//#include "ActionSelect.h"
#include <iostream>

ActionCopy::ActionCopy(ApplicationManager* pApp) : Action(pApp)
{
	
}

ActionCopy::~ActionCopy(void)
{

}

void ActionCopy::Execute()
{	
	//ActionType act = SELECT; //creating a select action

	//pManager->ExecuteAction(act);

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print 1st Action Message
	pUI->PrintMsg("Click on a Component to be copied");

	//Get starting point of the connection while making sure a component is being selected
	pUI->GetPointClicked(Sx, Sy);
	Component* co = pManager->GetComponentByCordinates(Sx, Sy);
	//Component* co = pManager->GetSelectedComponent();
	pManager->SetTemporaryType(co->GetComponentType()); // a line to store the type of the component that needs to be copied
	//pManager->SetTemporaryComponent(*co);
	//Component* NewComp;
	
	//pManager->SetTemporaryComponent(co);



	//ActionSelect::Execute();
	/*
	/////////
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("click on a component to copy");
	
	**************************************************************************
			Add code here to get the click or the selected component
	**************************************************************************
	
	Component* c = pManager->GetSelectedComponent();
	pManager->;
	*/

	pManager->setSaved(false);
}