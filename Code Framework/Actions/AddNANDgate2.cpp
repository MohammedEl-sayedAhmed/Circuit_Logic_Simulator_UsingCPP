#include "AddNANDgate2.h"
#include "..\ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddNANDgate2::~AddNANDgate2(void)
{
}

void AddNANDgate2::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input NAND Gate: Click to add the gate");

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
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the NAND2 gate
	
	pGInfo->PointsList[0].x = Cx - gateWidth/2;
	pGInfo->PointsList[0].y = Cy - gateHeight/2;
	pGInfo->PointsList[1].x = Cx + gateWidth/2;
	pGInfo->PointsList[1].y = Cy + gateHeight/2;
	NAND2 *pA=new NAND2(pGInfo, NAND2_FANOUT); 
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddNANDgate2::Undo()
{}

void AddNANDgate2::Redo()
{}

