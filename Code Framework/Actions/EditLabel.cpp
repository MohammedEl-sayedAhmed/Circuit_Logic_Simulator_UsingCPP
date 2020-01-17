#include "EditLabel.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "ActionSelect.h"
using namespace std;
#include <iostream>


EditLabel::EditLabel(ApplicationManager* pApp) : Action(pApp)
{

}

void EditLabel::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Checks if a component is selected
	if (pManager->GetSelectedComponent() == NULL)
	{
		pUI->PrintMsg("Please, select the component first to edit its label!");
		return;
	}

	//Get the selected component conrner on the GUI
	Component* pComp = pManager->GetSelectedComponent();


	//Print Action Message
	pUI->PrintMsg("Edit Label: Please, Type in a new label for the selected component");

	//Get user input, showing it in the status bar, and save it to a local variable "lbl"
	string lbl = pUI->GetSrting();

	//pUI->GetPtrWind()->DrawString(500, 500, lbl);

	//Set the new label to the selected component
	pComp->SetLabel(lbl);
	//cout << Cx << Cy << lbl << endl << pComp->GetComponentType();


	//Clear Status Bar
	pUI->ClearStatusBar();

	pManager->setSaved(false);
}
