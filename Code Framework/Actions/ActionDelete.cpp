#include "ActionDelete.h"
#include "..\ApplicationManager.h"

#include "..\UI\UI.h"
#include <iostream>
using namespace std;

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{

}

//Execute the action
void ActionDelete::Execute()
{
	//UI* pUI = pManager->GetUI();
	DeleteComponent();
	pManager->setSaved(false);
}

void ActionDelete::DeleteComponent() 
{
	UI* pUI = pManager->GetUI();
	int SelectedCount = pManager->GetSelectedCount();
	Component** CompListptr = pManager->GetComponentList();
	int CompCount = pManager->GetComponentsCount();
	Component* SelectedCompGate;
	Component* SelectedCompConnection;
	
	if (SelectedCount == 0) {
		pUI->PrintMsg("There is no selected component(s), please select one or more component to delete");
	}
	else {
		for (int i =0; i<CompCount; i++) {
			if (CompListptr[i]->IsSelected()) {
				SelectedCompGate = CompListptr[i]; //selectedgate
				for (int j = 0; j < CompCount; j++) {
					if (CompListptr[j]->GetComponentType() == "Connection") {
						SelectedCompConnection = CompListptr[j];
						if ((SelectedCompConnection->getSourcePin()) == (SelectedCompGate->getComponentOutput())
							|| SelectedCompConnection->getDestPin() == SelectedCompGate->getComponentInput(0)
							|| SelectedCompConnection->getDestPin() == SelectedCompGate->getComponentInput(1)) {
							
							delete SelectedCompConnection;
							SelectedCompConnection = nullptr;
							for (int k = j + 1; k <= CompCount; k++) {
								CompListptr[k - 1] = CompListptr[k];
								//CompListptr[k - 1]->SetID(k);
								//pManager->ResetIDs();
							}
							j--;
							CompCount--;
							pManager->SetComponentsCount(CompCount);
						}
						
					}
				}
				//SelectedCompGate->getComponentOutput()
				delete CompListptr[i];
				CompListptr[i] = nullptr;
				for (int j = i + 1; j <= CompCount; j++)
				{
					CompListptr[j - 1] = CompListptr[j];
					/// lma a3ml delete 7ot satr zizo 
					//CompListptr[i - 1]->SetID(i);
					//cout << "Id of comp i is  " << i << endl;
					//pManager->ResetIDs();
				}
				i--;
				SelectedCount--;
				pManager->SetSelectedCount(SelectedCount);
				CompCount--;
				pManager->SetComponentsCount(CompCount);
			} 
		}	
		pUI->PrintMsg("Component(s) deleted");
	}
}

