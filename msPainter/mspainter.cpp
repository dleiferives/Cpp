#include <windows.h>
#include <cstdio>
// moves mouse to the position indicated.0

struct pos{
	int x;
	int y;
};

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

int main()
{
	moveMouse({100,100});
	return 0;
}
