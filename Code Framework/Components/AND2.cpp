#include "AND2.h"
#include <iostream>
using namespace std;

AND2::AND2(GraphicsInfo *r_pGfxInfo, int r_FanOut):Gate(r_pGfxInfo,2, r_FanOut)
{

}

void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	if (m_InputPins[0].getStatus()== LOW || m_InputPins[1].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
	else if(m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawAND2(*m_pGfxInfo, Selected);
}


//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string AND2::GetComponentType()
{
	return "AND2";
}


//Checks whether the clicked point is in the region of the AND gate or not
bool AND2::IsInRegion(int x, int y)
{
	
	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{
			
			cout << "AND2 is in region\n";
			return true;
		}
	}
	return false;
}
