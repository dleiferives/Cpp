//  7-25-2020 Dylan Leifer-Ives: A simple addition script in C++ to be compiled and ran in terminal.

#include <iostream>
//7:28 gotta remember to do the following line right I keep messing it up.
using namespace std;

//7:45 So I just learned that you have to declare your functions and that was why it wasn't compiling
int add(int x, int y);

int main() {

	int x;
	int y;
	int z;

	//7:30 So I think that this should be the right way to get the variables inputed
	//7:49 Was thinking about it and having a newline should look nicer.	
	cout << "Enter X\n";
	cin >> x;

	cout << "Enter Y\n";
	cin >> y;
	
	//7:42 I just learned that you have to set the result to the variable, Î know its dumb but I learned it regardless
	z = add(x,y);

	cout << z;	




return 0;
}	



//7:39 implemented
int add(int x, int y) {
	return x+y;
}
