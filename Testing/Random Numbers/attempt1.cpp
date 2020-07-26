// Dylan Leifer-Ives simple random number: 7-25-2020 22:53

#include <iostream>

int main() {
	std::ios_base::sync_with_stdio (false);
	int a;
	int b;
	int m;
	int seed;

	std::cout << "Input a Bigger is BETTER\n";
	std::cin >> a;
	std::cout << "Seed\n";
	std::cin >> seed;
	std::cout << "Mod m upper range i would hope\n";
	std::cin >> m;
	std::cout << "Now b, should be smallish\n";
	std::cin >> b;

	int result;

	result = (((seed * a) + b) % m);

	std::cout << result;



}
