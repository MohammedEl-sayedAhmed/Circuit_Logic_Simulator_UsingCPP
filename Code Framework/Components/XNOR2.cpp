#include "XNOR2.h"
#include <iostream>
using namespace std;

XNOR2::XNOR2(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,2, r_FanOut)
{
}


void XNOR2::Operate()
{
	//caclulate the output status as the XNORing of the two input pins

	if (m_InputPins[0].getStatus() == m_InputPins[1].getStatus()) {
		m_OutputPin.setStatus(HIGH);
	}
	else if (m_InputPins[0].getStatus() != m_InputPins[1].getStatus()) {
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 2-input XNOR gate
void XNOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawXNOR2(*m_pGfxInfo, Selected);
}


//returns status of outputpin
int XNOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string XNOR2::GetComponentType()
{
	return "XNOR2";
}

//Checks whether the clicked point is in the region of the XNOR gate or not
bool XNOR2::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{

			cout << "XNOR2 is in region\n";
			return true;
		}
	}
	return false;
}
