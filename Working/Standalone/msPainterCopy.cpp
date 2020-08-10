#include<windows.h>  
#include<iostream>
#include <stdlib.h>
#include <time.h>
 
 
	void toDropper();
int main(){
	int speed = 4;
	int scale = 1;

	int xScale = 320;
	int yScale = 400;
	//std::cout a<< "Speed (ms)?\n";
	//std::cin >> speed;
	//std::cout << "Scale?\n";
	//std::cin >> scale;b
    while (true)
    {



	if(GetAsyncKeyState('B'))
        {
		for(int i =0; i < xScale; i++)
		{
			for(int j=0; j< yScale; j++)
			{
				int tempx = 5+(i*scale);
				int tempy = 144+(j*scale);
				
				toDropper();
				SetCursorPos(tempx,tempy);
				
				//sleeps the speed variable declared at the start
				Sleep(speed+2);

				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

				// this section is the same as the last but it should just copy over the stuff, lets see if it works?
					SetCursorPos((tempx+((xScale+50)*scale)),tempy);
					
					//sleeps the speed variable declared at the start
					Sleep(speed);

					mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
					mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

				if(GetAsyncKeyState(VK_ESCAPE))
        			{
        			    break;
        			}
			}
		}
	}
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
   }

return 0;

}

void toDropper(){


	SetCursorPos(265,90);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(6);

}