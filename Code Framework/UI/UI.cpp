#include "UI.h"
#include <iostream>
using namespace std;
UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	LabelColor = BLUE;

	//Create the drawing window
	pWind = new window(width, height, wx, wy);


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}


int UI::getGateWidth() const
{
	return GATE_Width;
}

int UI::getGateHeight() const
{
	return GATE_Height;
}

window* UI::GetPtrWind()
{
	return pWind;
}

Point UI::GetterLastClickedPoint()
{
	return LastClickedPoint;
}

int UI::GetPinsDist() const
{
	return Pins_Dist;
}

MODE UI::GetAppMode() const
{
	return AppMode;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//


void UI::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input

		case 13:		//ENTER key is pressed
			return userInput;

		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;

		default:
			userInput+= Key;
		};

		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction()
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	LastClickedPoint.x = x;
	LastClickedPoint.y = y;



	if (AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = 100;
			if (x <= MaxItemPerRow * ToolItemWidth)
				ClickedItemOrder = (x / ToolItemWidth) + floor(y / ToolItemHeight) * MaxItemPerRow;
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

			case ITM_AND2:  return ADD_AND_GATE_2;
			case ITM_OR2:   return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2:  return ADD_NOR_GATE_2;
			case ITM_XOR2:  return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_BUFF:  return ADD_Buff;
			case ITM_INV:   return ADD_INV;
			case ITM_MODULE: return ADD_MODULE;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED:   return ADD_LED;
			case ITM_CONNECTION: return ADD_CONNECTION;
				//case ITM_ADDLABEL: return ADD_LABEL;
			case ITM_EDITLABEL: return EDIT_LABEL;
			case ITM_DELETE: return DEL;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_SWITCH_MODE1: return SWITCH_MODES;



			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}


	//[3] User clicks on the status bar
		return STATUS_BAR;
	}


	else	//Application is in Simulation mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolItemHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int	ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SIM:	 return RUN_SIM;
			case ITM_TRUTH:  return TRUTH;
			case ITM_SWITCH_MODE2:	 return SWITCH_MODES;		//Switches to Design mode


			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return Change_Switch;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
void UI::ClearToolBar()const
{
	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	if (AppMode == DESIGN)
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);
	else
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(WHITE);
	if (AppMode == DESIGN)
	pWind->DrawRectangle(0, ToolBarHeight+5, width, height - StatusBarHeight+5);
	else
	pWind->DrawRectangle(0, ToolBarHeight/2+5, width, height - StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar()
{
	AppMode = DESIGN;	//Design Mode
	ClearToolBar();

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Gate_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\Gate_OR2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Gate_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Gate_NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Gate_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Gate_XNOR2.jpg";
	MenuItemImages[ITM_BUFF] = "images\\Menu\\Gate_Buff.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Gate_INV.jpg";
	MenuItemImages[ITM_MODULE] = "images\\Menu\\Gate_Module.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\LED.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Connection.jpg";
	//MenuItemImages[ITM_ADDLABEL] = "images\\Menu\\Add_Label.jpg";
	MenuItemImages[ITM_EDITLABEL] = "images\\Menu\\Edit_Label.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Save.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	MenuItemImages[ITM_COPY] = "images\\Menu\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Load.jpg";

	MenuItemImages[ITM_SWITCH_MODE1] = "images\\Menu\\Simulation.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < MaxItemPerRow; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolItemHeight);
	
	for (int i = 0; i < ITM_DSN_CNT - MaxItemPerRow; i++)
		pWind->DrawImage(MenuItemImages[i + MaxItemPerRow], i * ToolItemWidth, 50, ToolItemWidth, ToolItemHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, ToolBarHeight+5, width, ToolBarHeight+5);

	CreateStatusBar();		//Create Status bar
}



//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode
	ClearToolBar();


	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\RunSimulation.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\Truth.jpg";
	MenuItemImages[ITM_SWITCH_MODE2] = "images\\Menu\\Design.jpg";


	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolItemHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, ToolBarHeight/2 + 5, width, ToolBarHeight/2 + 5);

	CreateStatusBar();		//Create Status bar
}



//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawBUFF1(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_Buff_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Buff.jpg";

	//Draw Buffer Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by Buffer Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawINV1(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INV_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INV.jpg";

	//Draw NOT Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOT Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawNAND2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawNOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawXNOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawXOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected, bool closed) const
{
	if (AppMode == DESIGN)
	{
		string GateImage;
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\Switch_Hi.jpg";
		else
			GateImage = "Images\\Gates\\Switch.jpg";
		//Draw Switch at Gfx_Info (1st corner)
		//Set the Image Width & Height by Switch Image Parameter in UI_Info
		pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	}

	else
	{
		string GateImage;
		if (closed)	//use image in the highlighted case
			GateImage = "Images\\Gates\\Switch_Hi.jpg";
		else
			GateImage = "Images\\Gates\\Switch.jpg";
		//Draw Switch at Gfx_Info (1st corner)
		//Set the Image Width & Height by Switch Image Parameter in UI_Info
		pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	}
	
}

void UI::DrawLed(const GraphicsInfo& r_GfxInfo, bool selected, bool illum) const
{
	if (AppMode == DESIGN)
	{
		string GateImage;
		if (selected)	//use image in the highlighted case
			GateImage = "Images\\Gates\\LED_Hi.jpg";
		else
			GateImage = "Images\\Gates\\LED.jpg";

		//Draw LED at Gfx_Info (1st corner)
		//Set the Image Width & Height by LED Image Parameter in UI_Info
		pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	}

	else
	{
		string GateImage;
		if (illum)	//use image in the highlighted case
			GateImage = "Images\\Gates\\LED_Hi.jpg";
		else
			GateImage = "Images\\Gates\\LED.jpg";
		//Draw Switch at Gfx_Info (1st corner)
		//Set the Image Width & Height by Switch Image Parameter in UI_Info
		pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	}

	
}

//TODO: Add similar functions to draw all components



void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	if (selected) {
		pWind->SetPen(RED, 8);
	}
	else {
		pWind->SetPen(BLUE, 8);
	}
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	pWind->DrawLine(r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y, r_GfxInfo.PointsList[2].x, r_GfxInfo.PointsList[2].y);
	pWind->DrawLine(r_GfxInfo.PointsList[2].x, r_GfxInfo.PointsList[2].y, r_GfxInfo.PointsList[3].x, r_GfxInfo.PointsList[3].y);
}

void UI::DrawLabel(int x, int y, string label)
{
	pWind->SetFont(15, PLAIN | BOLD, BY_NAME, "ARIAL");
	pWind->SetPen(BLUE);
	pWind->DrawString(x, y, label);
}


void UI::DrawModule(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Module_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Module.jpg";
	
	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}


void UI::ClearOldLabel(int x, int y)
{
	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(x, y, x + 100, y + 20);
}

UI::~UI()
{
	delete pWind;
}