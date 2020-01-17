#include "AddXORgate2.h"
#include "..\ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input XOR Gate: Click to add the gate");

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
	XOR2 *pA=new XOR2(pGInfo, XOR2_FANOUT);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddXORgate2::Undo()
{}

void AddXORgate2::Redo()
{}

