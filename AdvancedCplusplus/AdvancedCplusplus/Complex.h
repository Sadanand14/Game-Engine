#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Complex {
	double real;
	double imaginary;
public:
	Complex() { cout << "Default Constructor Running" << endl; }
	Complex(double a, double b) : real(a), imaginary(b) { cout << "Custom Constructor Running" << endl; }
	const double GetReal() const { return real; }
	const double GetImaginary() const { return imaginary; }

	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);
	bool operator==(const Complex& other);
	bool operator!=(const Complex& other);
};

ostream& operator<<(ostream &out,const Complex &other);
Complex operator+(const Complex& a, const Complex&b);
Complex operator+(Complex a, double d);
Complex operator+(double d, const Complex&a);
