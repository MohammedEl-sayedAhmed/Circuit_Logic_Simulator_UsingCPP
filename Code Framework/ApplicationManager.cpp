#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddLed.h"
#include "Actions\AddINV1.h"
#include "Actions\AddBUFF1.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddNORgate2.h"
#include "Actions\ActionExit.h"
#include "Actions/AddConnection.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionDelete.h"
#include "Actions/AddModule.h"
#include "Actions/Save.h"
//#include "Actions/AddLabel.h"
#include "Actions/EditLabel.h"
#include "Actions/ActionCopy.h"
#include "Actions/ActionCut.h"
#include "Actions/ActionPaste.h"
#include "Actions/SwitchModes.h"
#include "Actions/RunSimulation.h"
#include "Actions/Truth.h"
#include "Actions/Load.h"
#include "Actions/ActionSwitch.h"


#include <iostream>
using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}



////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
	//StaticCompCount++;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to action type create its relevant object
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;

	case ADD_Switch:
		pAct = new AddSwitch(this);
		break;

	case ADD_LED:
		pAct = new AddLed(this);
		break;

	case ADD_Buff:
		pAct = new AddBUFF1(this);
		break;

	case ADD_INV:
		pAct = new AddINV1(this);
		break;


	case ADD_CONNECTION:
		//TODO: Create AddConection Action here
		pAct = new AddConnection(this);
		break;

	/*case ADD_LABEL:
		//TODO: Create AddLabel Action here
		pAct = new AddLabel(this);
		break;*/

	case EDIT_LABEL:
		//TODO: Create AddLabel Action here
		pAct = new EditLabel(this);
		break;

	case SELECT:
		//TODO : Create Select Action here
		pAct = new ActionSelect(this);
		break;

	case DEL:
		//TODO: Create Delete Action here
		pAct = new ActionDelete(this);
		break;

	case PASTE:
		pAct = new ActionPaste(this);
		break;

	case SAVE:
		//TODO: Create Save Action here
		pAct = new Save(this);
		break;

	case EXIT:
		pAct = new ActionExit(this);
		break;

	case COPY:
		pAct = new ActionCopy(this);
		break;
	case CUT:
		pAct = new ActionCut(this);
		break;

	case ADD_MODULE:
		pAct = new AddModule(this);
		break;

	case LOAD:
		pAct = new Load(this);
		break;

	case SWITCH_MODES:
		pAct = new SwitchModes(this);
		break;

	case TRUTH:
		pAct = new Truth(this);
		break;

	case RUN_SIM:
		pAct = new RunSimulation(this);
		break;

	case Change_Switch:
		pAct = new ActionSwitch(this);
		break;

	}




	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}


////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Draw(pUI);
		
		int Cx = CompList[i]->GetCornerDoX();
		int Cy = CompList[i]->GetCornerDoY() + 50;
		pUI->DrawLabel(Cx, Cy, CompList[i]->GetLabel());
	}

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetComponent(int index)
{

	return CompList[index];
}
////////////////////////////////////////////////////////////////////
int ApplicationManager::GetComponentsCount()
{
	return CompCount;
};

////////////////////////////////////////////////////////////////////
void ApplicationManager::SetComponentsCount(int NewCount)
{
	CompCount = NewCount;
};

////////////////////////////////////////////////////////////////////

void ApplicationManager::AddComponentAtIndex(Component* pComp , int index)
{
	CompList[index] = pComp;
	CompCount++;
}


////////////////////////////////////////////////////////////////////
Component** ApplicationManager::GetComponentList()
{
	return CompList;
}


////////////////////////////////////////////////////////////////////

bool ApplicationManager::isSaved() {
	return Saved;

}

void ApplicationManager::setSaved(bool newSavedState) {

	Saved = newSavedState;
}

void ApplicationManager::ClearCompList() {
	for (int i = 0; i < CompCount; i++) {
		delete CompList[i];
	}
	CompCount = 0;
}

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;

}

Component* ApplicationManager::GetComponentByCordinates(int x, int y)
{
	for (int i = CompCount - 1; i >= 0; i--) {

		if (CompList[i] != 0) {

			if (CompList[i]->IsInRegion(x, y)) {

				return CompList[i];
			}
		}
	}
	return nullptr;
}

Component* ApplicationManager::GetSelectedComponent()
{
	for (int i = CompCount - 1; i >= 0; i--) {

		if (CompList[i] != 0) {

			if (CompList[i]->IsSelected()) {

				return CompList[i];
			}
		}
	}
	return nullptr;
}

void ApplicationManager::DeselectAllComponents()
{
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelected(false);
	}
}

int ApplicationManager::GetSelectedCount() {
	int SelectedCount = 0;

	for (int i = 0; i < CompCount; i++) {

		if (CompList[i]->IsSelected()) {
			SelectedCount++;
		}
	}
	return SelectedCount;
}

void ApplicationManager::SetSelectedCount(int newSelectedCount) {

	SelectedCount = newSelectedCount;


}


void ApplicationManager::SetTemporaryComponent(Component& component)
{
	*Temporary = component;
}

Component* ApplicationManager::GetTemporaryComponent()
{
	return Temporary;
}

void ApplicationManager::SetTemporaryType(string type)
{
	TemporaryType = type;
}

string ApplicationManager::GetTemporaryType()
{
	return TemporaryType;
}

/*void ApplicationManager::ResetIDs() {
	// re-assigns IDs
	for (int i = 0; i < CompCount; i++)
		CompList[i]->SetID(i + 1);
}*/