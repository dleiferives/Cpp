#include<windows.h>  
#include<iostream>
#include <stdlib.h>
#include <time.h>
 
int main(){
	int speed;
	int scale = 1;
	std::cout << "Speed (ms)?\n";
  //speed 4 is my chosen favourite nice and fast
	std::cin >> speed;
	std::cout << "Scale?\n";
  //scale 1 = 100% zoom 2 = 200% and that follows in kind.
	std::cin >> scale;

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
		for(int i =0; i < 100; i++)
		{
			for(int j=0; j<100; j++)
			{
				int tempx = 5+(i*scale);
				int tempy = 144+(j*scale);
				

				if ((j%11) != 0)
				{

				if ((i%11) != 0)
				{		
				SetCursorPos(tempx,tempy);
				
				//sleeps the speed variable declared at the start
				Sleep(speed);

				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
				}}b
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
