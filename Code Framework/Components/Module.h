#ifndef _MODULE_H
#define _MODULE_H

/*
  Class Module
  -----------
  represent the Module
*/

//#include "Gate.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include "..\UI\UI.h"
#include "..\ApplicationManager.h"

class Module : public Component
{


private:

	InputPin* module_InputPins;	//Array of input pins of the Module
	OutputPin* moudule_OutputPin;	//The Module output pin
	int module_Inputs;			//No. of input pins of that Module.
	int module_Outputs;			//No. of input pins of that Module.

	
public:

	Module(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut);
	virtual InputPin* getComponentInput(int inputNumber);
	virtual OutputPin* getComponentOutput(int inputNumber);


	//pins finders
	//virtual Point getInPinCoordinates();		//gets the location from which an input-connection should be drawn
	//virtual Point getOutPinCoordinates();		//gets the location from which an output-connection should be drawn


	virtual void Operate();	//Calculates the output of the Module 
	virtual void Draw(UI* );	//Draws 5-input Module

	virtual int GetOutPinStatus();
	virtual int GetOutPinStatusS(int n);	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual bool IsInRegion(int x, int y); //Checks whether the clicked point is in the region of the Module gate or not

	virtual string GetComponentType(); //virtual type getter function

};

#endif