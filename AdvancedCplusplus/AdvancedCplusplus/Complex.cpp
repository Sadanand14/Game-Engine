#include <iostream>
#include "Complex.h"

Complex::Complex(const Complex &other) 
{
	cout << "Copy Constructor running" << endl;
	this->real = other.real;
	this->imaginary = other.imaginary;
}

const Complex& Complex:: operator=(const Complex &other) 
{
	cout << "Assignment Operator Running" << endl;
	this->imaginary = other.imaginary;
	this->real = other.real;
	return *this;
}

ostream &operator<<(ostream &out, const Complex &other) 
{
	cout << "bitWiseShift operator is running" << endl;
	out << "(" << other.GetReal() << "," << other.GetImaginary()<<")" ;
	return out;
}

Complex operator+(const Complex& a, const Complex& b)
{
	return Complex(a.GetReal()+b.GetReal(),a.GetImaginary()+b.GetImaginary());
}

Complex operator+( Complex a, double d)
{
	return Complex(a.GetReal() + d, a.GetImaginary());
}

Complex operator+(double d, const Complex& a)
{
	return Complex(a.GetReal() + d, a.GetImaginary());
}
bool Complex::operator==(const Complex& other)
{
	return (real==other.real) && (imaginary==other.imaginary);
}
bool Complex::operator!=(const Complex& other)
{
	return (real != other.real) && (imaginary != other.imaginary);
}