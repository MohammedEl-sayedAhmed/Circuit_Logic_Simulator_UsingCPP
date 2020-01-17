#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut):Component(pGfxInfo), m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
	{
		m_InputPins[i].setComponent(this);
		m_InputPins[i].SetPinNumber(i + 1);
	}
	m_OutputPin.SetAttachedComponent(this);
}

InputPin* Gate::getComponentInput(int inputNumber)
{
	return &m_InputPins[inputNumber];
}

OutputPin* Gate::getComponentOutput()
{
	return &m_OutputPin;
}

//Default definition for AND Gates
Point Gate::getOutPinCoordinates()
{
	Point p;
	p.x = this->GetCornerDoX() + this->GetGateWidth();
	p.y = this->GetCornerDoY() + this->GetGatHeight() / 2 + 1;
	return p;
}


Point Gate::getInPinCoordinates()
{
	Point p;
	p.x = this->GetCornerDoX();
	p.y = this->GetCornerDoY() + this->GetGatHeight() / 2 - 6.5;
	return p;
}