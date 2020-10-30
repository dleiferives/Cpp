#include<iostream>
#include<string>
#include<time.h>
#include<windows.h>



void toSprayPaint();
void toCaligraphy1();
void toCaligraphy2();
void toPencil();
void toDropper();
void toolChange();
void openTools();
void fillEach(int curX);
void fillEnds();
void getColor(int red, int green, int blue);


int main(int numArgs,char  **args){

	//Declaring The Variables

	int originalX =400;
	int originalY =400;
	int randomX = 10;
	int randomY	= 10;
	int scale = 1;
	int spacing = 1;
	//Variables Loaded if possible
	if(numArgs >=2){
		//Help section
		{
			if(numArgs ==2){
			originalX = std::stoi(args[1]);
			if(numArgs ==3){
			originalY = std::stoi(args[2]);
			if(numArgs == 4){
			randomX = std::stoi(args[3]);
			if(numArgs == 5){
			randomY = std::stoi(args[4]);
			if(numArgs == 6){
			scale = std::stoi(args[5]);
			if(numArgs == 7){
			spacing = std::stoi(args[6]);
			}}}}}}

		}
			std::cout << "This is a simple ms paint program it can be passed 6 Variables at the moment:\noriginalX, originalY, randomX, randomY, scale, spacing. \3
	}
	std::cout << originalX << " " << originalY	<< " Is the size of the original 40
	int curX = originalX + 0
	
	while(true){
		if(GetAsyncKeyState('B'))
    	{

    		fillEach(2);

3
		}

		if(GetAsyncKeyState(VK_ESCAPE))
		{
		    break;
		}
	}

	return 0;
}




void toSprayPaint(){
	for(int i=0; i<3; i++){
	openTools();
	SetCursorPos(334,125);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	toolChange();}
}
void toCaligraphy1(){
	openTools();
	SetCursorPos(245,135);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(1000);
	toolChange();
}
void toCaligraphy2(){
	openTools();
	SetCursorPos(296,135);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(1000);
	toolChange();
}
void toPencil(){
	SetCursorPos(244,67);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	toolChange();
}
void toDropper(){
	SetCursorPos(267,93);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	toolChange();
}

void toolChange(){
	Sleep(4);
	SetCursorPos(10,1030);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
}

void openTools(){
	SetCursorPos(334,104);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(10);
}





void fillEach(int curX){
	int startx = 5;
	int starty = 145;
	
	for(int x =0;x < 255; x++){
		for(int y =0; y<255; y++){
			getColor(x,y,0);
			SetCursorPos(x+startx,y+starty);
			mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
			Sleep(10);
		}
	}


}
void fillEnds(){



}


void getColor(int red, int green, int blue){
	std::string redString = std::to_string(red);
	std::string greenString = std::to_string(green);
	std::string blueString = std::to_string(blue);



	int speed = 5;
	
	SetCursorPos(990,90);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);

//Red
	Sleep(50);
	SetCursorPos(1160,590);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(speed);
	//Deltes any given number prior
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	Sleep(speed);
	for(int i =0; i < redString.length(); i++){
		keybd_event(0x30 + ( (int)redString[i] - '0'), 0 ,0,0);

	}


//Green
	Sleep(speed);
	SetCursorPos(1160,617);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
	Sleep(speed);
	//Deltes any given number prior
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
Sleep(speed);
	for(int i =0; i < greenString.length(); i++){
		keybd_event(0x30 + ( (int)greenString[i] - '0'), 0 ,0,0);
		
	}
//Blue
	Sleep(speed);
	SetCursorPos(1160,640);
	mouse_event(MOUSEEVENTF_LEFTDOWN,200,200,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,200,200,0,0);
Sleep(speed);
	//Deltes any given number prior
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
	keybd_event(0x08,0,0,0);
	keybd_event(0x08,0x0002,0,0);
Sleep(speed);
	for(int i =0; i < blueString.length(); i++){
		keybd_event(0x30 + ( (int)blueString[i] - '0'), 0 ,0,0);
		
	}

	keybd_event(0x0D, 0,0,0);


//Open Color editor pos: 990 90
//REd POs : 1160 590
//Green Pos: 1160 617
//Blue Pos: 1160 640

//Backspace: 0x08
//Enter: 0x0D
//Keyup : 0x0002
// numbers: 0x3(0-9)
//keybd_event(0x30, 0,0,0)
//keybd_event(0x30, 0x0002,0,0)

}