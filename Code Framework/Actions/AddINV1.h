#ifndef _ADD_INV_H
#define _ADD_INV_H

#include "action.h"
#include "..\Components\INV1.h"

class AddINV1 :	public Action
{
private:

	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:

	AddINV1(ApplicationManager *pApp);
	virtual ~AddINV1(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif