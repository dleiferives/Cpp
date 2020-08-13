//Dylan Leifer-Ives 8-9-2020: just draws stuff in ms paint based on whats on the other side.
#include<windows.h>  
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
 
	int speed = 5;
	int scale = 1;

	int xScale = 420;
	int yScale = 420;
	int k = 16;

void toDropper();
void toPencil();
void waterColor();
void squareBoy();
int main(){


	srand(time(0));

	//std::cout a<< "Speed (ms)?\n";
	//std::cin >> speed;
	//std::cout << "Scale?\n";
	//std::cin >> scale;b
    while (true)
    {

    	

	if(GetAsyncKeyState('B'))
    {
    	waterColor();
		squareBoy();	
		
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

void toPencil(){

	SetCursorPos(245,75);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(6);

}

void waterColor(){

	for(int i =0; i < xScale; i = i+k)
	{
		for(int j=2; j< yScale; j = j+k)
		{
			
			int tempx = 5+(i*scale);
			int tempy = 144+(j*scale);
			int tempRandX = rand() % 150 + 1;
			int tempRandY = rand() % 150 + 1;
			

			toDropper();
			SetCursorPos(tempx,tempy);
			
			//sleeps the speed variable declared at the start
			Sleep(speed+2);

			mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

			// this section is the same as the last but it should just copy over the stuff, lets see if it works?
				SetCursorPos((tempx+((xScale+50)*scale)),tempy);
				Sleep(speed);

				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);

						Sleep(speed);

				SetCursorPos(tempRandX+(tempx+((xScale+50)*scale)),tempy+tempRandY);
				Sleep(speed);
				

				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

				for (int i =0; i<20; i++){
				tempRandX = rand() % 30 + -5;
			 	tempRandY = rand() % 30 + -5;
										mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);

						Sleep(speed);

				SetCursorPos(tempRandX+(tempx+((xScale+50)*scale)),tempy+tempRandY);
				Sleep(speed);
				

				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
			}



			if(GetAsyncKeyState(VK_ESCAPE))
    			{
    			    break;
    			}
		}
	}

}

void squareBoy() {
	toPencil();
	for(int i =0; i < xScale; i = i+3)
		{
			for(int j=2; j< yScale; j = j+3)
			{
				int tempx = 5+(i*scale);
				int tempy = 144+(j*scale);
				// gets the color at tempx tempy
				{ 
				toDropper();
				SetCursorPos(tempx,tempy);
				Sleep(speed+2);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
				}
				// Draws the square
				SetCursorPos((tempx+((xScale+50)*scale)),tempy);
				Sleep(2);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

				SetCursorPos((tempx+((xScale+50)*scale)),tempy-1);
				Sleep(2);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

				SetCursorPos((tempx+((xScale+50)*scale))+1,tempy-1);
				Sleep(2);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

				SetCursorPos((tempx+((xScale+50)*scale))+1,tempy);
				Sleep(2);
				mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);



				if(GetAsyncKeyState(VK_ESCAPE))
    			{
    			    break;
    			}
			
			}

			if(GetAsyncKeyState(VK_ESCAPE))
    			{
    			    break;
    			}

		}



}