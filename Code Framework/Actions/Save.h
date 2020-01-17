#pragma once
#include "Action.h"
#include "String"
using namespace std;

class Save :
	public Action
{
private:
	string Address;
	int ComponentsCount = 0 , ConnectionCount = 0, OthersCount = 0;
	int Cx, Cy;
	string ComponentType;
public:
	Save(ApplicationManager* pApp);
	virtual ~Save(void);
	virtual void Execute();

};
