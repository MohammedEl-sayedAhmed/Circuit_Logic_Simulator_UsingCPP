#include "SwitchModes.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

SwitchModes::SwitchModes(ApplicationManager *pApp):Action(pApp)
{
}

SwitchModes::~SwitchModes(void)
{
}

void SwitchModes::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	switch (pUI->GetAppMode())
	{
	case DESIGN:
		pUI->CreateSimulationToolBar();

		//Print Action Message
		pUI->PrintMsg("Simulation Mode Entered!");

		break;

	case SIMULATION:
		pUI->CreateDesignToolBar();

		//Print Action Message
		pUI->PrintMsg("Returned to Design Mode!");

		break;
	}
}

