//Dylan Leifer-Ives 10/30/2020
/*
To configure for your computer you have to run the included MousePos.exe and see the difference between your window and screen coordinates at 0,0 mine is 0,0 screen 8,8 window so change the ints below this comment to change it for you.
*/
int windowx = 8;
int windowy = 8;


/* Documentation to read/ to use later for some cool shit. 
	Finding Window Handle ID from title: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-findwindowa
		Alternate way is to iterate through all hwnd's with getwindowText and search for Paint within them if the prior one does not work: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowtexta
	Getting Window Size on screen: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowrect

	##Notes##
	On ms paint Y hight smaller than 251 uppper bar dissapears
	
	On x smaller than 1104 smushing occurs
		x 970 shapes get smushed
		x 880 clipboard
		continues like that but lets just say always have it more than 1000 pix and you chill
		
	5, 145 is the start of the drawing area
	ending pixel drawing area 1900, 995
	1928, 1048
	
	minimum drawin area point is paintTopLeft.x + 5, paintTopLeft.y + 145
	maximum drawin area point is paintBotRight.x - 30, paintBotRight.y - 50

*/

#include <windows.h>
#include <iostream>
 
 
 //Getting paints Hwnd
 
 HWND fuck_me_baby = FindWindowW(NULL,L"Untitled - Paint");
 //Rectangle that gets filled with the position of the window on the screen. 
 RECT cum_in_calliou;
 
 

//Defined struct that we will use to move our mouse all about.
struct pos {
	int x;
	int y;
};
pos paintTopLeft;
pos paintBotRight;
pos drawTopLeft;
pos drawBotRight;

/* ### functions ### */

	// moves mouse to the position indicated.0
	void moveMouse(pos pos){
		SetCursorPos(pos.x,pos.y);
	}

	//Click mouse 
	void clickMouse(bool mouseBool){
		if (mouseBool == 0){
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		}
		if (mouseBool == 1){
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		}
	}


int main(){	
	//Getting msPaint window Size
	GetWindowRect(fuck_me_baby, &cum_in_calliou);
	//Pushing window size into the pos paintTopLeft and paintBotRight
	paintTopLeft.x = cum_in_calliou.left;
	paintTopLeft.y = cum_in_calliou.top;
	paintBotRight.x = cum_in_calliou.right;
	paintBotRight.y = cum_in_calliou.bottom;
	//declaring the drawing area that can be used with current setup
	drawTopLeft.x = paintTopLeft.x + 5 + windowx; drawTopLeft.y = paintTopLeft.y + 144 + windowy;
	drawBotRight.x = paintBotRight.x - 30; drawBotRight.y = paintBotRight.y - 50;
	
	moveMouse(drawTopLeft);
	
	//displays paint top left and bottom right pos in console
	if (false){
		std::cout << paintTopLeft.x << "," << paintTopLeft.y << "\n";
		std::cout << paintBotRight.x << "," << paintBotRight.y << "\n";
	}
	//some testing / debuging shit idk will probably delete
	if (false){
		clickMouse(1);
		pos cunt = {200,400};
		moveMouse(cunt);
	}
	return 0;
}

