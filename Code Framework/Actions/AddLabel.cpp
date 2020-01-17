/*#include "AddLabel.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "ActionSelect.h"


AddLabel::AddLabel(ApplicationManager* pApp) : Action(pApp)
{

}

void AddLabel::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Checks if a component is selected
	if (pManager->GetSelectedComponent() == NULL)
	{

		pUI->PrintMsg("Please, select the component to be labeled first!");
		return;
	}

	//Get the selected component conrner
	Component* pComp = pManager->GetSelectedComponent();
	
	if (pComp->GetLabel == NULL)
	{
		pUI->PrintMsg("This component is labeled already! Choose the (Edit Label) Tool!");
		return;
	}

	Cx = pComp->GetCornerDoX();
	Cy = pComp->GetCornerDoY() + 50;

	//Print Action Message
	pUI->PrintMsg("Add Label: Please, Type in a new label for the selected component");

	//Get user input, showing it in the status bar, and save it to a local variable "lbl"
	string lbl = pUI->GetSrting();

	//Set the new label to the selected component
	pComp->SetLabel(lbl);

	//Add the new label to the GUI
	pUI->DrawLabel(Cx, Cy, lbl);

	//Clear Status Bar
	pUI->ClearStatusBar();
}*/
