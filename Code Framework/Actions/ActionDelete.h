#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H

#include "Action.h"
#include "..\UI\UI.h"


class ActionDelete : public Action
{

private:


public:
	ActionDelete(ApplicationManager* pApp);
	void DeleteComponent();
	virtual void Execute();

};
#endif