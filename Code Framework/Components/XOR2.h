#ifndef _XOR2_H
#define _XOR2_H

/*
  Class XOR2
  -----------
  represent the 2-input XOR gate
*/

#include "Gate.h"
#include "..\UI\UI.h"
#include "..\ApplicationManager.h"

class XOR2 : public Gate
{

private:

public:

	XOR2(GraphicsInfo *r_pGfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(UI* );	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual bool IsInRegion(int x, int y); //Checks whether the clicked point is in the region of the XOR gate or not

	virtual string GetComponentType();	//virtual type getter function

};

#endif