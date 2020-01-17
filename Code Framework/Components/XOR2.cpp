#include "XOR2.h"
#include <iostream>
using namespace std;

XOR2::XOR2(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,2, r_FanOut)
{
}


void XOR2::Operate()
{
	//caclulate the output status as the XORing of the two input pins

	if (m_InputPins[0].getStatus() == m_InputPins[1].getStatus()) {
		m_OutputPin.setStatus(LOW);
	}
	else if (m_InputPins[0].getStatus() != m_InputPins[1].getStatus()) {
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawXOR2(*m_pGfxInfo, Selected);
}


//returns status of outputpin
int XOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string XOR2::GetComponentType()
{
	return "XOR2";
}

//Checks whether the clicked point is in the region of the XOR gate or not
bool XOR2::IsInRegion(int x, int y)
{

	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{

			cout << "XOR2 is in region\n";
			return true;
		}
	}
	return false;
}
