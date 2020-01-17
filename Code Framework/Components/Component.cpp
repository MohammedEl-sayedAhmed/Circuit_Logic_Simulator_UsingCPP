#include "Component.h"
#include <iostream>
#include "..\ApplicationManager.h"

static int StaticID = 0;

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;
	Selected = false;
	Guide = NON;
	StaticID++;
	ID = StaticID;
	//ID = (pManager->GetComponentsCount())+1;

	ref_factor_out[0] = 0;
	ref_factor_out[1] = 0;

	ref_factor_in[0] = 0;
	ref_factor_in[1] = -7;
	//cout << boolalpha << "ay 3lama " << Selected << endl;
}

Component::Component()
{}

Component::~Component()
{}

InputPin* Component::getComponentInput(int inputNumber)
{
	cout << "Alert: you tried to get the input of a component that does not has inputpin" << endl;
	return nullptr;
}

OutputPin* Component::getComponentOutput()
{
	cout << "Alert: you tried to get the output of a component that does not has outputpin" << endl;
	return nullptr;
}



int Component::GetCornerDoX()
{
	return m_pGfxInfo->GetCornerDownX();
}

int Component::GetCornerDoY()
{
	return m_pGfxInfo->GetCornerDownY();
}

int Component::GetGateWidth()
{
	return pGateUIInfo->getGateWidth();
}

int Component::GetGatHeight()
{
	return pGateUIInfo->getGateHeight();
}

bool Component::IsSelected()
{
	return Selected;
}

bool Component::IsInRegion(int x, int y)
{

	return false;
}

void Component::SetSelected(bool selected)
{
	//UI* pUI;
	//pUI->PrintMsg("set selected");
	Selected = selected;
}

string Component::GetLabel()
{
	return m_Label;
}

void Component::SetLabel(string label)
{
	m_Label = label;
}

Point Component::getOutPinCoordinates(int refinement_factor)
{
	Point p;
	p.x = this->GetCornerDoX() + this->GetGateWidth() + refinement_factor;
	p.y = this->GetCornerDoY() + this->GetGatHeight() / 2 + refinement_factor;
	return p;
}

Point Component::getInPinCoordinates(int refinement_factor)
{
	Point p;
	p.x = this->GetCornerDoX() + refinement_factor;
	p.y = this->GetCornerDoY() + this->GetGatHeight() / 2 + refinement_factor;
	return p;
}

IN_GUIDE Component::GetGuide()
{
	return this->Guide;
}

void Component::SetGuide(IN_GUIDE guide)
{
	this->Guide = guide;
}

OutputPin* Component::getSourcePin()
{
	cout << "Error you tried to get source pin of a non connection component" << endl;
	return nullptr;
}

InputPin* Component::getDestPin()
{
	cout << "Error you tried to get destination pin of a non connection component" << endl;
	return nullptr;
}

int Component::GetID()
{
	return ID;
}

void Component::SetID(int id)
{
	ID = id;
}
int Component::GetRefFactorOut(bool x) const
{
	int r = this->ref_factor_out[x];
	return r;
}

int Component::GetRefFactorIn(bool x) const
{
	int r = this->ref_factor_in[x];
	return r;
}