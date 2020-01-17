#include<iostream>
#include "Switch.h"
using namespace std;

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Switch::Switch(GraphicsInfo* pGfxInfo, int r_FanOut) :Component(pGfxInfo), m_OutputPin(r_FanOut)
{
	ref_factor_out[0] = 0;
	ref_factor_out[1] = 3;

	ref_factor_in[0] = 0;
	ref_factor_in[1] = 4;

	m_OutputPin = NCON;
	closed = false;
}

void Switch::Operate()
{
	//caclulate the output status of the switch
	if (closed)
	{
		this->m_OutputPin.setStatus(HIGH);
	}

	else if (!closed)
	{
		this->m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws the led
void Switch::Draw(UI* pUI)
{
	//Call output class and pass led drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, Selected, closed);
}


//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return closed;
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return closed;
}

//Set status of an input pin ot HIGH or LOW


//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	if (s == 0)
		this->closed = 0;

	if (s == 1)
		this->closed = 1;
}

//virtual type getter function
string Switch::GetComponentType()
{
	return "Switch";
}

OutputPin* Switch::getComponentOutput()
{
	return &m_OutputPin;
}

//Checks whether the clicked point is in the region of the AND gate or not
bool Switch::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{

			//cout << "Switch is in region\n";
			return true;
		}
	}
	return false;
}
