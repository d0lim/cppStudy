#include <iostream>
#include <string>


template <typename T>
class Vector {
	T* data;
	int capacity;
	int length;
	
public:
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}
	
	void pushBack(T s) {
		if (capacity <= length) {
			T* temp = new T[capacity * 2];
			for(int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		data[length] = s;
		length++;
	}
	
	T operator[](int i) {
		return data[i];
	}
	
	void remove(int x) {
		for(int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}
	
	int size() {
		return length;
	}
	
	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

int main() {
	Vector<int> intVec;
	intVec.pushBack(3);
	intVec.pushBack(2);
	
	std::cout << "first : " << intVec[0] << std::endl;
	std::cout << "second : " << intVec[1] << std::endl;
	
	Vector<std::string> strVec;
	strVec.pushBack("hello");
	strVec.pushBack("world");
	std::cout << "first string : " << strVec[0] << std::endl;
	std::cout << "second string : " << strVec[1] << std::endl;
	
	return 0;
}

