#include <iostream>

	int a = 123456789;
	int b;
	int m;
	int seed;
	int result;
	
	int rand(int b, int m, int seed);
	
	int main() {
	std::ios_base::sync_with_stdio (false);
	
	std::cout << "Random number will be generated from:\n";
	std::cin >> b;
	std::cout << "To:\n";
	std::cin >> m;
	std::cout << "Seed:\n";
	std::cin >> seed;
	result = rand(b,m,seed);
	std::cout << result;
	}


	int rand(b,m,seed) {


	result = (((seed*a)+b)%m);

	return result;
	}

