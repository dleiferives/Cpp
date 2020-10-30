#include <windows.h>
#include<stdio.h>
#include<iostream>

HWND fgWnd = NULL;
char wndTitle[256];
int main(){
 fgWnd = GetForegroundWindow();
 std::cout << fgWnd;
 
 GetWindowTextA(fgWnd,wndTitle,sizeof(wndTitle));
 std::cout << wndTitle;
 Sleep(400);
 
 SetForegroundWindow(fgWnd);

return 0;
}
