
#include <iostream>
#include <sstream>
#include <cmath>

#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

// Function to wait for a mouse click and clear the screen
void WaitNClear(window &inputWindow);

/////////////////////////////////////////////////////////////////////////////
// -- LINE DEMO --
/////////////////////////////////////////////////////////////////////////////
// Draw some different lines for example purposes
void LineDemo(window &testWindow)
{
    
    // Draws a green vertical line with a pen thickness of 5 pixels
    testWindow.SetPen(0.0, 1.0, 0.0, 5);    
    testWindow.DrawLine(5, 10, 5, 420);
    
    // Draws a black vertical line with a pen thickness of 1 pixel
    testWindow.SetPen(0.0, 0.0, 0.0, 1);
    testWindow.DrawLine(15, 10, 15, 420);
    
    // Draws a red diagonal line with a pen thickness of 10 pixels
    testWindow.SetPen(1.0, 0.0, 0.0, 10);
    testWindow.DrawLine(25, 10, 570, 420);
}
    

/////////////////////////////////////////////////////////////////////////////
// -- RECTANGLE DEMO --  
/////////////////////////////////////////////////////////////////////////////
// Draw a FRAME rectangle in black with a 5 pixel border
void RectangleDemo(window & testWindow)
{
    testWindow.SetPen(BLACK, 5);    
    testWindow.DrawRectangle(10, 10, 100, 100, FRAME);
    
    // Draw a FILLED rectangle in red without a border
    testWindow.SetPen(RED, 0);    
    testWindow.SetBrush(RED);
    testWindow.DrawRectangle(30, 30, 200, 200, FILLED);
    
    // Draw a FILLED rectangle in blue with a green 5 pixel border
    testWindow.SetPen(GREEN, 5);    
    testWindow.SetBrush(BLUE);
    testWindow.DrawRectangle(50, 50, 300, 300, FILLED);
    
    // Draw a FILLED rounded rectangle in cyan with a yellow 5 pixel border
    testWindow.SetPen(1.0, 1.0, 0.0, 5);    
    testWindow.SetBrush(0.0, 1.0, 1.0);
    testWindow.DrawRectangle(70, 70, 400, 400, FILLED, 20, 20);
    
    // Draw an INVERTED rectangle
    testWindow.DrawRectangle(200, 200, 500, 300, INVERTED);
}

/////////////////////////////////////////////////////////////////////////////
// -- TRIANGLE DEMO --     
/////////////////////////////////////////////////////////////////////////////
// Draw a FRAME triangle in blue with a 5 pixel border
void TriangleDemo(window & testWindow)
{
    testWindow.SetPen(BLUE, 5);    
    testWindow.DrawTriangle(10, 10, 10, 50, 300, 300, FRAME);
    
    // Draw a FILLED triangle in magenta without a border
    testWindow.SetPen(0.9, 0.2, 0.9, 0);    
    testWindow.SetBrush(0.9, 0.2, 0.9);
    testWindow.DrawTriangle(570, 430, 400, 400, 150, 200, FILLED);
    
    // Draw a FILLED triangle in green with a red 5 pixel border
    testWindow.SetPen(RED, 5);    
    testWindow.SetBrush(GREEN);
    testWindow.DrawTriangle(580, 10, 590, 200, 300, 300, FILLED);

    // Draw an INVERTED triangle
    testWindow.DrawTriangle(100, 100, 10, 420, 300, 250, INVERTED);
}

/////////////////////////////////////////////////////////////////////////////
// -- POLYGON DEMO --    
/////////////////////////////////////////////////////////////////////////////
// Draw a FRAME polygon with a red 5 pixel border
void PolygonDemo(window & testWindow)
{

    testWindow.SetPen(RED, 5);    
    int XPoints1[] = {10, 250, 300, 100};
    int YPoints1[] = {10, 50, 300, 150};
    testWindow.DrawPolygon(XPoints1, YPoints1, 4, FRAME);
    
    // Draw a FILLED polygon in aquamarine without a border
    testWindow.SetPen(AQUAMARINE, 0);    
    testWindow.SetBrush(AQUAMARINE);
    int XPoints2[] = {590, 420, 300, 100, 50, 20};
    int YPoints2[] = {420, 400, 150, 200, 45, 80};
    testWindow.DrawPolygon(XPoints2, YPoints2, 6, FILLED);
    
    // Draw a FILLED polygon in mistyrose with a grey 5 pixel border
    testWindow.SetPen(GREY, 5);    
    testWindow.SetBrush(MISTYROSE);
    int XPoints3[] = {400, 320, 400, 100, 120};
    int YPoints3[] = {40, 150, 250, 200, 380};
    testWindow.DrawPolygon(XPoints3, YPoints3, 5, FILLED);

    // Draw an INVERTED polygon
    int XPoints4[] = {300, 500, 580, 200};
    int YPoints4[] = {100, 100, 400, 400};
    testWindow.DrawPolygon(XPoints4, YPoints4, 4, INVERTED);
}
        
/////////////////////////////////////////////////////////////////////////////
// -- CIRCLE DEMO --     
/////////////////////////////////////////////////////////////////////////////
// Draw a FRAME circle in orange with a 5 pixel border
void CircleDemo(window & testWindow)
{
    testWindow.SetPen(ORANGE, 5);    
    testWindow.DrawCircle(100, 100, 70, FRAME);
    
    // Draw a FILLED circle in purple without a border
    testWindow.SetPen(0.5, 0.1, 0.9, 0);    
    testWindow.SetBrush(0.5, 0.1, 0.9);
    testWindow.DrawCircle(300, 200, 100, FILLED);
    
    // Draw a FILLED circle in grey with a yellow 7 pixel border
    testWindow.SetPen(YELLOW, 7);    
    testWindow.SetBrush(GREY);
    testWindow.DrawCircle(400, 400, 30, FILLED);

    // Draw an INVERTED circle
    testWindow.DrawCircle(500, 50, 120, INVERTED);
}

/////////////////////////////////////////////////////////////////////////////
// -- ELLIPSE DEMO -- 
/////////////////////////////////////////////////////////////////////////////
// Draw a FRAME ellipse in khaki with a 4 pixel border
void EllipseDemo(window & testWindow)
{

    testWindow.SetPen(KHAKI, 4);    
    testWindow.DrawEllipse(50, 100, 70, 300, FRAME);
    
    // Draw a FILLED ellipse in green without a border
    testWindow.SetPen(0.0, 1.0, 0.0, 0);    
    testWindow.SetBrush(0.0, 1.0, 0.0);
    testWindow.DrawEllipse(300, 200, 150, 400, FILLED);
    
    // Draw a FILLED ellipse in salmon with a tomato 3 pixel border
    testWindow.SetPen(TOMATO, 3);    
    testWindow.SetBrush(SALMON);
    testWindow.DrawEllipse(350, 100, 560, 150, FILLED);

    // Draw an INVERTED ellipse
    testWindow.DrawEllipse(100, 300, 200, 400, INVERTED);
}

/////////////////////////////////////////////////////////////////////////////
// -- ARC DEMO -- 
/////////////////////////////////////////////////////////////////////////////
// Draw a FRAME arc from 30 to 120 degrees in orchid with a 4 pixel border 
void ArcDemo(window & testWindow)
{
    testWindow.SetPen(ORCHID, 4);    
    testWindow.DrawArc(20, 150, 90, 300, 30.0, 120.0, FRAME);
    
    // Draw a FILLED arc from 0.2 to 2.1 radians in cyan without a border
    testWindow.SetPen(0.0, 1.0, 0.5, 0);    
    testWindow.SetBrush(0.0, 1.0, 0.5);
    testWindow.DrawArc(200, 100, 350, 400, 0.2, 2.1, FILLED, RADIANS);
    
    // Draw a FILLED arc from 90 to 270 degrees in thistle with a plum 6 pixel border
    testWindow.SetPen(PLUM, 6);    
    testWindow.SetBrush(THISTLE);
    testWindow.DrawArc(350, 100, 560, 150, 90, 270, FILLED);

    // Draw an INVERTED arc from 1.0 to 3.141 radians
    testWindow.DrawArc(100, 300, 200, 400, 1.0, 3.141, INVERTED, RADIANS);

}

/////////////////////////////////////////////////////////////////////////////
// -- BEZIER CURVE DEMO --
/////////////////////////////////////////////////////////////////////////////
// Draw a maroon curve with a pen thickness of 5 pixels
void BezierCurveDemo(window & testWindow)
{
    testWindow.SetPen(MAROON, 5);    
    testWindow.DrawBezier(5, 10, 5, 470, 10, 5, 470, 5);
    
    // Draw a black curve with a pen thickness of 1 pixel
    testWindow.SetPen(0.0, 0.0, 0.0, 1);
    testWindow.DrawBezier(15, 24, 200, 470, 300, 100, 560, 400);
    
    // Draw a coral curve with a pen thickness of 10 pixels
    testWindow.SetPen(CORAL, 10);
    testWindow.DrawBezier(500, 10, 630, 470, 300, 300, 10, 10);

}

/////////////////////////////////////////////////////////////////////////////
// -- TEXT DEMO --
/////////////////////////////////////////////////////////////////////////////
// Draw black text in italicized arial.
void TextDemo(window & testWindow)
{
    int iX, iY;
	testWindow.SetPen(BLACK); 
    testWindow.SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");   
    testWindow.DrawString(0, 0, "The moving cursor writes, and having written, blinks on.");

    // Draw "42" in hotpink bold modern text
    testWindow.SetPen(HOTPINK);
    testWindow.SetFont(72, BOLD, MODERN);

	int a = 125;
    
    // Use GetIntegerSize to find out where to draw a box around the number
    testWindow.GetIntegerSize(iX, iY, a);
    testWindow.DrawRectangle(100,100, 100 + iX, 100 + iY, FILLED);
    testWindow.DrawInteger(100,100,a);
    
    // Draws a dark grey colored approximation of pi
    testWindow.SetPen(DARKGREY);
    testWindow.SetFont(36, UNDERLINED, SWISS);
    testWindow.DrawDouble(500, 340, 3.1415926); 
}

/////////////////////////////////////////////////////////////////////////////
// -- IMAGE DEMO --
/////////////////////////////////////////////////////////////////////////////
//Placing an image in certain postion of the window with certian size
//And Zoominh
void ImageDemo(window & testWindow)
{

	testWindow.SetPen(BLACK); 
    testWindow.SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");   
    testWindow.DrawString(0, 0, "placing an image at any position with any size.");

	
	image testImage("scs.jpg", JPEG);

	testWindow.DrawImage(testImage, 50, 50);

	testWindow.DrawImage(testImage, 50, 300,500, 300);

	testWindow.DrawImage(testImage, 400, 50,400, 400);

	WaitNClear(testWindow);

    // Draw the image once
    testWindow.DrawImage(testImage, 10, 10);
    
    // Turn on double buffering
    testWindow.SetBuffering(true);

    double dScale;
    for(dScale = 1.0; dScale < 3.0; dScale += 0.01)
    {
        // Paint the background white
        testWindow.SetPen(WHITE, 0);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());

        // Scale and draw the image
        testWindow.DrawImage(testImage, 10, 10, (int)(testImage.GetWidth() * dScale), (int)(testImage.GetHeight() * dScale));

        // Update the screen buffer
        testWindow.UpdateBuffer();
        
        // Pause for a few milliseconds so it doesn't animate too quickly
        Pause(20);
    }
    
    // Store the screen in our image variable
    testWindow.StoreImage(testImage, 0, 0, (unsigned short)(testWindow.GetWidth() - 1), (unsigned short)(testWindow.GetHeight() - 1));
    
    for(dScale = 1.0; dScale > 0.0; dScale -= 0.01)
    {
        // Paint the background white
        testWindow.SetPen(WHITE, 0);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());

        // Scale and draw the image
        testWindow.DrawImage(testImage, 0, 0, (int)(testImage.GetWidth() * dScale), (int)(testImage.GetHeight() * dScale));

        // Update the screen buffer
        testWindow.UpdateBuffer();
        
        // Pause for a few milliseconds so it doesn't animate too quickly
        Pause(20);
    }    
        
    // Turn double buffering off
    testWindow.SetBuffering(false);
}

/////////////////////////////////////////////////////////////////////////////
// -- KEYBOARD AND MOUSE INPUT DEMO --
/////////////////////////////////////////////////////////////////////////////
void Keyboard_MouseDemo(window & testWindow)
{    
    testWindow.SetBuffering(true);
   
    bool bQuit = false;
    keytype ktInput;
    clicktype ctInput;
    char cKeyData;
    
    // Flush out the input queues before beginning
    testWindow.FlushMouseQueue();
    testWindow.FlushKeyQueue();

    testWindow.SetFont(20, BOLD, BY_NAME, "Arial");  

    do
    {
      // Paint the background white
      testWindow.SetPen(WHITE, 0);    
      testWindow.SetBrush(WHITE);
      testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());
    
      // Draws instructions
      testWindow.SetPen(BLACK); 
  
      testWindow.DrawString(5, 5, "Keyboard and Mouse Input Demo. Press \"Escape\" to quit");

	  int iX, iY;
	  ktInput = testWindow.GetKeyPress(cKeyData);
      ctInput = testWindow.GetMouseClick(iX, iY);
  
      // Figure out what key was pressed
      if(ktInput == ESCAPE) {
          bQuit = true;
      } else if(ktInput == ASCII) {
          ostringstream output;
          output << "The ASCII key '" << cKeyData << "' was pressed.";
          testWindow.DrawString(5, 30, output.str());
      } else if(ktInput == FUNCTION) {
          ostringstream output;
          output << "The Function key F" << int(cKeyData) << " was pressed.";
          testWindow.DrawString(5, 30, output.str());      
      } else if(ktInput == ARROW) {
          switch(cKeyData)
          {
            case 1:
              testWindow.DrawString(5, 30, "The End key was pressed.");
              break;
            case 2:
              testWindow.DrawString(5, 30, "The Down Arrow key was pressed.");
              break;
            case 3:
              testWindow.DrawString(5, 30, "The Page Down key was pressed.");
              break;
            case 4:
              testWindow.DrawString(5, 30, "The Left Arrow key was pressed.");
              break;
            case 5:
              testWindow.DrawString(5, 30, "The Center Keypad key was pressed.");
              break;
            case 6:
              testWindow.DrawString(5, 30, "The Right Arrow key was pressed.");
              break;
            case 7:
              testWindow.DrawString(5, 30, "The Home key was pressed.");
              break;
            case 8:
              testWindow.DrawString(5, 30, "The Up Arrow key was pressed.");
              break;
            case 9:
              testWindow.DrawString(5, 30, "The Page Up key was pressed.");
          }
      
      }

      if(ctInput == LEFT_CLICK) {
          ostringstream output;
          output << "The mouse was left-clicked at (" << iX << ", " << iY << ").";
          testWindow.DrawString(5, 60, output.str()); 
          
      } else if(ctInput == RIGHT_CLICK) {
          ostringstream output;
          output << "The mouse was right-clicked at (" << iX << ", " << iY << ").";
          testWindow.DrawString(5, 60, output.str()); 
      }

      // Update the screen buffer
      testWindow.UpdateBuffer();

      // Pause for half a second
      Pause(500);

    } while(bQuit != true);

    testWindow.SetBuffering(false);
}

/////////////////////////////////////////////////////////////////////////////
// -- GETCOLOR DEMO --
/////////////////////////////////////////////////////////////////////////////
//Getting the color of any pixel on the screen
void GetColorDemo(window & testWindow)
{
    image testImage("scs.jpg", JPEG);

	testWindow.SetBuffering(true);    

    // Flush out the input queues before beginning
    testWindow.FlushMouseQueue();
    testWindow.FlushKeyQueue();

    //testImage.Open("scs.jpg", JPEG); 

    // Clear the screen
    testWindow.SetPen(WHITE);    
    testWindow.SetBrush(WHITE);
    testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());

    int iX = 0,  iY = 0;

    testWindow.DrawImage(testImage, 10, 10);
 
    // Loop until there is a mouse click
    while(testWindow.GetMouseClick(iX, iY) == NO_CLICK)
    {
       testWindow.SetPen(WHITE);    
       testWindow.SetBrush(WHITE);
       testWindow.DrawRectangle(4, 370, 630, 430);
    
       testWindow.SetPen(BLACK);    
       testWindow.SetBrush(WHITE);
   
       double dRed, dGreen, dBlue;
       
       // Get the color currently under the mouse...
       testWindow.GetMouseCoord(iX, iY);
       testWindow.GetColor(iX, iY, dRed, dGreen, dBlue);
       
       // Draw the color info near the bottom of the window
       ostringstream output;
       output << "Red: " << dRed << "  Green: " << dGreen << "  Blue: " << dBlue;
	   testWindow.SetFont(28, BOLD | ITALICIZED, BY_NAME, "Arial");   
       testWindow.DrawString(5, 380, output.str());
       testWindow.DrawString(testWindow.GetWidth()/2 - 100, testWindow.GetHeight() - 50, "Click mouse to continue...");
	
        // Update the screen buffer
        testWindow.UpdateBuffer();
    }    
    testWindow.SetBuffering(false); 
}

/////////////////////////////////////////////////////////////////////////////
// -- MOUSESTATE and Dragging DEMO --
/////////////////////////////////////////////////////////////////////////////
// how to check for mouse state(i.e button up/down)
// how to simulate dragging by clearing and then redrawing 
void MouseState_DragDemo(window & testWindow)
{
    // Flush out the input queues before beginning
    testWindow.FlushMouseQueue();
    testWindow.FlushKeyQueue();

    testWindow.SetFont(20, BOLD, BY_NAME, "Arial");  

    testWindow.SetBuffering(true);   
    
    int RectULX = 100; 
    int RectULY = 100;
    int RectWidth = 20;
    
    bool bDragging = false;

    int iX = 0 , iY = 0;

    int iXOld = 0;
    int iYOld = 0;

    char cKeyData;
	// Loop until there escape is pressed
    while(testWindow.GetKeyPress(cKeyData) != ESCAPE)
    {
        testWindow.SetPen(WHITE);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth() - 1, testWindow.GetHeight() - 1);          
      

       // Dragging voodoo
        if(bDragging == false) {
            if(testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_DOWN) {
                if(((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth)))) {
                   bDragging = true; 
                   iXOld = iX; iYOld = iY;
                }
            }
        } else {
            if(testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_UP) {
                bDragging = false; 
            } else {
                if(iX != iXOld) {
                    RectULX = RectULX + (iX - iXOld);
                    iXOld = iX;
                }
                if(iY != iYOld) {
                    RectULY = RectULY + (iY - iYOld);
                    iYOld = iY;
                }
            }
        
        }
       
        // Draw rectangle
      
        testWindow.SetPen(ORANGE);    
        testWindow.SetBrush(ORANGE);
        testWindow.DrawRectangle(RectULX, RectULY, RectULX + RectWidth, RectULY + RectWidth);
       
        // Draw some info 
        testWindow.SetPen(BLACK); 
        testWindow.DrawString(5, 5, "MouseState Demo. Drag the orange box around. Press \"Escape\" to quit");   
     
        // Update the screen buffer
        testWindow.UpdateBuffer();
 
    }
    
	testWindow.SetBuffering(false);

}

/////////////////////////////////////////////////////////////////////////////
//  --- Move by arrows control DEMO ---
/////////////////////////////////////////////////////////////////////////////
// how to move using arrows
void MoveByArrowsDemo(window & testWindow)
{
    testWindow.FlushKeyQueue();

    testWindow.SetFont(20, BOLD, BY_NAME, "Arial");  

    testWindow.SetBuffering(true);   
    
    int RectULX = 100; 
    int RectULY = 100;
    int RectWidth = 50;
    
    bool bDragging = false;

    int iX = 0 , iY = 0;

    int iXOld = 0;
    int iYOld = 0;

    char cKeyData;
	keytype kType;

	// Loop until there escape is pressed
    do
    {
		kType = testWindow.GetKeyPress(cKeyData);
        testWindow.SetPen(WHITE);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth() - 1, testWindow.GetHeight() - 1);          
      

		if(kType == ARROW )
		{
			switch(cKeyData)
			{
			case 2:	//Down Arrow
				RectULY += RectWidth;
				break;
			case 4:	//left Arrow
				RectULX -= RectWidth;
				break;
			case 6:	//Down Arrow
				RectULX += RectWidth;
				break;
			case 8:	//Down Arrow
				RectULY -= RectWidth;
				break;
			}

		}
       
        // Draw rectangle
      
        testWindow.SetPen(BLUE);    
        testWindow.SetBrush(BLUE);
        testWindow.DrawRectangle(RectULX, RectULY, RectULX + RectWidth, RectULY + RectWidth);
       
        // Draw some info 
        testWindow.SetPen(BLACK); 
        testWindow.DrawString(5, 5, "Move by Arrows Demo. use arrows button to move the box. Press \"Escape\" to quit");   
     
        // Update the screen buffer
        testWindow.UpdateBuffer();
 

	}while(kType != ESCAPE);
    
	testWindow.SetBuffering(false);
}

/////////////////////////////////////////////////////////////////////////////
// --- Draw Menu Demo ---
/////////////////////////////////////////////////////////////////////////////
void DrawMenuDemo(window & testWindow, string *MenuItems, int ItemCount, int MenuItemWidth, int MenuItemHeight)
{
	// Draw menu item one image at a time
	for(int i=0; i<ItemCount; i++)
		testWindow.DrawImage(MenuItems[i], i*MenuItemWidth, 0, MenuItemWidth, MenuItemHeight);

	// Draw a line under the toolbar
	testWindow.SetPen(RED, 3);
	testWindow.DrawLine(0, MenuItemHeight, testWindow.GetWidth(), MenuItemHeight);	

}


/////////////////////////////////////////////////////////////////////////////
// --- Draw Menu Demo ---
/////////////////////////////////////////////////////////////////////////////
void DetectMenuDemo(window & testWindow, int ItemCount, int MenuItemWidth, int MenuItemHeight)
{

	// Draws instructions
	testWindow.SetPen(BLACK); 
    testWindow.SetFont(20, BOLD, BY_NAME, "Arial");  
  
	testWindow.DrawString(5, testWindow.GetHeight()-50, "Click on a menu icon. ==> Right-click to quit.....");

	while(1)
	{
		int Xcoord,Ycoord;
		clicktype ClkType = testWindow.WaitMouseClick(Xcoord,Ycoord);

		testWindow.SetPen(WHITE);
		testWindow.SetBrush(WHITE);
		testWindow.DrawRectangle(0,testWindow.GetHeight()-100,testWindow.GetWidth(),testWindow.GetHeight());

		if ( ClkType == RIGHT_CLICK) return;

		
		if(Ycoord < MenuItemHeight)
		{
			int itemClicked = Xcoord / MenuItemWidth;	//int division
			if(itemClicked < ItemCount)
			{
				ostringstream msg;
				msg<<"You clicked on menu item #"<<itemClicked+1<<"  Click on a menu icon. ==> Right-click to quit.....";
				testWindow.SetPen(BLACK);
				testWindow.DrawString(5, testWindow.GetHeight()-50, msg.str());
			}


		}

			
	}

}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
int main()
{
    
    // Create a new window 600 by 440 in size
    window myWind(900, 700, 5, 5);
    // Change the window title to something different
	myWind.ChangeTitle("CMU Graphics Package Demo");
    
    
	LineDemo(myWind);	
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
	RectangleDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
    
	TriangleDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window

	PolygonDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
	CircleDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
	EllipseDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
       
	ArcDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
	BezierCurveDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
	TextDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
	ImageDemo(myWind);
    WaitNClear(myWind); // Wait for a mouse click and clear the window
    
    
   	Keyboard_MouseDemo(myWind); // -- KEYBOARD AND MOUSE INPUT DEMO --
    WaitNClear(myWind); // Wait for a mouse click and clear the window

   	GetColorDemo(myWind); 
    
    MouseState_DragDemo(myWind);

	MoveByArrowsDemo(myWind);
	WaitNClear(myWind);

	
	///  Testing draw menu 
	//First prepare a list of images and save their paths into array of strings
	//The images MUST be in jpg format
	const int count = 7;
	const int menuHeight = 80,  menuItemWidth = 50;

	string MenuIconsPaths[count];	
	MenuIconsPaths[0] = "images\\copy.jpg";
	MenuIconsPaths[1] = "images\\cut.jpg";
	MenuIconsPaths[2] = "images\\delete.jpg";
	MenuIconsPaths[3] = "images\\run.jpg";
	MenuIconsPaths[4] = "images\\undo.jpg";
	MenuIconsPaths[5] = "images\\redo.jpg";
	MenuIconsPaths[6] = "images\\exit.jpg";
	DrawMenuDemo(myWind, MenuIconsPaths, count, menuItemWidth, menuHeight);
	

	DetectMenuDemo(myWind, count, menuItemWidth, menuHeight);
	



	return 0;
}

void WaitNClear(window &inputWindow)
{
 int iX, iY;
 
 	inputWindow.SetPen(BLACK);
	inputWindow.SetFont(28, BOLD, SWISS);
    inputWindow.DrawString(inputWindow.GetWidth()/2 - 100, inputWindow.GetHeight() - 50, "Click mouse to continue...");

    // Flush the mouse queue
    inputWindow.FlushMouseQueue();

    // Ignore return value since we don't care what type of click it was
    inputWindow.WaitMouseClick(iX, iY);

    // Set the brush and pen white so we can clear the background
    inputWindow.SetPen(WHITE, 0);    
    inputWindow.SetBrush(WHITE);
    
    // Draw a rectangle that covers the entire window
    inputWindow.DrawRectangle(0, 0, inputWindow.GetWidth(), inputWindow.GetHeight());
}
