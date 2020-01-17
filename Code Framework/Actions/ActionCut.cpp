#include "ActionCut.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "ActionCopy.h"

ActionCut::ActionCut(ApplicationManager* pApp) : Action(pApp)
{

}

ActionCut::~ActionCut(void)
{

}

void ActionCut::Execute()
{
	UI* pUI = pManager->GetUI();
	//Print 1st Action Message
	pUI->PrintMsg("Click on a Component to be cut");

	//Get starting point of the connection while making sure a component is being selected
	pUI->GetPointClicked(Sx, Sy);
	Component* co = pManager->GetComponentByCordinates(Sx, Sy);
	//Component* co = pManager->GetSelectedComponent();
	pManager->SetTemporaryType(co->GetComponentType());
	//ActionType act = COPY; //creating a copy action
	co->SetSelected(true);
	//pManager->ExecuteAction(COPY);
	//pManager->ExecuteAction(act);
	//this->Temp = pManager->GetSelectedComponent();
	//pManager->SetTemporaryComponent(Temp);
	///// Call delete Action here /////
	//ActionType act2 = DEL; // creating a delete action
	pManager->ExecuteAction(DEL);
	pManager->setSaved(false);

}