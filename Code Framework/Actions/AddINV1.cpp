#include "AddINV1.h"
#include "..\ApplicationManager.h"

AddINV1::AddINV1(ApplicationManager *pApp):Action(pApp)
{
}

AddINV1::~AddINV1(void)
{
}

void AddINV1::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Inverter: Click to add the gate");

	//Get Center point of the Gate while making sure it is outside toolbar area
	pUI->GetPointClicked(Cx, Cy);
	while (Cy < (pUI->getGateHeight()) * 2.75)
	{
		pUI->PrintMsg("Please click on the drawing area!");
		pUI->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pUI->ClearStatusBar();	
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Inverter gate
	
	pGInfo->PointsList[0].x = Cx - gateWidth/2;
	pGInfo->PointsList[0].y = Cy - gateHeight/2;
	pGInfo->PointsList[1].x = Cx + gateWidth/2;
	pGInfo->PointsList[1].y = Cy + gateHeight/2;
	INV1 *pA=new INV1(pGInfo, INV1_FANOUT);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddINV1::Undo()
{}

void AddINV1::Redo()
{}

