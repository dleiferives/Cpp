#include<iostream>
#include <cstdlib>
	// defining our int's and some other stuff like functions
	const int xRows = 10;
	const int yRows = 10;
	
	int targetX;
	int targetY;

	int chaserX;
	int chaserY;

	char grid1[xRows][yRows];

	void display();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

int main() {
	//fills the board with # 
	for (int y = 0; y < yRows; y++) {
		for (int x = 0; x < xRows; x++) {
			grid1[x][y] = '#';
		}
		
	}

	// Set target
	
	std::cout << "Target X: ";
	std::cin >> targetX;
	std::cout << "Target Y: ";
	std::cin >> targetY;

	grid1[targetX][targetY] = 'X';

	display();
	
	//Set start.

	std::cout << "Chaser X: ";
	std::cin >> chaserX;
	std::cout << "Chaser Y: ";
	std::cin >> chaserY;

	grid1[chaserX][chaserY] = 'o';
	
	int z = 100;
	std::cout << "Max Number of Iterations: ";
	std::cin >> z;
	std::cout << "\n";
	
	//The wall *testing*


	//Start the chase

	//The actual looping of the code, It does the following, draws the chaser and the target, determines the closest of four moves, takes them.
	while (z > 1){
		z-=1;

		grid1[chaserX][chaserY] = '0';
		grid1[targetX][targetY] = 'X';

		display();

		int disUP = abs(targetY - (chaserY-1)) + abs(targetX - chaserX);
		if (disUP == 0) {moveUp(); break;}
		int disDown = abs(targetY - (chaserY+1)) + abs(targetX - chaserX);
		if (disDown== 0) {moveDown(); break;}
		int disRight = abs(targetY - (chaserY)) + abs(targetX - (chaserX+1));
		if (disRight == 0) {moveRight(); break;}
		int disLeft = abs(targetY - (chaserY)) + abs(targetX - (chaserX-1));
		if (disLeft == 0) {moveLeft(); break; }

		if (disUP < disDown) {
			if (disRight < disLeft){
				if ( disUP < disRight){
					moveUp();
				}
				else
				{
					if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
							moveRight();
					}
					else
					{
						if (grid1[chaserX][(chaserY+1)] != 'B'){
						moveUp();
						}
						else
						{
							if (grid1[(chaserX-1)][(chaserY)] != 'B'){
							       moveLeft();
							}
							else
							{
								if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
								moveDown();
								}
								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}

				}
			}
			else
			{
				if (disUP < disLeft){
					if (grid1[chaserX][(chaserY+1)] != 'B'){
						moveUp();
					}
					else
					{
						if (grid1[(chaserX-1)][(chaserY)] != 'B'){
							moveLeft();
						}
						else
						{
							if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
								moveRight();
							}
							else
							{
								if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
									moveDown();
								}
								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}
				}
				else
				{
					if (grid1[(chaserX-1)][(chaserY)] != 'B'){
						moveLeft();
					}
					else
					{
						if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
							moveRight();
						}
						else
						{
							if (grid1[chaserX][(chaserY+1)] != 'B'){
								moveUp();
							}
							else
							{
								if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
									moveDown();
								}
								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if(disRight < disLeft) {
				if (disDown < disRight){
					if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
						moveDown();
					}
					else
					{
						if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
							moveRight();
						}
						else
						{
							if (grid1[(chaserX-1)][(chaserY)] != 'B'){
								moveLeft();
							}
							else
							{
								if (grid1[chaserX][(chaserY+1)] != 'B'){
									moveUp();
								}

								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}
				}
				else
				{
					
					if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
						moveRight();
					}
					else
					{
						if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
							moveDown();
						}
						else
						{
							if (grid1[(chaserX-1)][(chaserY)] != 'B'){
								moveLeft();
							}
							else
							{
								if (grid1[chaserX][(chaserY+1)] != 'B'){
									moveUp();
								}

								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}

				}
			}
			else
			{
				if (disDown < disLeft){
					if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
						moveDown();
					}
					else
					{
						if (grid1[(chaserX-1)][(chaserY)] != 'B'){
							moveLeft();
						}
						else
						{
							if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
								moveRight();
							}
							else
							{
								if (grid1[chaserX][(chaserY+1)] != 'B'){
									moveUp();
								}

								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}
				}
				else
				{
					if (grid1[(chaserX-1)][(chaserY)] != 'B'){
						moveLeft();
					}
					else
					{
						if (grid1[(chaserX)][(chaserY-1)] != 'B'){ 
							moveDown();
						}
						else
						{
							if (grid1[(chaserX+1)][(chaserY)] != 'B'){ 
								moveRight();
							}
							else
							{
								if (grid1[chaserX][(chaserY+1)] != 'B'){
									moveUp();
								}

								else
								{
									std::cout << "fucking stuck \n";
									break;
								}
							}
						}
					}
				}
			}
		}

	if (chaserX == targetX){
		if (chaserY == targetY){
			break;
		}
	}

	}//end of while I hope


	display();

	return 0;
	
	
} 

//Right so this area displays the two dimentional character array, simple as that

void display() {	
	for (int y = 0; y < yRows; y++) {                                                                                                                                                                                                                    for (int x = 0; x < xRows; x++) {
			char tempx = grid1[x][y];
			std::cout << tempx;
		}                                                                                                                                                                                                                                            
	std::cout << "\n";                                                        
	}	 

}


void moveUp () {
	int chaserYOld = chaserY;
	chaserY -= 1;
	grid1[chaserX][chaserYOld] = '*';
}

void moveDown() {
	int chaserYOld = chaserY;
	chaserY += 1;
	grid1[chaserX][chaserYOld] = '*';
}

void moveRight() {
	int chaserXOld = chaserX;
	chaserX += 1;
	grid1[chaserXOld][chaserY] = '*';
}

void moveLeft() { 
	int chaserXOld = chaserX;
	chaserX -= 1;
	grid1[chaserXOld][chaserY] = '*';
}










































