#ifndef _ACTION_EXIT_H
#define _ACTION_EXIT_H

#include "action.h"

class ActionExit :	public Action
{
private:
	
public:

	ActionExit(ApplicationManager *pApp);
	virtual ~ActionExit(void);

	//Execute action (code depends on action type)
	virtual void Execute();


};

#endif