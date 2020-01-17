#ifndef _LED_H
#define _LED_H

/*
  Class Led
  -----------
  - Each Led has one inputs pins and no output pin
*/


#include "InputPin.h"
#include "Component.h"

class Led : public Component
{
protected:

	InputPin* m_InputPins;	//Array of input pins of the Led
	int m_Inputs;		//No. of input pins of that Led.
	bool illum;

public:

	Led(GraphicsInfo* pGfxInfo, int r_Inputs);

	virtual void Operate();	//Calculates the output of the led; whether it is on or off
	virtual void Draw(UI*);	//Draws the led

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual InputPin* getComponentInput(int inputNumber);

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual bool IsInRegion(int x, int y); //Checks whether the clicked point is in the region of the AND gate or not
	//virtual type getter function
	virtual string GetComponentType();
};

#endif
