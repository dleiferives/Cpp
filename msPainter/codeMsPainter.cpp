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
#include <stdlib.h>
#include <time.h> 
 
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
	void clickMouse(int mouseBool, int sleep =8){
		if (mouseBool == 0){
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		}
		if (mouseBool == 1){
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		}
		if(mouseBool == 3)
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
			Sleep(sleep);
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
			Sleep(10+sleep);
		
		}
		if(mouseBool == 4)
		{
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
		}
	}
	pos rand_pos(pos , pos );
	
	void random_draw( pos dropper, pos range, pos dTL, pos dBR, int iterations, bool further_rand=false);

int main(){	
	srand (time(NULL));
	//ensuring that paint is indeed open
	if (fuck_me_baby == 0 ) { 
		system("C:\\Windows\\System32\\mspaint.exe");
		fuck_me_baby = FindWindowW(NULL,L"Untitled - Paint");
	}
	//Getting msPaint window Size
	GetWindowRect(fuck_me_baby, &cum_in_calliou);
	//Pushing window size into the pos paintTopLeft and paintBotRight
	paintTopLeft.x = cum_in_calliou.left;
	paintTopLeft.y = cum_in_calliou.top;
	paintBotRight.x = cum_in_calliou.right;
	paintBotRight.y = cum_in_calliou.bottom;
	//declaring the drawing area that can be used with current setup
	drawTopLeft.x = paintTopLeft.x + 5 + windowx; drawTopLeft.y = paintTopLeft.y + 144 + windowy;
	drawBotRight.x = paintBotRight.x - 30; drawBotRight.y = paintBotRight.y - 55;
        
	pos mid_top = {(drawTopLeft.x + ((drawBotRight.x - drawTopLeft.x) / 2)),drawTopLeft.y};
	pos mid_bot = {mid_top.x, drawBotRight.y};	
	pos range = {mid_top.x - drawTopLeft.x, drawBotRight.y-drawTopLeft.y};

	pos dropper = {cum_in_calliou.left+120,cum_in_calliou.top+10};
	random_draw(dropper,range,drawTopLeft,drawBotRight,3000,true);
	
	random_draw(dropper,range,drawTopLeft,drawBotRight,10000);
	

	if (true){
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

pos rand_pos(pos range, pos dTL)
{

	pos rand_1 = {(dTL.x + (rand() % range.x)), dTL.y + (rand() % range.y)};
	return rand_1;
}

int rand_in_range(int dist, int start = 0)
{
	int result = start+(rand() % dist);
	return result;
}
void restrict_number(pos dBR, pos &number)
{
		if( number.x > (dBR.x-10)){number.x = dBR.x;}
		if( number.y > (dBR.y-10)){number.y = dBR.y;}
}
void random_draw( pos dropper, pos range, pos dTL, pos dBR, int iterations, bool further_rand)
{
	moveMouse(dTL);
	clickMouse(3);
	std::cout << "### Random Begin ### \n";
	for(int i =0; i< iterations; i++)
	{
		pos rand_pos1 = rand_pos(range,drawTopLeft); // getting the random position
		moveMouse(dropper);
		clickMouse(3,20);
		
		moveMouse(rand_pos1); // copying the color therre
		clickMouse(3,20);	


		rand_pos1.x += (range.x + dTL.x); // pasting color on other side
		moveMouse(rand_pos1);
		if (further_rand == false)
		{
			clickMouse(3,10);
		}
		else
		{
			clickMouse(1);
			rand_pos1.x += rand_in_range(5); rand_pos1.y += rand_in_range(5);
			restrict_number(dBR,rand_pos1);
			moveMouse(rand_pos1);
			Sleep(3);
			rand_pos1.x += rand_in_range(30,-15); rand_pos1.y += rand_in_range(30,-15);
			restrict_number(dBR,rand_pos1);
			moveMouse(rand_pos1);
			Sleep(3);
			for(int i=0; i < rand_in_range(40); i++)
			{
				clickMouse(1);
				rand_pos1.x += rand_in_range(30,-15); rand_pos1.y += rand_in_range(30,-15);
				restrict_number(dBR,rand_pos1);
				moveMouse(rand_pos1);
				rand_pos1.x += rand_in_range(30,-15); rand_pos1.y += rand_in_range(30,-15);
				restrict_number(dBR,rand_pos1);
				moveMouse(rand_pos1);
				Sleep(3);
				clickMouse(4);
			}
			rand_pos1.x += rand_in_range(30,-15); rand_pos1.y += rand_in_range(30,-15);
			moveMouse(rand_pos1);
			Sleep(3);
			rand_pos1.x += rand_in_range(30,-15); rand_pos1.y += rand_in_range(30,-15);
			moveMouse(rand_pos1);
			Sleep(3);
			clickMouse(4);	
			Sleep(15);
		}
		float it = 100* ((i*1.0)/(iterations));	
		std::cout << "x: "<< rand_pos1.x << " y: " << rand_pos1.y << " %: " << it << "\r";
		Sleep(30);
	
        if (GetAsyncKeyState('A'))
        {
		break;
	}
	}

}
