#ifndef _SWITCH_H
#define _SWITCH_H

/*
  Class Switch
  -----------
  - Each switch has no inputs pins and one output pin
*/


#include "OutputPin.h"
#include "Component.h"

class Switch :public Component
{
protected:
	
	bool closed;
	OutputPin m_OutputPin;	//The Gate output pin
	
public:
	Switch(GraphicsInfo* pGfxInfo,int r_FanOut);

	virtual void Operate();	//Calculates the output of the led; whether it is on or off
	virtual void Draw(UI*);	//Draws the switch

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual  OutputPin* getComponentOutput();

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	
	virtual bool IsInRegion(int x, int y); //Checks whether the clicked point is in the region of the AND gate or not
	//virtual type getter function
	virtual string GetComponentType() ;
};

#endif
