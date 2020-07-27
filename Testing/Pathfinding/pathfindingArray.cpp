#include<iostream>

	
	const int xRows = 10;
	const int yRows = 10;

	char grid1[xRows][yRows];

	void display ();

int main() {
	//fill  
	for (int y = 0; y < yRows; y++) {
		for (int x = 0; x < xRows; x++) {
			grid1[x][y] = '#';
			std::cout << "#";
		}
		
		std::cout << "\n";
	}
	


	std::cout << "thanos\n";
	
	display();

	grid1[0][0] = 'o';

	display();

	return 0;
	
	
} 

//Right so this area displays the two dimentional character array, simple as that

void display () {	
	for (int y = 0; y < yRows; y++) {                                                                                                                                                                                                                    for (int x = 0; x < xRows; x++) {
			char tempx = grid1[x][y];
			std::cout << tempx;
		}                                                                                                                                                                                                                                            
	std::cout << "\n";                                                        
	}	 

}
