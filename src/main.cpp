#include <iostream>


class Animal {
	private:
	int food;
	int weight;
	
	public:
	void setAnimal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increaseFood(int feed) {
		food += feed;
		weight += (feed / 3);
	}
	void viewStat() {
		std::cout << "This animal has " << food << " food" << std::endl;
		std::cout << "This animal's weight is " << weight <<  std::endl;
	}
}; // Do not forget semicolon !!!

int main() {
	Animal animal;
	animal.setAnimal(100, 50);
	animal.increaseFood(30);
	
	animal.viewStat();
	return 0;
}

