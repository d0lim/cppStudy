#include <iostream>

template <typename T, int num>
T addNum(T t) {
	return t + num;
}

int main() {
	double x = 3.5;
	std::cout << "x : " << addNum<double, 5>(x) << std::endl;
	
	return 0;
}
