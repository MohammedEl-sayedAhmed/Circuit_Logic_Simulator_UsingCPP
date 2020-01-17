/*#include "ActionMove.h"
#include "ActionSelect.h"
#include "..\ApplicationManager.h"

#include "..\UI\UI.h"
#include <iostream>
using namespace std;

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{

}

//Execute the action
void ActionMove::Execute()
{


	MoveComponent();

}





void ActionMove::MoveComponent() {
	
	// instead of making getters for them
	static const int	width = 1250, height = 650,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 47,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 70;		//Width of each item in toolbar menu

	
	UI* pUI = pManager->GetUI();
	UI UIinfo;
	pManager->DeselectAllComponents();
	pUI->PrintMsg("Select a Component to move");

	Point ClickedPoint;
	int xCL = ClickedPoint.x;
	int yCL = ClickedPoint.y;

	Point MovedtoPoint;
	int xMT = MovedtoPoint.x;
	int yMT = MovedtoPoint.y;

	Point MouseClickPoint;
	int xMC = MouseClickPoint.x;
	int yMC = MouseClickPoint.y;

	ActionSelect* SelectPtr;
	SelectPtr->SelectComponent(ClickedPoint);

	pUI->GetPtrWind()->WaitMouseClick(xCL,yCL);
	if (yCL > ToolBarHeight && yCL < (height - StatusBarHeight)) {
		if (pManager->GetSelectedCount() == 0) {
			pUI->PrintMsg("No Components are selected, Please select one or more component to move.");
		}
		else {
			pManager->UpdateInterface();
			pUI->PrintMsg("Click to drop");
			bool isMoved;
			// keep moving till left click is pressed
			while (pUI->GetPtrWind()->WaitMouseClick(xMC, yMC) != LEFT_CLICK) {
				pUI->GetPtrWind()->GetMouseCoord(xMT, yMT);
				

			}

		}

	}
}

*/
