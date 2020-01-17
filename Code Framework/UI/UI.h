#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
{
	int x,y;
};


//A structure to contain drawing parameters for each component
//Each component stores its drawing points in this struct
//For example, a Gate can store points of the rectangluar area it occupies
//				The Connection
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	};

	int GetCornerDownX()
	{
		return this->PointsList[0].x;
	};

	int GetCornerDownY()
	{
		return this->PointsList[0].y;
	};

};


class UI
{

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		//If you want to change the menu items order, change the order here
		ITM_AND2,		//AND gate item in menu
		ITM_OR2,		//OR gate item in menu
		ITM_NAND2,
		ITM_NOR2,
		ITM_XOR2,
		ITM_XNOR2,
		ITM_BUFF,
		ITM_INV,
		ITM_MODULE,
		ITM_SWITCH,
		ITM_LED,
		ITM_CONNECTION,
		//ITM_ADDLABEL,
		ITM_EDITLABEL,
		ITM_DELETE,
		ITM_EXIT,	//Exit item
		ITM_COPY,
		ITM_CUT,
		ITM_PASTE,
		ITM_SAVE,
		ITM_LOAD,
		ITM_SWITCH_MODE1,	//Switches to Simulation Mode
		//TODO: Add more items names here

		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

	};


	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_SIM,	//Simulate menu item
		ITM_TRUTH,	//Truth table menu item
		ITM_SWITCH_MODE2,	//Switches back to Design Mode
		//TODO:Add more items names here
		
		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

	};



	MODE AppMode;		//Application Mode (design or simulation)

	static const int	width = 1350, height = 700,	//Window width and height
						wx = 10 , wy = 10,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 100,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 70,	//Width of each item in toolbar menu
						ToolItemHeight = 47,	//Height of each item in toolbar menu
						MaxItemPerRow = 14;		//Max no. of items per row for the toolbar

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color
	color LabelColor;		//Components' Labels color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	GATE_Width = 70,		//Gate Image default width
						GATE_Height = 47;		//Gate Image default height

	static const int	Pins_Dist = 15;			//Distance between 2 adjacent input pins of the same component

	window *pWind; // pointer to graphics window
	Point LastClickedPoint;
	

public:

	
	UI();
	int getGateWidth() const;
	int getGateHeight() const;
	int UI::GetPinsDist() const;
	// Input Functions  ---------------------------
	//Point GetPointClicked();	//Get coordinate where user clicks
	window* GetPtrWind();
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() ; //Reads the user click and maps it to an action
	Point GetterLastClickedPoint();

	MODE GetAppMode() const;

	// Output Functions  ---------------------------

	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearToolBar() const;		//Clears the status bar



	// Draws 2-input AND gate
	void DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected = false) const;

	// Draws 1-input Buffer gate
	void DrawBUFF1(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 1-Input Inverse gate
	void DrawINV1(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input NAND gate
	void DrawNAND2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input NOR gate
	void DrawNOR2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input OR gate
	void DrawOR2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input XNOR gate
	void DrawXNOR2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws 2-input XOR gate
	void DrawXOR2(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	// Draws Switch
	void DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false, bool closed = false) const;

	// Draws LED
	void DrawLed(const GraphicsInfo& r_GfxInfo, bool selected = false, bool illum = false) const;
	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc



	// Draws Connection
	void DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected = false) const;

	// Draws Label
	void DrawLabel(int x, int y, string label);

	void DrawModule(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	void ClearOldLabel(int x, int y);

	void PrintMsg(string msg) const;	//Print a message on Status bar

	~UI();
};

#endif
