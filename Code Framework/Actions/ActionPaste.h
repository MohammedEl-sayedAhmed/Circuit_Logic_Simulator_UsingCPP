#ifndef ACTIONPASTE_H
#define ACTIONPASTE_H
#pragma once
#include "Action.h"
//#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
using namespace std;

class ActionPaste :
	public Action
{
private:
	//Component* Temp;
	string Type;
public:
	ActionPaste(ApplicationManager* pApp);
	virtual~ActionPaste(void);
	virtual void Execute();
};
#endif

