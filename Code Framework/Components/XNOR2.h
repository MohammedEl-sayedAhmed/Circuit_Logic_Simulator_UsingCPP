#ifndef _XNOR2_H
#define _XNOR2_H

/*
  Class XNOR2
  -----------
  represent the 2-input XNOR gate
*/

#include "Gate.h"
#include "..\UI\UI.h"
#include "..\ApplicationManager.h"

class XNOR2 : public Gate
{

private:

	/*ApplicationManager* pManager;
	UI* pUI = pManager->GetUI();
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();*/


public:

	XNOR2(GraphicsInfo *r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XNOR gate
	virtual void Draw(UI* );	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual bool IsInRegion(int x, int y); //Checks whether the clicked point is in the region of the XNOR gate or not

	//virtual type getter function
	virtual string GetComponentType();
};

#endif