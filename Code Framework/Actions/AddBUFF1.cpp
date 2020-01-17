#include "AddBUFF1.h"
#include "..\ApplicationManager.h"

AddBUFF1::AddBUFF1(ApplicationManager *pApp):Action(pApp)
{
}

AddBUFF1::~AddBUFF1(void)
{
}

void AddBUFF1::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Buffer: Click to add the gate");

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
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Buffer gate
	
	pGInfo->PointsList[0].x = Cx - gateWidth/2;
	pGInfo->PointsList[0].y = Cy - gateHeight/2;
	pGInfo->PointsList[1].x = Cx + gateWidth/2;
	pGInfo->PointsList[1].y = Cy + gateHeight/2;
	BUFF1 *pA=new BUFF1(pGInfo, BUFF1_FANOUT);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddBUFF1::Undo()
{}

void AddBUFF1::Redo()
{}

