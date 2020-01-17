#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
//#include "..\ApplicationManager.h"
//Base class for classes Gate, Switch, and LED.
//class ApplicationManager;

class Component
{
private:

	string m_Label;
	IN_GUIDE Guide;			//Input pins guide for multiple inputs gates
	//static int StaticID;
	int ID;
	//ApplicationManager* pManager;

protected:
	bool Selected;
	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	//GraphicsInfo* connect_pGfxInfo;	//The parameters required to draw a connection

	UI* pGateUIInfo;
	int ref_factor_out[2];			//A factor used to adjust the pins locations of each gates due to small differences
	int ref_factor_in[2];

public:

	Component(GraphicsInfo *r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself


	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual InputPin* getComponentInput(int inputNumber);
	virtual OutputPin* getComponentOutput();


	virtual bool IsInRegion(int x, int y); // bokra han5leha pure
	bool IsSelected();
	void SetSelected(bool selected);


	int GetCornerDoX();
	int GetCornerDoY();

	int GetGateWidth();
	int GetGatHeight();

	virtual Point getOutPinCoordinates(int refinement_factor);
	virtual Point getInPinCoordinates(int refinement_factor);

	//pure virtual type getter function
	virtual string GetComponentType() = 0;

	string GetLabel();
	void SetLabel(string label);
	Component();

	//Destructor must be virtual
	virtual ~Component();

	IN_GUIDE GetGuide();
	void SetGuide(IN_GUIDE guide);
	virtual OutputPin* getSourcePin();
	virtual InputPin* getDestPin();
	int GetID();
	void SetID(int id);

	int GetRefFactorOut(bool x) const;
	int GetRefFactorIn(bool x) const;

};

#endif
