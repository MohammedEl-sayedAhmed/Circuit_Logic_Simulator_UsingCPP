#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddXNORgate2::~AddXNORgate2(void)
{
}

void AddXNORgate2::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input XNOR Gate: Click to add the gate");

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
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate
	
	pGInfo->PointsList[0].x = Cx - gateWidth/2;
	pGInfo->PointsList[0].y = Cy - gateHeight/2;
	pGInfo->PointsList[1].x = Cx + gateWidth/2;
	pGInfo->PointsList[1].y = Cy + gateHeight/2;
	XNOR2 *pA=new XNOR2(pGInfo, XNOR2_FANOUT);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddXNORgate2::Undo()
{}

void AddXNORgate2::Redo()
{}

