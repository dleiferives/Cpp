//Dylan Leifer-Ives 8-9-2020: just draws stuff in ms paint based on whats on the other side.
#include<windows.h>  
#include<iostream>
#include<stdlib.h>
#include<time.h>

 
	int speed = 4;
	int scale = 1;

	int xScale = 819;
	int yScale = 505;
	int k = 5;
	int waterColorxk = 30;
	int waterColoryk = k;
	int shift=15;
	int ratio = 1;
		// defines in printer man function the height of vertical draw lines.
	int iterator = 20;

void toDropper();
void toPencil();
void sprayPaintFiller();
void squareBoy();
void printerMan();
void waterColor();
void toCalygOne();
void toCalgTwo();
void toSprayPaint();

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

    	//waterColor();
    	//printerMan();
    	//sprayPaintFiller();
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
	Sleep(4);
	SetCursorPos(265,90);
	Sleep(5);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	Sleep(5);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(2);
}

void toPencil(){

	SetCursorPos(245,75);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(6);

}

void sprayPaintFiller(){
	toSprayPaint();
	for(int i =0; i < xScale+1; i = i+k)
	{
		for(int j=2; j< yScale+1; j = j+k)
		{
			
			int tempx = 5+(i*scale);
			int tempy = 144+(j*scale);
			int tempRandX = rand() % 10 + -2;
			int tempRandY = rand() % 10 + -2;
			

			toDropper();
			SetCursorPos(tempx,tempy);
			
			//sleeps the speed variable declared at the start
			Sleep(speed+2);

			mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
			mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);

			// this section is the same as the last but it should just copy over the stuff, lets see if it works?
				SetCursorPos((tempx+((xScale)*scale))+shift,tempy);
				Sleep(speed);

				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);

						Sleep(speed);

				SetCursorPos(tempRandX+(tempx+((xScale)*scale))+shift,tempy+tempRandY);
				Sleep(speed);
				

				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);

				for (int i =0; i<30; i++){
				tempRandX = rand() % 10 + -2;
			 	tempRandY = rand() % 10 + -2;
										mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);

						Sleep(speed-1);

				SetCursorPos(tempRandX+(tempx+((xScale)*scale))+shift,tempy+tempRandY);
				Sleep(speed-1);
				

				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);

					Sleep(3);
			}



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
int squareIncrease =8;
void squareBoy() {
	toPencil();
	for(int i =0; i < xScale; i = i+squareIncrease)
		{
			for(int j=0; j< yScale; j = j+squareIncrease)
			{
				int tempx = 5+(i*scale);
				int tempy = 144+(j*scale);
				// gets the color at tempx tempy
				{ 
				toDropper();
				SetCursorPos(tempx,tempy);
				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
				}
				// Draws the square
				Sleep(speed+2);
				SetCursorPos((tempx+((xScale)*scale))+shift,tempy);
				Sleep(2);
				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
				SetCursorPos((tempx+((xScale)*scale))+shift,tempy-1);
				Sleep(2);
				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
				SetCursorPos((tempx+((xScale)*scale))+shift+1,tempy-1);
				Sleep(2);
				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
				SetCursorPos((tempx+((xScale)*scale))+shift+1,tempy);
				Sleep(2);
				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
				Sleep(2);	

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

int printerSpacer =3;
void printerMan(){
		
		int yEnd = iterator;
		for(int yStart = 0; yStart <= yScale; yStart += iterator){

			for(int x=0; x <= xScale	; x += printerSpacer){
				
				for(int y =yStart; y <= yEnd; y+= printerSpacer){
					int tempx = 5+(x*scale);
					int tempy = 144+(y*scale);
					SetCursorPos(tempx,tempy);
					mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
					mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
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
			if(GetAsyncKeyState(VK_ESCAPE))
    		{
    			break;
    		}
			Sleep(10);
			yEnd += iterator;
		}



}


void waterColor(){
	toCalygOne();
	for(int i =0; i < xScale; i = i+waterColorxk)
	{
		for(int j=2; j< yScale; j = j+waterColoryk)
		{
			int preTempx = 5+(i*scale);
			int preTempy =144+(j*scale);
			
			int tempx = preTempx + (rand() % 100 - 50);
			int tempy = preTempy + (rand() % 60 - 30);
			int tempRandX = rand() % 40 + -2;
			int tempRandY = rand() % 40 + -2;
			
			if (tempx >= (xScale + 5)){ tempx = (xScale+5);}
			if (tempx <= (6)){ tempx = (6);}
			if (tempx >= (yScale + 146)){ tempx = (yScale+146);}
			if (tempy <= (146)){ tempx = (146);}

			toDropper();
			SetCursorPos(tempx,tempy);
			
			//sleeps the speed variable declared at the start
			Sleep(speed+2);

			mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
			mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);

			// this section is the same as the last but it should just copy over the stuff, lets see if it works?
				SetCursorPos((tempx+((xScale)*scale))+shift,tempy);
				Sleep(speed);

				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);

						Sleep(speed);

				SetCursorPos(tempRandX+(tempx+((xScale)*scale))+shift,tempy+tempRandY);
				Sleep(speed);
				

				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);

				for (int i =0; i<1; i++){
				tempRandX = rand() % 40 + -2;
										mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
			 	tempRandY = rand() % 40 + -2;

						Sleep(speed+100);

				SetCursorPos(tempRandX+(tempx+((xScale)*scale))+shift,tempy+tempRandY);
				Sleep(speed);
				

				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);

					Sleep(4);
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
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
		waterColorxk = rand() % 10 + 10;
	}

}

void toCalygOne(){

	SetCursorPos(330,100);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
	SetCursorPos(250,135);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
	SetCursorPos(250,135);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
	SetCursorPos(0,1024);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);

}

void toCalgTwo(){
	Sleep(26);
	SetCursorPos(330,100);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(21);	
	SetCursorPos(300,135);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
		SetCursorPos(300,135);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
	SetCursorPos(0,1024);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);


}

void toSprayPaint(){
	Sleep(20);
	SetCursorPos(330,100);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(21);
	SetCursorPos(340,135);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
	SetCursorPos(340,135);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
	SetCursorPos(0,1024);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
	Sleep(26);
}
