#include "Truth.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

Truth::Truth(ApplicationManager *pApp):Action(pApp)
{
}

Truth::~Truth(void)
{
}

void Truth::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Build Truth table based on all possible values
}

