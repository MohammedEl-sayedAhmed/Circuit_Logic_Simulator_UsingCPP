#include "ActionPaste.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "AddANDgate2.h"
#include "AddANDgate2.h"
#include "AddORgate2.h"
#include "AddNANDgate2.h"
#include "AddLed.h"
#include "AddINV1.h"
#include "AddBUFF1.h"
#include "AddXORgate2.h"
#include "AddXNORgate2.h"
#include "AddSwitch.h"
#include "AddNORgate2.h"
#include <iostream>


using namespace std;

ActionPaste::ActionPaste(ApplicationManager* pApp) : Action(pApp)
{
	
}

ActionPaste::~ActionPaste(void)
{

}

void ActionPaste::Execute()
{
	Action* pAct = NULL;

	cout << "Action Paste is called" << endl;
	Type = pManager->GetTemporaryType();
	cout << "Type : "<< Type << endl;
	//Type = Temp->GetComponentType();
	if (Type == "AND2")
	{
		pManager->ExecuteAction(ADD_AND_GATE_2);
	}
	else if (Type == "BUFF1")
	{
		pManager->ExecuteAction(ADD_Buff);
	}
	else if (Type == "INV1")
	{
		pManager->ExecuteAction(ADD_INV);
	}
	else if (Type == "Led")
	{
		pManager->ExecuteAction(ADD_LED);
	}
	else if (Type == "NAND2")
	{
		pManager->ExecuteAction(ADD_NAND_GATE_2);
	}
	else if (Type == "NOR2")
	{
		pManager->ExecuteAction(ADD_NOR_GATE_2);
	}
	else if (Type == "OR2")
	{
		pManager->ExecuteAction(ADD_OR_GATE_2);
	}
	else if (Type == "Switch")
	{
		pManager->ExecuteAction(ADD_Switch);
	}
	else if (Type == "XNOR2")
	{
		pManager->ExecuteAction(ADD_XNOR_GATE_2);
	}
	else if (Type == "XOR2")
	{
		pManager->ExecuteAction(ADD_XOR_GATE_2);
	}
	pManager->setSaved(false);
}