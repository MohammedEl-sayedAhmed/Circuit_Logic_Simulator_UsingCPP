#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"
#include "..\UI\UI.h"


class ActionSelect : public Action
{

private:

	bool SelectedToBeUnselected;

public:
	ActionSelect(ApplicationManager* pApp);
	void SelectComponent(Point toBeSelectedPoint);
	virtual void Execute();

};
#endif