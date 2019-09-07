#include <iostream>

class Marine {
	int hp;
	int coordX, coordY;
	int damage;
	bool isDead;
public:
	Marine();
	Marine(int x, int y);
	~Marine();
	
	int attack();
	void beAttacked(int attackedDamage);
	void move(int x, int y);
	
	void showStatus();
};


Marine::Marine() {
	hp = 50;
	coordX = coordY = 0;
	damage = 5;
	isDead = false;
}
Marine::Marine(int x, int y) {
	hp = 50;
	coordX = x;
	coordY = y;
	damage = 5;
	isDead = false;
}
Marine::~Marine() {
	std::cout << "Marine Deleted!" << std::endl;
}

void Marine::move(int x, int y) {
	coordX = x;
	coordY = y;
}
int Marine::attack() {
	return damage;
}
void Marine::beAttacked(int attackedDamage) {
	if (!isDead) {
		hp -= attackedDamage;
		if (hp <= 0) {
			isDead = true;
			hp = 0;
		}
	} else {
		std::cout << "Already Dead" << std::endl;
	}
}
void Marine::showStatus() {
	std::cout << "====================================================" << std::endl;
	std::cout << "HP : " << hp << std::endl;
	std::cout << "Coordinate : (" << coordX << ", " << coordY << ")" << std::endl;
	std::cout << "Damage : " << damage << std::endl;
	std::cout << "====================================================" << std::endl;
}

void test1() {
	/* This is first method to make object. 
	   Dynamic allocation.
	   Save object to heap of memory. */
	Marine* marine1 = new Marine(1, 1);
	Marine* marine2 = new Marine(3, 3);
	
	marine1->showStatus();
	marine2->showStatus();
	
	marine1->move(0, 0);
	marine1->beAttacked(marine2->attack());
	
	marine1->showStatus();
	marine2->showStatus();
}

void test2() {
	/* This is second method to make object. 
	   Static allocation.
	   Save object to stack of memory.
	   If function ends, objects will be deleted. */
	Marine marine1(1, 1);
	Marine marine2(3, 3);
	
	marine1.showStatus();
	marine2.showStatus();
	
	marine1.move(0, 0);
	marine1.beAttacked(marine2.attack());
	
	marine1.showStatus();
	marine2.showStatus();
}

int main() {
	test1();
	// test2();
	return 0;
}
