#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate : public Component
{
protected:

	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;			//No. of input pins of that Gate.

public:

	Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut);
	virtual InputPin* getComponentInput(int inputNumber);
	virtual OutputPin* getComponentOutput();
	//pure virtual type getter function
	virtual string GetComponentType() = 0;

	//pins finders
	virtual Point getInPinCoordinates();		//gets the location from which an input-connection should be drawn
	virtual Point getOutPinCoordinates();		//gets the location from which an output-connection should be drawn

};

#endif
