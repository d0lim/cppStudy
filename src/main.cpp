#include <iostream>



int main() {
	int arrSize;
	
	std::cout << "Input arr size : ";
	std::cin >> arrSize;
	
	int *list = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		std::cout << "Input " << i + 1 << " index data : ";
		std::cin >> list[i];
	}
	for (int i = 0; i < arrSize; i++) {
		std::cout << "Data of " << i + 1 << " index is : " << list[i] << std::endl;
	}
	
	delete[] list;
    return 0;
}

