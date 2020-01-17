#include "AddNORgate2.h"
#include "..\ApplicationManager.h"

AddNORgate2::AddNORgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddNORgate2::~AddNORgate2(void)
{
}

void AddNORgate2::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input NOR Gate: Click to add the gate");

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
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the NOR2 gate
	
	pGInfo->PointsList[0].x = Cx - gateWidth/2;
	pGInfo->PointsList[0].y = Cy - gateHeight/2;
	pGInfo->PointsList[1].x = Cx + gateWidth/2;
	pGInfo->PointsList[1].y = Cy + gateHeight/2;
	NOR2 *pA=new NOR2(pGInfo, NOR2_FANOUT);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddNORgate2::Undo()
{}

void AddNORgate2::Redo()
{}

