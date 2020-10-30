#include<iostream>
#include<windows.h>
#include<time.h>

int main(int arguments, char * arguemnt[]){

	arguments = 2;
	if (arguemnt[1] == "help"){
		std::cout << "A simple program that selects and area, Q gets the top left while W gets the bottom right. And fills it on the press of F. (In ms paint of coarse)\n";
	}

	while(true){
	int topLeftX;
	int topLeftY;
	int botRightX;
	int botRightY;
	if(GetAsyncKeyState('Q'))
    {	
		POINT pLeft;
		if(GetCursorPos(&pLeft)){
			topLeftX = pLeft.x;
			topLeftY = pLeft.y;
		}
	}

	if(GetAsyncKeyState('W'))
    {	
		POINT pRight;
		if(GetCursorPos(&pRight)){
			botRightX = pRight.x;
			botRightY = pRight.y;
		}
	}

	if(GetAsyncKeyState('F')){
		mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
		for(int x = topLeftX; x < botRightX; x+=10){
				Sleep(5);
				
				SetCursorPos(x,topLeftY);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				Sleep(10);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				SetCursorPos(x,botRightY);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				Sleep(5);

				if(GetAsyncKeyState(VK_ESCAPE))
		        {
		            break;
		        }
			
			if(GetAsyncKeyState(VK_ESCAPE))
	        {
	            break;
	        }
		}
		mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
		
	}
	if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
}







}