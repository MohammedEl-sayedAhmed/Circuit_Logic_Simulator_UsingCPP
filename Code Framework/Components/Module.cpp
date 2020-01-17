#include "Module.h"
#include <iostream>

#include "AND2.h"
#include "BUFF1.h"
#include "INV1.h"
#include "NAND2.h"
#include "NOR2.h"
#include "OR2.h"
#include "XNOR2.h"
#include "XOR2.h"


using namespace std;

Module::Module(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut) :Component(pGfxInfo)
{
	//here add different gates and connections between them according to the module equation.
}

void Module::Operate()
{



	//The "operate" function inside the Module class should run the "operate" of each gate/connection to get the output from the input
//It is NOT valid to make its operate function just calculate the o/p using the module equation

	//caclulate the output status as the ANDing of the two input pins

}


// Function Draw
// Draws 5-input Module 
void Module::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawModule(*m_pGfxInfo, Selected);
}


//returns status of outputpin #n
int Module::GetOutPinStatus()
{
	return 0;
}
//returns status of outputpin #n
int Module::GetOutPinStatusS(int n)
{
	return moudule_OutputPin[n-1].getStatus();
}


//returns status of Inputpin #n
int Module::GetInputPinStatus(int n)
{
	return module_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Module::setInputPinStatus(int n, STATUS s)
{
	module_InputPins[n-1].setStatus(s);
}

//virtual type getter function
string Module::GetComponentType()
{
	return "Module";
}


//Checks whether the clicked point is in the region of the AND gate or not
bool Module::IsInRegion(int x, int y)
{
	
	if (x >= GetCornerDoX() && x <= (GetCornerDoX() + GetGateWidth()))
	{
		if (y >= GetCornerDoY() && y <= (GetCornerDoY() + GetGatHeight()))
		{
			
			cout << "Module is in region\n";
			return true;
		}
	}
	return false;
}

InputPin* Module::getComponentInput(int inputNumber) {
	return &module_InputPins[inputNumber];
}

OutputPin* Module::getComponentOutput(int inputNumber) {
	return &moudule_OutputPin[inputNumber];
}