#include <iostream>

	int a = 123456789;
	int result;
	int m;
	int b;
	int seed;

	int rand(int,int, int);
	
	int main() {
	std::ios_base::sync_with_stdio (false);
	
	std::cout << "Random number will be generated from:\n";
	std::cin >> b;
	std::cout << "To:\n";
	std::cin >> m;
	std::cout << "Seed:\n";
	std::cin >> seed;
	result = rand(b,m,seed);
	while ( result < b) {
		seed += 1;
		result =rand(b,m,seed);
		std::cout << result;
	}
	std::cout << "\nYour result is: " << result;
	}


	int rand(int b,int m,int seed) {


	result = ((((seed*a)+b)%m));

	if (result > 0 && b > 0){
		return result;
	}
	else if (result < 0 && b > 0) {
		return result *-1;
	}
	else{
		return result;
	}
	}

