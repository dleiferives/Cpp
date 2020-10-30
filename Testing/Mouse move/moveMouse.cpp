#include<windows.h>  
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h> 


int main(){
	int speed = 4;
	int scale = 8;
	//std::cout << "Speed (ms)?\n";
	//std::cin >> speed;
	//std::cout << "Scale?\n";
	//std::cin >> scale;

    while (1)
    {

        if (GetAsyncKeyState('A'))
        {
            std::cout << "A key pressed" << std::endl;
		
		SetCursorPos(5,144);
		//mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
		//mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
        }


	if(GetAsyncKeyState('B'))
        {
		for(int i =0; i < 80; i++)
		{
			for(int j=0; j<60; j++)
			{
				int tempx = 5+(i*scale);
				int tempy = 144+(j*scale);
				int sinY = sin(j);
				int sinX = sin(i);

				if ((j%11) != 0)
				{

				if ((i%11) != 0)
				{	
				
				if((i%2) != 0)
				{
				
				if((j%2) != 0)
				{
				if((sinX%2) != 0)
				{

				if((sinY%3) != 0)
				{
				SetCursorPos(tempx,tempy);
				
				//sleeps the speed variable declared at the start
				Sleep(speed);

				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
				}}}}}}
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