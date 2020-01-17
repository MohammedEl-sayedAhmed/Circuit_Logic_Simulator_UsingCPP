#include "Save.h"
#include "String"
#include <iostream>
#include <fstream>
#include "..\ApplicationManager.h"

using namespace std;

Save::Save(ApplicationManager* pApp) : Action(pApp)
{

}

Save::~Save(void)
{

}

void Save::Execute()
{
	ofstream myfile("SavedOutput.txt");
	//myfile.open(Address);
	/*
	if (!myfile.is_open()) // check to make sure the the file is available to read
	{
		cout << "The file is not good to go\n";
	}x
	*/
	ComponentsCount = pManager->GetComponentsCount();
	for (int i = 0; i < ComponentsCount; i++)
	{
		ComponentType = pManager->GetComponent(i)->GetComponentType(); // Type is yet to be defined as a pure virtual function in component and its child classes and it returns a string
		if (ComponentType == "Connection")
		{
			ConnectionCount++;
		}
		else
		{
			OthersCount++;
		}
	}
	myfile << OthersCount << "\n";
	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the component
	UI* pUI = pManager->GetUI();
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();
	////***Label call and save is yet to be implemented in the text file
	for (int i = 0; i < ComponentsCount; i++)
	{
		ComponentType = pManager->GetComponent(i)->GetComponentType(); // Type is yet to be defined as a pure virtual function in component and its child classes and it returns a string
		if (ComponentType == "Connection")
		{
			continue;
		}
		else
		{
			myfile << ComponentType << " ";
			myfile << i + 1 << " " ; // saves the ID of the component which corresponds to its index in the compList + 1
			myfile << pManager->GetComponent(i)->GetLabel() << " "; //saves the label of the components
			

			Cx = pManager->GetComponent(i)->GetCornerDoX() + gateWidth / 2; // Cx is the x coordinate of the center of the image of the component
			Cy = pManager->GetComponent(i)->GetCornerDoY() + gateHeight / 2; // Cy is the y coordinate of the center of the image of the component
			myfile << Cx << " " ;
			myfile << Cy << "\n";
		}

	}
	myfile << "Connections\n";
	myfile << ConnectionCount << "\n" ;
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;
	for (int i = 0; i < ComponentsCount; i++)
	{
		ComponentType = pManager->GetComponent(i)->GetComponentType(); // Type is yet to be defined as a pure virtual function in component and its child classes and it returns a string
		if (ComponentType == "Connection")
		{
			SrcPin = pManager->GetComponent(i)->getSourcePin();
			DstPin = pManager->GetComponent(i)->getDestPin();
			myfile << SrcPin->GetAttachedComponent()->GetID() << " ";
			myfile << DstPin->getComponent()->GetID() << " ";
			myfile << DstPin->GetPinNumber() << "\n";


			///***A code to save connections will be added here***///
			//ComponentType = pManager->GetComponent(i).;
		}
		else
		{
			continue;
		}
	}
	//Print 1st Action Message
	pUI->PrintMsg("Saved");
	pManager->setSaved(true);

	
}
