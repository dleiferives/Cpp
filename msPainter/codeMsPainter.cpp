//Dylan Leifer-Ives 10/30/2020
/* Documentation to read/ to use later for some cool shit. 
	Finding Window Handle ID from title: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-findwindowa
		Alternate way is to iterate through all hwnd's with getwindowText and search for Paint within them if the prior one does not work: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowtexta
	Getting Window Size on screen: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowrect
*/

#include <windows.h>
#include <iostream>
 
 
 //Getting paints Hwnd
 
 HWND fuck_me_baby = FindWindowW(NULL,L"2mice.png - Paint");
 
 
 

//Defined struct that we will use to move our mouse all about.
struct pos {
	int x;
	int y;
};

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
	std::cout<< fuck_me_baby;
	if (false){
		clickMouse(1);
		pos cunt = {200,400};
		moveMouse(cunt);
	}
	return 0;
}

