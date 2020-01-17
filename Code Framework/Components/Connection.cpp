#include "Connection.h"
#include "../Actions/AddConnection.h"
#include<iostream>
using namespace std;
Connection::Connection(GraphicsInfo *r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus( (STATUS)SrcPin->getStatus() );
}

void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*m_pGfxInfo, Selected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

//virtual type getter function
string Connection::GetComponentType()
{
	return "Connection";
}

InputPin* Connection::getComponentInput()
{
	return DstPin;
}

OutputPin* Connection::getComponentOutput()
{
	return SrcPin;
}

bool Connection::IsInRegion(int x, int y)
{

	int x1 = m_pGfxInfo->PointsList[0].x;
	int y1 = m_pGfxInfo->PointsList[0].y;

	int x2 = m_pGfxInfo->PointsList[1].x;
	int y2 = m_pGfxInfo->PointsList[1].y;

	int x3 = m_pGfxInfo->PointsList[2].x;
	int y3 = m_pGfxInfo->PointsList[2].y;

	int x4 = m_pGfxInfo->PointsList[3].x;
	int y4 = m_pGfxInfo->PointsList[3].y;

	if ( (x >= x1 && x <= x2) || (x>= x2 && x<=x3) || (x>=x3 && x<=x4) )
	{
		if ((y >= y4 && y <= y3) || (y >= y3 && y <= y2) || (y >= y2 && y <= y1) )
		{
			cout << "Connection is in region\n";
			return true;
		}
	}
	return false;
}
