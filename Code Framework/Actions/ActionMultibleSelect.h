/*#ifndef ACTION_MULTIBLE_SELECT_H
#define ACTION_MULTIBLE_SELECT_H

#include "Action.h"
#include "..\UI\UI.h"


class ActionMultibleSelect : public Action
{

private:

	bool SelectedToBeUnselected;

public:
	ActionMultibleSelect(ApplicationManager* pApp);
	void SelectManyComponent(Point toBeSelectedPoint);
	virtual void Execute();

};
#endif
*/