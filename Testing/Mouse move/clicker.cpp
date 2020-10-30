#include<windows.h>
#include<time.h>

int main(){

		while (true){
			if(GetAsyncKeyState('B'))
    		{
    				mouse_event(MOUSEEVENTF_RIGHTDOWN,200,200,0,0);
    				mouse_event(MOUSEEVENTF_RIGHTUP,200,200,0,0);
    		}
		}



	return 0;
}
