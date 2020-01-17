#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components

private:

	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	UI* pUI; //pointer to the UI
	bool Saved; // current window is saved
	Component* Temporary;
	string TemporaryType;
	int SelectedCount;


public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	
	//Executes the created action
	void ExecuteAction(ActionType);
	


	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void ClearCompList();

	bool ExitFlag = 0;
	bool isSaved();
	void setSaved(bool newSavedState);

	//Gets a component at specific index in CompList
	Component* GetComponent(int index);
	int GetComponentsCount();
	void SetComponentsCount(int NewCount);

	Component** GetComponentList();

	void AddComponentAtIndex(Component* pComp, int index);


	Component* GetComponentByCordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region
	Component* GetSelectedComponent(); //return a pointer to the selected component
	void DeselectAllComponents(); // deselects all the components
	int GetSelectedCount();
	void SetSelectedCount(int newSelectedCount);
	void SelectComponent(int x, int y); //print in the status bar if the figure is selected or not
	void SetTemporaryComponent(Component& component);
	Component* GetTemporaryComponent();
	void SetTemporaryType(string type);
	string GetTemporaryType();
	//void ResetIDs();

	//destructor
	~ApplicationManager();
};

#endif
