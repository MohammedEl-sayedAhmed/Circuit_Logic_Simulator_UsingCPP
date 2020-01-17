#include <iostream>
#include <fstream>
#include "Load.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND2.h"
#include "..\Components\BUFF1.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "..\Components\InputPin.h"
#include "..\Components\INV1.h"
#include "..\Components\Led.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\OR2.h"
#include "..\Components\OutputPin.h"
#include "..\Components\Pin.h"
#include "..\Components\Switch.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
#include "AddANDgate2.h"

Load::Load(ApplicationManager* pApp) : Action(pApp)
{

};

Load::~Load(void)
{

}


void Load::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Load is called");
	ifstream myfile;
	myfile.open("Load_test.txt");
	if (!myfile.is_open()) // check to make sure the the file is available to read
	{
		cout << "The file is not good to go\n";
	}
	myfile >> n_components;
	string** comp_str = new string* [n_components];
	int** comp_int = new int* [n_components];
	for (int i = 0; i < n_components; i++) // here the function starts to read the data of the components from the text file and store them in 2 2D dynamic arrays
	{
		comp_str[i] = new string[2];
		comp_int[i] = new int[3];
		myfile >> comp_str[i][0];  //storing the type of the component 
		myfile >> comp_int[i][0];  //storing the ID of the component
		myfile >> comp_str[i][1];  //storing the label of the component
		myfile >> comp_int[i][1];  //storing the x index of the component
		myfile >> comp_int[i][2];  //storing the y index of the component
	}
	string conn_label;
	myfile >> conn_label;
	myfile >> n_connections;
	int** con2;
	if (n_connections != 0)
	{
		int** con = new int* [n_connections];
		con2 = con;
		for (int i = 0; i < n_connections; i++) // her ethe function start to read the data of the connections and store them in a dynamic array	
		{
			con[i] = new int[3];
			myfile >> con[i][0];
			myfile >> con[i][1];
			myfile >> con[i][2];
		}
	}
	
	myfile.close();
	//////******Check How a component can be added and how to pass the x, y to it and draw it******//////
	/////////**********NOTE******////////////
	///////////Label has not been read yet////////////
	//UI* pUI = pManager->GetUI();
	//pUI->ClearStatusBar();
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();
	int Cx, Cy;	//Center point of the gate
	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the component
	for (int i = 0; i < n_components; i++)
	{
		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

		Cx = comp_int[i][1];
		Cy = comp_int[i][2];
		pGInfo->PointsList[0].x = Cx - gateWidth / 2;
		pGInfo->PointsList[0].y = Cy - gateHeight / 2;
		pGInfo->PointsList[1].x = Cx + gateWidth / 2;
		pGInfo->PointsList[1].y = Cy + gateHeight / 2;
		if (comp_str[i][0] == "AND2")
		{
			AND2* pA = new AND2(pGInfo, AND2_FANOUT);
			pA->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pA, comp_int[i][0] - 1);
			//pA->Draw(pUI);
		}
		else if (comp_str[i][0] == "OR2")
		{
			OR2* pO = new OR2(pGInfo, OR2_FANOUT);
			pO->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pO, comp_int[i][0] - 1);
			//pUI->DrawOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "XNOR2")
		{
			XNOR2* pXN = new XNOR2(pGInfo, OR2_FANOUT);
			pXN->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pXN, comp_int[i][0] - 1);
			//pUI->DrawXNOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "NAND2")
		{
			NAND2* pNAN = new NAND2(pGInfo, NAND2_FANOUT);
			pNAN->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pNAN, comp_int[i][0] - 1);
			//pUI->DrawNAND2(*pGInfo);
		}
		else if (comp_str[i][0] == "NOR2")
		{
			NOR2* pNOR = new NOR2(pGInfo, NOR2_FANOUT);
			pNOR->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pNOR, comp_int[i][0] - 1);
			//pUI->DrawNOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "XNOR2")
		{
			XNOR2* pXNOR = new XNOR2(pGInfo, XNOR2_FANOUT);
			pXNOR->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pXNOR, comp_int[i][0] - 1);
			//pUI->DrawXNOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "XOR2")
		{
			XOR2* pXOR = new XOR2(pGInfo, XOR2_FANOUT);
			pXOR->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pXOR, comp_int[i][0] - 1);
			//pUI->DrawXOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "SWITCH")
		{
			Switch* pSWI = new Switch(pGInfo, Switch_FANOUT);
			pSWI->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pSWI, comp_int[i][0] - 1);
			//pUI->DrawSwitch(*pGInfo);
		}
		else if (comp_str[i][0] == "BUFF")
		{
			BUFF1* pBUF = new BUFF1(pGInfo, BUFF1_FANOUT);
			pBUF->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pBUF, comp_int[i][0] - 1);
			//pUI->DrawBUFF1(*pGInfo);
		}
		else if (comp_str[i][0] == "NOT")
		{
			INV1* pINV = new INV1(pGInfo, INV1_FANOUT);
			pINV->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pINV, comp_int[i][0] - 1);
			//pUI->DrawINV1(*pGInfo);
		}
		else if (comp_str[i][0] == "LED")
		{
			Led* pLED = new Led(pGInfo, Led_FANOUT);
			pLED->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pLED, comp_int[i][0] - 1);
			//pUI->DrawLed(*pGInfo);
		}

	}
	//cout << "count  = " << pManager->GetComponentsCount() << endl;
	//cout << "ID = " << (pManager->GetComponentList())[0]->GetID() << endl;
	//cout << "Load ended" << endl;
	// r_FanOut = number of outputs

	if (n_connections != 0)
	{
		for (int i = 0; i < n_connections; i++)
		{
			// con[i][0]; // ID of source component of the connection
			// con[i][1]; // ID of trageted component of the connection
			// con[i][2]; // No of input to connect to in the trageted component
			Component* Dest_ptr = pManager->GetComponent(con2[i][0] - 1);
			Component* Src_ptr = pManager->GetComponent(con2[i][1] - 1);
			OutputPin* pOp = Dest_ptr->getComponentOutput(); // con[i][0] - 1 //because the indexing starts from zero in the compList in application manager
			InputPin* pIp = Src_ptr->getComponentInput(con2[i][2]);
			int Sx, Sy;	//Starting point of the connection
			int Ex, Ey;	//Ending point of the connection
			Sx = Src_ptr->getOutPinCoordinates(Src_ptr->GetRefFactorOut(0)).x;
			Sy = Src_ptr->getOutPinCoordinates(Src_ptr->GetRefFactorOut(1)).y;


			Ex = Dest_ptr->getInPinCoordinates(Dest_ptr->GetRefFactorIn(0)).x;

			Ey = Dest_ptr->getInPinCoordinates(Dest_ptr->GetRefFactorIn(1)).y;


			GraphicsInfo* pGInfo = new GraphicsInfo(4); //Gfx info to be used to construct the connection

			pGInfo->PointsList[0].x = Sx;
			pGInfo->PointsList[0].y = Sy;

			pGInfo->PointsList[1].x = Sx + 25;
			pGInfo->PointsList[1].y = Sy;

			pGInfo->PointsList[2].x = Ex - 25;
			pGInfo->PointsList[2].y = Ey;

			pGInfo->PointsList[3].x = Ex;
			pGInfo->PointsList[3].y = Ey;

			//Connection* con = new Connection();
			Connection * pA = new Connection(pGInfo, pOp, pIp);
			Component** ptr = pManager->GetComponentList();
			int location = 0;
			// the next for loop will provide us with the first empty location in the components list
			while (ptr[location])
			{
				location++;
			}
			pManager->AddComponentAtIndex(pA, location);
			//pManager->AddComponent(pA);

			////***Write code here to initialize the connection component and store it in comList in application manager***////

			//Connection(GraphicsInfo* r_GfxInfo, pOp, pIp);



	}
	}
	


}
//the matrix_load function will read the data from the text file in 2 matrices one for strings and another for integers to make any operations in this data in the future
//the function should take 3 pointers to pointers to save the data in them
/*
void Load::MatrixRead(string** comp_str , int** comp_int , int** con)
{
	ifstream myfile;
	myfile.open(Address);
	if (!myfile.is_open()) // check to make sure the the file is available to read
	{
		cout << "The file is not good to go\n";
	}

	myfile >> n_components;
	for (int i = 0; i < n_components; i++) // here the function starts to read the data of the components from the text file and store them in 2 2D dynamic arrays
	{
		comp_str[i] = new string[2];
		comp_int[i] = new int[3];
		myfile >> comp_str[i][0];
		myfile >> comp_int[i][0];
		myfile >> comp_str[i][1];
		myfile >> comp_int[i][1];
		myfile >> comp_int[i][2];
	}
	myfile >> n_connections;
	for (int i = 0; i < n_connections; i++) // her ethe function start to read the data of the connections and store them in a dynamic array	
	{
		con[i] = new int[3];
		myfile >> con[i][0];
		myfile >> con[i][1];
		myfile >> con[i][2];
	}
	myfile.close();
	//////******Check How a component can be added and how to pass the x, y to it and draw it******//////
	/////////**********NOTE******////////////
	///////////Label has not been read yet////////////
/*
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the component
	for (int i = 0; i < n_components; i++)
	{ 
		Cx = comp_int[i][1];
		Cy = comp_int[i][2];
		pGInfo->PointsList[0].x = Cx - gateWidth / 2;
		pGInfo->PointsList[0].y = Cy - gateHeight / 2;
		pGInfo->PointsList[1].x = Cx + gateWidth / 2;
		pGInfo->PointsList[1].y = Cy + gateHeight / 2;
		if (comp_str[i][0] == "AND2")
		{
			AND2* pA = new AND2(pGInfo, AND2_FANOUT);
			pA->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pA, comp_int[i][0]-1);
			//pManager->AddComponent(pA);
			pUI->DrawAND2(*pGInfo);
		}
		else if (comp_str[i][0] == "OR2")
		{
			OR2* pO = new OR2(pGInfo, OR2_FANOUT);
			pO->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pO, comp_int[i][0] - 1);
			pUI->DrawOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "XNOR2")
		{
			XNOR2* pXN = new XNOR2(pGInfo, OR2_FANOUT);
			pXN->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pXN, comp_int[i][0] - 1);
			pUI->DrawXNOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "NAND2")
		{
			NAND2* pNAN = new NAND2(pGInfo, NAND2_FANOUT);
			pNAN->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pNAN, comp_int[i][0] - 1);
			pUI->DrawNAND2(*pGInfo);
		}
		else if (comp_str[i][0] == "NOR2")
		{
			NOR2* pNOR = new NOR2(pGInfo, NOR2_FANOUT);
			pNOR->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pNOR, comp_int[i][0] - 1);
			pUI->DrawNOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "XNOR2")
		{
			XNOR2* pXNOR = new XNOR2(pGInfo, XNOR2_FANOUT);
			pXNOR->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pXNOR, comp_int[i][0] - 1);
			pUI->DrawXNOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "XOR2")
		{
			XOR2* pXOR = new XOR2(pGInfo, XOR2_FANOUT);
			pXOR->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pXOR, comp_int[i][0] - 1);
			pUI->DrawXOR2(*pGInfo);
		}
		else if (comp_str[i][0] == "SWITCH")
		{
			Switch* pSWI = new Switch(pGInfo, Switch_FANOUT);
			pSWI->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pSWI, comp_int[i][0] - 1);
			pUI->DrawSwitch(*pGInfo);
		}
		else if (comp_str[i][0] == "BUFF")
		{
			BUFF1* pBUF = new BUFF1(pGInfo, BUFF1_FANOUT);
			pBUF->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pBUF, comp_int[i][0] - 1);
			pUI->DrawBUFF1(*pGInfo);
		}
		else if (comp_str[i][0] == "NOT")
		{
			INV1* pINV = new INV1(pGInfo, INV1_FANOUT);
			pINV->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pINV, comp_int[i][0] - 1);
			pUI->DrawINV1(*pGInfo);
		}
		else if (comp_str[i][0] == "LED")
		{
			Led* pLED = new Led(pGInfo, Led_FANOUT);
			pLED->SetLabel(comp_str[i][1]);
			pManager->AddComponentAtIndex(pLED, comp_int[i][0] - 1);
			pUI->DrawLed(*pGInfo);
		}

	}
	// r_FanOut = number of outputs
	for (int i = 0; i < n_connections; i++)
	{
		// con[i][0]; // ID of source component of the connection
		// con[i][1]; // ID of trageted component of the connection
		// con[i][2]; // No of input to connect to in the trageted component
		OutputPin* pOp= pManager->GetComponent(con[i][0]-1)->getComponentOutput(); // con[i][0] - 1 //because the indexing starts from zero in the compList in application manager
		InputPin* pIp = pManager->GetComponent(con[i][1]-1)->getComponentInput(con[i][2]);
		*/
		////***Write code here to initialize the connection component and store it in comList in application manager***////
		
		//Connection(GraphicsInfo* r_GfxInfo, pOp, pIp);
		/*

	}

}
*/
