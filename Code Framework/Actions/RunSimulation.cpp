#include "RunSimulation.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

RunSimulation::RunSimulation(ApplicationManager *pApp):Action(pApp)
{
}

RunSimulation::~RunSimulation(void)
{
}

void RunSimulation::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Running Simulation...");

	/*
	//Print 1st Action Message
	pUI->PrintMsg("RunSimulation: Please Select the output to Evaluate");

	int X, Y;
	pUI->GetPointClicked(X, Y);
	Component* Sel_ptr = pManager->GetComponentByCordinates(X, Y);
	while (Sel_ptr == nullptr || Sel_ptr->GetComponentType() != "Led")
	{
		if (Sel_ptr != nullptr)
		{
			pUI->PrintMsg("Only LED's can be selected for this!");
			return;
		}
		pUI->PrintMsg("Please, make sure you click on a component!");
		pUI->GetPointClicked(X, Y);
		Sel_ptr = pManager->GetComponentByCordinates(X, Y);
	}

	Sel_ptr->Operate();
	*/

	int cnt = pManager->GetComponentsCount();
	Component** CompListptr = pManager->GetComponentList();

	for (int i = 0; i < cnt ; i++)
	{
		for (int i = 0; i < cnt; i++)
		{
			CompListptr[i]->Operate();
		}

	}

}

