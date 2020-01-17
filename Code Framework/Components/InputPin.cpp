#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::SetPinNumber(int n)
{
	PinNumber = n;
}

int InputPin::GetPinNumber()
{
	return PinNumber;
}
