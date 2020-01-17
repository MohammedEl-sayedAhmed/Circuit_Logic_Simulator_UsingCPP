#ifndef _RUN_SIMULATION
#define _RUN_SIMULATION

#include "action.h"

class RunSimulation :	public Action
{
private:

public:

	RunSimulation(ApplicationManager *pApp);
	virtual ~RunSimulation(void);

	//Execute action (code depends on action type)
	virtual void Execute();
};

#endif