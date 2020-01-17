#ifndef ACTIONCUT_H
#define ACTIONCUT_H
#pragma once
#include "Action.h"\
//#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

class ActionCut :
	public Action
{
private:
	Component* Temp;
	int Sx, Sy;

public:
	ActionCut(ApplicationManager* pApp);
	virtual~ActionCut(void);
	virtual void Execute();
};
#endif

