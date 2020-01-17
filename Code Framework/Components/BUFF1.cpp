#include "BUFF1.h"
#include <iostream>
using namespace std;

BUFF1::BUFF1(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,1, r_FanOut)
{
	ref_factor_out[0] = 0;
	ref_factor_out[1] = 0;

	ref_factor_in[0] = 0;
	ref_factor_in[1] = 0;
}


void BUFF1::Operate()
{
	//caclulate the output status as the Buffering of the one input pins

	if (m_InputPins[0].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
	else if (m_InputPins[0].getStatus() == HIGH) {
		m_OutputPin.setStatus(HIGH);
	}
}

// Function Draw
// Draws 1-input Buffer gate
void BUFF1::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawBUFF1(*m_pGfxInfo, Selected);
}


//returns status of outputpin
int BUFF1::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF1::GetInputPinStatus(int n)
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF1::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string BUFF1::GetComponentType()
{
	return "BUFF1";
}


//Checks whether the clicked point is in the region of the BUFF gate or not
bool BUFF1::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{

			cout << "BUFF1 is in region\n";
			return true;
		}
	}
	return false;
}
