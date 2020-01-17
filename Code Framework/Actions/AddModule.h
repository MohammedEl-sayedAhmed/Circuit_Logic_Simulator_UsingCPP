#ifndef _ADD_MODULE_H
#define _ADD_MODULE_H

#include "action.h"
#include "..\Components\Module.h"

class AddModule :	public Action
{
private:

	//Parameters for rectangular area to be occupied by the led
	int Cx, Cy;	//Center point of the led
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:

	AddModule(ApplicationManager *pApp);
	virtual ~AddModule(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif