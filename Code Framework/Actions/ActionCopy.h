#ifndef ACTIONCOPY_H
#define ACTIONCOPY_H
#pragma once

#include "Action.h"
//#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

class ActionCopy : public Action
{
private:
	//Component* Temp;
	//Component* New;
	int Sx, Sy;
public:
	ActionCopy(ApplicationManager* pApp);
	virtual ~ActionCopy(void);
	virtual void Execute();
};
#endif
