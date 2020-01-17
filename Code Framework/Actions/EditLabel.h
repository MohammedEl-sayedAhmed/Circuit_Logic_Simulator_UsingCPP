#pragma once
#include "Action.h"
#include "../UI/UI.h"

class EditLabel :
	public Action
{
private:
	int Cx, Cy;	//Corner point of the gate

public:
	EditLabel(ApplicationManager* pApp);
	void Execute();
};