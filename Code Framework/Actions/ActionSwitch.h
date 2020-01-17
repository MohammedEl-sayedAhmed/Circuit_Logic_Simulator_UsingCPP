#ifndef ACTIONSWITCH_H
#define ACTIONSWITCH_H

#include "Action.h"
#include "..\UI\UI.h"


class ActionSwitch : public Action
{

private:

public:
	ActionSwitch(ApplicationManager* pApp);
	void FlipSwitch(Point toBeSelectedPoint);
	virtual void Execute();

};
#endif