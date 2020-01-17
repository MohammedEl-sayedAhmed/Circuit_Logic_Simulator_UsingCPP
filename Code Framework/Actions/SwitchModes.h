#ifndef _SWITCH_MODES_H
#define _SWITCH_MODES_H

#include "action.h"


class SwitchModes :	public Action
{
private:

public:

	SwitchModes(ApplicationManager *pApp);
	virtual ~SwitchModes(void);

	//Execute action (code depends on action type)
	virtual void Execute();


};

#endif