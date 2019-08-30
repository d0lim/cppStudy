#include <iostream>

int getSquare(int arg);

int main() {
	int i;
	
	std::cout << "Input : ";
	std::cin >> i;
	std::cout << getSquare(i) << std::endl;
    return 0;
}

int getSquare(int arg) {
	return arg * arg;
}
