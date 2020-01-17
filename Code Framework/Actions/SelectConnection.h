#ifndef _SELECT_CONNECTION_H
#define _SELECT_CONNECTION_H

#include "action.h"
#include "..\Components\Connection.h"

class SelectConnection : public Action
{
private:

	//Parameters for rectangular area to be occupied by the gate
	int Sx, Sy;	//Starting point of the connection
	int Jx1, Jx2, Jy1, Jy2; //Conection Junctions coordinates
	int Ex, Ey;	//Ending point of the connection
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:

	SelectConnection(ApplicationManager *pApp);
	virtual ~SelectConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif