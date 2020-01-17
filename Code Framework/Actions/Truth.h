#ifndef _TRUTH
#define _TRUTH

#include "action.h"


class Truth :	public Action
{
private:

public:

	Truth(ApplicationManager *pApp);
	virtual ~Truth(void);

	//Execute action (code depends on action type)
	virtual void Execute();


};

#endif