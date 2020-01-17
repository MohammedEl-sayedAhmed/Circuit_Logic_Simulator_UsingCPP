#include "ActionSwitch.h"

#include "..\ApplicationManager.h"

#include "..\UI\UI.h"
#include <iostream>
using namespace std;

ActionSwitch::ActionSwitch(ApplicationManager* pApp) : Action(pApp)
{

}

//Execute the action
void ActionSwitch::Execute()
{
	UI* pUI = pManager->GetUI();

	Point ClickedPoint = pUI->GetterLastClickedPoint();

	FlipSwitch(ClickedPoint);
}

void ActionSwitch::FlipSwitch(Point toBeSelectedPoint)
{

	int x = toBeSelectedPoint.x;
	int y = toBeSelectedPoint.y;

	UI* pUI = pManager->GetUI();
	int CompCount = pManager->GetComponentsCount();
	Component** CompListptr = pManager->GetComponentList();

	for (int i = 0; i < CompCount; i++)
	{
		if ((CompListptr[i])->IsInRegion(x, y))
		{
			if ( (CompListptr[i])->GetComponentType() != "Switch" )
			{
				pUI->PrintMsg("Only Switches shall be selected!");
			}

			else
			{
				if (CompListptr[i]->GetOutPinStatus() == 0)
				{
					CompListptr[i]->setInputPinStatus(0, HIGH);
					CompListptr[i]->Draw(pUI);
				}

				else if (CompListptr[i]->GetOutPinStatus() == 1)
				{
					CompListptr[i]->setInputPinStatus(0, LOW);
					CompListptr[i]->Draw(pUI);
				}
			}
		}
	}
}