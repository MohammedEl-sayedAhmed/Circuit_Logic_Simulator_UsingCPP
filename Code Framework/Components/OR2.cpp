#include "OR2.h"
#include <iostream>
using namespace std;

OR2::OR2(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,2, r_FanOut)
{

}


void OR2::Operate()
{
	//caclulate the output status as the ORing of the two input pins

	if (m_InputPins[0].getStatus() == HIGH || m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(HIGH);
	}
	else if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawOR2(*m_pGfxInfo, Selected);
}


//returns status of outputpin
int OR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string OR2::GetComponentType()
{
	return "OR2";
}

//Checks whether the clicked point is in the region of the OR gate or not
bool OR2::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{
			cout << "OR2 is in region\n";

			return true;
		}
	}
	return false;
}
