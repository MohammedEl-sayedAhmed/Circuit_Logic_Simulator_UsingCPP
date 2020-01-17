#include "Led.h"
#include <iostream>
using namespace std;

//Led Constructor
//Parameters:
//r_Inputs: no. of led's input pins = 1
//r_FanOut: Fan out of the led's output pin
Led::Led(GraphicsInfo* pGfxInfo, int r_Inputs):Component(pGfxInfo)
{
	ref_factor_out[0] = 0;
	ref_factor_out[1] = 5;

	ref_factor_in[0] = 0;
	ref_factor_in[1] = 6;

	illum = false;

	//Allocate number of input pins (equals r_Inputs) = 1
	r_Inputs = 1;
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that led
	
	//Associate all input pins to this led
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

InputPin* Led::getComponentInput(int inputNumber)
{
	return &m_InputPins[inputNumber];
}

void Led::Operate()
{
	//caclulate the output status of the led
	if (GetInputPinStatus(1) == LOW)
	{
		illum = 0;
	}

	else if (GetInputPinStatus(1) == HIGH)
	{
		illum = 1;
	}
	//Add you code here
}


// Function Draw
// Draws the led
void Led::Draw(UI* pUI)
{
	//Call output class and pass led drawing info to it.
	pUI->DrawLed(*m_pGfxInfo, Selected, illum);
}


//returns status of outputpin
int Led::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int Led::GetInputPinStatus(int n)
{
	n = 1;
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Led::setInputPinStatus(int n, STATUS s)
{
	n = 1;
	m_InputPins[n - 1].setStatus(s);
}

//virtual type getter function
string Led::GetComponentType()
{
	return "Led";
}

//Checks whether the clicked point is in the region of the AND gate or not
bool Led::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{

			//cout << "Led is in region\n";
			return true;
		}
	}
	return false;
}
