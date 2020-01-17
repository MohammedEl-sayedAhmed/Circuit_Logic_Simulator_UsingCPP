#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_MODULE,          //Add Module
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_LABEL,			//Add Label to a Component, a Connection
	EDIT_LABEL,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode


	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//empty gui region
	SIM_MODE,	
	SWITCH_MODES,	///Switch between modes

	TRUTH,
	RUN_SIM,

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

	COPY,
	CUT,
	PASTE,

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NCON	//not connected
};

//Possible Status for input pins of 2-input components
enum IN_GUIDE
{
	NON,	//not connected at all
	ONE,	//only the first pin is connected
	TWO,	//only the second pin is connected
	BOTH	//both pins are connected
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	OR2_FANOUT = 5,		//Default fan out of 2-input OR gate
	BUFF1_FANOUT = 5,		//Default fan out of BUFFER gate
	INV1_FANOUT = 5,		//Default fan out of INVERSE gate
	Led_FANOUT = 0,		//Default fan out of LED
	NAND2_FANOUT = 5,		//Default fan out of 2-input NAND gate
	NOR2_FANOUT = 5,		//Default fan out of 2-input NOR gate
	Switch_FANOUT = 1,		//Default fan out of SWITCH
	XNOR2_FANOUT = 5,		//Default fan out of 2-input XNOR gate
	XOR2_FANOUT = 5,		//Default fan out of 2-input XOR gate
	Connection_FANOUT = 5, //Default fan out of connection

};


#ifndef NULL
#define NULL 0
#endif

#endif
