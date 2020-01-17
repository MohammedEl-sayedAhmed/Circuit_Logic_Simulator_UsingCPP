#include "AddModule.h"
#include "..\ApplicationManager.h"

AddModule::AddModule(ApplicationManager *pApp):Action(pApp)
{
}

AddModule::~AddModule(void)
{
}

void AddModule::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Module: Click to add the module");

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
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Led
	
	pGInfo->PointsList[0].x = Cx - gateWidth/2;
	pGInfo->PointsList[0].y = Cy - gateHeight/2;
	pGInfo->PointsList[1].x = Cx + gateWidth/2;
	pGInfo->PointsList[1].y = Cy + gateHeight/2;
	Module *pA=new Module(pGInfo,5, Led_FANOUT);
	pManager->AddComponent(pA);
	pManager->setSaved(false);
}

void AddModule::Undo()
{}

void AddModule::Redo()
{}

