#include "ActionExit.h"
#include "..\ApplicationManager.h"
#include "..\\UI\UI.h"

ActionExit::ActionExit(ApplicationManager *pApp):Action(pApp)
{
}

ActionExit::~ActionExit(void)
{
}

void ActionExit::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Do you want to exit? Y/N");
	//User choics wheteher it is yes or no 
	string userExitChoice = pUI->GetSrting();
	if (userExitChoice == "Y") {
		pManager->ExitFlag = 1;
		if (pManager->isSaved() == 0) {
			pUI->PrintMsg("Your current windows is not saved. Do you want to save it first? Y/N");
			string userSaveChoice = pUI->GetSrting();
			if (userSaveChoice == "Y") {

				pManager->ExecuteAction(SAVE);
			}
		}

		pManager->ClearCompList();
		pUI->ClearDrawingArea();
		//pManager->ExecuteAction(EXIT);
	}
	else {
		pUI->ClearStatusBar();
	}
}


