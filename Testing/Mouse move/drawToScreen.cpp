#include <Windows.h>
#include <iostream>

void drawRect(){
    HDC screenDC = ::GetDC(0);
    ::Rectangle(screenDC, 200, 200, 300, 300);
::ReleaseDC(0, screenDC);
}
int main(void){
    char c;
    std::cin >> c;
    if (c == 'd') drawRect();
    std::cin >> c;
    return 0;
}