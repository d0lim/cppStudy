#include <iostream>

class Complex {
	double real, img;
	
public:
	Complex(double real, double img);
	Complex operator+(const Complex &c);
	Complex operator-(const Complex &c);
	Complex operator*(const Complex &c);
	Complex operator/(const Complex &c);
	Complex& operator=(const Complex &c);
	void println();
};

Complex::Complex(double real, double img) : real(real), img(img) {}

Complex Complex::operator+(const Complex &c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex &c) {
	Complex temp(real - c.real, img + c.img);
	return temp;
}
Complex Complex::operator*(const Complex &c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex &c) {
	Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator=(const Complex &c) {
	real = c.real;
	img = c.img;
	return *this;
}


void Complex::println() {
	if (img > 0)
		std::cout << real << "+" << img << "i" << std::endl;
	else if (img == 0)
		std::cout << real <<std::endl;
	else
		std::cout << real << img << "i" << std::endl;
}

int main() {
	Complex *p1 = new Complex(1, 1);
	Complex *p2 = new Complex(4, -2);
	Complex *p3 = new Complex(0, 0);
	p1->println();
	p2->println();
	*p3 = *p1 + *p2 + *p1;
	p3->println();
	
	return 0;
}
