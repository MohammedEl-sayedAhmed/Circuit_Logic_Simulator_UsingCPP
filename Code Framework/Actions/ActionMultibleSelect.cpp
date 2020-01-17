/*#include "ActionMultibleSelect.h"

#include "..\ApplicationManager.h"

#include "..\UI\UI.h"
#include <iostream>
using namespace std;

ActionMultibleSelect::ActionMultibleSelect(ApplicationManager* pApp) :Action(pApp)
{

}

//Execute the action
void ActionMultibleSelect::Execute()
{
	UI* pUI = pManager->GetUI();

	Point ClickedPoint = pUI->GetterLastClickedPoint();

	SelectManyComponent(ClickedPoint);

}

void ActionMultibleSelect::SelectManyComponent(Point toBeSelectedPoint) {

	int x = toBeSelectedPoint.x;
	int y = toBeSelectedPoint.y;

	UI* pUI = pManager->GetUI();
	int CompCount = pManager->GetComponentsCount();
	Component** CompListptr = pManager->GetComponentList();

	for (int i = 0; i < CompCount; i++) {

		if ((CompListptr[i])->IsInRegion(x, y)) {
			bool toBeSelected = (CompListptr[i])->IsSelected();
			(CompListptr[i])->SetSelected ( ! toBeSelected);
			(CompListptr[i])->Draw(pUI);

			if (! toBeSelected) {
				pUI->ClearStatusBar();
				//pUI->PrintMsg("You selected this component");
			}
			else { 
				pUI->ClearStatusBar();
				//pUI->PrintMsg("You Unselected this component");
			}
		}
	}
}*/