#include "SelectConnection.h"
#include "..\ApplicationManager.h"
using namespace std;
#include <iostream>

SelectConnection::SelectConnection(ApplicationManager *pApp):Action(pApp)
{
}

SelectConnection::~SelectConnection(void)
{
}

void SelectConnection::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print 1st Action Message
	pUI->PrintMsg("Select Connection: Click on a Component to select as the source of the connection");

	//Get starting point of the connection while making sure a component is being selected
	pUI->GetPointClicked(Sx, Sy);
	Component* Src_ptr = pManager->GetComponentByCordinates(Sx, Sy);
	while (Src_ptr == nullptr)
	{
		pUI->PrintMsg("Please, make sure you click on a component!");
		pUI->GetPointClicked(Sx, Sy);
		Src_ptr = pManager->GetComponentByCordinates(Sx, Sy);
	}

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Print 2ndAction Message
	pUI->PrintMsg("Select Connection: Click on a Component to select as the Destination of the connection");
	
	//* Get ending point of the connection while making sure that:
	//- a component is being selected
	//- a component has at least one empty input pin
	//- the user did not select the same gate selected as source gate
	pUI->GetPointClicked(Ex, Ey);
	Component* Dest_ptr = pManager->GetComponentByCordinates(Ex, Ey);
	while (Dest_ptr == nullptr || Dest_ptr->GetGuide() == BOTH || Dest_ptr == Src_ptr)
	{
		if (Dest_ptr == nullptr)
		{
			pUI->PrintMsg("Please, make sure you click on a component!");
			pUI->GetPointClicked(Ex, Ey);
			Dest_ptr = pManager->GetComponentByCordinates(Ex, Ey);
		}

		else if (Dest_ptr->GetGuide() == BOTH)
		{
			pUI->PrintMsg("Select Connection: Can't Take more Inputs! .. Please, Select Another One");
			pUI->GetPointClicked(Ex, Ey);
			Dest_ptr = pManager->GetComponentByCordinates(Ex, Ey);
		}

		else if (Dest_ptr == Src_ptr)
		{
			pUI->PrintMsg("Select Connection: Can't Connect the Gate to itself! .. Please, Select Another One");
			pUI->GetPointClicked(Ex, Ey);
			Dest_ptr = pManager->GetComponentByCordinates(Ex, Ey);
		}
	}

	//Clear Status Bar
	pUI->ClearStatusBar();
	cout << Src_ptr->GetRefFactorOut(0) << Src_ptr->GetRefFactorOut(1) << endl;
	//Updating Points Values
	Sx = Src_ptr->getOutPinCoordinates(Src_ptr->GetRefFactorOut(0)).x;
	Sy = Src_ptr->getOutPinCoordinates(Src_ptr->GetRefFactorOut(1)).y;


	Ex = Dest_ptr->getInPinCoordinates(Dest_ptr->GetRefFactorIn(0)).x;

	switch (Dest_ptr->GetGuide())
	{
	case NON:
		Ey = Dest_ptr->getInPinCoordinates(Dest_ptr->GetRefFactorIn(1)).y;
		//update Guide enum for the component depending on its type
		if(Dest_ptr->GetComponentType() == "BUFF1" || Dest_ptr->GetComponentType() == "INV1")
			Dest_ptr->SetGuide(BOTH);
		else
			Dest_ptr->SetGuide(ONE);
		break;
	case ONE:
		Ey = Dest_ptr->getInPinCoordinates(Dest_ptr->GetRefFactorIn(1)).y + pUI->GetPinsDist();
		Dest_ptr->SetGuide(BOTH);
		break;
	case TWO:
		Ey = Dest_ptr->getInPinCoordinates(Dest_ptr->GetRefFactorIn(1)).y;
		Dest_ptr->SetGuide(BOTH);
		break;
	}

	//Calculate the rectangle Corners
	int horizontal = abs (Ex - Sx);
	int vertical = abs (Ey - Sy);
	
	GraphicsInfo * pGInfo= new GraphicsInfo(4); //Gfx info to be used to construct the connection
	
	pGInfo->PointsList[0].x = Sx;
	pGInfo->PointsList[0].y = Sy;

	pGInfo->PointsList[1].x = Sx + 25;
	pGInfo->PointsList[1].y = Sy;

	pGInfo->PointsList[2].x = Ex - 25;
	pGInfo->PointsList[2].y = Ey;

	pGInfo->PointsList[3].x = Ex;
	pGInfo->PointsList[3].y = Ey;
	//// A code needs to be added here to pass the correct outputpin and inputpin to the connection 
	OutputPin* pOutputPinConnection = nullptr;
	InputPin* pInputPinConnection = nullptr;

	Connection *pA=new Connection(pGInfo, pOutputPinConnection, pInputPinConnection);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void SelectConnection::Undo()
{}

void SelectConnection::Redo()
{}

