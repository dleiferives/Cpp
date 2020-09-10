/*
IN;SP1;PU0,0;PD0,90;PU27,449;PD22,448,19,444

*/

	int temp =0;
	int curX;
	int curY;
	int startx = 10;
	int starty = 150;
	int scale = 1;
#include <string>
#include <iostream>
#include <cstddef>
#include <windows.h> 
#include <fstream>
#include <streambuf>
#include <sstream>

void mouseLeftDown ()
{
	 INPUT Input = {0};
     // left down
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
     ::SendInput(1,&Input,sizeof(INPUT));
     
}
	
void mouseLeftUp ()
{
     INPUT Input = {0};
    
     // left up
     ::ZeroMemory(&Input,sizeof(INPUT));
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
     ::SendInput(1,&Input,sizeof(INPUT));
}

void tempInc(){temp++;};
void tempZero(){temp=0;};
void cursor(int x, int y, bool click){
	x /= scale;
	y /= scale;
	x += startx;
	y += starty;
	if(x >= 1890+startx){x=1890+startx;}
	if(y >= 850+starty){y=850+starty;}
	if (click == 0){
		Sleep(1);
		mouseLeftUp();
		SetCursorPos(x,y);
		
	}
	
	else {
		Sleep(1);
		SetCursorPos(x,y);
		mouseLeftDown();
	}
	
	std::cout << x << " " << y<< " " << click << "\n";
}




template<typename StringFunction>
void splitString(const std::string &str, char delimiter, StringFunction f) {
	int temp =0;
  std::size_t from = 0;
  for (std::size_t i = 0; i < str.size(); ++i) {
    if (str[i] == delimiter) {
      f(str, from, i);
      from = i + 1;
    }
  }
  if (from <= str.size())
    f(str, from, str.size());
}


int main(int argc, char* argv[]) {
	std::string input1;
    if (argc != 2){
		std::ifstream t("files/mosaicWelsh.hpgl");
		std::stringstream buffer;
		buffer << t.rdbuf();
		
		input1 = buffer.str();
	}
	else{
		input1 = argv[1];
	}
	std::string string1 = "IN;SP1;PU0,0;PD0,90;PU27,449;PD22,448,19,444";
    splitString(input1, ';', [](const std::string &s, std::size_t from, std::size_t to) {
		//Makes string currString and prits the currently read string.
		std::string currString;
        std::cout << "`" << s.substr(from, to - from) << "`\n";
		currString = s.substr(from, to - from);
		//Switch statment that reads current line and then tells the code what the current line is telling it to do.
		char switchString = s.at(1+from);
	
		switch(switchString){
			case 'N' :
				std::cout << "program started or ended\n";
				break;
			case 'P' :
				std::cout << "selected pen\n";
				break;
			case 'U' :
				std::cout << "Pen Up\n";
				currString.erase(0,2);
				
				splitString(currString, ',', [](const std::string &s2, std::size_t from, std::size_t to) {
					tempInc();
					if( temp % 2 == 0){curY = stoi(s2.substr(from, to - from )); cursor(curX,curY,0);}
					else{
						curX = stoi(s2.substr(from, to - from));
					}
					//std::cout << temp <<  " -" << s2.substr(from, to - from) << "\n";
				});
				std::cout << temp / 2 << "\n";
				tempZero();
				break;
			case 'D' :
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				std::cout << "Pen Down\n";
				currString.erase(0,2);
		// same as above 
				splitString(currString, ',', [](const std::string &s2, std::size_t from, std::size_t to) {
					tempInc();
					if( temp % 2 == 0){curY = stoi(s2.substr(from, to - from )); cursor(curX,curY,1);}
					else{
						curX = stoi(s2.substr(from, to - from));
					}
					//std::cout << temp <<  " -" << s2.substr(from, to - from) << "\n";
				});
				std::cout << temp << "\n";
				tempZero();
		//Copy stops
				break;
		}
		
		// another split string that breaks up the commas for the commands
		
    });

    return 0;

}



