#include "INV1.h"
#include <iostream>
using namespace std;

INV1::INV1(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,1, r_FanOut)
{
	ref_factor_out[0] = 0;
	ref_factor_out[1] = 0;

	ref_factor_in[0] = 0;
	ref_factor_in[1] = 0;
}


void INV1::Operate()
{
	//caclulate the output status as the Inverting of the two input pins

	if (m_InputPins[0].getStatus() == LOW) {
		m_OutputPin.setStatus(HIGH);
	}
	else if (m_InputPins[0].getStatus() == HIGH) {
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 1-input Inverter gate
void INV1::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawINV1(*m_pGfxInfo, Selected);
}


//returns status of outputpin
int INV1::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV1::GetInputPinStatus(int n)
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV1::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string INV1::GetComponentType()
{
	return "INV1";
}

//Checks whether the clicked point is in the region of the INV gate or not
bool INV1::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{

			cout << "INV1 is in region\n";
			return true;
		}
	}
	return false;
}
